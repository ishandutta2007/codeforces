#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define mid (l+r>>1)
#define M 100020
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,p[M],t[M],ans1,ans2;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(LL i=1;i<=n;i++) ans1+=read();
	for(LL i=1;i<=n;i++) ans2+=read();
	if(ans1>=ans2) puts("Yes");
	else puts("No");
	return 0;
}