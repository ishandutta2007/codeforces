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
#define N 200010
using namespace std;
ll n,k,a[N],sum[N];
int main(){
	ll T,i;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			sum[i+1]=sum[i]+a[i];
		}
		if(k>=n)
		{
			printf("%lld\n",sum[n]+(k-1+k-n)*n/2);
			continue;
		}
		ll ans=0;
		for(i=k;i<=n;i++)
		{
			ans=max(ans,sum[i]-sum[i-k]);
		}
		printf("%lld\n",ans+k*(k-1)/2);
	}
	return 0;
}