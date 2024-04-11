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
ll n,k,s[N];
vector<ll> qry[N],erz[N];
struct SegT{
	ll lo[N<<3],hi[N<<3],val[N<<3],pd[N<<3];
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
		if(pd[x]==0)
		{
			return;
		}
		val[a]=hi[a]-lo[a]+1-val[a];
		val[a|1]=hi[a|1]-lo[a|1]+1-val[a|1];
		pd[a]^=1;
		pd[a|1]^=1;
		pd[x]=0;
		return;
	}
	void update(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		push_down(x);
		if(l<=tl&&tr<=r)
		{
			pd[x]^=1;
			val[x]=tr-tl+1-val[x];
			push_down(x);
			return;
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			update(a,l,r);
		}
		if(mid<r)
		{
			update(a|1,l,r);
		}
		val[x]=val[a]+val[a|1];
		return;
	}
	ll query(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		push_down(x);
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
ll deg[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,j,l,r;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	sort(s,s+n);
	for(i=0;i<k;i++)
	{
		cin>>l>>r;
		l=lower_bound(s,s+n,l)-s;
		r=upper_bound(s,s+n,r)-s-1;
		if(l<=r)
		{
			qry[l].push_back(r);
			erz[r].push_back(l);
		}
	}
	segt.build(1,0,n-1);
	for(i=0;i<n;i++)
	{
		for(j=0;j<qry[i].size();j++)
		{
			segt.update(1,i,qry[i][j]);
		}
		deg[i]=i-segt.query(1,0,i);
		for(j=0;j<erz[i].size();j++)
		{
			segt.update(1,erz[i][j],i);
		}
	}
	segt.build(1,0,n-1);
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<erz[i].size();j++)
		{
			segt.update(1,erz[i][j],i);
		}
		deg[i]+=segt.query(1,i,n-1);
		for(j=0;j<qry[i].size();j++)
		{
			segt.update(1,i,qry[i][j]);
		}
	}
	ll ans=n*(n-1)*(n-2)/6;
	for(i=0;i<n;i++)
	{
		ans-=deg[i]*(deg[i]-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}