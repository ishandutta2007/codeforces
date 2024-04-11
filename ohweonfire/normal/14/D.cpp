#include <bits/stdc++.h>
using namespace std;
const int maxn=205;
bool adj[maxn][maxn];
int dep[maxn];
int n;
int dfs(int x,int d,int f)
{
	dep[x]=d;
	int ans=x;
	for(int i=1;i<=n;i++)
		if(adj[x][i]&&i!=f)
		{
			int t=dfs(i,d+1,x);
			if(dep[ans]<dep[t])ans=t;
		}
	return ans;
}
int f(int x)
{
	int t=dfs(x,0,0);
	return dep[dfs(t,0,0)];
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		adj[x][y]=adj[y][x]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(adj[i][j]==false)continue;
			adj[i][j]=adj[j][i]=false;
			ans=max(ans,f(i)*f(j));
			adj[i][j]=adj[j][i]=true;
		}
	printf("%d\n",ans);
}