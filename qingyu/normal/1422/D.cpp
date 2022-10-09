#include <bits/stdc++.h>

const int N = 1e5 + 50;

int n, m, sx, sy, fx, fy;
int x[N], y[N], id[N];
long long d[N];
std::vector<std::pair<int, int>> G[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> m >> sx >> sy >> fx >> fy;
	for (int i = 1; i <= m; ++i) {
		std::cin >> x[i] >> y[i];
		id[i] = i;
	}
	x[m + 1] = sx, y[m + 1] = sy, id[m + 1] = m + 1;
	x[m + 2] = fx, y[m + 2] = fy, id[m + 2] = m + 2;
	auto add = [&](int u, int v, int w) {
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	};
	std::sort(id + 1, id + m + 1, [&](int i, int j) {
		return x[i] < x[j];
	});
	for (int i = 1; i < m; ++i) {
		int a = id[i], b = id[i + 1], w = std::min(std::abs(x[a] - x[b]), std::abs(y[a] - y[b]));
		add(a, b, w);
	}
	std::sort(id + 1, id + m + 1, [&](int i, int j) {
		return y[i] < y[j];
	});
	for (int i = 1; i < m; ++i) {
		int a = id[i], b = id[i + 1], w = std::min(std::abs(x[a] - x[b]), std::abs(y[a] - y[b]));
		add(a, b, w);
	}
	auto dijkstra = [&](int s) {
		std::priority_queue<std::pair<long long, int>> que;
		memset(d, 0x3f, sizeof d);
		d[s] = 0;
		que.emplace(-d[s], s);
		while (!que.empty()) {
			auto [_, x] = que.top(); que.pop();
			if (d[x] == -_) {
				for (auto [y, w] : G[x])  {
					if (d[y] > d[x] + w) {
						d[y] = d[x] + w;
						que.emplace(-d[y], y);
					}
				}
			}
		}
	};
	int s = m + 1, t = m + 2;
	add(s, t, std::abs(x[s] - x[t]) + std::abs(y[s] - y[t]));
	for (int i = 1; i <= m; ++i) {
		add(s, i, std::min(std::abs(x[i] - x[s]), std::abs(y[i] - y[s])));
		add(t, i, std::abs(x[i] - x[t]) + std::abs(y[i] - y[t]));
	}
	dijkstra(s);
	std::cout << d[t] << '\n';
	return 0;
}