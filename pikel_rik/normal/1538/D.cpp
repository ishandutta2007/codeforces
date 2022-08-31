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

constexpr int N = 100000;
sieve<N> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> primes;
	for (int i = 1; i * i <= 1000 * 1000 * 1000; i++) {
		if (s.is_prime(i)) {
			primes.push_back(i);
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int a, b, k;
		cin >> a >> b >> k;

		int g = __gcd(a, b);

		int x = a / g, y = b / g, z = g;
		int cx = 0, cy = 0, cg = 0;

		for (auto p : primes) {
			while (x % p == 0) {
				x /= p;
				cx += 1;
			}
			while (y % p == 0) {
				y /= p;
				cy += 1;
			}
			while (z % p == 0) {
				z /= p;
				cg += 1;
			}
		}

		cx += x > 1;
		cy += y > 1;
		cg += z > 1;

		if (k == 1) {
			if (a == b || (a % b != 0 && b % a != 0)) {
				cout << "No\n";
			} else {
				cout << "Yes\n";
			}
		} else if (k <= cx + cy + 2 * cg) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	return 0;
}