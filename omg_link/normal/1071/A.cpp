#include <stdio.h>
#include <iostream>
#define MN 100000
int A,B,c,p=0,q=0,tt;
int a[MN+5],b[MN+5];
bool fl;
int main(){
	scanf("%d%d",&A,&B); tt=A+B;
	for(c=1;tt>=c;c++) tt-=c; c--;
	if(A<B) std::swap(A,B),fl=true;
	if(A!=0){
		for(p=1;A>=c&&c>0;p++,c--){
			a[p]=c; A-=c;
		}if(A!=0&&A<=c)a[p]=A; else p--;
	}
	if(B!=0){
		for(q=1;B>=c&&c>0;q++){
			b[q]=c; B-=c;
			c--; if(c==a[p]) c--;
		} q--;
	}
	if(!fl){
		printf("%d\n",p);
		for(int i=1;i<=p;i++)
			printf("%d ",a[i]);
		printf("\n%d\n",q);
		for(int i=1;i<=q;i++)
			printf("%d ",b[i]);
	}else{
		printf("%d\n",q);
		for(int i=1;i<=q;i++)
			printf("%d ",b[i]);
		printf("\n%d\n",p);
		for(int i=1;i<=p;i++)
			printf("%d ",a[i]);
			
	}
}