#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<int> iu(n + 1), iv(n + 1);
	std::vector<std::vector<int>> G(2 * n + 1, std::vector<int>());
	for (int i = 1; i <= n; ++i) {
		int a, b;
		std::cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
		iu[i] = a, iv[i] = b;
	}
	for (int i = 1; i < 2 * n; i += 2) {
		G[i].push_back(i + 1);
		G[i + 1].push_back(i);
	}
	std::vector<int> vis(2 * n + 1, -1);
	std::function<void(int, int)> dfs = [&](int x, int c) {
		vis[x] = c;
		for (int y : G[x]) {
			assert(vis[x] != vis[y]);
			if (vis[y] == -1)
				dfs(y, !c);
		}
	};
	for (int i = 1; i <= 2 * n; ++i)
		if (vis[i] == -1) 
			dfs(i, 0);
	for (int i = 1; i <= n; ++i)
		std::cout << 1 + vis[iu[i]] << " " << 1 + vis[iv[i]] << '\n';
	return 0;
}