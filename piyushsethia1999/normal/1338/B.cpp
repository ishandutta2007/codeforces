#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef print
#define print(...)
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
//const int mod = 998244353;
const int mod = 1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0, lim - 1); return uid(rang); }
int powm(int a, int b) { int res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }

vi gr[100004];
vi leaf;
set<int> s;
int h[100004];

void dfs(int u, int p) {
	h[u] = h[p] + 1;
	for (int v : gr[u])
		if (v != p)
			dfs(v, u);
	if (sz(gr[u]) == 1) {
		leaf.pb(u);
		s.insert(gr[u][0]);
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		gr[u].pb(v);
		gr[v].pb(u);
	}
	dfs(0, 0);
	bool odd = 0;
	bool eve = 0;
	for (int l : leaf) {
		if (h[l] & 1) odd = 1;
		else eve = 1; 
	}
	if (odd && eve) {
		cout << 3 << " ";
	} else {
		cout << 1 << " ";
	}
	cout << n - 1 - sz(leaf) + sz(s) << "\n";
}