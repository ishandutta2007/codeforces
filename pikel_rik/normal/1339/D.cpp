#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> g(n);
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> leaves;
	for (int i = 0; i < n; i++) {
		if (g[i].size() == 1) {
			leaves.push_back(i);
		}
	}

	vector<int> d(n, -1);

	auto dfs = [&](int x, const auto &dfs) -> void {
		for (int i : g[x]) {
			if (d[i] == -1) {
				d[i] = 1 + d[x];
				dfs(i, dfs);
			}
		}
	};

	d[leaves.front()] = 0;
	dfs(leaves.front(), dfs);

	bool no_odd = true;
	for (int l : leaves) {
		no_odd &= d[l] % 2 == 0;
	}

	cout << (no_odd ? 1 : 3) << ' ';

	int ans = n - 1;
	for (int x = 0; x < n; x++) {
		int c = 0;
		for (int i : g[x]) {
			c += g[i].size() == 1;
		}
		ans -= max(0, c - 1);
	}
	cout << ans << '\n';
	return 0;
}