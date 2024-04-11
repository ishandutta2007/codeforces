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
#define N 250010
using namespace std;
struct SegT{
	ll lo[N<<2],hi[N<<2],mn[N<<2],mx[N<<2];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l,hi[x]=r,mn[x]=LINF,mx[x]=-LINF;
		if(l==r)
		{
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		return;
	}
	void update(ll x,ll l,ll v)
	{
		ll tl=lo[x],tr=hi[x];
		if(l==tl&&tr==l)
		{
			mn[x]=mx[x]=v;
			return;
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			update(a,l,v);
		}
		else
		{
			update(a|1,l,v);
		}
		mn[x]=min(mn[a],mn[a|1]),mx[x]=max(mx[a],mx[a|1]);
		return;
	}
	ll querymn(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			return mn[x];
		}
		ll mid=(tl+tr)>>1,a=x<<1,ret=LINF;
		if(mid>=l)
		{
			ret=min(ret,querymn(a,l,r));
		}
		if(mid<r)
		{
			ret=min(ret,querymn(a|1,l,r));
		}
		return ret;
	}
	ll querymx(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			return mx[x];
		}
		ll mid=(tl+tr)>>1,a=x<<1,ret=-LINF;
		if(mid>=l)
		{
			ret=max(ret,querymx(a,l,r));
		}
		if(mid<r)
		{
			ret=max(ret,querymx(a|1,l,r));
		}
		return ret;
	}
	ll getnxtmn(ll x,ll l,ll v)
	{
		ll tl=lo[x],tr=hi[x],a=x<<1;
		if(tr<l)
		{
			return LINF;
		}
		if(tl==tr)
		{
			return (mn[x]<=v)?tl:LINF;
		}
		if(tl>=l)
		{
			if(mn[a]<=v)
			{
				return getnxtmn(a,l,v);
			}
			return getnxtmn(a|1,l,v);
		}
		return min(getnxtmn(a,l,v),getnxtmn(a|1,l,v));
	}
	ll getnxtmx(ll x,ll l,ll v)
	{
		ll tl=lo[x],tr=hi[x],a=x<<1;
		if(tr<l)
		{
			return LINF;
		}
		if(tl==tr)
		{
			return (mx[x]>=v)?tl:LINF;
		}
		if(tl>=l)
		{
			if(mx[a]>=v)
			{
				return getnxtmx(a,l,v);
			}
			return getnxtmx(a|1,l,v);
		}
		return min(getnxtmx(a,l,v),getnxtmx(a|1,l,v));
	}
}segt;
ll n,a[N],id[N];
int main(){
	ll T,i;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		segt.build(1,0,n-1);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			a[i]--;
			segt.update(1,i,a[i]);
			id[a[i]]=i;
		}
		ll ans=0;
		for(i=0;i<n-1;)
		{
			ll nxt;
			if(a[i]<a[i+1])
			{
				nxt=min(n,segt.getnxtmn(1,i,a[i]-1));
				i=id[segt.querymx(1,i,nxt-1)];
			}
			else
			{
				nxt=min(n,segt.getnxtmx(1,i,a[i]+1));
				i=id[segt.querymn(1,i,nxt-1)];
			}
			ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}