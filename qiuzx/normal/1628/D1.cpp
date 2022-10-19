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
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 2010
using namespace std;
ll n,m,k,dp[N][N],inv2=(mod+1)>>1;
ll dfs(ll x,ll y)
{
	if(dp[x][y]!=-1)
	{
		return dp[x][y];
	}
	if(x==n)
	{
		return dp[x][y]=((y>=m)?0:LINF);
	}
	ll c1=dfs(x+1,y+1),c2=dfs(x+1,y);
	if(c1==LINF&&c2==LINF)
	{
		dp[x][y]=LINF;
	}
	else if(c1==LINF)
	{
		dp[x][y]=(c2+k)%mod;
	}
	else if(c2==LINF)
	{
		dp[x][y]=(c1+k)%mod;
	}
	else
	{
		dp[x][y]=((c1+c2)*inv2)%mod;
	}
	return dp[x][y];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T,i,j;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<N;j++)
			{
				dp[i][j]=-1;
			}
		}
		cout<<dfs(0,0)<<endl;
	}
	return 0;
}