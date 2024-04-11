#include <bits/stdc++.h>
using namespace std;

template<typename T, int D>
struct tensor : std::vector<tensor<T, D - 1>> {
	tensor() : std::vector<tensor<T, D - 1>>() {}

	template<typename...args>
	tensor(size_t n, args...A) : std::vector<tensor<T, D - 1>>(n, tensor<T, D - 1>(A...)) {}

	tensor(const std::initializer_list<tensor<T, D - 1>> &list) : std::vector<tensor<T, D - 1>>(list) {}

	void fill(const T &val) {
		for (auto it = this->begin(); it != this->end(); it++) {
			it->fill(val);
		}
	}
};

template<typename T>
struct tensor<T, 1> : std::vector<T> {
	tensor() : std::vector<T>() {}

	tensor(size_t n, const T &val = T()) : std::vector<T>(n, val) {}

	tensor(const std::initializer_list<T> &list) : std::vector<T>(list) {}

	void fill(const T &val = T()) {
		std::fill(this->begin(), this->end(), val);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> adj(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			adj[i][j] = (c == '1');
		}
	}

	tensor<long long, 3> dp(n, 1 << n);
	for (int i = 0; i < n; i++) {
		dp[i][0] = {1};
	}

	for (int choose_mask = 1; choose_mask < (1 << n) - 1; choose_mask++) {
		vector<int> set_bits;
		for (int i = 0; i < n; i++) {
			if (choose_mask >> i & 1) {
				set_bits.push_back(i);
			}
		}
		for (int last = 0; last < n; last++) {
			if (choose_mask >> last & 1) {
				continue;
			}
			int popcount = __builtin_popcount(choose_mask);
			dp[last][choose_mask].resize(1 << popcount);
			for (int gen_mask = 0; gen_mask < (1 << popcount); gen_mask++) {
				for (int next : set_bits) {
					if (adj[last][next] == (gen_mask & 1)) {
						dp[last][choose_mask][gen_mask] += dp[next][choose_mask ^ (1 << next)][gen_mask >> 1];
					}
				}
			}
		}
	}

	const int all_mask = (1 << n) - 1;
	for (int gen_mask = 0; gen_mask < (1 << (n - 1)); gen_mask++) {
		long long ans = 0;
		int reversed_mask = 0;
		for (int i = 0; i < n - 1; i++) {
			if (gen_mask >> i & 1) {
				reversed_mask |= 1 << (n - 1 - i - 1);
			}
		}
		for (int i = 0; i < n; i++) {
			ans += dp[i][all_mask ^ (1 << i)][reversed_mask];
		}
		cout << ans << ' ';
	}
	cout << '\n';
	return 0;
}