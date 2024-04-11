#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 1020
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int ans,vis[M],n,p[M];
int dfs(int x){
	if(vis[x]>0) return x;
	vis[x]=1; return dfs(p[x]);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<=n;i++) memset(vis,0,sizeof(vis)),printf("%d%c",dfs(i),i==n?'\n':' ');
	return 0;
}