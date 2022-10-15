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
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
set<int> alive;
int stat[200001];
int par[200001];
vector<int> ind[200001];
vector<int> obj[200001];

ll hah[200001];
map<ll,int> cnt;

void merg(int x, int y) {
	if (ind[x].size()+obj[x].size()<=ind[y].size()+obj[y].size()) {
		for (auto g : ind[x]) {
			par[g]=y;
			ind[y].push_back(g);
		}
		for (auto g : obj[x]) {
			if (g<0) {
				cnt[hah[-g]]--;
				hah[-g]^=ll(x^y);
				cnt[hah[-g]]++;
			}
			else {
				cnt[hah[g]]--;
				hah[g]^=ll(x^y)<<30;
				cnt[hah[g]]++;
			}
			obj[y].push_back(g);
		}
		ind[x].clear();
		obj[x].clear();
	} else {
		for (auto g : ind[y]) {
			par[g]=x;
			ind[x].push_back(g);
		}
		for (auto g : obj[y]) {
			if (g<0) {
				cnt[hah[-g]]--;
				hah[-g]^=ll(x^y);
				cnt[hah[-g]]++;
			}
			else {
				cnt[hah[g]]--;
				hah[g]^=ll(x^y)<<30;
				cnt[hah[g]]++;
			}
			obj[x].push_back(g);
		}
		ind[y].clear();
		obj[y].clear();
	}
}

int main()
{
	fio;
	cin>>n>>m;


	for (i=1;i<=n;i++) {
		stat[i]=1;
		alive.insert(i);
	}
	for (i=0;i<=n;i++) {
		par[i]=i;
		ind[i].push_back(i);
	}


	for (t=1;t<=m;t++) {
		cin>>t1;
		if (t1==0) {
			cin>>u>>v>>a;
			if (a==0) {
				auto it = alive.lower_bound(u);
				while(it!=alive.end()&&(*it)<=v) {
					merg(par[(*it)-1],par[(*it)]);
					stat[(*it)]=0;
					it=alive.erase(it);
				}
			}
			else {
				u=par[u-1];
				v=par[v];
				hah[t]=(ll(v)<<30)^u;
				cnt[hah[t]]++;
				obj[u].push_back(-t);
				obj[v].push_back(t);
			}
		}
		else {
			cin>>a;
			// cout<<a<<' '<<stat[a]<<endl;
			if (!stat[a]) cout<<"NO\n";
			else {
				u=par[a-1];
				v=par[a];
				if (cnt[(ll(v)<<30)^u]) cout<<"YES\n";
				else cout<<"N/A\n";
			}
		}	
	}
}