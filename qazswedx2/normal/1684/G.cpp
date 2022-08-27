#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[1000005],vis[1005],tans[1000005][2],tt;
int g[1005][1005],mat[1005];
void check(int x,int y)
{
	tt++;
	tans[tt][0]=x+y;
	tans[tt][1]=x+2*y;
}
int dfs(int x)
{
	for(int i=1;i<=n;i++)
		if(g[x][i]&&!vis[i])
		{
			vis[i]=1;
			if(!mat[i]||dfs(mat[i]))
			{
				mat[i]=x;
				return 1;
			}
		}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int mn=1e9;
	for(int i=1;i<=n;i++)
	{
		int u=m-2*a[i];
		if(u>=a[i]) continue;
		mn=min(mn,i);
		//int id=-1;
		for(int j=i-1;j>0;j--)
			if(!vis[j]&&u>=a[j]&&a[i]%a[j]==0)
			{
				g[i][j]=1;
			//	id=j;
			//	break;
			}
	/*	if(!id)
		{
			printf("-1\n");
			return 0;
		}
		vis[i]=vis[id]=1;
		check(a[id],a[i]);*/
	}
	for(int i=mn;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(!dfs(i))
		{
			printf("-1\n");
			return 0;
		}
	}
	memset(vis,0,sizeof(vis)); 
	for(int i=1;i<=n;i++)
		if(mat[i])
		{
			check(a[i],a[mat[i]]);
			vis[i]=vis[mat[i]]=1;
		}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			check(a[i],a[i]);
	printf("%d\n",tt);
	for(int i=1;i<=tt;i++)
		printf("%d %d\n",tans[i][0],tans[i][1]); 
	return 0;
}