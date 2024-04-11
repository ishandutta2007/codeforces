#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int n,m,h[100005],t,d[100005],c[100005][22],size[100005],dfn[100005],cnt,fl;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int dep)
{
	d[u]=dep;
	size[u]=1;
	dfn[u]=++cnt;
	c[u][0]=fa;
	for(int i=1;i<=18;i++)
		c[u][i]=c[c[u][i-1]][i-1];
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
		size[u]+=size[v];
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
int getl(int u,int v)
{
	return d[u]+d[v]-2*d[lca(u,v)];
}
void check(int x,int y)
{
	if(x<=y&&(y-x)%2==0) fl=1;
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
		int u,v,x,y,k;
		scanf("%d%d%d%d%d",&x,&y,&u,&v,&k);
		fl=0;
		check(getl(u,v),k);
		check(getl(u,x)+getl(v,y)+1,k);
		check(getl(u,y)+getl(v,x)+1,k);
		if(fl) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}