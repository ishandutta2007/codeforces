//j
#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
#ifdef mod
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
#endif
int fir[500010],dis[1000010],nxt[1000010],id;
il vd link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
ll ans[500010];
int siz[500010];
il vd predfs(int x,int fa=-1){
	siz[x]=1;
	for(int i=fir[x];i;i=nxt[i]){
		if(fa==dis[i])continue;
		predfs(dis[i],x);
		siz[x]+=siz[dis[i]];
	}
}
il vd dfs(int x,int fa=-1){
	for(int i=fir[x];i;i=nxt[i]){
		if(fa==dis[i])continue;
		ans[dis[i]]=ans[x]+1ll*(siz[x]-siz[dis[i]])*siz[dis[i]];
		dfs(dis[i],x);
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),a,b;
	for(int i=1;i<n;++i)a=gi(),b=gi(),link(a,b),link(b,a);
	predfs(1);
	ans[1]=1ll*n*(n-1)/2;dfs(1);
	int x=2;for(int i=3;i<=n;++i)if(ans[i]>ans[x])x=i;
	predfs(x);
	ans[x]=1ll*n*(n-1)/2;dfs(x);
	ll ANS=0;
	for(int i=1;i<=n;++i)if(i!=x)ANS=std::max(ANS,ans[i]);
	printf("%lld\n",ANS);
	return 0;
}