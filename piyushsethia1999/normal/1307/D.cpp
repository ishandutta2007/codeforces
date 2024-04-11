#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
//const int mod=998244353;
const int mod = 1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0, lim - 1); return uid(rang); }
int powm(int a, int b) { int res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }

int a[300005];
int da[300005];
int db[300005];
std::vector<int> adj[300005];
pair<int, int> p[300005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < m; ++i) {
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	queue<int> q;
	q.push(0);
	da[0] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u])
			if (!da[v]) {
				da[v] = da[u] + 1;
				q.push(v);
			}
	}
	q.push(n - 1);
	db[n - 1] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u])
			if (!db[v]) {
				db[v] = db[u] + 1;
				q.push(v);
			}
	}
	for (int i = 0; i < n; ++i) da[i]--, db[i]--;
	print(pair(da, n));
	print(pair(db, n));
	for (int i = 0; i < k; ++i) p[i] = {da[a[i]], db[a[i]]};
	sort(p, p + k, [](auto a, auto b) {
		if (a.fi != b.fi) return a.fi < b.fi;
		return a.se > b.se;
	});
	// sort(p, p + k);
	int ma = 0;
	for (int i = 0; i < k - 1; ++i)
		ma = max(ma, min(p[i].fi + p[i + 1].se + 1, p[i].se + p[i + 1].fi + 1));
	ma = min(ma, da[n - 1]);
	cout << ma;
}