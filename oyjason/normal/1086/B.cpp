#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 1000020
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,ind[M],cnt;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(),cnt=n,m<<=1;
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		if(ind[x]==1) cnt--; ind[x]++;
		if(ind[y]==1) cnt--; ind[y]++;
	}
	printf("%.9lf\n",(double)m/(cnt*1.0));
	return 0;
}