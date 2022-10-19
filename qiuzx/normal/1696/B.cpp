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
ll n,a[N];
int main(){
	ll T,i,j;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		ll mx=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			mx=max(mx,a[i]);
		}
		if(mx==0)
		{
			puts("0");
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(a[i]!=0)
				{
					break;
				}
			}
			for(j=n-1;j>=0;j--)
			{
				if(a[j]!=0)
				{
					break;
				}
			}
			ll ans=1;
			for(;i<=j;i++)
			{
				if(a[i]==0)
				{
					ans=2;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}