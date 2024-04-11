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
#define N 100010
using namespace std;
ll sum[N];
struct SegT{
	ll lo[N*4],hi[N*4],mn[N*4],mx[N*4];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l;
		hi[x]=r;
		if(l==r)
		{
			mx[x]=mn[x]=sum[l];
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		mx[x]=max(mx[a],mx[a|1]);
		mn[x]=min(mn[a],mn[a|1]);
		return;
	}
	ll qry(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			return mx[x];
		}
		ll mid=(tl+tr)>>1,a=x<<1,ret;
		ret=-LINF;
		if(mid>=l)
		{
			ret=max(ret,qry(a,l,r));
		}
		if(mid<r)
		{
			ret=max(ret,qry(a|1,l,r));
		}
		return ret;
	}
	ll qry2(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			return mn[x];
		}
		ll mid=(tl+tr)>>1,a=x<<1,ret;
		ret=LINF;
		if(mid>=l)
		{
			ret=min(ret,qry2(a,l,r));
		}
		if(mid<r)
		{
			ret=min(ret,qry2(a|1,l,r));
		}
		return ret;
	}
}segt;
ll n,q,a[N],b[N];
int main(){
	ll i;
	scanf("%lld%lld",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
		sum[i]=sum[i-1]+a[i]-b[i];
	}
	segt.build(1,1,n);
	while(q--){
		ll l,r;
		scanf("%lld%lld",&l,&r);
		if(a[l]>b[l]||a[r]<b[r]||sum[r]-sum[l-1]!=0)
		{
			puts("-1");
			continue;
		}
		if(segt.qry(1,l,r)>sum[l-1])
		{
			puts("-1");
			continue;
		}
		printf("%lld\n",sum[l-1]-segt.qry2(1,l,r));
	}
	return 0;
}