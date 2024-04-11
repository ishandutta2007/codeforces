//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll dp[35][35][52],n,m,k;
ll dfs(ll x,ll y,ll z)
{
	if(dp[x][y][z]!=-1)
	{
		return dp[x][y][z];
	}
	if(z==0)
	{
		return dp[x][y][z]=0;
	}
	if(x*y==z)
	{
		return dp[x][y][z]=0;
	}
	dp[x][y][z]=LINF;
	if(x*y<z)
	{
		return dp[x][y][z];
	}
	ll i,j,l;
	for(l=0;l<=z;l++)
	{
		for(i=1;i<x;i++)
		{
			dp[x][y][z]=min(dp[x][y][z],dfs(i,y,l)+dfs(x-i,y,z-l)+y*y);
		}
		for(i=1;i<y;i++)
		{
			dp[x][y][z]=min(dp[x][y][z],dfs(x,i,l)+dfs(x,y-i,z-l)+x*x);
		}
	}
	return dp[x][y][z];
}
int main(){
	ll T,i,j,l;
	scanf("%lld",&T);
	memset(dp,-1,sizeof(dp));
	for(i=1;i<=30;i++)
	{
		for(j=1;j<=30;j++)
		{
			for(l=1;l<=50;l++)
			{
				dfs(i,j,l);
			}
		}
	}
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&m,&k);
		printf("%lld\n",dp[n][m][k]);
	}
	return 0;
}