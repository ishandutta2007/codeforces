#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 50;
int n, m;
vector<pair<int, int>> G[N];
long long d[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
		G[v + n].emplace_back(u + n, w);	
	}
	for (int i = 1; i <= n; ++i)
		G[i].emplace_back(i + n, 0);
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	priority_queue<pair<long long, int>> que;
	que.emplace(-d[1], 1);
	while (!que.empty()) {
		auto [dd, x] = que.top(); que.pop();
		if (-dd != d[x]) continue;
		for (auto [y, w] : G[x]) {
			if (d[y] > d[x] + w) {
				d[y] = d[x] + w;
				que.emplace(-d[y], y);
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		long long ans = d[i + n];
		if (ans >= 1e18) ans = -1;
		cout << ans << " \n"[i == n];
	}
}