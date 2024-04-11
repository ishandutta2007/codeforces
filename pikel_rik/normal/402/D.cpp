#include <bits/stdc++.h>
using namespace std;

template<typename T>
std::vector<std::pair<T, int>> prime_factors(T n) {
	std::vector<std::pair<T, int>> factors;
	for (int i = 2; (T) i * i <= n; i++) {
		if (n % i == 0) {
			factors.emplace_back(i, 0);
			while (n % i == 0) {
				n /= i;
				factors.back().second++;
			}
		}
	}
	if (n > 1) {
		factors.emplace_back(n, 1);
	}
	return factors;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(m);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	unordered_set<int> bad(b.begin(), b.end());

	vector<vector<pair<int, int>>> factors(n);
	vector<vector<int>> f(n, vector<int>(n + 1));

	for (int i = 0; i < n; i++) {
		factors[i] = prime_factors(a[i]);
		for (auto &[p, c] : factors[i]) {
			if (bad.find(p) != bad.end()) {
				f[i][n] -= c;
			} else f[i][n] += c;
		}
	}

	auto divide = [&](vector<pair<int, int>> factors_a, const vector<pair<int, int>> factors_b) -> vector<pair<int, int>> {
		for (int i = 0, j = 0; i < int(factors_a.size()); i++) {
			while (j < int(factors_b.size()) && factors_a[i].first > factors_b[j].first) {
				j++;
			}
			if (j < int(factors_b.size()) && factors_a[i].first == factors_b[j].first) {
				factors_a[i].second -= factors_b[j].second;
			}
		}
		return factors_a;
	};

	int g = a[0]; f[0][0] = 0;
	vector<pair<int, int>> g_factors = factors[0];
	for (int i = 1; i < n; i++) {
		int new_g = __gcd(g, a[i]);
		vector<pair<int, int>> ratio_factors;
		if ((long long)new_g * new_g < g) {
			auto new_g_factors = prime_factors(new_g);
			ratio_factors = divide(g_factors, new_g_factors);
			g_factors.swap(new_g_factors);
		} else {
			ratio_factors = prime_factors(g / new_g);
			g_factors = divide(g_factors, ratio_factors);
		}
		g = new_g;

		for (int j = 0; j < i; j++) {
			f[j][i] = f[j][i - 1];
			for (auto &[p, c] : ratio_factors) {
				if (bad.find(p) != bad.end())
					f[j][i] -= c;
				else f[j][i] += c;
			}
		}
		for (auto &[p, c] : divide(factors[i], g_factors)) {
			if (bad.find(p) != bad.end())
				f[i][i] -= c;
			else f[i][i] += c;
		}
	}

	vector<vector<int>> dp(n, vector<int>(n + 1));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (i == 0)
				dp[i][j] = max(f[0][0], f[0][j]);
			else dp[i][j] = max(dp[i - 1][j] + f[i][j], dp[i - 1][i] + f[i][i]);
		}
	}

	cout << dp[n - 1][n] << '\n';
	return 0;
}