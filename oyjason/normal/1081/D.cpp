#include<bits/stdc++.h>
#define M 1000010
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
struct node{int x,y,w;}p[M];
int fa[M],cnt[M],vis[M],n,m,k;
bool cmp(node x1,node x2){return x1.w<x2.w;}
int fd(int x){return x==fa[x]?x:fa[x]=fd(fa[x]);}
bool merge(int x,int y){
	int t1=fd(x),t2=fd(y); if(t1==t2) return false;
	fa[t1]=t2; cnt[t2]+=cnt[t1]; if(cnt[t2]==k) return true;
	return false;
}
int main(){
	n=read(),m=read(),k=read();for(int i=1;i<=k;i++) vis[read()]=1;
	for(int i=1;i<=n;i++){fa[i]=i;if(vis[i]) cnt[i]=1;}
	for(int i=1;i<=m;i++) p[i].x=read(),p[i].y=read(),p[i].w=read();sort(p+1,p+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(merge(p[i].x,p[i].y)) {for(int j=1;j<=k;j++) printf("%d ",p[i].w);return 0;}
	}
 	return 0;
}