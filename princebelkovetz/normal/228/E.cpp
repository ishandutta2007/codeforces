#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
vector <vector <int>> a, rev, comp;
vector <bool> used;
vector <int> ts, color;
void dfs(int v) {
	used[v] = true;
	for (auto u : a[v]) {
		if (used[u]) continue;
		dfs(u);
	}
	ts.push_back(v);
}
void dfs2(int v, int col) {
	used[v] = true;
	color[v] = col;
	for (auto u : rev[v]) {
		if (used[u]) continue;
		dfs2(u, col);
	}
}
void dfs3(int v) {
	used[v] = true;
	for (auto u : comp[v]) {
		if (used[u]) continue;
		dfs3(u);
	}
	ts.push_back(v);
}

signed main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int n, m; cin >> n >> m;
	a.resize(2 * n);
	used.resize(2 * n);
	rev.resize(2 * n);
	color.resize(2 * n);

	for (int i = 0, u, v, z; i < m; ++i) {
		cin >> u >> v >> z;
		--u; --v;
		if (z) {
			a[2 * u].push_back(2 * v);
			a[2 * v].push_back(2 * u);
			a[2 * u + 1].push_back(2 * v + 1);
			a[2 * v + 1].push_back(2 * u + 1);
		}
		else {
			a[2 * u].push_back(2 * v + 1);
			a[2 * v].push_back(2 * u + 1);
			a[2 * u + 1].push_back(2 * v);
			a[2 * v + 1].push_back(2 * u);
		}
	}
	for (int i = 0; i < 2 * n; ++i) {
		if (used[i]) continue;
		dfs(i);
	}
	for (int i = 0; i < 2 * n; ++i)
		used[i] = false;
	for (int i = 0; i < 2 * n; ++i) {
		for (auto x : a[i])
			rev[x].push_back(i);
	}
	int col = 0;
	for (auto x : ts) {
		if (used[x]) continue;
		dfs2(x, col++);
	}
	comp.resize(col);
	for (int i = 0; i < 2 * n; ++i) {
		for (auto x : a[i]) {
			if (color[x] != color[i])
				comp[color[i]].push_back(color[x]);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (color[2 * i] == color[2 * i + 1]) {
			cout << "Impossible\n";
			return 0;
		}
	}
	ts.clear();
	for (int i = 0; i < col; ++i)
		used[i] = false;
	for (int i = 0; i < col; ++i) {
		if (used[i]) continue;
		dfs3(i);
	}
	vector <int> ind(col);
	for (int i = 0; i < col; ++i)
		ind[ts[i]] = i;
	vector <bool> ans(n), was(2 * n);
	for (int i = 0; i < n; ++i) {
		int x = 2 * i, y = 2 * i + 1;
		if (was[x] or was[y]) continue;
		int c;
		if (ind[color[x]] < ind[color[y]]) {
			c = color[x];
		}
		else c = color[y];
		for (int i = 0; i < 2 * n; ++i) {
			if (color[i] == c) 
				was[i] = true;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (was[2 * i]) ++cnt;
	}
	cout << cnt <<  '\n'; 
	for (int i = 0; i < n; ++i) {
		if (was[2 * i]) cout << i + 1 << ' ';
	}
	return 0;
}