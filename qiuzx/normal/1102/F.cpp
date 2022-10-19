//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 10010
using namespace std;
ll n,m,a[20][N],cost[20][20],dp[18][(1<<16)+10],ans=0;
ll rev_cost(ll x,ll y)
{
	ll i,ret=LINF;
	for(i=0;i+1<m;i++)
	{
		ret=min(ret,abs(a[x][i]-a[y][i+1]));
	}
	return ret;
}
int main(){
	ll i,j,k,mask;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cost[i][j]=LINF;
			for(k=0;k<m;k++)
			{
				cost[i][j]=min(cost[i][j],abs(a[i][k]-a[j][k]));
			}
		}
	}
	for(i=0;i<n;i++)
	{
		memset(dp,-63,sizeof(dp));
		dp[i][(1<<i)]=LINF;
		for(mask=(1<<i);mask<(1<<n);mask++)
		{
			for(j=0;j<n;j++)
			{
				if(mask&(1<<j))
				{
					for(k=0;k<n;k++)
					{
						if(!(mask&(1<<k)))
						{
							dp[k][mask|(1<<k)]=max(dp[k][mask|(1<<k)],min(dp[j][mask],cost[j][k]));
						}
					}
				}
			}
		}
		for(j=0;j<n;j++)
		{
			ans=max(ans,min(dp[j][(1<<n)-1],rev_cost(j,i)));
		}
	}
	printf("%lld\n",ans);
	return 0;
}