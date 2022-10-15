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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul or USACO.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
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

struct lvl {
	ll id;
	ll p1, p2;
};

struct cmp01 {
	int operator() (lvl a, lvl b) const {
		if (a.p1-b.p1) return a.p1<b.p1;
		return (a.id<b.id);
	}
};

struct cmp02 {
	int operator() (lvl a, lvl b) const {
		if (a.p2-b.p2) return a.p2<b.p2;
		return (a.id<b.id);

	}
};

struct cmp12 {
	int operator() (lvl a, lvl b) const {
		if (a.p2-a.p1-b.p2+b.p1) return a.p2-a.p1<b.p2-b.p1;
		return (a.id<b.id);
	}
};


struct cmp10 {
	int operator() (lvl a, lvl b) const {
		if (a.p1-b.p1) return -a.p1<-b.p1;
		return (a.id<b.id);
	}
};

struct cmp21 {
	int operator() (lvl a, lvl b) const {
		if (a.p1-a.p2-b.p1+b.p2) return a.p1-a.p2<b.p1-b.p2;
		return (a.id<b.id);
	}
};



lvl arr[300001];

set<lvl,cmp01> st01;
set<lvl,cmp02> st02;
set<lvl,cmp10> st10;
set<lvl,cmp12> st12;
set<lvl,cmp21> st21;

ll n,m,i,j,k,t,t1,u,v,a,b,val;
ll t01, t12, t10, t21;
int res[300001];
void proc01() {
	int u = st01.begin()->id;
	st01.erase(arr[u]);
	st02.erase(arr[u]);
	st10.insert(arr[u]);
	st12.insert(arr[u]);
}

void proc12() {
	int u = st12.begin()->id;
	st10.erase(arr[u]);
	st12.erase(arr[u]);
	st21.insert(arr[u]);
}

void proc10() {
	int u = st10.begin()->id;
	int v = st02.begin()->id;
	st10.erase(arr[u]);
	st12.erase(arr[u]);
	st01.insert(arr[u]);
	st02.insert(arr[u]);
	st01.erase(arr[v]);
	st02.erase(arr[v]);
	st21.insert(arr[v]);
}

void proc21() {
	int u = st21.begin()->id;
	int v = st02.begin()->id;
	st21.erase(arr[u]);
	st10.insert(arr[u]);
	st12.insert(arr[u]);
	st01.erase(arr[v]);
	st02.erase(arr[v]);
	st21.insert(arr[v]);
}

int main()
{
	fio;
	cin>>n>>m;
	for (i=0;i<n;i++) {
		arr[i].id=i;
		cin>>arr[i].p1>>arr[i].p2;
		st01.insert(arr[i]);
		st02.insert(arr[i]);
	}
	for (t=0;t<m;t++) {
		// for (auto g : st01) cout<<g.id<<' '; cout<<endl;
		// for (auto g : st12) cout<<g.id<<' '; cout<<endl;
		// for (auto g : st10) cout<<g.id<<' '; cout<<endl;
		// for (auto g : st21) cout<<g.id<<' '; cout<<endl;
		// for (auto g : st02) cout<<g.id<<' '; cout<<endl;
		t01=t12=t21=t10=4e9;
		if (st01.size()) t01=st01.begin()->p1;
		if (st12.size()) t12=(st12.begin()->p2)-(st12.begin()->p1);
		if (st02.size()) {
			if (st10.size()) {
				t10=-(st10.begin()->p1)+(st02.begin()->p2);
			}
			if (st21.size()) {
				t21=(st21.begin()->p1)-(st21.begin()->p2)+(st02.begin()->p2);
			}
		}
		if (t01<=t10 && t01<=t21 && t01<=t12) {
			val+=t01;
			proc01();	
		}
		else if (t10<=t01 && t10<=t12 && t10<=t21) {
			val+=t10;
			proc10();
		}
		else if (t12<=t21 && t12<=t10 && t12<=t01) {
			val+=t12;
			proc12();
		}
		else {
			val+=t21;
			proc21();
		}
		// cout<<t01<<' '<<t10<<' '<<t12<<' '<<t21<<endl;
		// cout<<val<<endl;
	}
	for (auto g : st01) res[g.id]=0;
	for (auto g : st12) res[g.id]=1;
	for (auto g : st21) res[g.id]=2;
		cout<<val<<endl;
	for (i=0;i<n;i++) cout<<res[i];
}

/*
01
12
10 02
21
*/