#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=50;

ll n,a[4][4],to[4][4],dp[4][4][N];
ll dfs(int u,int v,int n)
{
	if (n==1) dp[u][v][n]=to[u][v];
	if (dp[u][v][n]) return dp[u][v][n];
	ll ans1,ans2,x=6-u-v;
	ans1=dfs(u,x,n-1)+dfs(x,v,n-1)+a[u][v];
	ans2=dfs(u,v,n-1)*2+dfs(v,u,n-1)+a[u][x]+a[x][v];
	return dp[u][v][n]=min(ans1,ans2);
}

int main()
{
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=3;i++)
	for (int j=1;j<=3;j++)
	{
		scanf("%lld",&a[i][j]);
		to[i][j]=a[i][j];
	}
	scanf("%d",&n);
	for (int k=1;k<=3;k++)
	for (int i=1;i<=3;i++)
	for (int j=1;j<=3;j++) to[i][j]=min(to[i][j],to[i][k]+to[k][j]);
	printf("%lld",dfs(1,3,n));

	return 0;
}