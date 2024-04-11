#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

std::vector<std::vector<int> > adj;
std::vector<pair<int, int> > seg[400002];
std::vector<int> de;
std::vector<int> va;
int tin[100002];
int tou[100002];
int depth[100002];
int t = 0;
void build(int node, int s, int e)
{
	if (s == e) { seg[node].pb({de[s], va[s]}); return; }
	int m = (s + e) >> 1;
	build(2 * node, s, m);
	build(2 * node + 1, m + 1, e);
	seg[node].resize(e - s + 1);
	merge(seg[2 * node + 1].begin(), seg[2 * node + 1].end(), seg[2 * node].begin(), seg[2 * node].end(), seg[node].begin());
	int mi = seg[node][0].second;
	for (int i = 0; i < (e - s + 1); ++i) {
		seg[node][i].second = min(seg[node][i].second, mi);
		mi = seg[node][i].second;
	}
}

int query(int node, int s, int e, int l, int r, int val)
{
	if (e < l || r < s)
		return 100000000000000ll;
	if (l <= s && e <= r) {
		auto it = upper_bound(seg[node].begin(), seg[node].end(), make_pair(val + 1, 0ll));
		if (it == seg[node].begin()) {
			return 100000000000000ll;
		} 
		it--;
		return it->second;
	}
	int m = (s + e) >> 1;
	return min(query(2 * node, s, m, l, r, val), query(2 * node + 1, m + 1, e, l, r, val));
}

int a[100003];

void predfs(int u, int p) {
	tin[u] = t++;
	depth[u] = depth[p] + 1;
	de.pb(depth[u]);
	va.pb(a[u]);
	for (int v : adj[u]) 
		if (v != p) 
			predfs(v, u);
	tou[u] = t - 1;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int r; cin >> r; r--;
	for (int i = 0; i < n; ++i) cin >> a[i];
	adj.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	predfs(r, r);
	build(1, 0, n - 1);
	int m; cin >> m;
	int last = 0;
	while (m--) {
		int p; cin >> p;
		int q; cin >> q;
		int x = (p + last) % n;
		int k = (q + last) % n;
		last = query(1, 0, n - 1, tin[x], tou[x], depth[x] + k);
		cout << last << "\n";
	}
}