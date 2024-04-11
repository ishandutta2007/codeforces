#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, long long>> e;
	vector<vector<long long>> Ge(n, vector<long long>(n, (long long)1e18));
	vector<vector<long long>> G(n, vector<long long>(n, (long long)1e18));
	for (int i = 0; i < m; ++i) {
		int u, v;
	   	long long w;
		cin >> u >> v >> w;
		--u, --v;
		e.emplace_back(u, v, w);
		Ge[u][v] = Ge[v][u] = min(Ge[u][v], 1ll);
		G[u][v] = G[v][u] = min(G[u][v], w);
	}
	for (int i = 0; i < n; ++i) {
		Ge[i][i] = 0;
		G[i][i] = 0;
	}
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				Ge[i][j] = min(Ge[i][j], Ge[i][k] + Ge[k][j]);
			}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
		}
	}
	long long ans = 1e18;
	for (auto [u, v, w] : e) {
		auto upd = [&](long long z) {
			if (z > 1e9) return;
			ans = min(ans, z * w);
		};
		upd(1 + Ge[0][u] + Ge[v][n - 1]);
		upd(1 + Ge[0][v] + Ge[u][n - 1]);
		for (int x = 0; x < n; ++x) {
			upd(2 + Ge[0][x] + Ge[x][n - 1] + Ge[u][x]);
			upd(2 + Ge[0][x] + Ge[x][n - 1] + Ge[v][x]);
		}
	}
	cout << ans << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}