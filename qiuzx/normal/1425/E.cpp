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
ll n,k,a[N],d[N],sum=0,ans=0,mn=LINF;
int main(){
	ll i;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&d[i]);
	}
	if(k%2==0)
	{
		for(i=n-1;i>=0;i--)
		{
			sum+=a[i];
			ans=max(ans,sum-d[i]);
		}
	}
	if(k==0)
	{
		printf("%lld\n",ans);
		return 0;
	}
	sum=0;
	for(i=0;i<n-1;i++)
	{
		sum+=a[i];
	}
	for(i=0;i<n-1;i++)
	{
		mn=min(mn,d[i]);
	}
	if(k!=1)
	{
		ans=max(ans,sum+a[n-1]-mn);
	}
	ans=max(ans,sum-mn);
	mn=d[0];
	for(i=0;i<n-1;i++)
	{
		mn=min(mn,d[i]);
		ans=max(ans,max((ll)0,sum-mn)+max((ll)0,a[n-1]-d[i+1]));
	}
	mn=LINF;
	sum=0;
	for(i=n-1;i>=0;i--)
	{
		mn=min(mn,a[i]);
		sum+=a[i];
		ans=max(ans,sum-mn-d[i]);
		if(i)
		{
			ans=max(ans,sum-d[i]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}