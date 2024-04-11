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
#define N 200010
using namespace std;
struct SegT{//segment addition and segment minimum value
	ll lo[N<<2],hi[N<<2],val[N<<2],pd[N<<2];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l,hi[x]=r,val[x]=pd[x]=0;
		if(l==r)
		{
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		return;
	}
	void push_down(ll x)
	{
		ll a=x<<1;
		val[a]+=pd[x],pd[a]+=pd[x];
		val[a|1]+=pd[x],pd[a|1]+=pd[x];
		pd[x]=0;
		return;
	}
	void update(ll x,ll l,ll r,ll v)
	{
		ll tl=lo[x],tr=hi[x];
		if(tl<tr)
		{
			push_down(x);
		}
		if(l<=tl&&tr<=r)
		{
			val[x]+=v;
			pd[x]+=v;
			if(tl<tr)
			{
				push_down(x);
			}
			return;
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			update(a,l,r,v);
		}
		if(mid<r)
		{
			update(a|1,l,r,v);
		}
		val[x]=min(val[a],val[a|1]);
		return;
	}
	ll query(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		if(tl<tr)
		{
			push_down(x);
		}
		if(l<=tl&&tr<=r)
		{
			return val[x];
		}
		ll mid=(tl+tr)>>1,a=x<<1,ret=LINF;
		if(mid>=l)
		{
			ret=min(ret,query(a,l,r));
		}
		if(mid<r)
		{
			ret=min(ret,query(a|1,l,r));
		}
		return ret;
	}
}segt1,segt2;
ll n,m,q,a[N],b[N];
vector<pair<ll,ll> > vt[N];
int main(){
	ll i,j,x,y,z;
	scanf("%lld%lld%lld",&n,&m,&q);
	for(i=0;i+1<n;i++)
	{
		scanf("%lld%lld",&a[i],&b[i+1]);
	}
	a[n-1]=b[n]=0;
	segt1.build(1,0,n-1);
	segt2.build(1,0,n-1);
	for(i=0;i<n;i++)
	{
		segt1.update(1,i,i,b[i]);
		segt2.update(1,i,i,a[i]);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		x--,y--;
		vt[x].push_back(make_pair(y,z));
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<vt[i].size();j++)
		{
			segt1.update(1,0,vt[i][j].F,vt[i][j].S);
		}
		segt2.update(1,i,i,segt1.query(1,0,n-1));
	}
	printf("%lld\n",segt2.query(1,0,n-1));
	while(q--)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		segt2.update(1,x,x,y-a[x]);
		a[x]=y;
		printf("%lld\n",segt2.query(1,0,n-1));
	}
	return 0;
}