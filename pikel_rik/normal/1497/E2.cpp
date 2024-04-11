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

template<typename T>
struct fenwick_tree {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<T> bit;
	F f;

	fenwick_tree() : n(), f() {}
	fenwick_tree(int n, F f = plus<T>()) : n(n), bit(n + 1, 0), f(f) {}

	void add(int i, T val) {
		for (++i; i <= n; i += i & -i) {
			bit[i] = f(bit[i], val);
		}
	}

	T query(int i) {
		T ans = 0;
		for (++i; i; i -= i & -i) {
			ans = f(ans, bit[i]);
		}
		return ans;
	}

	int lower_bound(T sum) {
		const static int lg = 21;

		int i = 0;
		for (int j = lg - 1; j >= 0; j--) {
			if ((i | (1 << j)) <= n && sum > bit[i | (1 << j)]) {
				sum -= bit[i | (1 << j)];
				i |= 1 << j;
			}
		}
		return i;
	}
};

constexpr int M = (int)1e7;
sieve<M> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	vector<int> last(M + 1);

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		for (auto &x : a) {
			cin >> x;
			for (auto [p, c] : s.prime_factors(x)) {
				while (c > 1) {
					x /= p * p;
					c -= 2;
				}
			}
			last[x] = -1;
		}

		vector<int> nxt(n, -1);
		for (int i = n - 1; i >= 0; i--) {
			nxt[i] = last[a[i]];
			last[a[i]] = i;
		}

		fenwick_tree<int> ft(n);
		vector<vector<int>> jump(n, vector<int>(k + 1));

		for (int i = 0; i < n; i++) {
			if (nxt[i] != -1) {
				ft.add(nxt[i], 1);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= k; j++) {
				jump[i][j] = ft.lower_bound(j + 1);
			}
			if (nxt[i] != -1) {
				ft.add(nxt[i], -1);
			}
		}

		vector<vector<int>> dp(n + 1, vector<int>(k + 1));
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j <= k; j++) {
				dp[i][j] = n + 1;
				for (int take = 0; take <= j; take++) {
					dp[i][j] = min(dp[i][j], 1 + dp[jump[i][take]][j - take]);
				}
			}
		}

		int ans = n + 1;
		for (int j = 0; j <= k; j++) {
			ans = min(ans, dp[0][j]);
		}
		cout << ans << '\n';
	}
	return 0;
}