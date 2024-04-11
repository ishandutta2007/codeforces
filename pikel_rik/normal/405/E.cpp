#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, m;
vector<int> g[N];
pair<int, int> edges[N];

bool marked[N];
vector<tuple<int, int, int>> ans;

int dfs(int x) {
	vector<int> left, adj;
	for (int i : g[x]) {
		if (marked[i]) continue;
		marked[i] = true;
		adj.push_back(i);
	}

	for (int i : adj) {
		int u = edges[i].first ^ edges[i].second ^ x;
		int w = dfs(u);
		if (w) {
			ans.emplace_back(w, u, x);
		} else {
			left.push_back(u);
		}
	}

	while (left.size() > 1) {
		int u = left.back(); left.pop_back();
		int w = left.back(); left.pop_back();
		ans.emplace_back(u, x, w);
	}
	return (!left.empty() ? left.front() : 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> edges[i].first >> edges[i].second;
		g[edges[i].first].push_back(i);
		g[edges[i].second].push_back(i);
	}

	if (m % 2 != 0) {
		cout << "No solution\n";
	} else {
		for (int i = 1; i <= n; i++) dfs(i);
		for (auto&[x, y, z] : ans) cout << x << ' ' << y << ' ' << z << '\n';
	}
	return 0;
}