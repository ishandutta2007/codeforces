#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, k;
vector<vector<int>> g;
vector<int> d, par, sz;

int dfs(int v, int prev, int dep) {
	d[v] = dep;
	par[v] = prev;
	sz[v] = 1;
	for (const auto &i : g[v])
		if (i != prev)
			sz[v] += dfs(i, v, 1 + dep);
	return sz[v];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	g.resize(n);
	d.resize(n);
	par.resize(n);
	sz.resize(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, 0, 0);
	vector<int> val(n);
	for (int i = 0; i < n; i++)
		val[i] = d[i] - sz[i] + 1;
	sort(val.rbegin(), val.rend());
	ll ans = 0;
	for (int i = 0; i < k; i++)
		ans += val[i];
	cout << ans << endl;
}