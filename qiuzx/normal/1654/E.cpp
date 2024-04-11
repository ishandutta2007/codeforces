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
#define ll int
#define N 200010
using namespace std;
ll n,a[N],ans=0,cnt[50000010];
ll solve1(ll x)
{
	ll i,res=0;
	for(i=0;i<n;++i)
	{
		++cnt[a[i]-x*i+25000000];
		res=max(res,cnt[a[i]-x*i+25000000]);
	}
	for(i=0;i<n;++i)
	{
		--cnt[a[i]-x*i+25000000];
	}
	return res;
}
ll solve2(ll l)
{
	ll res=0,i;
	for(i=l+1;i<=l+450&&i<n;++i)
	{
		if(abs(a[i]-a[l])%(i-l)==0)
		{
			++cnt[(a[i]-a[l])/(i-l)+100000];
			res=max(res,cnt[(a[i]-a[l])/(i-l)+100000]);
		}
	}
	for(i=l+1;i<=l+450&&i<n;++i)
	{
		if(abs(a[i]-a[l])%(i-l)==0)
		{
			--cnt[(a[i]-a[l])/(i-l)+100000];
		}
	}
	return res+1;
}
int main(){
	ll i;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	for(i=-225;i<=225;++i)
	{
		ans=max(ans,solve1(i));
	}
	for(i=0;i<n;++i)
	{
		ans=max(ans,solve2(i));
	}
	printf("%lld\n",n-ans);
	return 0;
}