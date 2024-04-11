#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,g[605][605],dis[605][605],vis[605];
int main()
{
	memset(g,0x3f,sizeof(g));
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u][v]=w;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			g[i][(j+1)%n]=min(g[i][(j+1)%n],g[i][j]+1);
		for(int j=0;j<n;j++)
			g[i][(j+1)%n]=min(g[i][(j+1)%n],g[i][j]+1);
		/*for(int j=n-1;j>=0;j--)
			g[i][(j+n-1)%n]=min(g[i][(j+n-1)%n],g[i][j]+1);
		for(int j=n-1;j>=0;j--)
			g[i][(j+n-1)%n]=min(g[i][(j+n-1)%n],g[i][j]+1);*/
	}
	for(int i=0;i<n;i++)
	{
		dis[i][i]=0;
		memset(vis,0,sizeof(vis));
		for(int j=0;j<n;j++)
		{
			int mn=2e9,id=0;
			for(int k=0;k<n;k++)
				if(!vis[k]&&mn>dis[i][k])
				{
					mn=dis[i][k];
					id=k;
				}
			vis[id]=1;
			for(int k=0;k<n;k++)
				if(!vis[k])
				{
					int u=(k-dis[i][id]%n+n)%n;
					dis[i][k]=min(dis[i][k],dis[i][id]+g[id][u]);
				}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",dis[i][j]);
		printf("\n");
	}
	return 0;
}