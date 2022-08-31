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

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	int lg = 32 - __builtin_clz(n);
	vector<int> go(n + 1, n), d(n + 1), last(N, n);
	vector<vector<int>> up(n, vector<int>(lg, n));

	for (int i = n - 1; i >= 0; i--) {
		for (auto &[p, c] : s.prime_factors(a[i])) {
			go[i] = min(go[i], last[p]);
			last[p] = i;
		}
		go[i] = min(go[i], go[i + 1]);
		d[i] = 1 + d[go[i]];
		up[i][0] = go[i];
		for (int j = 1; j < lg && up[i][j - 1] < n; j++) {
			up[i][j] = up[up[i][j - 1]][j - 1];
		}
	}

	while (q--) {
		int l, r;
		cin >> l >> r, --l, --r;

		int i = l;
		for (int j = lg - 1; j >= 0; j--) {
			if (up[i][j] <= r) {
				i = up[i][j];
			}
		}
		cout << d[l] - d[i] + 1 << '\n';
	}
	return 0;
}