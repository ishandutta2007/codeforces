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
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) p[i]=read();
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		if(p[i]>p[i-1]) m--,printf("%d\n",p[i]-p[i-1]);
		if(!m) return 0;
	}
	while(m--) puts("0");
	return 0;
}