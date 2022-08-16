#include <bits/stdc++.h>
using namespace std;

namespace tensor {
	template<typename T, int N, int...args>
	struct static_tensor : std::array<static_tensor<T, args...>, N> {
		static_tensor() : std::array<static_tensor<T, args...>, N>() {}

		void fill(const T &val) {
			for (int i = 0; i < N; i++) {
				(*this)[i].fill(val);
			}
		}
	};

	template<typename T, int N>
	struct static_tensor<T, N> : std::array<T, N> {
		static_tensor() : std::array<T, N>() {}
	};

	template<typename T, int D>
	struct dynamic_tensor : std::vector<dynamic_tensor<T, D - 1>> {
		dynamic_tensor() : std::vector<dynamic_tensor<T, D - 1>>() {}

		template<typename...args>
		dynamic_tensor(size_t n, args...A) : std::vector<dynamic_tensor<T, D - 1>>(n, dynamic_tensor<T, D - 1>(A...)) {}

		dynamic_tensor(const std::initializer_list<dynamic_tensor<T, D - 1>> &list) : std::vector<dynamic_tensor<T, D - 1>>(list) {}

		void fill(const T &val) {
			for (auto it = this->begin(); it != this->end(); it++) {
				it->fill(val);
			}
		}
	};

	template<typename T>
	struct dynamic_tensor<T, 1> : std::vector<T> {
		dynamic_tensor() : std::vector<T>() {}

		dynamic_tensor(size_t n, const T &val = T()) : std::vector<T>(n, val) {}

		dynamic_tensor(const std::initializer_list<T> &list) : std::vector<T>(list) {}

		void fill(const T &val = T()) {
			std::fill(this->begin(), this->end(), val);
		}
	};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using tensor::dynamic_tensor;

	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n);

	vector<long long> c(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		g[--u].push_back(--v);
		c[u] += w, c[v] -= w;
	}

	vector<int> top_order;
	vector<bool> visited(n);

	auto dfs = [&](int u, const auto &self) -> void {
		visited[u] = true;
		for (int v : g[u]) {
			if (!visited[v]) {
				self(v, self);
			}
		}
		top_order.push_back(u);
	};

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i, dfs);
		}
	}

	reverse(top_order.begin(), top_order.end());

	vector<int> submask(n), pos(n);
	for (int u = 0; u < n; u++) {
		pos[top_order[u]] = u;
	}

	for (int u = 0; u < n; u++) {
		int &mask = submask[u];
		for (int v : g[top_order[u]]) {
			mask |= 1 << pos[v];
		}
	}

	constexpr long long inf = (long long)1e12;

	dynamic_tensor<long long, 2> dp(n + 1, 1 << n, inf);
	dynamic_tensor<bool, 3> p(n, n, 1 << n);

	vector<long long> prev(1 << n, inf);
	prev[(1 << n) - 1] = 0;

	for (int i = n - 1; i >= 0; i--) {
		dp.fill(inf);
		for (int j = n - 1; j >= 0; j--) {
			for (int mask = 0; mask < (1 << n); mask++) {
				const auto &nxt = (j + 1 == n ? prev : dp[j + 1]);
				if (!(mask >> j & 1) && (mask | submask[j]) == mask) {
					long long value = i * c[top_order[j]] + nxt[mask | (1 << j)];
					if (value < dp[j][mask]) {
						dp[j][mask] = value;
						p[i][j][mask] = true;
					}
				}
				if (nxt[mask] < dp[j][mask]) {
					dp[j][mask] = nxt[mask];
					p[i][j][mask] = false;
				}
			}
		}
		for (int mask = 0; mask < (1 << n); mask++) {
			prev[mask] = dp[0][mask];
		}
	}

	vector<int> a(n);
	for (int i = 0, mask = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (p[i][j][mask]) {
				a[top_order[j]] = i;
				mask |= 1 << j;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
	return 0;
}