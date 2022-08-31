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

spf_sieve<1000 * 1000> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, e;
		cin >> n >> e;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		vector<int> before(n), after(n);
		for (int i = 0; i < e; i++) {
			int zeroes = 0, last_idx = -1;
			for (int j = i; j < n; j += e) {
				last_idx = j;
				if (a[j] == 1) {
					zeroes += 1;
				} else if (s.is_prime(a[j])) {
					before[j] = zeroes;
					zeroes = 0;
				} else {
					zeroes = 0;
				}
			}

			zeroes = 0;
			for (int j = last_idx; j >= i; j -= e) {
				if (a[j] == 1) {
					zeroes += 1;
				} else if (s.is_prime(a[j])) {
					after[j] = zeroes;
					zeroes = 0;
				} else {
					zeroes = 0;
				}
			}
		}

		long long ans = 0;
		for (int i = 0; i < n; i++) {
			if (s.is_prime(a[i])) {
				ans += (1ll + before[i]) * (1ll + after[i]) - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}