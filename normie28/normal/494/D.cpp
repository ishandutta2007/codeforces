#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
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
#define pb push_back
#define ff first
#define ss second
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
const int MAXN = 100 * 1000 + 17, mod = 1e9 + 7, lg = 20;
 
int sum(int a, int b) { return (1LL * a + b + mod) % mod; }
int mul(int a, int b) { return (1LL * a * b) % mod; }
 
int n, dp[MAXN][5], q, sz[MAXN], up[MAXN][lg], tin[MAXN], tout[MAXN], timer, sm[MAXN][lg];
vector<pii> adj[MAXN];
 
int addEDGE(int x, int y, int sz, int e) { return sum(x, sum(mul(e, mul(e, sz)), mul(mul(2, e), y))); }
 
void dfs_down(int v = 1, int par = 0) {
	tin[v] = ++timer;
	up[v][0] = par;
	for (int i = 1; i < lg; i++)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for (auto i : adj[v])
		if (i.ff != par) {
			int u = i.ff;
			dfs_down(u, v);
			sz[v] += sz[u];
			dp[v][2] = sum(dp[v][2], addEDGE(dp[u][2], dp[u][3], sz[u], i.ss));
			dp[v][3] = sum(dp[v][3], sum(dp[u][3], mul(i.ss, sz[u])));
		}
	tout[v] = ++timer;
	sz[v]++;
}
void dfs_up(int v = 1, int par = 0, int e = 0) {
	if (v == 1)
		;
	else {
		dp[v][4] = sum(sum(dp[par][3], -sum(dp[v][3], mul(e, sz[v]))), sum(dp[par][4], mul(e, n - sz[v])));
		int tmp1 = sum(sum(dp[par][2], dp[par][1]), -addEDGE(dp[v][2], dp[v][3], sz[v], e));
		int tmp2 = mul(2, mul(e, sum(dp[par][4], sum(dp[par][3], -sum(dp[v][3], mul(e, sz[v]))))));
		int tmp3 = mul(n - sz[v], mul(e, e));
		dp[v][1] = sum(tmp1, sum(tmp2, tmp3));
	}
	sm[v][0] = e;
	for (int i = 1; i < lg; i++)
		sm[v][i] = sum(sm[v][i - 1], sm[up[v][i - 1]][i - 1]);
	for (auto i : adj[v])
		if (i.ff != par)
			dfs_up(i.ff, v, i.ss);
 
}
 
bool is_anc(int v, int u) { return tin[v] <= tin[u] && tout[u] <= tout[v]; }
int lca(int v, int u) {
	if (is_anc(u, v)) return u;
	for (int i = lg - 1; i >= 0; i--)
		if (!is_anc(up[u][i], v))
			u = up[u][i];
	return up[u][0];
}
int getPAR(int v, int u) {
	if (v == u) return 0;
	int res = 0;
	for (int i = lg - 1; i >= 0; i--)
		if (!is_anc(up[u][i], v))
			res = sum(res, sm[u][i]), u = up[u][i];
	return sum(res, sm[u][0]);
}
int get(int v, int u) {
	if (v == u) return 0;
	int res = 0, lc = lca(v, u);
	res = sum(getPAR(lc, v), getPAR(lc, u));
	return res;
}
 
int main() {
    fio;
	tout[0] = MAXN * 4;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		adj[v].pb({u, w});
		adj[u].pb({v, w});
	}
	dfs_down();
	dfs_up();
	cin >> q;
	while (q--) {
		int v, u;
		cin >> u >> v;
		if (is_anc(v, u)) {
			int e = get(v, u);
			int tmp = addEDGE(dp[v][1], dp[v][4], n - sz[v], e);
			cout << sum(sum(dp[u][1], dp[u][2]), -mul(2, tmp)) << '\n';
 
		}
		else {
			int e = get(v, u);
			cout << sum(mul(2, addEDGE(dp[v][2], dp[v][3], sz[v], e)), -sum(dp[u][1], dp[u][2])) << '\n';
		}
	}
}