
// Problem : E. Interesting Graph and Apples
// Contest : Codeforces - Codeforces Beta Round #9 (Div. 2 Only)
// URL : https://codeforces.com/problemset/problem/9/E
// Memory Limit : 64 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int N = 60;
 
int deg[N], par[N], sz[N];
 
int getPar(int v){
	return (par[v] == v ? v : par[v] = getPar(par[v]));
}
 
bool merge(int u, int v){
	u = getPar(u);
	v = getPar(v);
	if (u == v)
		return false;
	if (sz[v] < sz[u])
		swap(u, v);
	par[u] = v;
	sz[v] += sz[u];
	return true;
}
 
int main(){
	fio;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
    	par[i] = i, sz[i] = 1;
    bool con = true, cyc = false;
    for (int i = 0; i < m; i ++){
    	int u, v;
    	cin >> u >> v;
    	if (!merge(u, v))
    		cyc = true;
    	deg[u] ++;
    	deg[v] ++;
    	if (2 < deg[u] || 2 < deg[v])
    		return cout << "NO", 0;
    }
    for (int i = 1; i <= n; i ++)
    	if (getPar(i) != getPar(1))
    		con = false;
    if (cyc && con)
    	return cout << "YES\n0", 0;
    if (cyc && !con)
    	return cout << "NO", 0;
    if (n == 1)
    	return cout << "YES\n1\n1 1", 0;
    cout << "YES\n" << n - m << '\n';
    for (int i = 1; i <= n; i ++)
    	for (int j = i + 1; j <= n; j ++)
    		if (deg[i] < 2 && deg[j] < 2 && getPar(i) != getPar(j))
    			cout << i << ' ' << j << '\n', deg[i] ++, deg[j] ++, merge(i, j);
    int v;
    for (int i = 1; i <= n; i ++)
    	if (deg[i] == 1)
    		v = i;
    for (int i = 1; i < v; i ++)
    	if (deg[i] == 1)
    		cout << i << ' ' << v;
}