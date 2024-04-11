#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int n,m,h[100005],t,f[100005][55],g[100005][55],a[100005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		for(int j=0;j<2*m;j++)
			f[u][j]^=f[v][(j+1)%(2*m)];
	}
	for(int j=m;j<2*m;j++)
		f[u][j]^=a[u];
}
int tmp[55];
void dfs2(int u,int fa)
{
	for(int i=0;i<2*m;i++)
	{
		tmp[i]=g[u][i]^f[u][i];
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		for(int j=0;j<2*m;j++)
			g[v][j]=tmp[(j+1)%(2*m)]^f[v][(j+2)%(2*m)];
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,u);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++)
		if(f[i][0]^g[i][0]) printf("1 ");
		else printf("0 ");
	return 0;
}