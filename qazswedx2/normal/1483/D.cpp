#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,q,g[1005][1005],a[1005][1005],e[1000005][3];
int main()
{
	memset(g,0x3f,sizeof(g));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u][v]=g[v][u]=w;
		e[i][0]=u,e[i][1]=v,e[i][2]=w;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=max(a[u][v],w);
		a[v][u]=max(a[v][u],w);
	}
	for(int i=1;i<=n;i++)
		g[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)	
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
			{
				a[i][k]=max(a[i][k],a[i][j]-g[j][k]);
				a[k][j]=max(a[k][j],a[i][j]-g[i][k]);
			}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}*/
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int u=e[i][0],v=e[i][1],w=e[i][2];
		for(int j=1;j<=n;j++)
			if(a[u][j]>=g[v][j]+w)
			{
				ans++;
				break;
			}
	}
	printf("%d\n",ans);
	return 0;
}