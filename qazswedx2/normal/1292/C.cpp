#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[500005];
int n,h[100005],t=1,sz[100005],dfn[100005],cnt;
ll f[3005][3005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
int getsz(int u,int fu,int v)
{
//	printf("getsz:u=%d,fu=%d,v=%d,ans=",u,fu,v);
	if(dfn[v]>=dfn[u]&&dfn[v]<dfn[u]+sz[u]) return n-sz[fu];
	return sz[u];
}
ll F(int u,int v,int fu,int fv)
{
	if(f[u][v]!=-1) return f[u][v];
	ll ans=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int vv=e[i].v;
		if(vv==fu) continue;
		ans=max(ans,F(vv,v,u,fv)+1ll*getsz(vv,u,v)*getsz(v,fv,vv));
	}
	swap(u,v),swap(fu,fv);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int vv=e[i].v;
		if(vv==fu) continue;
		ans=max(ans,F(vv,v,u,fv)+1ll*getsz(vv,u,v)*getsz(v,fv,vv));
	}
//	printf("u=%d,v=%d,ans=%d\n",u,v,ans);
	return f[u][v]=f[v][u]=ans;
}
void dfs(int u,int fa)
{
	dfn[u]=++cnt;
	sz[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
//	printf("u=%d,sz=%d,dfn=%d\n",u,sz[u],dfn[u]);
}
int main()
{
	memset(f,-1,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	ll ans=0;
	for(int i=2;i<=t;i+=2)
	{
		int v=e[i].v,u=e[i^1].v;
		if(sz[u]<sz[v]) swap(u,v);
		ans=max(ans,1ll*sz[v]*(n-sz[v])+F(u,v,v,u));
	//	printf("qwq:u=%d,v=%d,ans=%d\n",u,v,1ll*sz[v]*(n-sz[v])+F(u,v,v,u));
	}
	printf("%lld\n",ans);
	return 0;
}