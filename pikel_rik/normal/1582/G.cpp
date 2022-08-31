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

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	string b;
	cin >> b;

	constexpr int MX = 1000 * 1000;

	vector<vector<int>> prefix(MX + 1);
	for (int i = 1; i <= MX; i++) {
		if (s.is_prime(i)) {
			prefix[i].push_back(0);
		}
	}

	vector<pair<int, vector<pair<int, int>>>> divs = {{n, {}}};

	long long ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == 1) {
			b[i] = '*';
		}
		auto factors = s.prime_factors(a[i]);
		for (auto [p, c] : factors) {
			if (b[i] == '*') {
				prefix[p].push_back(c + prefix[p].back());
			} else {
				prefix[p].push_back(-c + prefix[p].back());
			}
		}
		if (b[i] == '*') {
			while (divs.size() > 1) {
				bool success = true;
				auto [j, div_factors] = divs.back();
				for (auto [p, c] : div_factors) {
					success &= prefix[p].back() - c >= 0;
				}
				if (success) {
					divs.pop_back();
				} else {
					break;
				}
			}
		} else {
			for (auto &[p, c] : factors) {
				c = prefix[p].back() + c;
			}
			divs.emplace_back(i, factors);
		}
		ans += divs.back().first - i;
	}

	cout << ans << '\n';
	return 0;
}