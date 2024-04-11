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
int n,m,x,p[1000010];
#define bas 300000
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) p[i]=read()%n;
	printf("%d\n",n+1);
	printf("1 %d %d\n",n,n-p[n]-1);
	for(int i=1;i<n;i++) printf("1 %d %d\n",i,(p[i+1]-1-p[i]+n)%n);
	printf("2 %d %d\n",n,n);
	return 0;
}