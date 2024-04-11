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
ll n,q,v[N];
struct _data{
	ll tot,lft,rht,lo,hi;
};
struct SegT{
	_data val[N<<2];
	_data push_up(_data a1,_data a2)
	{
		ll l=a1.lo,r=a2.hi,mid=a1.hi;
		_data x;
		x.lo=l;
		x.hi=r;
		x.tot=a1.tot+a2.tot;
		x.lft=a1.lft;
		x.rht=a2.rht;
		if(v[mid]<=v[mid+1])
		{
			x.tot+=a1.rht*a2.lft;
			if(a1.lft==mid-l+1)
			{
				x.lft=a1.lft+a2.lft;
			}
			if(a2.rht==r-mid)
			{
				x.rht=a1.rht+a2.rht;
			}
		}
		return x;
	}
	void build(ll x,ll l,ll r)
	{
		if(l==r)
		{
			val[x].lo=l;
			val[x].hi=r;
			val[x].tot=val[x].lft=val[x].rht=1;
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		val[x]=push_up(val[a],val[a|1]);
		return;
	}
	void upd(ll x,ll l)
	{
		ll tl=val[x].lo,tr=val[x].hi;
		if(l==tl&&tr==l)
		{
			return;
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			upd(a,l);
		}
		else
		{
			upd(a|1,l);
		}
		val[x]=push_up(val[a],val[a|1]);
		return;
	}
	_data qry(ll x,ll l,ll r)
	{
		ll tl=val[x].lo,tr=val[x].hi;
		if(l<=tl&&tr<=r)
		{
			return val[x];
		}
		_data ret;
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			ret=qry(a,l,r);
		}
		if(mid<r)
		{
			if(mid>=l)
			{
				_data nxt=qry(a|1,l,r);
				ret=push_up(ret,nxt);
			}
			else
			{
				ret=qry(a|1,l,r);
			}
		}
		return ret;
	}
}segt;
int main(){
	ll i,tp,l,r;
	scanf("%lld%lld",&n,&q);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&v[i]);
	}
	segt.build(1,0,n-1);
	while(q--)
	{
		scanf("%lld%lld%lld",&tp,&l,&r);
		if(tp==1)
		{
			l--;
			v[l]=r;
			segt.upd(1,l);
		}
		else
		{
			l--;
			r--;
			printf("%lld\n",segt.qry(1,l,r).tot);
		}
	}
	return 0;
}