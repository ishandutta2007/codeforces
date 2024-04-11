#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
vector<int> g[maxn];
int n,dp[maxn][2],m;
void dfs(int x)
{
	if(g[x].empty())
	{
		m++;
		dp[x][0]=dp[x][1]=1;
		return;
	}
	dp[x][0]=n;
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];
		dfs(y);
		dp[x][0]=min(dp[x][0],dp[y][1]);
		dp[x][1]+=dp[y][0];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
	}
	dfs(1);
	printf("%d %d\n",m-dp[1][0]+1,dp[1][1]);
}