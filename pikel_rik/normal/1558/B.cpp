#include <bits/stdc++.h>
using namespace std;

struct dynamic_mint {
	static int M;

	static void set_mod(int m) {
		assert(0 < m);
		M = m;
	}

	int val;

	dynamic_mint() : val() {}

	dynamic_mint(long long x) : val(x % M) { if (val < 0) { val += M; }}

	dynamic_mint pow(long long n) const {
		dynamic_mint ans = 1, x(*this);
		for (; n > 0; n /= 2) {
			if (n & 1) ans *= x;
			x *= x;
		}
		return ans;
	}

	dynamic_mint inv() const { return pow(M - 2); }

	dynamic_mint operator+() const {
		dynamic_mint m;
		m.val = val;
		return m;
	}

	dynamic_mint operator-() const {
		dynamic_mint m;
		m.val = (val == 0 ? 0 : M - val);
		return m;
	}

	dynamic_mint &operator+=(const dynamic_mint &m) {
		if ((val += m.val) >= M) val -= M;
		return *this;
	}

	dynamic_mint &operator-=(const dynamic_mint &m) {
		if ((val -= m.val) < 0) val += M;
		return *this;
	}

	dynamic_mint &operator*=(const dynamic_mint &m) {
		val = (long long) val * m.val % M;
		return *this;
	}

	dynamic_mint &operator/=(const dynamic_mint &m) {
		val = (long long) val * m.inv().val % M;
		return *this;
	}

	friend dynamic_mint operator+(const dynamic_mint &lhs, const dynamic_mint &rhs) {
		return dynamic_mint(lhs) += rhs;
	}

	friend dynamic_mint operator-(const dynamic_mint &lhs, const dynamic_mint &rhs) {
		return dynamic_mint(lhs) -= rhs;
	}

	friend dynamic_mint operator*(const dynamic_mint &lhs, const dynamic_mint &rhs) {
		return dynamic_mint(lhs) *= rhs;
	}

	friend dynamic_mint operator/(const dynamic_mint &lhs, const dynamic_mint &rhs) {
		return dynamic_mint(lhs) /= rhs;
	}

	friend bool operator==(const dynamic_mint &lhs, const dynamic_mint &rhs) {
		return lhs.val == rhs.val;
	}

	friend bool operator!=(const dynamic_mint &lhs, const dynamic_mint &rhs) {
		return lhs.val != rhs.val;
	}

	dynamic_mint &operator++() {
		return *this += 1;
	}

	dynamic_mint &operator--() {
		return *this -= 1;
	}

	dynamic_mint operator++(int) {
		dynamic_mint result(*this);
		*this += 1;
		return result;
	}

	dynamic_mint operator--(int) {
		dynamic_mint result(*this);
		*this -= 1;
		return result;
	}

	template<typename T>
	explicit operator T() const {
		return T(val);
	}

	friend std::ostream &operator<<(std::ostream &os, const dynamic_mint &m) {
		return os << m.val;
	}

	friend std::istream &operator>>(std::istream &is, dynamic_mint &m) {
		long long x;
		return is >> x, m = x, is;
	}
};

int dynamic_mint::M;

template <int N>
struct sieve {
	std::vector<int> primes;
	std::array<int, N + 1> spf;

	constexpr sieve() : spf() {
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

	template <typename T, typename F>
	T compute_multiplicative_function(int x, F &&f) {
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

constexpr int N = 4 * 1000 * 1000;

sieve<N> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = dynamic_mint;

	int n, m;
	cin >> n >> m;

	mint::set_mod(m);

	vector<mint> dp(n + 1), pref(n + 1);
	dp[1] = 1;

	mint sum = 1, pref_sum = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			if (j / i >= i) {
				break;
			}
			pref[j] += dp[j / i];
			if (j + i <= n) {
				pref[j + i] -= dp[j / i];
			}
		}
		pref_sum += pref[i];
		dp[i] = sum + pref_sum;
		for (int k = 2;; k++) {
			int j = k * i;
			if (j > n || j / k < k) {
				break;
			}
			pref[j] += dp[i];
			if (j + k <= n) {
				pref[j + k] -= dp[i];
			}
		}
		sum += dp[i];
	}
	cout << dp[n] << '\n';
	return 0;
}