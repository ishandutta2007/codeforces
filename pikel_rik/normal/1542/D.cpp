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

	using mint = static_mint<998244353>;

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == '-') {
			a[i] = -1;
		} else {
			cin >> a[i];
		}
	}

	vector<int> b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	mint ans = 0;
	for (auto x : b) {
		if (x == -1) {
			continue;
		}
		int cnt = count(a.begin(), a.end(), x);

		vector<vector<mint>> dp0(n - cnt + 1, vector<mint>(cnt + 1));
		vector<vector<mint>> dp1(n - cnt + 1, vector<mint>(cnt + 1));
		for (int smaller = 0; smaller <= n - cnt; smaller++) {
			for (int same = 0; same <= cnt; same++) {
				dp0[smaller][same] = dp1[smaller][same] = same;
			}
		}

		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j <= n - cnt; j++) {
				for (int k = 0; k <= cnt; k++) {
					if (a[i] == -1) {
						if (j > 0) {
							dp1[j][k] += dp0[j - 1][k];
						} else if (k > 0) {
							dp1[j][k] += dp0[j][k - 1];
						} else {
							dp1[j][k] += dp0[j][k];
						}
					} else {
						if (a[i] < x && j + 1 <= n - cnt) {
							dp1[j][k] += dp0[j + 1][k];
						} else if (a[i] == x && k + 1 <= cnt) {
							dp1[j][k] += dp0[j][k + 1];
						} else if (a[i] > x) {
							dp1[j][k] += dp0[j][k];
						}
					}
				}
			}
			for (int j = 0; j <= n - cnt; j++) {
				for (int k = 0; k <= cnt; k++) {
					dp0[j][k] = dp1[j][k];
				}
			}
		}
		ans += x * dp0[0][0];
	}
	cout << ans << '\n';
	return 0;
}