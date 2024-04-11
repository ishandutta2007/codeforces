#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 2000020
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,m,S[M];
LL calc(LL r){
	return (2+n-(n/r))*r/2ll; 
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(LL i=1;i*i<=n;i++) if(n%i==0){
		S[++m]=calc(i);
		if(i*i<n) S[++m]=calc(n/i);
	}
	sort(S+1,S+m+1);
	for(LL i=1;i<=m;i++) printf("%lld ",S[i]);
	puts("");
	return 0;
}