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
ll n,a[N],cursuf,curpre;
int main(){
	ll T,i;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		bool ok=false;
		ll ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(i>0&&i<n-1&&(a[i]%2==0||a[i]>=2))
			{
				ok=true;
			}
			if(i>0&&i+1<n)
			{
				ans+=(a[i]+1)>>1;
			}
		}
		if((!ok)||(n==3&&(a[1]&1)))
		{
			puts("-1");
			continue;
		}
		printf("%lld\n",ans);
	}
	return 0;
}