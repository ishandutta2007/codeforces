#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,g[105][105],a[105][105][105],vis[105],nwu,nwv,ans=1e9;
int b[15];
bool cmp(const int x,const int y)
{
	return g[nwu][x]+g[x][nwv]<g[nwu][y]+g[y][nwv];
}
int getans(int u,int v)
{
	for(int i=1;i<=a[u][v][0];i++)
	{
		int val=a[u][v][i];
		if(!vis[val])
			return g[u][val]+g[val][v];
	}
	return -1;
}
void dfs(int dep)
{
	if(dep==m/2)
	{
		for(int i=1;i<=m/2;i++)
			vis[b[i]]=1;
		int nw=0;
		for(int i=1;i<=m/2;i++)
		{
			int q=getans(b[i-1],b[i]);
			if(q==-1) 
			{
				for(int i=1;i<=m/2;i++)
					vis[b[i]]=0;
				return;
			}
			nw+=q;
		}
		/*if(b[1]==2&&b[2]==1&&b[3]==2)
		{
			printf("nw=%d,vis=%d,%d,%d,%d,%d\n",nw,vis[1],vis[2],vis[3],vis[4],vis[5]);
		}
		if(nw==5)
		{
			printf("%d,%d,%d,%d\n",b[1],b[2],b[3],b[4]);
		}*/
		ans=min(ans,nw);
		for(int i=1;i<=m/2;i++)
			vis[b[i]]=0;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		b[dep]=i;
		dfs(dep+1);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&g[i][j]);
	for(int u=1;u<=n;u++)
		for(int v=1;v<=n;v++)
		{
			int ct=0;
			for(int j=1;j<=n;j++)
				if(j!=u&&j!=v)
					a[u][v][++ct]=j;
			nwu=u,nwv=v;
			a[u][v][0]=ct;
			sort(a[u][v]+1,a[u][v]+ct+1,cmp);
		//	printf("u=%d,v=%d,%d,%d\n",u,v,g[u][a[u][v][1]]+g[a[u][v][1]][v],a[u][v][1]);
		}
	if(m<=8)
	{
		b[0]=b[m/2]=1;
		dfs(1);
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				for(int l=1;l<=n;l++)
				{
					vis[1]=vis[i]=vis[j]=vis[k]=vis[l]=1;
					int q1=getans(1,i),q2=getans(i,j),q3=getans(j,k),q4=getans(k,l),q5=getans(l,1);
					if(!(q1==-1||q2==-1||q3==-1||q4==-1||q5==-1))
						ans=min(ans,q1+q2+q3+q4+q5);
					vis[1]=vis[i]=vis[j]=vis[k]=vis[l]=0;
				}
	printf("%d",ans);
	return 0;
}