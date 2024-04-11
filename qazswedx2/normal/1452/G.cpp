#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int n,m,h[200005],t,vis[200005],dis[200005],q[200005],head,tail;
int sz[200005],rt,d[200005],a[200005],ans[200005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	sz[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
void dfs2(int u,int fa,int nsz)
{
	int mx=nsz-sz[u];
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		dfs2(v,u,nsz);
		mx=max(mx,sz[v]);
	}
	//printf("dfs2:u=%d,nsz=%d,mx=%d\n")
	if(mx<=nsz/2) rt=u;
}
void dfs3(int u,int fa,int dep,int nsz)
{
	int q=min(dis[u]-dep,nsz);
	if(q>=0) a[q]=max(a[q],dis[u]);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		dfs3(v,u,dep+1,nsz);
	}
}
void dfs4(int u,int fa,int dep)
{
	ans[u]=max(ans[u],a[dep]);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		dfs4(v,u,dep+1);
	}
}
void dfz(int u)
{
/*	printf("dfz:u=%d\n",u);
	for(int i=1;i<=n;i++)
		printf("%d ",vis[i]);
	printf("\n");*/
	dfs(u,0);
	dfs2(u,0,sz[u]);
//	printf("rt=%d\n",rt);
	for(int i=0;i<=sz[u];i++)
		a[i]=0;
	dfs3(rt,0,1,sz[u]);
	for(int i=sz[u]-1;i>=0;i--)
		a[i]=max(a[i],a[i+1]);
	dfs4(rt,0,0);
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
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	head=1,tail=0;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		vis[x]=1;
		dis[x]=0;
		q[++tail]=x;
	}
	while(head<=tail)
	{
		int u=q[head];
		head++;
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(vis[v]) continue;
			dis[v]=dis[u]+1;
			vis[v]=1;
			q[++tail]=v;
		}
	}
	memset(vis,0,sizeof(vis));
	dfz(1);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}