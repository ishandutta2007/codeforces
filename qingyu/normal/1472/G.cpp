#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> G(n + 1, std::vector<int>());
	std::vector<int> d(n + 1, 0x3f3f3f3f);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		std::cin >> u >> v;
		G[u].push_back(v);
	}
	auto dijkstra = [&](int s) {
		d[s] = 0;
		std::priority_queue<std::pair<int, int>> que;
		que.emplace(-d[s], s);
		while (!que.empty()) {
			auto [_, x] = que.top(); que.pop();
			if (_ == -d[x]) {
				for (int y : G[x]) {
					if (d[y] > d[x] + 1) {
						d[y] = d[x] + 1;
						que.emplace(-d[y], y);
					}
				}
			}
		}
	};
	dijkstra(1);
	std::vector<int> ans(n + 1, 0x3f3f3f3f), vis(n + 1, 0);
	for (int x = 1; x <= n; ++x) {
		ans[x] = d[x];
		for (int y : G[x])
			ans[x] = std::min(ans[x], d[y]);
	}
	std::function<void(int)> dfs = [&](int x) -> void{
		if (vis[x]) return;
		vis[x] = true;
		for (int y : G[x])
			if (d[y] > d[x]) {
				dfs(y);
				ans[x] = std::min(ans[x], ans[y]);
			}
	};
	dfs(1);
	for (int i = 1; i <= n; ++i) std::cout << ans[i] << ' ';
	std::cout << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) solve();
}