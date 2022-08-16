#include <bits/stdc++.h>
using namespace std;

template<int M>
struct static_mint {
	static_assert(0 < M, "Module must be positive");

	int val;

	static_mint() : val() {}

	static_mint(long long x) : val(x % M) { if (val < 0) val += M; }

	static_mint pow(long long n) const {
		static_mint ans = 1, x(*this);
		for (; n > 0; n /= 2) {
			if (n & 1) ans *= x;
			x *= x;
		}
		return ans;
	}

	static_mint inv() const {
		return pow(M - 2);
	}

	static_mint operator+() const {
		static_mint m;
		m.val = val;
		return m;
	}

	static_mint operator-() const {
		static_mint m;
		m.val = (val == 0 ? 0 : M - val);
		return m;
	}

	static_mint &operator+=(const static_mint &m) {
		if ((val += m.val) >= M) val -= M;
		return *this;
	}

	static_mint &operator-=(const static_mint &m) {
		if ((val -= m.val) < 0) val += M;
		return *this;
	}

	static_mint &operator*=(const static_mint &m) {
		val = (long long) val * m.val % M;
		return *this;
	}

	static_mint &operator/=(const static_mint &m) {
		val = (long long) val * m.inv().val % M;
		return *this;
	}

	friend static_mint operator+(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) += rhs;
	}

	friend static_mint operator-(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) -= rhs;
	}

	friend static_mint operator*(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) *= rhs;
	}

	friend static_mint operator/(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) /= rhs;
	}

	friend bool operator==(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val == rhs.val;
	}

	friend bool operator!=(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val != rhs.val;
	}

	static_mint &operator++() {
		return *this += 1;
	}

	static_mint &operator--() {
		return *this -= 1;
	}

	static_mint operator++(int) {
		static_mint result(*this);
		*this += 1;
		return result;
	}

	static_mint operator--(int) {
		static_mint result(*this);
		*this -= 1;
		return result;
	}

	template<typename T>
	explicit operator T() const {
		return T(val);
	}

	friend std::ostream &operator<<(std::ostream &os, const static_mint &m) {
		return os << m.val;
	}

	friend std::istream &operator>>(std::istream &is, static_mint &m) {
		long long x;
		return is >> x, m = x, is;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = static_mint<1000000007>;

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<vector<mint>> win(n, vector<mint>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				win[i][j] = mint(a[i]) / (a[i] + a[j]);
			}
		}
	}

	vector<vector<mint>> all_win(n, vector<mint>(1 << n));
	for (int u = 0; u < n; u++) {
		for (int mask = 0; mask < (1 << n); mask++) {
			if (mask >> u & 1) {
				continue;
			}
			all_win[u][mask] = 1;
			for (int v = 0; v < n; v++) {
				if (mask >> v & 1) {
					all_win[u][mask] *= win[u][v];
				}
			}
		}
	}

	//dp[mask] = probability that it forms a dag

	vector<mint> dp(1 << n);
	for (int mask = 0; mask < (1 << n); mask++) {
		if (__builtin_popcount(mask) <= 1) {
			dp[mask] = 0;
		}
		for (int s = mask; s != 0; s = (s - 1) & mask) {
			if (s != mask) {
				mint p = 1;
				for (int v = 0; v < n; v++) {
					if (s >> v & 1) {
						p *= all_win[v][s ^ mask];
					}
				}
				dp[mask] += (1 - dp[s]) * p;
			}
		}
	}

	mint ans = 0;
	for (int mask = 1; mask < (1 << n); mask++) {
		mint p = 1;
		for (int u = 0; u < n; u++) {
			if (mask >> u & 1) {
				for (int v = 0; v < n; v++) {
					if (!(mask >> v & 1)) {
						p *= win[u][v];
					}
				}
			}
		}
		ans += __builtin_popcount(mask) * (1 - dp[mask]) * p;
	}
	cout << ans << '\n';
	return 0;
}