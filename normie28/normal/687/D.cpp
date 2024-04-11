
// Problem : D. Dividing Kingdom II
// Contest : Codeforces - Codeforces Round #360 (Div. 1)
// URL : https://codeforces.com/contest/687/problem/D
// Memory Limit : 256 MB
// Time Limit : 6000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
	Normie's Template v2.0
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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
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
//---------END-------//
// nah im taking the shortcut
struct edge {
	int u, v, w;
	int id;
	bool operator < (const edge &t) const { return w < t.w; }
};
edge elis[1000005];
 
int f[1005], w[1005];
 
int F(int x) {
	if(x == f[x]) return x;
	int fa = f[x];
	f[x] = F(f[x]);
	w[x] = (w[x] + w[fa]) % 2;
	return f[x];
}
 
int main () {
	fio;
	int n, m, q;
	cin>>n>>m>>q;
	for(int i = 1; i <= m; ++ i) {
		int u, v, w; 
		cin>>u>>v>>w;
		elis[i].u = u; 
		elis[i].v = v;
		elis[i].w = w;
		elis[i].id = i;
	}
	sort(elis + 1, elis + 1 + m);
	while(q --) {
		int l, r;
		cin>>l>>r;
		for(int i = 1; i <= n; ++ i) f[i] = i, w[i] = 0;
		int res = -1;
		for(int i = m; i >= 1; -- i) {
			if(elis[i].id < l || elis[i].id > r) continue;
			int u = elis[i].u, v = elis[i].v;
			int fu = F(u), fv = F(v);
			if(fu != fv) {
				f[fu] = fv, w[fu] = (w[u] + w[v] + 1) % 2;
			} else {
				if(w[u] == w[v]) { res = elis[i].w; break; }
			}
		}
		cout<<res<<endl;
	}
}