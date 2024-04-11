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
int main(){
	ll T,n,z;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&z);
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			ll x;
			scanf("%lld",&x);
			ans=max(ans,x|z);
		}
		printf("%lld\n",ans);
	}
	return 0;
}