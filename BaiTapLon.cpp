#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char city_nm[30];
	char country[30];
	int year;
} city_st; 

int menu(city_st *c, int n);
void nhap(city_st *c, int n);
void xuat(city_st *c, int n);
void sapXep(city_st *c, int n);
void thongKe(city_st *c, int n);
void timKiem(city_st *c, int n);
void ghi(city_st *c, int n);
	
int main(){
	int n;
	city_st *cityList;
	cityList=(city_st*)malloc(n*sizeof(city_st));
	printf("Nhap so thanh pho ban muon nhap: ");
	scanf("%d", &n);
	nhap(cityList, n);
	printf("\nCac thanh pho ban vua nhap la:\n");
	xuat(cityList, n);
	sapXep(cityList, n);
	printf("\nCac thanh pho sau khi sap xep theo quoc gia (Z den A):\n");
	xuat(cityList, n);
	timKiem(cityList, n);
	ghi(cityList, n);
	menu(cityList, n);
	free(cityList);
}	 

//Hàm menu 
int menu(city_st *c, int n) {
    int luachon;
    //Hien ra bang menu cho nguoi dung chon
    printf("\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*                                                           *\n"); 
    printf("*      (MENU) Chon mot trong cac cong viec sau:             *\n");
	printf("*   1. Nhap du lieu cua tung thanh pho                      *\n");
	printf("*   2. Sap xep va hien thi thong tin chi tiet               *\n*      cua tung thanh pho theo quoc gia (Z->A).             *\n"); 
	printf("*   3. Tim  thanh pho theo quoc gia                         *\n");
	printf("*   4. Ghi vao tap tin nhi phan city.dat                    *\n");
	printf("*   5. Thoat                                                *\n");
	printf("*                                                           *\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n"); 
	printf("Nhap vao lua chon cua ban (1 den 5): ");
	scanf("%d", &luachon);
	switch(luachon) {
		case 1: nhap(c, n); break;
		case 2: xuat(c, n); sapXep(c, n); break; 
		case 3: timKiem(c, n); break; 
		case 4: ghi(c, n); break; 
		case 5: break; 
		default: printf("khong co lua chon %d, moi ban lua chon lai!\n", luachon);
		         menu(c,n); 
	}
}

//Hàm nhap 
void nhap(city_st *c, int n){
	printf("\nBan hay nhap du lieu  cua %d thanh pho \n\n", n);
	for(int i=0; i<n; i++){
		printf("Nhap du lieu thanh pho %d\n", i+1);
		fflush(stdin);
		printf("Ten: ");
		gets(c[i].city_nm);
		printf("Quoc gia: ");
		gets(c[i].country);
		printf("Nam: ");
		scanf("%d", &c[i].year);
		printf("\n");
	}
}

//Hàm xuat 
void xuat(city_st *c, int n){
	printf("STT||Ten                 ||Quoc gia            ||Nam\n");
	for(int i=0; i<n; i++){
		if(i<=8) 
            printf("00%d||%-20s||%-20s||%d\n", i+1, c[i].city_nm, c[i].country, c[i].year);
		else 
		    printf("0%d||%-20s||%-20s||%d\n", i+1, c[i].city_nm, c[i].country, c[i].year);
	}
}

//Hàm sap xep 
void sapXep(city_st *c, int n){
    for(int i=0; i<n-1; i++){
       for(int j=i+1; j<n; j++){
          if(strcmp(c[i].country, c[j].country) < 0){
         	city_st t; 
            t=c[i];
            c[i]=c[j];
            c[j]=t;
          }
       }
    }
}
	
//Hàm tim kiem
void timKiem(city_st *c, int n){
	char quocgia[30];
	int dem=0;
	city_st city_qg[50];
	printf("\nNhap quoc gia ban muon tim so thanh pho: ");
	fflush(stdin);
	gets(quocgia);
	for(int i=0; i<n; i++){
		if(strcmp(c[i].country, quocgia) == 0){
		   dem+=1;
		   city_qg[dem-1]=c[i];
		}
	}
	if(dem>0){
	   printf("Quoc gia ban nhap vao: %s co %d thanh pho\n", quocgia, dem); 
	   xuat(city_qg, dem);
    }
    else
	   printf("Khong co thanh pho nao thuoc quoc gia nay\n"); 	 
}


//Hàm ghi vào teo nhi phan city.dat	 
void ghi(city_st *c, int n){
	FILE *fnp;
	fnp=fopen("city.dat", "w");
	fprintf(fnp, "STT||%-20s||%-20s||%s\n", "Ten", "Quoc gia", "Nam"); 
	for(int i=0; i<n; i++){
		if(i<=8) 
            fprintf(fnp, "00%d||%-20s||%-20s||%d\n", i+1, c[i].city_nm, c[i].country, c[i].year);
		else 
		    fprintf(fnp, "0%d||%-20s||%-20s||%d\n", i+1, c[i].city_nm, c[i].country, c[i].year);
	}   
    fclose(fnp);
} 