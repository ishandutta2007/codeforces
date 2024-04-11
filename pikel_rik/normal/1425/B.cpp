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

struct union_find {
	int n, c;
	std::vector<int> p, r;

	union_find() : n(), c() {}
	union_find(int n) : n(n), c(n), p(n), r(n, 1) {
		std::iota(p.begin(), p.end(), 0);
	}

	int count() const noexcept {
		return c;
	}

	int find(int x) {
		return x == p[x] ? x : p[x] = find(p[x]);
	}

	bool merge(int x, int y) {
		int l1 = find(x);
		int l2 = find(y);
		if (l1 == l2) {
			return false;
		}
		if (r[l1] >= r[l2]) {
			r[l1] += r[l2];
			p[l2] = l1;
		} else {
			p[l1] = l2;
			r[l2] += r[l1];
		}
		c -= 1;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = static_mint<1000000007>;

	int n, m;
	cin >> n >> m;

	union_find uf(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v, --u, --v;
		if (u != 0 && v != 0) {
			uf.merge(u, v);
		}
	}

	vector<int> cycles;
	for (int u = 1; u < n; u++) {
		if (uf.p[u] == u) {
			cycles.push_back(uf.r[u] + 1);
		}
	}

	auto augment1 = [&](int l, int r, vector<mint> dp) -> vector<mint> {
		vector<mint> new_dp(2 * m + 1);
		for (int i = l; i <= r; i++) {
			for (int j = 0; j <= 2 * m; j++) {
				if (j - cycles[i] >= 0) {
					new_dp[j - cycles[i]] += dp[j];
				}
				if (j + cycles[i] <= 2 * m) {
					new_dp[j + cycles[i]] += dp[j];
				}
			}
			for (int j = 0; j <= 2 * m; j++) {
				dp[j] += new_dp[j];
				new_dp[j] = 0;
			}
		}
		return dp;
	};

	auto augment2 = [&](int l, int r, vector<mint> dp) -> vector<mint> {
		vector<mint> new_dp(2 * m + 1);
		for (int i = l; i <= r; i++) {
			for (int j = 0; j <= 2 * m; j++) {
				if (j - cycles[i] >= 0) {
					new_dp[j - cycles[i]] += dp[j];
				}
				if (j + cycles[i] <= 2 * m) {
					new_dp[j + cycles[i]] += dp[j];
				}
			}
			for (int j = 0; j <= 2 * m; j++) {
				dp[j] = new_dp[j];
				new_dp[j] = 0;
			}
		}
		return dp;
	};

	mint ans = 0;
	auto recurse = [&](int l, int r, const vector<mint> &dp1, const vector<mint> &dp2, const auto &self) -> void {
		if (l == r) {
			for (int i = 1; i < cycles[l]; i++) {
				int diff = i - (cycles[l] - i);
				ans += dp1[m + diff] + dp1[m - diff];
			}
			for (int i = 0; i < cycles[l]; i++) {
				int diff = i - (cycles[l] - i - 1);
				if (i == 0 || i + 1 == cycles[l]) {
					ans += dp2[m + diff] + dp2[m - diff];
				} else {
					ans += dp1[m + diff] + dp1[m - diff];
				}
			}
		} else {
			int mid = (l + r) >> 1;
			self(l, mid, augment1(mid + 1, r, dp1), augment2(mid + 1, r, dp2), self);
			self(mid + 1, r, augment1(l, mid, dp1), augment2(l, mid, dp2), self);
		}
	};

	int sz = (int) cycles.size();

	vector<mint> init_dp(2 * m + 1);
	init_dp[m + 0] = 1;

	recurse(0, sz - 1, init_dp, init_dp, recurse);

	vector<mint> dp = augment2(0, sz - 1, init_dp);
	ans += dp[m + 0];
	cout << ans << '\n';
	return 0;
}