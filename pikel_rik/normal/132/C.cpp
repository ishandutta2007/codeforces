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

	string s;
	cin >> s;

	int n = s.length(), m;
	cin >> m;

	tensor::dynamic_tensor<int, 4> dp(n, m + 1, 2 * n + 1, 2, -1);

	auto recurse = [&](int i, int j, int k, int f, auto self) -> int {
		if (j < 0)
			return 0;
		if (i == n)
			return (j == 0) * abs(k);
		if (dp[i][j][n + k][f] != -1)
			return dp[i][j][n + k][f];
		int &ans = dp[i][j][n + k][f];
		ans = max(ans, self(i + 1, j - (s[i] == 'F'), k, !f, self));
		ans = max(ans, self(i + 1, j - (s[i] == 'T'), k + !f - f, f, self));
		ans = max(ans, self(i, j - 2, k, f, self));
		return ans;
	};

	cout << recurse(0, m, 0, 0, recurse) << '\n';
	return 0;
}