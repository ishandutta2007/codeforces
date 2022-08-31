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

constexpr int N = 2 * 10 * 1000 * 1000;

spf_sieve<N> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<int> cnt(N + 1);
	for (auto &x : a) {
		for (int d : s.divisors(x)) {
			cnt[d] += 1;
		}
	}

	long long ans = 0;
	vector<long long> dp(N + 1, -1);

	auto recurse = [&](int x, auto &&self) -> long long {
		if (x == 1) {
			return 0;
		}
		if (dp[x] != -1) {
			return dp[x];
		}
		long long &ans = dp[x];
		for (int d : s.divisors(x)) {
			ans = max(ans, (long long)d * (cnt[d] - cnt[x]) + self(d, self));
		}
		return ans;
	};

	for (auto x : a) {
		ans = max(ans, (long long)cnt[x] * x + recurse(x, recurse));
	}
	cout << ans << '\n';
	return 0;
}