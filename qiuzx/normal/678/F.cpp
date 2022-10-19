//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 2000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 300010
using namespace std;
struct SegT{
	ll lo[N<<2],hi[N<<2],cur[N<<2];
	vector<pair<ll,ll> > nd[N<<2];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l,hi[x]=r,cur[x]=0;
		nd[x].clear();
		if(l==r)
		{
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		return;
	}
	void update(ll x,ll l,ll r,pair<ll,ll> v)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			while(nd[x].size()>1)
			{
				pair<ll,ll> s1=nd[x].back();
				nd[x].pop_back();
				pair<ll,ll> s2=nd[x].back();
				if((s1.S-s2.S)*(v.F-s1.F)<=(v.S-s1.S)*(s1.F-s2.F))
				{
					nd[x].push_back(s1);
					break;
				}
			}
			nd[x].push_back(v);
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
		return;
	}
	ll query(ll x,ll l,ll v)
	{
		ll tl=lo[x],tr=hi[x];
		while(cur[x]+1<nd[x].size())
		{
			if((nd[x][cur[x]+1].S-nd[x][cur[x]].S)>=v*(nd[x][cur[x]+1].F-nd[x][cur[x]].F))
			{
				break;
			}
			cur[x]++;
		}
		ll res=(cur[x]<nd[x].size())?(v*nd[x][cur[x]].F-nd[x][cur[x]].S):-LINF;
		if(l<=tl&&tr<=l)
		{
			return res;
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			res=max(res,query(a,l,v));
		}
		else
		{
			res=max(res,query(a|1,l,v));
		}
		return res;
	}
}segt;
ll n,lst[N],ans[N],dx[N],dy[N],tp[N];
vector<pair<ll,ll> > qry;
bool cmp(ll x,ll y)
{
	return dx[x]<dx[y];
}
int main(){
	ll i,x;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&tp[i]);
		lst[i]=n;
		if(tp[i]==1)
		{
			scanf("%lld%lld",&dx[i],&dy[i]);
		}
		else if(tp[i]==2)
		{
			scanf("%lld",&x);
			x--;
			lst[x]=i-1;
		}
		else
		{
			scanf("%lld",&x);
			qry.push_back(make_pair(x,i));
		}
	}
	segt.build(1,0,n);
	vector<ll> vv;
	for(i=0;i<n;i++)
	{
		if(tp[i]==1)
		{
			vv.push_back(i);
		}
	}
	sort(vv.begin(),vv.end(),cmp);
	for(i=0;i<vv.size();i++)
	{
		segt.update(1,vv[i],lst[vv[i]],make_pair(dx[vv[i]],-dy[vv[i]]));
	}
	sort(qry.begin(),qry.end());
	for(i=0;i<qry.size();i++)
	{
		ans[qry[i].S]=segt.query(1,qry[i].S,qry[i].F);
	}
	for(i=0;i<n;i++)
	{
		if(tp[i]==3)
		{
			if(ans[i]<=-LINF)
			{
				puts("EMPTY SET");
			}
			else
			{
				printf("%lld\n",ans[i]);
			}
		}
	}
	return 0;
}