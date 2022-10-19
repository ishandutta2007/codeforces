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
#define N 400010
using namespace std;
struct SegT{
	ll lo[N<<2],hi[N<<2],mn[N<<2],mx[N<<2];
	multiset<ll> allv[N<<2];
	bool isok[N<<2];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l,hi[x]=r,mn[x]=INF,mx[x]=-INF,isok[x]=true;
		allv[x].clear();
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
			if(v&1)
			{
				allv[x].insert(v);
				mn[x]=(*allv[x].begin());
			}
			else
			{
				allv[x].insert(-v);
				mx[x]=-(*allv[x].begin());
			}
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
		mn[x]=min(mn[a],mn[a|1]);
		mx[x]=max(mx[a],mx[a|1]);
		isok[x]=isok[a]&isok[a|1]&(mn[a]>mx[a|1]);
		return;
	}
	void recall(ll x,ll l,ll v)
	{
		ll tl=lo[x],tr=hi[x];
		if(l==tl&&tr==l)
		{
			if(v&1)
			{
				allv[x].erase(v);
				mn[x]=((allv[x].empty())?(INF):(*allv[x].begin()));
			}
			else
			{
				allv[x].erase(-v);
				mx[x]=((allv[x].empty())?(-INF):-(*allv[x].begin()));
			}
			return;
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			recall(a,l,v);
		}
		else
		{
			recall(a|1,l,v);
		}
		mn[x]=min(mn[a],mn[a|1]);
		mx[x]=max(mx[a],mx[a|1]);
		isok[x]=isok[a]&isok[a|1]&(mn[a]>mx[a|1]);
		return;
	}
}segt;
ll n,m,q;
map<pair<ll,ll>,ll> mp;
int main(){
	ll i,x,y;
	scanf("%lld%lld%lld",&n,&m,&q);
	segt.build(1,1,2*n);
	while(q--)
	{
		scanf("%lld%lld",&x,&y);
		if(mp.count(make_pair(x,y))&&mp[make_pair(x,y)]==1)
		{
			segt.recall(1,x,y);
			mp[make_pair(x,y)]=0;
		}
		else
		{
			segt.update(1,x,y);
			mp[make_pair(x,y)]=1;
		}
		puts(segt.isok[1]?"YES":"NO");
	}
	return 0;
}