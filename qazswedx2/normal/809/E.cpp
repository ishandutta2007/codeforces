#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
const int mod=1e9+7;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
struct edge
{
	int v,nxt;
}e[500005];
int n,a[200005],t,h[200005],pn=200000,p[200005],prime[200005],pt,phi[200005];
int mu[200005],f[200005],iphi[200005],vis[200005],d[200005],size[200005];
int rt,g[200005][2],ans=0,dl[10000005],dt,b[200005],bt;
std::vector<int> val[200005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	size[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		dfs(v,u);
		size[u]+=size[v];
	}
}
void dfs2(int u,int fa,int sz)
{
	int mx=sz-size[u];
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		dfs2(v,u,sz);
		mx=std::max(mx,size[v]);
	}
	if(sz/2>=mx) rt=u;
}
void dfs3(int u,int fa,int dep)
{
	d[u]=dep;
	b[++bt]=u;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		dfs3(v,u,dep+1);
	}
}
void clear()
{
	for(int i=1;i<=dt;i++)
		g[dl[i]][0]=g[dl[i]][1]=0;
	dt=0;
}
void getans(int fl)
{
	for(int i=1;i<=bt;i++)
	{
		int id=b[i];
		int sz=val[a[id]].size();
		for(int j=0;j<sz;j++)
		{
			int v=val[a[id]][j];
			ans=submod(ans-1ll*g[v][0]*g[v][1]%mod*f[v]%mod*fl%mod);
			g[v][0]=addmod(g[v][0]+1ll*d[id]*phi[a[id]]%mod);
			g[v][1]=addmod(g[v][1]+phi[a[id]]);
		//	printf("getans:fl=%d,id=%d,v=%d,g=%d,%d\n",fl,id,v,g[i][0],g[i][1]);
			ans=addmod(ans+1ll*g[v][0]*g[v][1]%mod*f[v]%mod*fl%mod);
			dl[++dt]=v;
		}
	}
	clear();
}
void dfz(int u)
{
	dfs(u,0);
	dfs2(u,0,size[u]);
	bt=0;
	dfs3(rt,0,0);
	getans(1);
	for(int i=h[rt];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		bt=0;
		dfs3(v,rt,1);
		getans(mod-1);
	}
//	printf("rt=%d,ans=%d\n",rt,ans);
	vis[rt]=1;
	for(int i=h[rt];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		dfz(v);
	}
}
int main()
{
	phi[1]=mu[1]=1;
	for(int i=2;i<=pn;i++)
	{
		if(!p[i]) prime[++pt]=i,phi[i]=i-1,mu[i]=-1;
		for(int j=1;j<=pt&&i*prime[j]<=pn;j++)
		{
			p[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				mu[i*prime[j]]=0;
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
			mu[i*prime[j]]=-mu[i];
		}
	}
	for(int i=1;i<=pn;i++)
		for(int j=i;j<=pn;j+=i)
			val[j].push_back(i);
	for(int i=1;i<=pn;i++)
		iphi[i]=fpow(phi[i],mod-2);
	for(int i=1;i<=pn;i++)
		for(int j=i;j<=pn;j+=i)
			if(mu[j/i]==1) f[j]=addmod(f[j]+1ll*i*iphi[i]%mod);
			else if(mu[j/i]==-1) f[j]=submod(f[j]-1ll*i*iphi[i]%mod);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfz(1);
	ans=2ll*ans*fpow(n,mod-2)%mod*fpow(n-1,mod-2)%mod;
	printf("%d\n",ans);
	return 0;
}