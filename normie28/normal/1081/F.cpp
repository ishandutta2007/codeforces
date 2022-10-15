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
#endif

vector<pii(int)> ops;
int n,m,i,j,k,t,t1,u,v,a,b;
int res[301];
int qc;
int las,cur;
int q(int l, int r) {
	las=cur;
	cout<<"? "<<l<<' '<<r<<endl;
	qc^=1;
	int x;
	cin>>x;
	assert(x!=-1);
	if (qc) cur=n-x; else cur=x;
	return (cur-las);
}

int normal_loop(int x) {
	int u;
	while(true) {
		u=q(x+1,n);
		if (u) {
			ops.push_back({1,x});
			return u;
		}
	}
}
int special_loop_21() {
	int u;
	while(true) {
		u=q(3,n-1);
		if (u==1 || u==-1) {
			ops.push_back({n,n});
		}
		else {
			ops.push_back({1,2});
			return u;
		}
	}
}

int special_loop_01() {
	int u;
	while(true) {
		u=q(1,n-1);
		if (u) {
			ops.push_back({n,n});
			return u;
		}
	}
}

void unwind() {
	for (auto g : ops) {
		for (int i=g.fi;i<=g.se;i++) res[i]^=1;
	}
}
void answer() {
	cout<<"! ";
	for (int i=1;i<=n;i++) cout<<res[i];
	cout<<endl;
}

int main()
{
	fio;
	cin>>n>>cur;
	if (n==1) {
		cout<<"! "<<cur<<endl;
	}
	else if (n==2) {
		if (special_loop_01()==1) res[2]=1; else res[2]=0;
		if (normal_loop(1)==1) res[1]=1; else res[1]=0;
		unwind(); 
		answer();
	}
	else if (n==3) {
		if (special_loop_01()==1) res[3]=1; else res[3]=0;
		if (normal_loop(1)==1) res[1]=1; else res[1]=0;
		res[2]=cur-res[1]-res[3];
		unwind();
		answer();
	}
	else {
		if (special_loop_21()==0) normal_loop(1);
		for (i=3;i<=n-1;i++) {
			u=normal_loop(i);
			if (abs(u)!=i) normal_loop(i-1);
		}
		if (cur==0) {
			for (i=1;i<n;i++) res[i]=0; res[n]=0;
		}
		if (cur==1) {
			for (i=1;i<n;i++) res[i]=0; res[n]=1;
		}
		if (cur==n-1) {
			for (i=1;i<n;i++) res[i]=1; res[n]=0;
		}
		if (cur==n) {
			for (i=1;i<n;i++) res[i]=1; res[n]=1;
		}
		unwind();
		answer();
	}
}