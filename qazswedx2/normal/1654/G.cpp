#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[2000005];
int n,p[500005],dis[500005],h[500005],t=1,f[200005][705],b[500005],bt;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs1(int u,int fa)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs1(v,u);
		if(dis[u]<dis[v]) continue;
		int c=1;
		if(dis[u]>dis[v]) c=-1;
		for(int j=1;j<=bt;j++)
			f[u][j]=min(f[u][j],max(f[v][j]+c,0));
	}
}
void dfs2(int u,int fa)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		if(dis[u]<=dis[v])
		{
			int c=1;
			if(dis[u]<dis[v]) c=-1;
			for(int j=1;j<=bt;j++)
				f[v][j]=min(f[v][j],max(f[u][j]+c,0));
		}
		dfs2(v,u);
	}
}
int q[500005],head,tail,vis[500005];
int main()
{
	memset(f,0x3f,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		if(p[i]) q[++tail]=i,vis[i]=1;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u); 
	}
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(vis[v]) continue;
			vis[v]=1;
			dis[v]=dis[u]+1;
			q[++tail]=v;
		}
	}
	for(int i=2;i<=t;i+=2)
	{
		int u=e[i].v,v=e[i^1].v;
	//	printf("i=%d,u=%d,v=%d,dis=%d,%d\n",i,u,v,dis[u],dis[v]);
		if(dis[u]==dis[v])
		{
			b[++bt]=dis[u];
		}
	}
	sort(b+1,b+bt+1);
	bt=unique(b+1,b+bt+1)-b-1;
	for(int i=2;i<=t;i+=2)
	{
		int u=e[i].v,v=e[i^1].v;
		if(dis[u]==dis[v])
		{
			int q=lower_bound(b+1,b+bt+1,dis[u])-b;
			f[u][q]=1;
			f[v][q]=1;
		}
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++)
	{
		int ans=dis[i];
		for(int j=1;j<=bt;j++)
		{
		//	printf("i=%d,j=%d,f=%d\n",i,j,f[i][j]);
			if(f[i][j]==0)
			{
				ans=dis[i]+(dis[i]-b[j]);
				break;
			}
		}
		printf("%d ",ans);
	}
	printf("\n");
	return 0;
}