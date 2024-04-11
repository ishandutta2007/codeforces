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
vector<piii(int)> vec;
int sz[300001];
int szcnt[300001],maxx,pol=0,por=0,iter;
int n,m,i,j,k,t,t1,u,v,a,b,bsz;
int res[300001],arr[300001];
void movepo(int l, int r)
{
	int u;
	while(pol>l)
	{
		pol--;
		sz[arr[pol]]++;
		u=sz[arr[pol]];
		szcnt[u-1]--;
		szcnt[u]++;
		if (maxx<u) maxx=u;
		iter++;
	}
	while(por<r)
	{
		por++;
		sz[arr[por]]++;
		u=sz[arr[por]];
		szcnt[u-1]--;
		szcnt[u]++;
		if (maxx<u) maxx=u;
		iter++;
	}


	while(pol<l)
	{
		sz[arr[pol]]--;
		u=sz[arr[pol]];
		szcnt[u+1]--;
		szcnt[u]++;
		if ((maxx==u+1)and(szcnt[u+1]==0)) maxx=u;
		pol++;
		iter++;
	}
	while(por>r)
	{
		sz[arr[por]]--;
		u=sz[arr[por]];
		szcnt[u+1]--;
		szcnt[u]++;
		if ((maxx==u+1)and(szcnt[u+1]==0)) maxx=u;
		por--;
		iter++;
	}
}
int main()
{
	fio;
	cin>>n>>m;
	for (i=0;i<n;i++) cin>>arr[i];
	bsz=max(1,int(floor(sqrt(n))));
//	cout<<bsz<<endl;
	for (i=1;i<=m;i++)
	{
		cin>>u>>v;
		u--;
		v--;
		vec.push_back({i,{u,v}});
	}
	sort(vec.begin(),vec.end(),[](piii(int) a, piii(int) b){
		if (a.p2/bsz-b.p2/bsz) return (a.p2/bsz<b.p2/bsz);
		return (a.p3<b.p3);
	});
	sz[arr[0]]=1;
	szcnt[1]=1;
	maxx=1;
	for (auto g : vec)
	{
		movepo(g.p2,g.p3);
		if (maxx-(g.p3-g.p2+1-maxx)>=2) res[g.p1]=maxx-(g.p3-g.p2+1-maxx);
		else res[g.p1]=1;
	}
//	cout<<iter<<endl;
	for (i=1;i<=m;i++) cout<<res[i]<<endl;
}