#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define mid (l+r>>1)
#define M 1000020
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int vis[M],n,m,p[M],ct[M];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) p[i]=read(),vis[p[i]]++,ct[p[i]&m]++;
	for(int i=1;i<=n;i++){
		if(vis[p[i]]>=2){
			puts("0");
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if((p[i]&m)!=p[i]&&vis[p[i]&m]>0){
			puts("1");
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(ct[p[i]&m]>=2){
			puts("2");
			return 0;
		}
	}
	puts("-1");
	return 0;
}