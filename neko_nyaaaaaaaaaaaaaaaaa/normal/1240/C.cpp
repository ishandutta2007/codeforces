#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX = 500001;

int n, k;
vector<pair<int, int>> adj[MAX];
vector<int> dpk(MAX);
vector<int> dpkm1(MAX);

void solve(int now, int prev) {
	vector<tuple<int, int, int>> nt;
	for (auto [u, w]: adj[now]) {
		if (u != prev) {
			solve(u, now);

			if (dpk[u] >= dpkm1[u] + w) {
				// always optimal to take dpk[u]
				dpk[now] += dpk[u];
				dpkm1[now] += dpk[u];
			} else {
				nt.emplace_back(dpkm1[u] + w - dpk[u], dpkm1[u] + w, u);
			}
		}
	}
	sort(nt.begin(), nt.end());
	reverse(nt.begin(), nt.end());
	// dpk = take k values
	// dpkm1 = take k-1 values
	for (int i = 0; i < nt.size(); i++) {
		int dif, val, u; tie(dif, val, u) = nt[i];
		if (i < k) {
			dpk[now] += val;
		} else {
			dpk[now] += dpk[u];
		}

		if (i < k-1) {
			dpkm1[now] += val;
		} else {
			dpkm1[now] += dpk[u];
		}
	}
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		dpk[i] = dpkm1[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	solve(1, 0);
	cout << max(dpk[1], dpkm1[1]) << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}