#include <bits/stdc++.h>

int n, m;
long long k, a[25][25], ans;
bool vis[25][25];
std::map<long long, long long> map1[25][25], map2[25][25];
bool calc1[25][25], calc2[25][25];
std::queue<std::pair<int, int>> que;

void upd1(int i, int j) {
	if (calc1[i][j]) return;
	calc1[i][j] = true;
	if (vis[i][j]) return;
	if (i + 1 <= n) {
		for (auto p : map1[i][j]) {
			long long x = p.first ^ a[i + 1][j];
			map1[i + 1][j][x] += p.second;
		}
		que.emplace(i + 1, j);
	}
	if (j + 1 <= m) {
		for (auto p : map1[i][j]) {
			long long x = p.first ^ a[i][j + 1];
			map1[i][j + 1][x] += p.second;
		}
		que.emplace(i, j + 1);
	}
}

void upd2(int i, int j) {
	if (calc2[i][j]) return;
	calc2[i][j] = true;
	if (vis[i][j]) {
		for (auto p : map1[i][j])
			if (map2[i][j].count(k ^ a[i][j] ^ p.first)) {
				ans += p.second * map2[i][j][k ^ a[i][j] ^ p.first];
			}
	}
	else {
		if (i - 1 >= 1) {
			for (auto p : map2[i][j]) {
				long long x = p.first ^ a[i - 1][j];
				map2[i - 1][j][x] += p.second;
			}
			que.emplace(i - 1, j);
		}
		if (j - 1 >= 1) {
			for (auto p : map2[i][j]) {
				long long x = p.first ^ a[i][j - 1];
				map2[i][j - 1][x] += p.second;
			}
			que.emplace(i, j - 1);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			std::cin >> a[i][j];
	for (int i = 1; ; ++i) {
		if (n - i + 1 <= 0 || i > m) break;
		vis[n - i + 1][i] = true;
	}
	map1[1][1][a[1][1]] = 1;
	map2[n][m][a[n][m]] = 1;
	que.emplace(1, 1);
	while (!que.empty())
	{
		auto [i, j] = que.front(); que.pop();
		upd1(i, j);
	}
	que.emplace(n, m);
	while (!que.empty())
	{
		auto [i, j] = que.front(); que.pop();
		upd2(i, j);
	}
	std::cout << ans << '\n';
	return 0;
}