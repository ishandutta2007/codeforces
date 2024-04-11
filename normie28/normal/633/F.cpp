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
#endif
vector<int> gt[100001];
ll n,m,i,j,k,t,t1,u,v,a,b,res;
ll dp1[100001];
ll dp2[100001];
ll dp3[100001];
ll dp4[100001];
ll arr[100001];
void proc(int x, int p) {
	dp1[x]=0;
	for (auto g : gt[x]) if (g-p) {proc(g,x);}
	int a1=0,a2=0,a3=0;
	for (auto g : gt[x]) if (g-p) {
		if (dp1[g]>dp1[a1]) {
			a3=a2;
			a2=a1;
			a1=g;
		}
		else if (dp1[g]>dp1[a2]) {
			a3=a2;
			a2=g;
		}
		else if (dp1[g]>dp1[a3]) {
			a3=g;
		}
	}
	dp1[x]=dp1[a1]+arr[x];
	dp2[x]=arr[x]+dp1[a1]+dp1[a2];
	for (auto g : gt[x]) if (g-p) dp2[x]=max(dp2[x],dp2[g]);
	for (auto g : gt[x]) if (g-p) {
		if (g==a1)
			dp3[x]=max(dp3[x],dp2[g]+dp1[a2]);
		else
			dp3[x]=max(dp3[x],dp2[g]+dp1[a1]);
	}
	for (auto g : gt[x]) if (g-p) dp3[x]=max(dp3[x],dp3[g]);
	dp3[x]+=arr[x];
	for (auto g : gt[x]) if (g-p) {
		if (g==a1)
			dp4[x]=max(dp4[x],dp3[g]+dp1[a2]);
		else
			dp4[x]=max(dp4[x],dp3[g]+dp1[a1]);
	}
	for (auto g : gt[x]) if (g-p) {
		if (g==a1) 
			dp4[x]=max(dp4[x],dp2[g]+dp1[a2]+dp1[a3]);
		else if (g==a2) 
			dp4[x]=max(dp4[x],dp2[g]+dp1[a1]+dp1[a3]);
		else 
			dp4[x]=max(dp4[x],dp2[g]+dp1[a2]+dp1[a1]);
	}
	dp4[x]+=arr[x];
	res=max(res,dp4[x]);

	a1=a2=0;
	for (auto g : gt[x]) if (g-p) {
		if (dp2[g]>dp2[a1]) {
			a2=a1;
			a1=g;
		}
		else if (dp2[g]>dp2[a2]) {
			a2=g;
		}
	}
	res=max(res,dp2[a1]+dp2[a2]);
	// cout<<x<<' '<<dp1[x]<<' '<<dp2[x]<<' '<<dp3[x]<<' '<<dp4[x]<<endl;
}
int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++) {
		cin>>arr[i];
	}
	for (i=1;i<n;i++) {
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	proc(1,1);
	cout<<res;
}