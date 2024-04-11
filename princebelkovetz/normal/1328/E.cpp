#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <queue>
using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
const int N = 1e6 + 2, mod = 1e9 + 7, mod2 = 998244353;
vector <vector <int>> g;
vector <int> h, p, tin, tout;
int timer = 0;
void dfs(int v, int x) {
	tin[v] = timer++;
	for (auto u : g[v]) {
		if (u == x) continue;
		h[u] = h[v] + 1, p[u] = v;
		dfs(u, v);
	}
	tout[v] = timer++;
}
bool upper(int u, int v) {
	return tin[u] <= tin[v] and tout[v] <= tout[u];
}
bool cmp(int a, int b) {
	return h[a] > h[b];
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n, m; cin >> n >> m;
	g.resize(n + 1);
	h.resize(n + 1), p.resize(n + 1, 1);
	tin.resize(n + 1), tout.resize(n + 1);
	for (int u, v, i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	while (m --> 0) {
		int k; cin >> k;
		vector <int> a;
		while (k --> 0) {
			int x; cin >> x;
			a.push_back(x);
		}
		sort(a.begin(), a.end(), cmp);
		bool c = true;
		for (int i = 1; i < a.size(); ++i) {
			if (upper(a[i], a[0]) or upper(p[a[i]], a[0])) continue;
			c = false; break;
		}
		cout << (c ? "YES" : "NO") << '\n';
	}
}