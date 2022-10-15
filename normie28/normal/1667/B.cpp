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

struct seg {
	ll val[1000022];
	ll n;
	void reset(int _n) {
		n=_n;
		for (int i=1;i<2*n;i++) val[i]=-1e18;
	}
	void upd(int u, int v) {
		// cout<<"upd "<<u<<' '<<v<<endl;
		u+=n-1;
		val[u]=max(val[u],v);
		while(true) {
			u>>=1;
			if (!u) break;
			val[u]=max(val[(u<<1)],val[(u<<1)|1]);
		}
	}
	ll query(int l, int r) {
		ll res = -1e18,u;
		// cout<<"wuery "<<l<<' '<<r<<endl;
		for (l += n-1, r += n-1; l < r; l >>= 1, r >>= 1) {
			if (l&1) {
				u = val[l++];
				res=max(res,u);
			}
			if (r&1) {
				u = val[--r];
				res=max(res,u);
			}
		}
		// cout<<res<<endl;
		return res;
	}
};
seg stl,stg;


vector<int> vec;
ll n,m,i,j,k,t,t1,u,v,a,b;

ll dp[500011];
ll arr[500011];
ll sum[500011];
ll ste[500011];
map<ll,ll> sus;
int main()
{
	fio;
	int tc;
	cin>>tc;
	for (t1=0;t1<tc;t1++) {
		cin>>n;
		sus.clear();
		for (i=1;i<=n;i++) {
			cin>>arr[i];
			sum[i]=arr[i]+sum[i-1];
		}
		for (i=0;i<=n;i++) {
			sus[sum[i]]=1;
		}
		t=0;
		for (auto& g : sus) {
			t++;
			g.se=t;
		}
		for (i=0;i<=n;i++) {
			sum[i]=sus[sum[i]];
		}

		stl.reset(t);
		stg.reset(t);
		for (i=1;i<=t;i++) ste[i]=-1e18;
		
		dp[0]=0;
		stl.upd(sum[0],0);
		stg.upd(sum[0],0);
		ste[sum[0]]=0;

		for (i=1;i<=n;i++) {
			dp[i]=-1e18;
			u=stl.query(1,sum[i])+i;
			dp[i]=max(dp[i],u);
			u=stg.query(sum[i]+1,t+1)-i;
			dp[i]=max(dp[i],u);
			dp[i]=max(dp[i],ste[sum[i]]);
			// cout<<"dp "<<i<<' '<<dp[i]<<endl;
			stl.upd(sum[i],dp[i]-i);
			stg.upd(sum[i],dp[i]+i);
			ste[sum[i]]=max(ste[sum[i]],dp[i]);
			
		}
		cout<<dp[n]<<endl;
	}
}
// a;