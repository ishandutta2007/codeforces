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
ll n,a[N],b[N],dp[N][N*100];
int main(){
	ll T,i,j;
	scanf("%lld",&T);
	while(T--)
	{
		ll ans=0;
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			ans+=a[i]*a[i]*(n-1);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&b[i]);
			ans+=b[i]*b[i]*(n-1);
		}
		for(i=0;i<=n;i++)
		{
			memset(dp,63,sizeof(dp));
		}
		ll sum=0;
		dp[0][0]=0;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=100*i;j++)
			{
				if(dp[i-1][j]<=LINF)
				{
					dp[i][j+a[i]]=min(dp[i][j+a[i]],dp[i-1][j]+a[i]*j+b[i]*(sum-j));
					dp[i][j+b[i]]=min(dp[i][j+b[i]],dp[i-1][j]+b[i]*j+a[i]*(sum-j));
				}
			}
			sum+=a[i]+b[i];
		}
		sum=LINF;
		for(i=0;i<=100*n;i++)
		{
			sum=min(sum,dp[n][i]);
		}
		printf("%lld\n",sum*2+ans);
	}
	return 0;
}