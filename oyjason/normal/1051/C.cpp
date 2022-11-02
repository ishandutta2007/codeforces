#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 120
using namespace std;
int n,s[M],D[M][M],sz[M],G[M],flag=-1,F[M],fa[M],mg,mf;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) s[i]=read(),D[s[i]][++sz[s[i]]]=i;
	for(int i=0;i<=100;i++){
		if(!sz[i]) continue;
		if(sz[i]!=1)  fa[++mf]=i;
		else F[++mg]=D[i][1];
	}
	if(mg&1){
		bool fg=true;
		for(int i=1;i<=mf;i++){
			if(sz[fa[i]]<=2) continue;
			fg=false;
			for(int j=2;j<=sz[fa[i]];j++) G[D[fa[i]][j]]=2;
			flag=fa[i],F[++mg]=D[fa[i]][1];
			break;
		}
		if(fg){puts("NO");return 0;}
	}
	for(int i=1;i<=mf;i++){
	    if((!(sz[fa[i]]&1))&&flag!=fa[i]) for(int j=1;j<=sz[fa[i]];j++) G[D[fa[i]][j]]=2;
	}
	puts("YES");
	for(int i=1;i<=(mg>>1);i++) G[F[i]]=2;
	for(int i=(mg>>1)+1;i<=mg;i++) G[F[i]]=1;
	for(int i=1;i<=n;i++) putchar(G[i]==1?'A':'B');
	puts("");
}