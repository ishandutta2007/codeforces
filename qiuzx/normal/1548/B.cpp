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
#define N 200010
using namespace std;
ll n,a[N],d[N];
struct SegT{
	ll lo[N*4],hi[N*4],val[N*4];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l;
		hi[x]=r;
		if(l==r)
		{
			val[x]=d[l];
			return;
		}
		ll mid=(l+r)>>1,nxt=x<<1;
		build(nxt,l,mid);
		build(nxt|1,mid+1,r);
		val[x]=__gcd(val[nxt],val[nxt|1]);
		return;
	}
	ll query(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		if(tl>r||tr<l)
		{
			return 0;
		}
		if(l<=tl&&tr<=r)
		{
			return val[x];
		}
		ll mid=(tl+tr)>>1,nxt=x<<1,ret=0;
		if(mid>=l)
		{
			ret=__gcd(ret,query(nxt,l,r));
		}
		if(mid<r)
		{
			ret=__gcd(ret,query(nxt|1,l,r));
		}
		return ret;
	}
}segt;
void solve()
{
	ll i,j,ans=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(n==1)
	{
		puts("1");
		return;
	}
	for(i=0;i+1<n;i++)
	{
		d[i]=abs(a[i+1]-a[i]);
	}
	segt.build(1,0,n-2);
	for(i=0,j=0;i<n-1;i++)
	{
		while(j<n-1&&segt.query(1,i,j)>1)
		{
			j++;
		}
		ans=max(ans,j-i);
		if(j==i)
		{
			j++;
		}
	}
	printf("%lld\n",ans+1);
	return;
}
int main(){
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		solve();
	}
	return 0;
}