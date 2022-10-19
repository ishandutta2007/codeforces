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
struct SegT{
	ll lo[8*N],hi[8*N],val[8*N];
	void build(ll x,ll l,ll r)
	{
		if(l>r)
		{
			return;
		}
		lo[x]=l;
		hi[x]=r;
		val[x]=0;
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
		if(tl>l||tr<l)
		{
			return;
		}
		if(l==tl&&tr==l)
		{
			val[x]=v;
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
		val[x]=max(val[a],val[a|1]);
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
		ll mid=(tl+tr)>>1,a=x<<1,ret=0;
		if(mid>=l)
		{
			ret=max(ret,query(a,l,r));
		}
		if(mid<r)
		{
			ret=max(ret,query(a|1,l,r));
		}
		return ret;
	}
}segt1,segt2;
ll n,m,hei[N];
set<pair<ll,ll> > trs1,trs2;
vector<pair<ll,ll> > bd;
int main(){
	ll i,tp,x,qq;
	scanf("%lld%lld",&n,&m);
	segt1.build(1,0,n-1);
	segt2.build(1,0,m+10);
	for(qq=1;qq<=m;qq++)
	{
		scanf("%lld%lld",&tp,&x);
		x--;
		if(tp==1)
		{
			scanf("%lld",&hei[x]);
			hei[x]+=m;
			hei[x]-=qq;
			trs1.insert(make_pair(x,hei[x]));
			trs2.insert(make_pair(hei[x],x));
			bd.clear();
			for(set<pair<ll,ll> >::iterator it=trs2.begin();it!=trs2.end();it++)
			{
				bd.push_back(*it);
				segt1.update(1,(*it).S,0);
				segt2.update(1,(*it).F,0);
				if((*it).F==hei[x])
				{
					break;
				}
			}
			reverse(bd.begin(),bd.end());
			for(i=0;i<bd.size();i++)
			{
				ll v=segt1.query(1,bd[i].S+1,n-1);
				segt1.update(1,bd[i].S,v+1);
				segt2.update(1,bd[i].F,v+1);
			}
		}
		else
		{
			bd.clear();
			set<pair<ll,ll> >::iterator it;
			for(it=trs1.begin();it!=trs1.end();it++)
			{
				segt1.update(1,(*it).F,0);
				segt2.update(1,(*it).S,0);
				if(bd.size()==x)
				{
					break;
				}
				bd.push_back(*it);
			}
			trs2.erase(trs2.lower_bound(make_pair((*it).S,(*it).F)));
			trs1.erase(it);
			reverse(bd.begin(),bd.end());
			for(i=0;i<bd.size();i++)
			{
				ll v=segt2.query(1,bd[i].S+1,m+10);
				segt1.update(1,bd[i].F,v+1);
				segt2.update(1,bd[i].S,v+1);
			}
		}
		printf("%lld\n",segt1.query(1,0,n-1));
	}
	return 0;
}