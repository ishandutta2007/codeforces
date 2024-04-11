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
#define N 1000010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
struct BIT{
	ll val[N];
	void init(ll mx)
	{
		ll i;
		for(i=0;i<mx;++i)
		{
			val[i]=0;
		}
		return;
	}
	void upd(ll x,ll v)
	{
		++x;
		while(x<N)
		{
			val[x]+=v;
			x+=x&(-x);
		}
		return;
	}
	ll qry(ll x)
	{
		++x;
		ll ret=0;
		while(x>0)
		{
			ret+=val[x];
			x-=x&(-x);
		}
		return ret;
	}
}bit;
struct SegT{
	ll lo[N<<2],hi[N<<2],val[N<<2],pd[N<<2];
	void build(ll x,ll l,ll r)
	{
		if(l>r)
		{
			return;
		}
		lo[x]=l,hi[x]=r,pd[x]=val[x]=0;
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
		val[a]+=pd[x];
		pd[a]+=pd[x];
		val[a|1]+=pd[x];
		pd[a|1]+=pd[x];
		pd[x]=0;
		return;
	}
	void update(ll x,ll l,ll r,ll v)
	{
		ll tl=lo[x],tr=hi[x];
		if(tl>r||tr<l)
		{
			return;
		}
		if(tl!=tr)
		{
			push_down(x);
		}
		if(l<=tl&&tr<=r)
		{
			val[x]+=v;
			pd[x]+=v;
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
	ll query()
	{
		return val[1];
	}
}segt;
ll n,m,a[N],b[N];
vector<pair<ll,ll> > vt;
vector<ll> apps[N];
void solve()
{
	ll i,j,ans=0;
	n=rint(),m=rint();
	vt.clear();
	vt.push_back(make_pair(-INF,0));
	bit.init(n+2);
	vector<ll> allv;
	for(i=0;i<n;++i)
	{
		apps[i].clear();
		a[i]=rint();
		allv.push_back(a[i]);
	}
	sort(allv.begin(),allv.end());
	allv.erase(unique(allv.begin(),allv.end()),allv.end());
	for(i=0;i<n;++i)
	{
		a[i]=lower_bound(allv.begin(),allv.end(),a[i])-allv.begin();
		vt.push_back(make_pair(a[i],i+1));
		apps[a[i]].push_back(i+1);
	}
	for(i=0;i<m;++i)
	{
		b[i]=rint();
	}
	sort(b,b+m);
	segt.build(1,0,n);
	sort(vt.begin(),vt.end());
	for(i=1;i<=n;++i)
	{
		segt.update(1,i,n,1);
	}
	vector<ll> anss;
	ll cnt=0;
	for(i=0;i<allv.size();++i)
	{
		//<v[i]
		anss.push_back(cnt+segt.query());
		//=v[i]
		for(j=0;j<apps[i].size();++j)
		{
			ans+=bit.qry(n)-bit.qry(apps[i][j]);
			bit.upd(apps[i][j],1);
			segt.update(1,apps[i][j],n,-1);
		}
		anss.push_back(cnt+segt.query());
		for(j=0;j<apps[i].size();++j)
		{
			segt.update(1,apps[i][j],n,-1);
			++cnt;
		}
	}
	anss.push_back(cnt+segt.query());
	for(i=0,j=0;i<m;++i)
	{
		while(j<allv.size()&&allv[j]<b[i])
		{
			++j;
		}
		if(j==allv.size())
		{
			ans+=anss[anss.size()-1];
		}
		else if(b[i]<allv[j])
		{
			ans+=anss[j<<1];
		}
		else
		{
			ans+=anss[(j<<1)|1];
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	ll T=rint();
	while(T--)
	{
		solve();
	}
	return 0;
}