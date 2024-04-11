#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define mid (l+r>>1)
#define M 200020
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,now,pos[M],last[M],fs[M],nt[M],vis[M];
int c[M];
char ch[M];
void opt(int l,int r){for(int i=l;i<=r;i++) putchar(ch[i]);}
int add(int x,int ps){for(int k=ps;k<=n;k+=(k&-k)) c[k]+=x;}
int sum(int ps){
	int tot=0;
	for(int k=ps;k;k-=(k&-k)) tot+=c[k];
	return tot;
}
int main(){
	n=read(),m=read(),scanf("%s",ch+1),last[0]=-1;
	for(int i=1;i<=n;i++,pos[i]=pos[i-1]){
		if(ch[i]=='(') pos[i]++;
		else pos[i]--;
		last[i]=fs[pos[i]]+1;
		fs[pos[i]]=i;
		add(1,i);
	}
	for(int i=n;i>0;i--){
		if(vis[i]) continue;
		int k=-sum(last[i]-1)+sum(i);
		if(k<=m) m-=k,i=last[i];
		else add(-1,i),add(-1,last[i]),vis[i]=vis[last[i]]=1;
	}
	for(int i=1;i<=n;i++) if(vis[i]==0) putchar(ch[i]);
	putchar('\n'); return 0;
}