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
struct SegT{
	ll val[N<<2],lo[N<<2],hi[N<<2];
	void build(ll x,ll l,ll r)
	{
		val[x]=0,lo[x]=l,hi[x]=r;
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
			val[x]+=v;
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
ll n,a[N],idl[N],idr[N],ans=0;
vector<ll> plc[N];
int main(){
	ll i,j;
	scanf("%lld",&n);
	memset(idl,63,sizeof(idl));
	memset(idr,0,sizeof(idr));
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		idl[a[i]]=min(idl[a[i]],i);
		idr[a[i]]=max(idr[a[i]],i);
		plc[a[i]].push_back(i);
	}
	segt.build(1,0,n-1);
	ll curl=0,curr=n-1;
	for(i=n;i>0;i--)
	{
		if(idl[i]<=idr[i])
		{
			for(j=0;j<plc[i].size();j++)
			{
				segt.update(1,plc[i][j],1);
			}
			if(idl[i]>curr)
			{
				curl=curr+1;
				curr=idr[i];
			}
			else if(idr[i]<curl)
			{
				curr=curl-1;
				curl=idl[i];
			}
			else
			{
				curl=idl[i];
				curr=idr[i];
			}
			ans+=segt.query(1,curl,curr);
		}
	}
	printf("%lld\n",ans);
	return 0;
}