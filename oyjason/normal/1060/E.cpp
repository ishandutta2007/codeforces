#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 400020
using namespace std;
LL read(){
	LL nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL cnt1fa[M],cnt2fa[M],cnt1S[M],cnt2S[M],t1,t2,sum1f[M],sum2f[M],sum1s[M],sum2s[M];
struct edge{LL to,next;}a[M];
LL n,cnte,dep[M],fs[M],ans;
void add(LL u,LL v){
	a[++cnte]=(edge){v,fs[u]};fs[u]=cnte;
	a[++cnte]=(edge){u,fs[v]};fs[v]=cnte;
}
void dfs1(LL u,LL last){
	dep[u]=dep[last]+1;
	cnt1S[u]=cnt2S[u]=sum1s[u]=sum2s[u]=0;
	for(LL i=fs[u];i!=-1;i=a[i].next){
		LL v=a[i].to;if(v==last) continue;
		dfs1(v,u),cnt1S[u]+=cnt2S[v];sum1s[u]+=sum2s[v]+cnt2S[v];
		cnt2S[u]+=cnt1S[v];sum2s[u]+=sum1s[v]+cnt1S[v];
	} cnt2S[u]++;
}
void dfs2(LL u,LL last){
	LL cnt1,tot;
	for(LL i=fs[u];i!=-1;i=a[i].next){
		LL v=a[i].to;if(v==last) continue;
		cnt1=cnt2S[u]-cnt1S[v]+cnt2fa[u];
		tot=sum2s[u]-(sum1s[v]+cnt1S[v])+sum2f[u]+cnt1;
		sum1f[v]=tot;cnt1fa[v]=cnt1,cnt1=cnt1S[u]-cnt2S[v]+cnt1fa[u];
		tot=sum1s[u]-(sum2s[v]+cnt2S[v])+sum1f[u]+cnt1;
		sum2f[v]=tot;cnt2fa[v]=cnt1,dfs2(v,u);
	}
}
int main(){
	n=read(),memset(fs,-1,sizeof(fs));
	for(LL i=1;i<n;i++)	t1=read(),t2=read(),add(t1,t2); dfs1(1,0),dfs2(1,0),ans=0;
	for(LL i=1;i<=n;i++) ans+=((sum2s[i]+sum2f[i])>>1)+((sum1s[i]-cnt1S[i])>>1)+((sum1f[i]-cnt1fa[i])>>1)+(cnt1S[i]+cnt1fa[i]);
	printf("%lld\n",ans>>1);
}