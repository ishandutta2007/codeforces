#include <bits/stdc++.h>

const int N = 3000;
std::bitset<N> bs[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::vector<std::tuple<int, int, int>> edges;
	std::cin >> n;
	std::vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> x[i] >> y[i];
	}
	auto dist = [&](int i, int j) {
		return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
	};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			edges.emplace_back(dist(i, j), i, j);
		}
	}
	std::sort(edges.begin(), edges.end());
	std::reverse(edges.begin(), edges.end());
	long double ans = 0.0;
	for (auto [w, u, v] : edges) {
		if ((bs[u] & bs[v]).any()) {
			ans = sqrtl(1.0L * w) / 2;
			break;
		}
		bs[u][v] = bs[v][u] = 1;
	}
	std::cout << std::fixed << std::setprecision(10) << ans << '\n';
}