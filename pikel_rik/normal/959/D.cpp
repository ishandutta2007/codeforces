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

sieve<1313839> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto primes = s.primes();
	vector<bool> mark(1313839 + 1);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<int> b(n); b[0] = a[0];

	auto take = [&](int x) -> bool {
		auto factors = s.prime_factors(x);
		bool marked = false;
		for (auto &[p, c] : factors) {
			marked |= mark[p];
		}
		if (!marked) {
			for (auto &[p, c] : factors) {
				mark[p] = true;
			}
		}
		return !marked;
	};

	assert(take(b[0]));

	bool greater = false;

	for (int i = 1, smallest = 2; i < n; i++) {
		if (greater) {
			for (; !take(smallest); smallest++);
			b[i] = smallest++;
		} else {
			for (b[i] = a[i]; !take(b[i]); b[i]++);
			greater |= b[i] > a[i];
		}
	}

	for (auto &x : b) {
		cout << x << ' ';
	}
	cout << '\n';
	return 0;
}