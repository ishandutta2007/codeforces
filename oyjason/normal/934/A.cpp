#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define LL long long
using namespace std;
LL read(){
	LL num=0,oe=1;char cw=getchar();
	while(!isdigit(cw)) oe=cw=='-'?-1:1,cw=getchar();
	while(isdigit(cw)) num=num*10+cw-'0',cw=getchar();
	return num*oe;
}
LL a[1000],b[1000],n,m,p[20000];
bool change;
int main(){
	n=read(),m=read();
	for(LL i=1;i<=n;i++) a[i]=read();
	for(LL i=1;i<=m;i++) b[i]=read();
	sort(a+1,a+n+1),sort(b+1,b+m+1);
	for(LL i=1;i<=n;i++){
		change=false;
		for(LL j=1;j<=n;j++){
			if(i==j) continue;
			if(!change) p[i]=max(a[j]*b[1],a[j]*b[m]),change=true;
			else p[i]=max(p[i],max(a[j]*b[1],a[j]*b[m]));
		}
	}
	sort(p+1,p+n+1);
	printf("%I64d\n",p[1]);
	return 0;
}