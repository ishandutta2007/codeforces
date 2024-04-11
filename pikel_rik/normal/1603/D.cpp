#include <bits/stdc++.h>
using namespace std;

template <int N>
struct spf_sieve {
	std::vector<int> primes;
	std::array<int, N + 1> spf;

	spf_sieve() : spf() {
		for (int i = 2; i <= N; i++) {
			if (spf[i] == 0) {
				spf[i] = i;
				primes.push_back(i);
			}
			for (int j = 0; j < (int) primes.size() && i * primes[j] <= N; j++) {
				spf[i * primes[j]] = primes[j];
				if (i % primes[j] == 0) {
					break;
				}
			}
		}
	}

	bool is_prime(int x) const {
		return spf[x] == x;
	}

	std::vector<std::pair<int, int>> prime_factors(int x) const {
		std::vector<std::pair<int, int>> factors;
		while (x != 1) {
			if (factors.empty() || factors.back().first != spf[x]) {
				factors.emplace_back(spf[x], 0);
			}
			factors.back().second++;
			x /= spf[x];
		}
		return factors;
	}

	std::vector<int> divisors(int x) const {
		std::vector<int> divisors = {1};
		while (x > 1) {
			int p = spf[x], c = 0;
			while (x % p == 0) {
				x /= p, c += 1;
			}
			int sz = (int) divisors.size();
			for (int i = 1, pw = p; i <= c; i++, pw *= p) {
				for (int j = 0; j < sz; j++) {
					divisors.push_back(divisors[j] * pw);
				}
			}
		}
		return divisors;
	}

	template <typename T, typename F>
	T compute_multiplicative_function(int x, F &&f) const {
		T result = T(1);
		while (x > 1) {
			int p = spf[x], c = 0;
			while (spf[x] == p) {
				x /= p, c += 1;
			}
			result *= f(p, c);
		}
		return result;
	}
};

constexpr int N = 100 * 1000;

spf_sieve<N> sieve;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<long long> phi_sum(N + 1);
	for (int i = 1; i <= N; i++) {
		int phi = i;
		for (auto [p, c] : sieve.prime_factors(i)) {
			phi /= p, phi *= p - 1;
		}
		phi_sum[i] = phi + phi_sum[i - 1];
	}

	constexpr long long inf = (long long) 1e14;

	auto c = [&](int l, int r) -> long long {
		long long ans = 0;
		while (l <= r) {
			int next_l = r / (r / l) + 1;
			ans += (next_l - l) * phi_sum[r / l];
			l = next_l;
		}
		return ans;
	};

	constexpr int K = 17;

	vector<vector<long long>> dp(K + 1, vector<long long>(N + 1, inf));
	for (int i = 1; i <= N; i++) {
		dp[1][i] = ((long long)i * i + i) / 2;
	}

	for (int k = 2; k <= K; k++) {
		auto recurse = [&](int l, int r, int opt_l, int opt_r, auto &&self) -> void {
			int m = (l + r) / 2;

			int best_l = min(m, opt_r);
			long long current_c = c(best_l, m);

			dp[k][m] = dp[k - 1][best_l - 1] + current_c;

			for (int i = best_l - 1; i >= opt_l; i--) {
				current_c += phi_sum[m / i];
				if (dp[k - 1][i - 1] + current_c < dp[k][m]) {
					dp[k][m] = dp[k - 1][i - 1] + current_c;
					best_l = i;
				}
			}

			if (l != m) {
				self(l, m - 1, opt_l, best_l, self);
			}
			if (r != m) {
				self(m + 1, r, best_l, opt_r, self);
			}
		};
		recurse(k, N, k, N, recurse);
	}

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		if (k <= K) {
			cout << dp[k][n] << '\n';
		} else {
			cout << n << '\n';
		}
	}
	return 0;
}