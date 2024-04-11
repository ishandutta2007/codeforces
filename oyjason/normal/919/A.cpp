#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 5020
using namespace std;
LL read(){
	LL num=0,oe=1;char cw=getchar();
	while(!isdigit(cw)) oe=cw=='-'?-1:1,cw=getchar();
	while(isdigit(cw)) num=num*10+cw-'0',cw=getchar();
	return num*oe;
}
LL n,m,s[M],t[M],u=1ll,v=0ll,a,b;
double tmp;
int main(){
	n=read(),m=read();
	for(LL i=1;i<=n;i++){
	    a=read(),b=read();
	    if(a*v<b*u) u=a,v=b;
	}
	tmp=u*m*1.0/(v*1.0);
	printf("%.6f\n",tmp);
	return 0;
}