#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <iomanip>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7;
vector <vector <int>> g;
vector <int> ans, k, cur;
vector <bool> used;

void f(int v) {
	cur[v] = (cur[v] + 1) & 1;
	ans.push_back(v);
}

void dfs(int v) {
	used[v] = true;
	f(v);
	for (auto u : g[v]) {
		if (used[u]) continue;
		dfs(u);
		f(v);
		if (cur[u] != k[u]) {
			f(u), f(v);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n, m; cin >> n >> m;
	g.resize(n);
	k.resize(n);
	cur.resize(n);
	used.resize(n);
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (auto& x : k) cin >> x;
	int id = -1;
	for (int i = 0; i < n; ++i) {
		if (k[i]) id = i;
	}
	if (id == -1) {
		cout << "0\n";
		return 0;
	}
	dfs(id);
	for (int i = 0; i < n; ++i) {
		if (k[i] != cur[i]) {
			if (id == i) ans.pop_back();
			else {
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto& x : ans) cout << x + 1 << ' ';
	cout << '\n';
	return 0;
}