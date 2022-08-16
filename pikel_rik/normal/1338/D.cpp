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

	vector<int> dp0(n), dp1(n), mx0(n), mx1(n);
	auto dfs = [&](int x, int p, const auto &dfs) -> void {
		dp0[x] = 0;
		dp1[x] = 1;
		for (int i : g[x]) {
			if (i == p) continue;
			dfs(i, x, dfs);
			mx0[x] = max(mx0[x], dp0[i]);
			mx1[x] = max(mx1[x], dp1[i]);
		}
		int ch = int(g[x].size()) - (p != -1);
		if (ch > 0) {
			dp0[x] = ch - 1 + max(mx0[x], mx1[x]);
			dp1[x] = 1 + mx0[x];
		}
	};

	int ans = 0;
	auto reroot = [&](int x, int p, const auto &dfs) -> void {
		if (p != -1) {
			mx0[x] = max(mx0[x], dp0[p]);
			mx1[x] = max(mx1[x], dp1[p]);
		}
		ans = max(ans, (int) g[x].size() + mx0[x] - 1);
		ans = max(ans, (int) g[x].size() + mx1[x] - 1);

		vector<int> v0, v1;
		for (int i : g[x]) {
			v0.push_back(dp0[i]);
			v1.push_back(dp1[i]);
		}

		sort(v0.begin(), v0.end(), greater<>());
		sort(v1.begin(), v1.end(), greater<>());

		for (int i : g[x]) {
			if (i == p) continue;
			if (g[x].size() >= 2) {
				dp1[x] = 1 + (dp0[i] != v0[0] ? v0[0] : v0[1]);
				dp0[x] = dp0[i] != v0[0] ? v0[0] : v0[1];
				dp0[x] = max(dp0[x], dp1[i] != v1[0] ? v1[0] : v1[1]);
				dp0[x] += (int) g[x].size() - 2;
				dfs(i, x, dfs);
			} else {
				dp1[x] = 1;
				dp0[x] = 0;
				dfs(i, x, dfs);
			}
		}
	};

	dfs(0, -1, dfs);
	reroot(0, -1, reroot);
	cout << ans << '\n';
	return 0;
}