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
struct SegT{
	ll lo[N<<2],hi[N<<2],val[N<<2],mn[N<<2];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l,hi[x]=r,val[x]=mn[x]=0;
		if(l==r)
		{
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		return;
	}
	void update1(ll x,ll l,ll r,ll v)
	{
		ll tl=lo[x],tr=hi[x],mid=(tl+tr)>>1,a=x<<1;
		if(l<=tl&&tr<=r)
		{
			if(mn[x]<v)
			{
				return;
			}
			if(tl==tr)
			{
				val[x]%=v;
				mn[x]%=v;
				return;
			}
			update1(a,l,r,v);
			update1(a|1,l,r,v);
			val[x]=val[a]+val[a|1];
			mn[x]=max(mn[a],mn[a|1]);
			return;
		}
		if(mid>=l)
		{
			update1(a,l,r,v);
		}
		if(mid<r)
		{
			update1(a|1,l,r,v);
		}
		val[x]=val[a]+val[a|1];
		mn[x]=max(mn[a],mn[a|1]);
		return;
	}
	void update2(ll x,ll l,ll v)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=l)
		{
			val[x]=mn[x]=v;
			return;
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			update2(a,l,v);
		}
		else
		{
			update2(a|1,l,v);
		}
		mn[x]=max(mn[a],mn[a|1]);
		val[x]=val[a]+val[a|1];
		return;
	}
	ll query(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			return val[x];
		}
		ll mid=(tl+tr)>>1,a=x<<1,ret=0;
		if(mid>=l)
		{
			ret+=query(a,l,r);
		}
		if(mid<r)
		{
			ret+=query(a|1,l,r);
		}
		return ret;
	}
}segt;
ll n,m,a[N];
int main(){
	ll i,tp,l,r,x;
	scanf("%lld%lld",&n,&m);
	segt.build(1,0,n-1);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		segt.update2(1,i,a[i]);
	}
	while(m--)
	{
		scanf("%lld",&tp);
		if(tp==1)
		{
			scanf("%lld%lld",&l,&r);
			l--,r--;
			printf("%lld\n",segt.query(1,l,r));
		}
		else if(tp==2)
		{
			scanf("%lld%lld%lld",&l,&r,&x);
			l--,r--;
			segt.update1(1,l,r,x);
		}
		else
		{
			scanf("%lld%lld",&l,&x);
			l--;
			segt.update2(1,l,x);
		}
	}
	return 0;
}