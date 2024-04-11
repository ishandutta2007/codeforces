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
#define N 500010
using namespace std;
vector<ll> allx,ally;
struct SegT{
	ll lo[N<<2],hi[N<<2],val[N<<2],num[N<<2];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l,hi[x]=r,val[x]=num[x]=0;
		if(l==r)
		{
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		return;
	}
	void update(ll x,ll l,ll r,ll v)
	{
		ll tl=lo[x],tr=hi[x],mid=(tl+tr)>>1,a=x<<1;
		if(l<=tl&&tr<=r)
		{
			num[x]+=v;
			val[x]=(num[x]==0)?(val[a]^val[a|1]):(ally[tr]^ally[tl-1]);
			return;
		}
		if(mid>=l)
		{
			update(a,l,r,v);
		}
		if(mid<r)
		{
			update(a|1,l,r,v);
		}
		val[x]=(num[x]==0)?(val[a]^val[a|1]):(ally[tr]^ally[tl-1]);
		return;
	}
}segt;
ll n,m,k,ans=0;
vector<pair<pair<ll,ll>,pair<ll,ll> > > allnd;
vector<pair<ll,ll> > upd[N],erz[N];
int main(){
	ll i,j,xa,xb,ya,yb;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=31;i>=0;i--)
	{
		if(k&(1<<i))
		{
			i++;
			break;
		}
	}
	k=(1<<i)-1;
	allx.push_back(0);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld%lld",&xa,&ya,&xb,&yb);
		xa--,ya--;
		allnd.push_back(make_pair(make_pair(xa,ya),make_pair(xb,yb)));
		allx.push_back(xa);
		allx.push_back(xb);
		ally.push_back(ya);
		ally.push_back(yb);
	}
	sort(allx.begin(),allx.end());
	allx.erase(unique(allx.begin(),allx.end()),allx.end());
	sort(ally.begin(),ally.end());
	ally.erase(unique(ally.begin(),ally.end()),ally.end());
	for(i=0;i<m;i++)
	{
		allnd[i].F.F=lower_bound(allx.begin(),allx.end(),allnd[i].F.F)-allx.begin();
		allnd[i].F.S=lower_bound(ally.begin(),ally.end(),allnd[i].F.S)-ally.begin();
		allnd[i].S.F=lower_bound(allx.begin(),allx.end(),allnd[i].S.F)-allx.begin();
		allnd[i].S.S=lower_bound(ally.begin(),ally.end(),allnd[i].S.S)-ally.begin();
		upd[allnd[i].F.F].push_back(make_pair(allnd[i].F.S,allnd[i].S.S));
		erz[allnd[i].S.F].push_back(make_pair(allnd[i].F.S,allnd[i].S.S));
	}
	segt.build(1,0,ally.size());
	for(i=0;i<allx.size();i++)
	{
		if(i)
		{
			ans^=(segt.val[1]&(allx[i]^allx[i-1]));
		}
		for(j=0;j<upd[i].size();j++)
		{
			segt.update(1,upd[i][j].F+1,upd[i][j].S,1);
		}
		for(j=0;j<erz[i].size();j++)
		{
			segt.update(1,erz[i][j].F+1,erz[i][j].S,-1);
		}
	}
	if(ans&k)
	{
		puts("Hamed");
	}
	else
	{
		puts("Malek");
	}
	return 0;
}