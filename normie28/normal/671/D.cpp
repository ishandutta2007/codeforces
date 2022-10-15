/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
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
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
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

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
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
typedef long long ll;
typedef long double ld;
typedef short sh;

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//


ll star[1000001];
struct seg
{
	ll val[4000401],lazy[4000401];
	vector<piii(ll)> nodes;
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
			val[cur]=min(val[(cur<<1)],val[(cur<<1)+1]);
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
			val[cur]=min(val[(cur<<1)],val[(cur<<1)+1]);
		}
	}
	void update(ll l, ll r, ll d)
	{
        
  //      cout<<"update "<<l<<' '<<r<<' '<<d<<endl;
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
		if ((tl>r)or(tr<l)) return 9e18;
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
			return min(aa,bb);
		}
	}
	ll get(ll l, ll r)
	{
   //     cout<<"get "<<l<<' '<<r<<endl;
		if (l>r) return 9e18;
		return getK(1,n,1,l,r);
	}
};
seg st;



ll n,m,i,j,k,t,t1,u,v,a,b;
ll dp[300001];
vector<ll> gt[300001],down[300001];
vector<pii(ll)> roads[300001];
ll l[300001],r[300001];
multiset<ll> cur[300001];
void prep(int x, int p)
{
    t++;
    l[x]=t;
    for (auto g : gt[x]) if (g!=p)
    {
        down[x].push_back(g);
        prep(g,x);
    }
    r[x]=t;
}
void calc(int x)
{
  //  cout<<"calc "<<x<<endl;
    for (auto g : roads[x])
    {
    //    cout<<"add "<<x<<' '<<g.fi<<' '<<g.se<<endl;
        if (cur[l[g.fi]].size())
        {
            st.update(l[g.fi],l[g.fi],1000000000000000000-(*(cur[l[g.fi]].begin())));
        }
        cur[l[g.fi]].insert(g.se);
    //    for (auto gg : cur[l[g.fi]]) cout<<gg<<' '; cout<<endl;
   //     cout<<(*(cur[l[g.fi]].begin()))<<endl;
            st.update(l[g.fi],l[g.fi],-1000000000000000000+(*(cur[l[g.fi]].begin())));
    }
    for (auto g : down[x]) calc(g);
    if (x==1)
    {
        ll u=0;
        for (auto g : down[x]) u+=dp[g];
        cout<<u;
        exit(0);
    }
    else
    {
    for (auto g : roads[x])
    {
    //    cout<<"del "<<x<<' '<<g.fi<<' '<<g.se<<endl;
        st.update(l[g.fi],l[g.fi],1000000000000000000-(*(cur[l[g.fi]].begin())));
        cur[l[g.fi]].erase(cur[l[g.fi]].lower_bound(g.se));
        if (cur[l[g.fi]].size())
        {
            st.update(l[g.fi],l[g.fi],-1000000000000000000+(*(cur[l[g.fi]].begin())));
        }
    }
    for (auto g : down[x])
    {
        st.update(l[x],r[x],dp[g]);
        st.update(l[g],r[g],-dp[g]);
    }
    ll u=st.get(l[x],r[x]);
    if (u>=0)
    {
        cout<<-1;
        exit(0);
    }
    else dp[x]=u+1000000000000000000;
   // cout<<x<<' '<<dp[x]<<endl;
    }
    
}
int main()
{
	fio;
    cin>>n;
    cin>>m;
    st.reset(n);
    for (i=1;i<n;i++)
    {
        cin>>u>>v;
        gt[u].push_back(v);
        gt[v].push_back(u);
    }
    prep(1,-1);
    for (i=1;i<=m;i++)
    {
        cin>>u>>v>>a;
        roads[v].push_back({u,a});
    }
    calc(1);
}