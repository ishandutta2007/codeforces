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
#define N 510
using namespace std;
ll n,a[N],ans=LINF;
ll mindiv(ll x,ll y)//minimum s such that x/s=y
{
	ll l=(x+y)/(y+1),r=x/y;
	if(l<=r)
	{
		return l;
	}
	return LINF;
}
ll calc(ll h)
{
	ll i,ret=0;
	for(i=0;i<n;i++)
	{
		ret+=mindiv(a[i],h);
		if(ret>=LINF)
		{
			return ret;
		}
	}
	return ret;
}
int main(){
//	freopen("in.txt","r",stdin);
	ll i;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	ll cur=0;
	for(i=1;i*i<=a[0];i++)
	{
		cur=a[0]/i;
		ans=min(ans,calc(cur));
		if(cur-1>0)
		{
			ans=min(ans,calc(cur-1));
		}
	}
	for(i=cur-2;i>0;i--)
	{
		ans=min(ans,calc(i));
	}
	printf("%lld\n",ans);
	return 0;
}