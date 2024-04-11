/*
        Normie's Template v2.0
*/

// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;

// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>

// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)

//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"

//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))

//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320

//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>

//Quick power of 2.
#define pow2(x) (ll(1)<<x)

//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)

//Typedefs.
#define bi BigInt
typedef int ll;
typedef long double ld;
typedef short sh;
//---------END-------//
ll star[1000001];
struct seg
{
	ll val[4000401],lazy[4000401];
	ll n;
	void resetK(ll l, ll r, ll cur)
	{
		if (l==r)
		{
			lazy[cur]=0;
			val[cur]=star[l];
		}
		else
		{
			lazy[cur]=0;
			ll mid=(l+r)/2;
			resetK(l,mid,(cur<<1));
			resetK(mid+1,r,(cur<<1)+1);
			val[cur]=max(val[(cur<<1)],val[(cur<<1)+1]);
		}
	}
	void reset(ll nn)
	{
		n=nn;
		resetK(1,n,1);
	}
	void flusha(ll cur)
	{
	//	cout<<"flusha "<<cur<<endl;
	//	cout<<"before: "<<lazy[(cur<<1)]<<' '<<val[(cur<<1)]<<' '<<lazy[(cur<<1)+1]<<' '<<val[(cur<<1)+1]<<endl;
		lazy[(cur<<1)]+=lazy[cur];
		val[(cur<<1)]+=lazy[cur];
		lazy[(cur<<1)+1]+=lazy[cur];
		val[(cur<<1)+1]+=lazy[cur];
	//	cout<<"after: "<<lazy[(cur<<1)]<<' '<<val[(cur<<1)]<<' '<<lazy[(cur<<1)+1]<<' '<<val[(cur<<1)+1]<<endl;
		lazy[cur]=0;
	}
	void updateK(ll l, ll r, ll cur, ll tl, ll tr, ll d)
	{
		if ((tl>r)or(tr<l)) return;
		if ((tl<=l)and(tr>=r)) 
		{
	//		cout<<"update directly "<<cur<<' '<<d<<endl;
	//		cout<<"before: "<<val[cur]<<' '<<lazy[cur]<<endl;
			val[cur]+=d;
			lazy[cur]+=d;
	//		cout<<"after: "<<val[cur]<<' '<<lazy[cur]<<endl;
		}
		else
		{
			ll mid=(l+r)/2;
			flusha(cur);
			updateK(l,mid,(cur<<1),tl,tr,d);
			updateK(mid+1,r,(cur<<1)+1,tl,tr,d);
			val[cur]=max(val[(cur<<1)],val[(cur<<1)+1]);
		}
	}
	void update(ll l, ll r, ll d)
	{
		if (l>r) return;
		updateK(1,n,1,l,r,d);
	//	debug();
	}
	void debugK(ll l, ll r, ll cur)
	{
		cout<<"---------------------------------\n";
		cout<<"Now crawling node: "<<cur<<endl;
		cout<<"Covering range: ("<<l<<","<<r<<")"<<endl;
		cout<<"It's values: "<<"val = "<<val[cur]<<" lazy = "<<lazy[cur]<<endl;
		cout<<"---------------------------------\n";
		ll mid=(l+r)/2;
		if (l<r)
		{
		debugK(l,mid,(cur<<1));
		debugK(mid+1,r,(cur<<1)+1);
		}
	}
	void debug()
	{
		debugK(1,n,1);
	}
	ll getK(ll l, ll r, ll cur, ll tl, ll tr)
	{
		if ((tl>r)or(tr<l)) return -1;
		if ((tl<=l)and(tr>=r)) 
		{
			return val[cur];
		}
		else
		{
			ll mid=(l+r)/2;
			flusha(cur);
			ll aa=getK(l,mid,(cur<<1),tl,tr);
			ll bb=getK(mid+1,r,(cur<<1)+1,tl,tr);
			return max(aa,bb);
		}
	}
	ll get(ll l, ll r)
	{
		if (l>r) return -1;
		return getK(1,n,1,l,r);
	}
	ll bsK(ll l, ll r, ll cur, ll x)
	{
		if (l==r)
		{
			if (val[cur]<x) return l+1;
			else return l;
		}
		else
		{
			ll mid=(l+r)/2;
			flusha(cur);
			if (val[(cur<<1)]>=x) return bsK(l,mid,(cur<<1),x);
			else return bsK(mid+1,r,(cur<<1)+1,x);
		}
	}
	ll bs(ll x)
	{
		return bsK(1,n,1,x);
	}
};
seg stval,stres;
ll n,m,i,j,k,t,t1,u,v,a,b,l,r;
ll qd[100001];
ll arr[100001];
ll res[100001];
vector<pair<ll,char>> opsad[100002],opslr[100002];
void proc(int x)
{
	if (x<arr[i]) return;
	int u=stval.bs(x-arr[i]);
	int v=stval.bs(x-arr[i]+1);
	stres.update(u,v-1,1);
}
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for (j=1;j<=m;j++)
	{
		string s;
		cin>>s;
		if (s=="add")
		{
			cin>>l>>r>>qd[j];
			opsad[l].push_back({j,'a'});
			opsad[r+1].push_back({j,'d'});
		}
		else
		{
			cin>>l>>r;
			opslr[l-1].push_back({j,'l'});
			opslr[r].push_back({j,'r'});
		}
	}
	stval.reset(m);
	stres.reset(m);
	for (i=1;i<=n;i++)
	{
		for (auto g : opsad[i])
		{
			if (g.se=='a') stval.update(g.fi,m,qd[g.fi]);
			else stval.update(g.fi,m,-qd[g.fi]);
		}
		proc(4);
		proc(7);
		
		proc(44);
		proc(77);
		proc(74);
		proc(47);
		
		proc(444);
		proc(477);
		proc(474);
		proc(447);
		proc(744);
		proc(777);
		proc(774);
		proc(747);
		
		
		proc(4444);
		proc(4477);
		proc(4474);
		proc(4447);
		proc(4744);
		proc(4777);
		proc(4774);
		proc(4747);
		
		
		proc(7444);
		proc(7477);
		proc(7474);
		proc(7447);
		proc(7744);
		proc(7777);
		proc(7774);
		proc(7747);
		
		for (auto g : opslr[i])
		{
			u=stres.get(g.fi,g.fi);
			if (g.se=='l') res[g.fi]-=u;
			else res[g.fi]+=u;
		}
	//	stval.debug();
	//	stres.debug();
	}
	for (i=1;i<=m;i++) if (!qd[i]) cout<<res[i]<<endl;
}