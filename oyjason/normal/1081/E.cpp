#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define MAXN 10000000000000ll
#define M 1000020 
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
void fad(){puts("No");exit(0);}
LL n,m,p[M],t[M],now=0,gg=1;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=2;i<=n;i+=2) p[i]=read();
//	for(int i=1;i<=n;i++) printf("%d ",p[i]); puts("");
	for(LL i=1;i<=n;i+=2){
		while(true){
			p[i]=gg*gg-now;
			if(p[i]>MAXN) fad();
			if(p[i]<=0){gg++;continue;}
			LL K=sqrtl(now+p[i]+p[i+1]);
			if(K*K==now+p[i]+p[i+1]){now+=p[i]+p[i+1],gg=K;break;} 
			gg++;
		}
	}	
	puts("Yes");
	for(int i=1;i<=n;i++) printf("%lld ",p[i]);
	puts("");
	return 0;
}