#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,len,tot;
void write(int x){
	tot++,printf("%d",x);
	if(tot==n) putchar('\n');
	else putchar(' ');
}
int main(){
	n=read();
	len=sqrt(n);
	for(int i=1;i*len<=n;i++){
		for(int x=i*len;x>(i-1)*len;x--) write(x);
	}
	for(int i=n;i%len>0;i--) write(i);
	return 0;
}