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
		if (x == 1) {
			return {1};
		}
		int c = 0, n = x;
		for (; spf[x] == spf[n]; n /= x, c++);
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

sieve<1000000> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			auto factors = s.prime_factors(a[i]);
			for (auto &[p, c] : factors) {
				while (c >= 2) {
					a[i] /= p * p;
					c -= 2;
				}
			}
			mp[a[i]]++;
		}

		int first = 1, odd = 0, even = 0;
		for (auto &[x, c] : mp) {
			if (x == 1) {
				even += c;
				first = max(first, c);
				continue;
			}
			if (c % 2 == 1) {
				odd = max(odd, c);
			} else {
				even += c;
			}
			first = max(first, c);
		}

		int q;
		cin >> q;

		long long w;
		while (q--) {
			cin >> w;
			if (w == 0) {
				cout << first << '\n';
			} else cout << max(odd, even) << '\n';
		}
	}
	return 0;
}