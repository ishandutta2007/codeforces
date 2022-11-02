#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 300020
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,fs[M],nt[M<<1],to[M<<1],tmp;
LL tot,cnt,p[M],F[M]; 
void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
void DP1(int x,int last){
	F[x]=p[x];
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]^last)
		DP1(to[i],x),F[x]+=max(F[to[i]],0ll); tot=max(tot,F[x]);
}
void DP2(int x,int last){
	F[x]=p[x];
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]^last)
		DP2(to[i],x),F[x]+=max(F[to[i]],0ll);
	if(F[x]==tot) F[x]=0ll,cnt++;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),tot=-100000000000000ll,memset(fs,-1,sizeof(fs));
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1,x,y;i<n;i++) x=read(),y=read(),link(x,y),link(y,x);
	DP1(1,0),DP2(1,0); printf("%lld %lld\n",tot*cnt,cnt);
	return 0;
}