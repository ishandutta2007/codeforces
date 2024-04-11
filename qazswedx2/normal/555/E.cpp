#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,vis,nxt;
}e[500005],e2[500005];
int n,m,q,h[200005],t=1,dfn[200005],low[200005],cnt,vis[200005],st[200005],tp;
int g[200005],gt,h2[200005],t2,c[200005][22],f[200005],f2[200005],d[200005];
int fl=1,ff[200005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void add2(int u,int v)
{
	e2[++t2].v=v;
	e2[t2].nxt=h2[u];
	h2[u]=t2;
}
void dfs(int u,int w)
{
	dfn[u]=low[u]=++cnt;
	st[++tp]=u;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(e[i].vis) continue;
		e[i].vis=e[i^1].vis=1;
		if(!dfn[v])
		{
			dfs(v,dfn[u]);
			low[u]=min(low[u],low[v]);
		}
		else if(!vis[v])
			low[u]=min(low[u],dfn[v]);
	}
//	printf("u=%d,dfn=%d,low=%d,w=%d\n",u,dfn[u],low[u],w);
	if(low[u]>w)
	{
		gt++;
		st[tp+1]=0;
		while(st[tp+1]!=u)
		{
			vis[st[tp]]=1;
			g[st[tp]]=gt;
			tp--;
		}
	}
}
void dfs2(int u,int fa,int dep)
{
	c[u][0]=fa;
	for(int i=1;i<=18;i++)
		c[u][i]=c[c[u][i-1]][i-1];
	d[u]=dep;
	for(int i=h2[u];i;i=e2[i].nxt)
	{
		int v=e2[i].v;
		if(v==fa) continue;
		dfs2(v,u,dep+1);
	}
}
int lca(int u,int v)
{
	if(d[u]<d[v]) swap(u,v);
	for(int i=18;i>=0;i--)
		if(d[c[u][i]]>=d[v])
			u=c[u][i];
	if(u==v) return u;
	for(int i=18;i>=0;i--)
		if(c[u][i]!=c[v][i])
			u=c[u][i],v=c[v][i];
	return c[u][0];
}
void dfs3(int u,int fa)
{
	for(int i=h2[u];i;i=e2[i].nxt)
	{
		int v=e2[i].v;
		if(v==fa) continue;
		dfs3(v,u);
		f[u]+=f[v],f2[u]+=f2[v];
	}
	if(f[u]&&f2[u]) fl=0;
	if(!fa&&f[u]+f2[u]) fl=0;
}
int find(int x)
{
	if(ff[x]==x) return x;
	return ff[x]=find(ff[x]);
}
void link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	ff[x]=y;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=gt;i++)
		ff[i]=i;
	for(int i=2;i<=t;i+=2)
	{
		int u=e[i].v,v=e[i^1].v;
		if(g[u]!=g[v])
		{
			add2(g[u],g[v]);
			add2(g[v],g[u]);
			link(g[u],g[v]);
		}
	}
	for(int i=1;i<=gt;i++)
		if(ff[i]==i)
			add2(0,i);
	dfs2(0,0,1);
	for(int i=1;i<=q;i++)
	{
		int u,v,l;
		scanf("%d%d",&u,&v);
		u=g[u],v=g[v];
	//	printf("u=%d,v=%d\n",u,v);
		if(u==v) continue;
		l=lca(u,v);
		f[u]++,f[l]--;
		f2[v]++,f2[l]--;
	}
	dfs3(1,0);
	if(fl) printf("Yes\n");
	else printf("No\n");
	return 0;
}