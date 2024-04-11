#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 3010
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,m,val[M],p[M][M],sz[M],u,v,ans,maxn,sum,now;
struct vt{LL num,pos,rk;}t[M];
bool cmp(vt i,vt j){return i.num>j.num;}
bool vis[M];
int main(){
	n=read(),m=read(),ans=1000000000000000ll; 
	for(LL i=1;i<=n;i++) t[i].pos=read(),t[i].num=read();
	sort(t+1,t+n+1,cmp);
	for(LL i=1;i<=n;i++) t[i].rk=++sz[t[i].pos];
	for(LL i=2;i<=m;i++) maxn=max(maxn,sz[i]);
	//for(LL i=1;i<=n;i++) printf("%lld  %lld %lld %lld\n",i,t[i].pos,t[i].num,t[i].rk);
	for(LL i=maxn;i>=0;i--){
		sum=sz[1],now=0;//memset(vis,false,sizeof(vis));
		for(LL j=n;j>0;j--){
			if(t[j].pos==1||t[j].rk<=i) continue;
			sum++,now+=t[j].num;
		}
		for(LL j=n;j>0&&sum<=i;j--){
			if(t[j].pos==1||t[j].rk>i) continue;
			sum++,now+=t[j].num;
		}
		//printf("%lld %lld %lld\n",i,sum,now);
		if(sum>i) ans=min(ans,now);
	}
	printf("%I64d\n",ans);
	return 0;
}