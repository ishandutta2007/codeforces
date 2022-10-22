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
vector <vector <int>> g, rev, colorpack, cg;
vector <bool> used;
vector <int> ts, color;
void topsort(int v) {
	used[v] = true;
	for (auto u : g[v]) {
		if (used[u]) continue;
		topsort(u);
	}
	ts.push_back(v);
}
void scc(int v, int c) {
	color[v] = c;
	colorpack.back().push_back(v);
	used[v] = true;
	for (auto u : rev[v]) {
		if (used[u]) continue;
		scc(u, c);
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n, m, h; cin >> n >> m >> h;
	vector <int> c(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	g.resize(n + 1);
	rev.resize(n + 1);
	used.resize(n + 1);
	color.resize(n + 1);
	for (int u, v, i = 0; i < m; ++i) {
		cin >> u >> v;
		if ((c[u] + 1) % h == c[v]) {
			g[u].push_back(v);
			rev[v].push_back(u);
		}
		if ((c[v] + 1) % h == c[u]) {
			g[v].push_back(u);
			rev[u].push_back(v);
		}
	}
	for (int i = 1; i <= n; ++i)
		if (!used[i])
			topsort(i);
	reverse(ts.begin(), ts.end());
	for (int i = 1; i <= n; ++i)
		used[i] = false;
	int cur = 0;
	for (auto x : ts) {
		if (!used[x]) {
			colorpack.push_back({});
			scc(x, cur++);
		}
	}
	cg.resize(cur);
	for (int i = 1; i <= n; ++i) {
		for (auto j : g[i]) {
			if (color[j] != color[i])
				cg[color[i]].push_back(color[j]);
		}
	}
	int mn = -1;
	for (int i = 0; i < cur; ++i) {
		if (cg[i].empty()) {
			if (mn == -1 or colorpack[i].size() < colorpack[mn].size())
				mn = i;
		}
	}
	cout << colorpack[mn].size() << '\n';
	sort(colorpack[mn].begin(), colorpack[mn].end());
	for (auto x : colorpack[mn]) cout << x << ' ';
	cout << '\n';
	return 0;
}