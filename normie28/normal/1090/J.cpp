#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.5
	Changes:
    Added warning against using pragmas on USACO.
*/
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul or USACO.)
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0)
#define nfio cin.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
// template<typename T>
// __attribute__((always_inline)) void chkmin(T& a, const T& b) {
//     a=(a<b)?a:b;
// }

// template<typename T>
// __attribute__((always_inline)) void chkmax(T& a, const T& b) {
//     a=(a>b)?a:b;
// }
 
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
#endif

struct dsu
{
	int n,par[300100],h[300100],sz[300100];
	dsu (int n=0)
	{
		for (int i=0;i<n;i++)
		{
			par[i]=i;
			sz[i]=1;
			h[i]=1;
		}
		this->n=n;
	}
	
	void reset (int n)
	{
		for (int i=0;i<n;i++)
		{
			par[i]=i;
			sz[i]=1;
			h[i]=1;
		}
		this->n=n;
	}
	int get_par(int x)
	{
		if (par[par[x]]==par[x]) return par[x];
		else return par[x]=get_par(par[x]);
	}
	int check_same(int a, int b)
	{
		return (get_par(a)==get_par(b));
	}
	int add_edge(int a, int b)
	{
		int ha=get_par(a),hb=get_par(b);
		if (ha!=hb)
		{
			if (h[ha]<h[hb])
			{
				par[ha]=hb;
				sz[hb]=min(sz[hb],sz[ha]);
				return hb;
			}
			else
			if (h[ha]>h[hb])
			{
				par[hb]=ha;
				sz[ha]=min(sz[hb],sz[ha]);
				return ha;
			}
			else
			{
				par[hb]=ha;
				sz[ha]=min(sz[hb],sz[ha]);
				h[ha]++;
				return ha;
			}
			return 1;
		}
		else return 0;
	}
};
dsu gr;
vector<int> vec;
vector<pii(int)> ev[200100];
int n,n1,n2,m,i,j,k,t,t1,u,v,a,b;
string s1,s2,s;
string sa,sb;
int z[200100];
int ord[200100];
int lcp(int a, int b) {
	if (a>b) swap(a,b);
	if (a+n2<=b) {
		if (z[a+n2+1]<n2) return a+z[a+n2+1];
		else return a+n2;
	}
	else {
		if (z[a+n2+1]<b-a) return a+z[a+n2+1];
		else if (z[b-a]<a+n2-b) return b+z[b-a];
		else return a+n2;
	}
}
ll res;
int main()
{
	fio;
	cin>>s1>>s2;
	n1=s1.length();	
	n2=s2.length();
	s=s2+"#"+s1;
	n=n1+n2+1;
	int l,r;
	l=r=0;
	for (i=0;i<n;i++) {
		if (i==0) z[i]=0;
		else {
			if (r>=i) z[i]=min(z[i-l],r-i+1);
			while(i+z[i]<n && s[i+z[i]]==s[z[i]]) z[i]++;
			if (i+z[i]>r) {
				l=i;
				r=i+z[i]-1;
			}
		}
	}
	for (i=1;i<=n1;i++) {
		vec.push_back(i);
		res+=n2+i;
	}

	sort(vec.begin(), vec.end(),[](int a, int b){
		int u = lcp(a,b);
		char ca,cb;
		if (u>=a) ca=s2[u-a]; else ca=s1[u];			
		if (u>=b) cb=s2[u-b]; else cb=s1[u];
		return (ca<cb);			
	});
	
	gr.reset(n1);
	for (i=0;i<n1;i++) {
		gr.sz[i]=vec[i]; ord[vec[i]]=i;}
	for (i=1;i<n1;i++) {
		u=lcp(vec[i-1],vec[i]);
		res-=u;
		ev[u].emplace_back(i-1,i);
	}
	for (i=n1+n2;i>=1;i--) {
		for (auto g :ev[i]) gr.add_edge(g.fi, g.se);
		if (i<=n1) {
			if (gr.sz[gr.get_par(ord[i])]<i) ;
			else res--;
		}
	}
	cout<<res;
}
// a;
// aaa
// abaa
/*
nnqnnnqqnqnnqnnqqqqqqnqnqqqnqnnqqqqnnnqqnqnqnnq
nnqnnnqqnnqqqqqqnqnqqqnqnnqqqqnnnqqnqnqnnq
10
*/