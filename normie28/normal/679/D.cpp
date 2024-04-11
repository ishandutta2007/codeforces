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
vector<int> gt[401];
int n,m,i,j,k,t,t1,u,v,a,b;
int dis[401][401];
ld prob[401][401];
ld fin[401];
vector<int> que;
vector<int> cand[401];
int bcd1,d1,bcd2;
ld occ[401];
vector<int> app;
ld mx[401],total;
int main()
{
	fio;
	cin>>n>>m;
	for (i=0;i<m;i++) {
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) dis[i][j]=-1;
		dis[i][i]=0;
		que.clear();
		que.push_back(i);
		for (j=0;j<que.size();j++) {
			u=que[j];
			for (auto g : gt[u]) if (dis[i][g]==-1) {
				dis[i][g]=dis[i][u]+1;
				que.push_back(g);
			}
		}
	}



	for (i=1;i<=n;i++) {
		for (j=0;j<n;j++) cand[j].clear();
		for (j=1;j<=n;j++) cand[dis[i][j]].push_back(j);
		for (j=0;j<n;j++) {
			bcd1=i;
			d1=j;

			if (cand[d1].size()) {
				prob[bcd1][d1]=ld(1)/cand[d1].size();
				for (i=1;i<=n;i++) occ[i]=0;
				for (auto g : cand[d1]) {
					for (auto gg : gt[g]) {
						occ[gg]+=ld(1)/(cand[d1].size()*gt[g].size());
					}
				}
				app.clear();
				for (i=1;i<=n;i++) if (occ[i]>0) app.push_back(i);
				for (bcd2=1;bcd2<=n;bcd2++) {
					total=0;
					for (auto g : app) {
						mx[dis[bcd2][g]]=max(mx[dis[bcd2][g]],occ[g]);
					}
					for (auto g : app) {
						total+=mx[dis[bcd2][g]];
						mx[dis[bcd2][g]]=0;
					}
					prob[bcd1][d1]=max(prob[bcd1][d1],total);
				}
			}
			// cout<<d1<<' '<<prob[bcd1][d1]<<' '<<cand[d1].size()<<endl;
			fin[bcd1]+=((ld)cand[d1].size()/n)*prob[bcd1][d1];
			j=d1;
			i=bcd1;
		}
	}
	total=0;
	for (i=1;i<=n;i++) total=max(total,fin[i]);
	cout<<fixed<<setprecision(9)<<total;
}