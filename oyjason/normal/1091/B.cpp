#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 100020
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,m,X[M],Y[M],tx[M],ty[M];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) X[i]=read(),Y[i]=read();
	for(int i=1;i<=n;i++) tx[i]=read(),ty[i]=read();
	sort(X+1,X+n+1),sort(Y+1,Y+n+1); 
	sort(tx+1,tx+n+1),sort(ty+1,ty+n+1);
	printf("%lld %lld\n",X[1]+tx[n],Y[1]+ty[n]);
	return 0;
}