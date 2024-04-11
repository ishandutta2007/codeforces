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

namespace CPL_Gauss {
	ll mat[1001][1002];
	ll res[1001];
	ll used[1001];
	ll i,j,k,t,u,v,a,b;
	vector<int> vec;
	int solve(int n) {
		// for (i=0;i<n;i++) {
		// 	for (j=0;j<=n;j++) cout<<mat[i][j]<<' ';
		// 	cout<<endl;
		// }
		for (i=0;i<n;i++) used[i]=0;
		vec.clear();
		for (t=0;t<n;t++) {
			for (i=0;i<n;i++) if (!used[i] && mat[i][t]) {
				break;
			}
			if (i==n) return 0;
			used[i]=1;
			vec.push_back(i);
			u=INV(mat[i][t],MOD);
			for (j=0;j<n;j++) if (!used[j]) {
				v=u*(MOD-mat[j][t]);
				v%=MOD;
				for (k=t;k<n+1;k++) {
					mat[j][k]+=mat[i][k]*v;
					mat[j][k]%=MOD;
				}
			}
		}
		
			for (i=n-1;i>=0;i--) {
				u=vec[i];
				mat[u][n]*=INV(mat[u][i],MOD);
				mat[u][n]%=MOD;
				res[i]=mat[u][n];
				for (j=0;j<i;j++) {
					v=vec[j];
					mat[v][n]+=mat[u][n]*(MOD-mat[v][i]);
					mat[v][n]%=MOD;
				}
			}
		
			return 1;
	}
};

vector<int> gt[100001];
int sc[100001];
int cnt[100001];
ll n,m,i,j,k,t,t1,u,v,a,b;
void calc(int x) {
	vector<int> sus;
	for (auto g : gt[x]) {
		if (sc[g]==-1) calc(g);
		sus.push_back(sc[g]); 
	} 
	sort(sus.begin(), sus.end());
	sus.erase(unique(sus.begin(), sus.end()), sus.end());
	int i;
	for (i=0;i<sus.size();i++) if (sus[i]-i) break;
	sc[x]=i;
	// cout<<"sc "<<x<<' '<<i<<endl;
}
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=m;i++) {
		cin>>u>>v;
		gt[u].push_back(v);
	}
	for (i=1;i<=n;i++) sc[i]=-1;
	for (i=1;i<=n;i++) if (sc[i]==-1) calc(i);
	for (i=1;i<=n;i++) cnt[sc[i]]++;
	t=0;
	t1=1;
	while(cnt[t]) t++;
	while(cnt[t1]) t1*=2;
	// cout<<t<<' '<<t1<<endl;
	u=INV(n+1,MOD);
	for (i=0;i<t1;i++) {
		CPL_Gauss::mat[i][i]=1;
		for (j=0;j<t;j++) {
			CPL_Gauss::mat[i][i^j]+=(MOD-cnt[j])*u;
			CPL_Gauss::mat[i][i^j]%=MOD;
		}
		if (i) CPL_Gauss::mat[i][t1]=u;
	}
	assert(CPL_Gauss::solve(t1));
	cout<<CPL_Gauss::res[0];
}
// a;