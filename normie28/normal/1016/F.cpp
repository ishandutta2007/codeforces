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
struct road
{
	ll to,val;
};
vector<road>side[300010];
ll fa[300010],dep[300010],siz[300010],maxdep[300010];
bool used[300010];
void dfs(ll x)
{
	siz[x]=1;maxdep[x]=dep[x];
	for(ll i=0;i<side[x].size();i++)
	{
		ll to=side[x][i].to;
		ll val=side[x][i].val;
		if(to==fa[x])continue;
		dep[to]=dep[x]+val;
		fa[to]=x;
		dfs(to);
		siz[x]+=siz[to];
		maxdep[x]=max(maxdep[x],dep[to]);
	}
}
signed main()
{
	fio;
	ll n,m,a,b,c;
	cin>>n>>m;
	for(ll i=1;i<n;i++)
	{
		cin>>a>>b>>c;
		side[a].push_back((road){b,c});
		side[b].push_back((road){a,c});
	}
	fa[1]=1;dfs(1);
	ll now=n,maxx=-9999999999999999,ladep=-9999999999999,ladep2=-9999999999999,qa=9999999999999999,qb=999999999999999;
	while(1)
	{
		ll tofa,sizz=0;used[now]=1;
		maxx=max(ladep2,maxx);
		for(ll i=0;i<side[now].size();i++)
		{
			ll to=side[now][i].to;
			ll val=side[now][i].val;
			if(to==fa[now])
			{
				tofa=val;
				continue;
			}
			if(used[to])continue;
			maxx=max(maxdep[to]-dep[now]+ladep,maxx);
			sizz+=siz[to];
			ladep=max(ladep,maxdep[to]-dep[now]);
		}
		if(sizz>1)maxx=99999999999999999;
		ladep2=max(ladep,ladep2);
		ladep2-=tofa;
		ladep=max(0ll,ladep);
		ladep-=tofa;
		maxx=max(-qa-qb,maxx);
		qb=qa;qa=tofa;
		if(now==1)break;
		now=fa[now];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a;
		cout<<dep[n]+min(0ll,maxx+a)<<endl;
	}
}