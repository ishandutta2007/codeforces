#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define mid (l+r>>1)
#define M 300020
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
void fail(){puts("NO");exit(0);}
int c[M],n,m,p[M<<2],last[M],fs[M],maxn,tg[M<<2],t[M];
void ins(int x,int l,int r,int L,int R,int num){
	if(r<L||R<l) return;
	if(L<=l&&r<=R){tg[x]=p[x]=num;return;}
	if(tg[x]) tg[x<<1]=p[x<<1]=tg[x<<1|1]=p[x<<1|1]=tg[x],tg[x]=0;
	ins(x<<1,l,mid,L,R,num),ins(x<<1|1,mid+1,r,L,R,num);
}
void dfs(int x,int l,int r){
	if(l==r){t[l]=p[x];return;}
	if(tg[x]) tg[x<<1]=p[x<<1]=tg[x<<1|1]=p[x<<1|1]=tg[x],tg[x]=0;
	dfs(x<<1,l,mid),dfs(x<<1|1,mid+1,r);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) c[i]=read(),maxn=max(c[i],maxn);
	if(maxn>m) fail();
	for(int i=1;i<=n;i++){
		if(!fs[c[i]]) fs[c[i]]=i;
		last[c[i]]=i;
	}
	for(int i=1;i<=m;i++){
		if(fs[i]) ins(1,1,n,fs[i],last[i],i);
		else if(fs[0]) ins(1,1,n,fs[0],fs[0],i);
		else if(i<maxn) continue;
		else fail();
	}
	dfs(1,1,n);
	//for(int i=1;i<=n;i++) printf("%d %d\n",i,t[i]);
	for(int i=1;i<=n;i++) if(c[i]>0&&t[i]!=c[i]) fail();
	puts("YES");
	for(int i=1;i<=n;i++) printf("%d%c",max(t[i],1),i==n?'\n':' ');
	return 0;
}