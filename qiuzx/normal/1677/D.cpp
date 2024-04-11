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
#define N 1000010
using namespace std;
ll n,k,a[N],p[N],lo[N],hi[N],dp[N];
int main(){
	ll T,i;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		for(i=1;i<=n;i++)
		{
			dp[i]=0;
			scanf("%lld",&a[i]);
			p[(i+k-1)%n+1]=a[i];
		}
		for(i=1;i<=n;i++)
		{
			if(p[i]==0)
			{
				lo[i]=0,hi[i]=k;
			}
			else if(p[i]==-1)
			{
				lo[i]=0,hi[i]=n-1;
			}
			else
			{
				lo[i]=hi[i]=p[i]+k;
			}
		}
		dp[1]=1;
		if(lo[1]>=1)
		{
			puts("0");
			continue;
		}
		for(i=2;i<=n;i++)
		{
			ll l=lo[i],r=min(hi[i],i-1);
			dp[i]=(dp[i-1]*max((ll)0,r-l+1))%mod;
		}
		if(i!=-1)
		{
			printf("%lld\n",dp[n]);
		}
	}
	return 0;
}