#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,w,nxt;
}e[500005];
int n,m,h[100005],e2[100005][3],vis[100005],a[100005];
int g[305][305],t;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int dep)
{
	vis[u]=dep;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		dfs(v,dep^1);
	}
}
int main()
{
	memset(g,0x3f,sizeof(g));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		g[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v);
		add(v,u);
		e2[i][0]=u,e2[i][1]=v,e2[i][2]=w;
	}
	dfs(1,2);
	for(int i=1;i<=m;i++)
		if(vis[e2[i][0]]==vis[e2[i][1]])
		{
			printf("NO\n");
			return 0;
		}
	for(int i=1;i<=m;i++)
	{
		int u=e2[i][0],v=e2[i][1];
		if(e2[i][2]==0)
		{
			if(vis[u]==2)
			{
				g[u][v]=1;
				g[v][u]=0;
			}
			else
			{
				g[u][v]=0;
				g[v][u]=1;
			}
		}
		else
		{
			if(vis[u]==2)
				g[u][v]=1,g[v][u]=-1;
			else g[u][v]=g[v][u]=0;
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(g[i][j]>g[i][k]+g[k][j])
					g[i][j]=g[i][k]+g[k][j];
				if(g[i][j]<-1e8)
				{
					printf("NO\n");
					return 0;
				}
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(g[i][j]>g[i][k]+g[k][j])
				{
					printf("NO\n");
					return 0;
				}
	int ans=-1,id=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			int q=g[i][j]*2-(vis[i]==2)+(vis[j]==2);
		//	printf("i=%d,j=%d,q=%d\n",i,j,q);
			if(ans<q)
			{
				ans=q;
				id=i;
			}
		}
	int mn=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=g[id][i]*2+(vis[i]==2);
		mn=min(a[i],mn);
	//	printf("i=%d,a=%d\n",i,id);
	}
	printf("YES\n%d\n",ans);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]-mn);
	return 0;
}