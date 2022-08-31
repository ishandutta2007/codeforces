#include <bits/stdc++.h>
using namespace std;

template <int N>
struct sieve {
	std::array<int, N + 1> spf;

	constexpr sieve() {
		spf.fill(0);
		for (int i = 2; i * i <= N; i++) {
			if (spf[i] == 0) {
				for (int j = i * i; j <= N; j += i) {
					if (spf[j] == 0) spf[j] = i;
				}
			}
		}
		for (int i = 2; i <= N; i++) {
			if (spf[i] == 0) {
				spf[i] = i;
			}
		}
	}

	bool is_prime(int x) const {
		return spf[x] == x;
	}

	std::vector<int> primes() const {
		std::vector<int> primes;
		for (int i = 1; i <= N; i++) {
			if (spf[i] == i) {
				primes.push_back(i);
			}
		}
		return primes;
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
		if (x == 1)
			return {1};
		int c = 0, n = x;
		for (; spf[x] == spf[n]; n /= spf[x], c++);
		std::vector<int> d = divisors(n);
		std::vector<int> res((c + 1) * d.size());
		for (int i = 0, j = 0, p = 1; i <= c; i++, p *= spf[x]) {
			for (int item : d) {
				res[j++] = p * item;
			}
		}
		return res;
	}
};

sieve<10 * 1000 * 1000> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		for (auto &x : a) {
			cin >> x;
			for (auto &[p, c] : s.prime_factors(x)) {
				while (c > 1) {
					x /= p * p;
					c -= 2;
				}
			}
		}

		set<int> nums;

		int ans = 1;
		for (auto x : a) {
			if (!nums.insert(x).second) {
				ans += 1;
				nums = {x};
			}
		}
		cout << ans << '\n';
	}
	return 0;
}