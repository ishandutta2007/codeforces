#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[1000005];
int n,m,h[500005],t,f[500005],g[500005],dp[500005],c[500005][22],d[500005];
map<pair<int,int>,int> mp;
ll ans=0;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int dep)
{
	c[u][0]=fa;
	for(int i=1;i<=19;i++)
		c[u][i]=c[c[u][i-1]][i-1];
	d[u]=dep;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
	}
}
int lca(int u,int v)
{
	if(d[u]<d[v]) swap(u,v);
	for(int i=19;i>=0;i--)
		if(d[c[u][i]]>=d[v])
			u=c[u][i];
	if(u==v) return u;
	for(int i=19;i>=0;i--)
		if(c[u][i]!=c[v][i])
			u=c[u][i],v=c[v][i];
	return c[u][0];
}
int getnxt(int u,int v)
{
	for(int i=19;i>=0;i--)
		if(d[c[u][i]]>d[v])
			u=c[u][i];
	return u;
}
void ins(int u,int v)
{
	if(u>v) swap(u,v);
	ans+=mp[make_pair(u,v)];
	mp[make_pair(u,v)]++;
}
void dfs2(int u,int fa)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,u);
		f[u]+=f[v],g[u]+=g[v];
		dp[u]+=dp[v];
	}
//	printf("u=%d,f=%d,g=%d,dp=%d\n",u,f[u],g[u],dp[u]);
	ans+=1ll*f[u]*(f[u]-1)/2;
	ans-=2ll*g[u]*(g[u]-1)/2;
	ans+=1ll*dp[u]*(dp[u]-1)/2;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0,1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,l;
		scanf("%d%d",&u,&v);
		l=lca(u,v);
	//	printf("u=%d,v=%d,l=%d\n",u,v,l);
		if(u!=l&&v!=l) ins(getnxt(u,l),getnxt(v,l));
		f[u]++;f[v]++;f[l]--;f[c[l][0]]--;
		g[u]++;g[v]++;g[l]-=2;
		if(u!=l)
		{
			dp[u]++;
			dp[getnxt(u,l)]--;
		}
		if(v!=l)
		{
			dp[v]++;
			dp[getnxt(v,l)]--;
		}
	}
	dfs2(1,0);
	printf("%lld\n",ans);
	return 0;
}