#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 800011;
std::vector<int>g[MAXN];
int a[MAXN],mx[MAXN],delta[MAXN];
ll ans=0;
void dfs1(int u,int fa)
{
	if(fa&&g[u].size()==1)
	{
		mx[u]=delta[u]=a[u];
		//printf("Mx[%d]=%d\n",u,mx[u]);
		ans+=a[u];return;
	}
	for(auto v:g[u])
		if(v!=fa)
		{
			dfs1(v,u);
			umax(mx[u],mx[v]);
		}
	if(mx[u]<a[u])delta[u]=a[u]-mx[u], ans+=delta[u],mx[u]=a[u];
}
int lim;
void dfs2(int u,int fa,ll sum,int extra)
{
	std::vector<int>suf;
	for(auto v:g[u])
	{
		if(v==fa)continue;
		suf.emplace_back(mx[v]);
	}
	suf.emplace_back(0);
	std::reverse(suf.begin(),suf.end());
	for(int i=1;i<int(suf.size());++i)umax(suf[i],suf[i-1]);
	umin(ans,sum+max(a[u]-max(suf.back(),extra),0));
	int pre=0;
	for(auto v:g[u])
	{
		if(v==fa)continue;
		suf.pop_back();
		int nxt=max(max(pre,suf.back()),extra);
		//printf("%d -> %d,nxt = %d\n",u,v,nxt);
		if(a[u]>nxt)dfs2(v,u,sum-delta[v]+a[u]-nxt,a[u]);
		else dfs2(v,u,sum-delta[v],nxt);
		umax(pre,mx[v]);
	}
}
int main()
{
	int n=read(),r=0;
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		if(a[i]>a[r])r=i;
	}
	for(int i=1;i<n;++i){int u=read(),v=read();g[u].emplace_back(v),g[v].emplace_back(u);}
	lim=a[r];
	ans+=lim;
	dfs1(r,0);
	//printf("Mx:");
	//for(int u=1;u<=n;++u)printf("%d ",mx[u]);
	//puts("");
	//printf("Preans=%lld\n",ans);
	dfs2(r,0,ans-delta[r],0);
	printf("%lld\n",ans);
	return 0;
}