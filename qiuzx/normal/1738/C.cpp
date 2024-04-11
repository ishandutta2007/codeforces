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
#define N 110
using namespace std;
ll dp[N][N][2][2];
ll dfs(ll x,ll y,ll c,ll t)
{
	if(dp[x][y][c][t]>=0)
	{
		return dp[x][y][c][t];
	}
	if(x==0&&y==0)
	{
		return dp[x][y][c][t]=c^1;
	}
	if(t==0)
	{
		dp[x][y][c][t]=0;
		if(x>0)
		{
			dp[x][y][c][t]|=dfs(x-1,y,c,t^1);
		}
		if(y>0)
		{
			dp[x][y][c][t]|=dfs(x,y-1,c^1,t^1);
		}
	}
	else
	{
		dp[x][y][c][t]=1;
		if(x>0)
		{
			dp[x][y][c][t]&=dfs(x-1,y,c,t^1);
		}
		if(y>0)
		{
			dp[x][y][c][t]&=dfs(x,y-1,c,t^1);
		}
	}
	return dp[x][y][c][t];
}
int main(){
	ll T,i;
	memset(dp,-1,sizeof(dp));
	scanf("%lld",&T);
	while(T--)
	{
		ll n,c0=0,c1=0;
		scanf("%lld",&n);
		while(n--)
		{
			ll x;
			scanf("%lld",&x);
			if(x%2==0)
			{
				c0++;
			}
			else
			{
				c1++;
			}
		}
		puts(dfs(c0,c1,0,0)?"Alice":"Bob");
	}
	return 0;
}