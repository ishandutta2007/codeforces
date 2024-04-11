#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int n,h[100005],t,sz[100005];
double f[105][105],g[105][105],fr[105],infr[105],tmp[105];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
double C(int x,int y)
{
	return fr[x]*infr[y]*infr[x-y];
}
void dfs(int u,int fa)
{
	sz[u]=0;
	f[u][0]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		memcpy(tmp,f[u],sizeof(tmp));
		memset(f[u],0,sizeof(f[u]));
		for(int j=0;j<=sz[u];j++)
			for(int k=0;k<=sz[v];k++)
			{
				f[u][j+k]+=tmp[j]*g[v][k]*C(j+k,j)*C(sz[u]+sz[v]-j-k,sz[u]-j);
		//		printf("i=%d,j=%d,k=%d,%f,%f,%f,%f\n",i,j,k,tmp[j],g[v][k],C(j+k,j),C(sz[u]+sz[v]-j-k,sz[u]-j));
			}
		sz[u]+=sz[v];
	}
	sz[u]++;
	double sum=0;
	for(int i=0;i<=sz[u];i++)
	{
		g[u][i]=sum/2+f[u][i]*(sz[u]-i);
		sum+=f[u][i];
	}
/*	printf("u=%d,sz=%d\n",u,sz[u]);
	for(int i=0;i<=sz[u];i++)
		printf("%f ",f[u][i]);
	printf("\n");
	for(int i=0;i<=sz[u];i++)
		printf("%f ",g[u][i]);
	printf("\n");*/
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
	fr[0]=infr[0]=1;
	for(int i=1;i<=2*n;i++)
	{
		fr[i]=fr[i-1]*i;
		infr[i]=1/fr[i];
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,0);
		double ans=f[i][n-1]*infr[n-1];
		printf("%.10f\n",ans);
	}
	return 0;
}