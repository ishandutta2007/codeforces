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

	int prime_factors(int x) const {
		int c = 0, last = 1;
		while (x != 1) {
			if (last != spf[x]) {
				c += 1, last = spf[x];
			}
			x /= spf[x];
		}
		return c;
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

template<typename T>
std::vector<T> divisors(T n) {
	std::vector<T> divisors;
	for (int i = 1; (T) i * i <= n; i++) {
		if (n % i == 0) {
			divisors.push_back(i);
			if (i != n / i) {
				divisors.push_back(n / i);
			}
		}
	}
	return divisors;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	constexpr int N = (int)1e7;

	vector<int> cnt(2 * N);
	cnt[1] = 0;

	for (int i = 2; i <= 2 * N; i++) {
		if (cnt[i] == 0) {
			for (int j = i; j <= 2 * N; j += i) {
				cnt[j] += 1;
			}
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int c, d, x;
		cin >> c >> d >> x;

		int init = __gcd(c, d);
		if (x % init != 0) {
			cout << "0\n";
			continue;
		}

		c /= init, d /= init, x /= init;

		auto div = divisors(x);

		long long ans = 0;
		for (auto g : div) {
			long long left = x + (long long)d * g;
			if (left % c != 0)
				continue;
			int lcm = left / c / g;
			if ((left / c) % g == 0)
				ans += (1ll << cnt[lcm]);
		}
		cout << ans << '\n';
	}
	return 0;
}