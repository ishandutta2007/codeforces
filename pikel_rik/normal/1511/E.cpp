#include <bits/stdc++.h>
using namespace std;

template<int M>
struct static_mint {
	static_assert(0 < M, "Module must be positive");

	int val;
	static_mint(): val() {}
	static_mint(long long x) : val(x % M) { if (val < 0) val += M; }
	static_mint pow(long long n) const { static_mint ans = 1, x(*this); while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
	static_mint inv() const { return pow(M - 2); }

	friend static_mint pow(const static_mint &m, long long n) { return m.pow(n); }
	friend static_mint inv(const static_mint &m) { return m.inv(); }

	static_mint operator+() const { static_mint m; m.val = val; return m; }
	static_mint operator-() const { static_mint m; m.val = M - val; return m; }
	static_mint &operator+=(const static_mint &m) { if ((val += m.val) >= M) val -= M; return *this; }
	static_mint &operator-=(const static_mint &m) { if ((val -= m.val) < 0) val += M; return *this; }
	static_mint &operator*=(const static_mint &m) { val = (long long) val * m.val % M; return *this; }
	static_mint &operator/=(const static_mint &m) { val = (long long) val * m.inv().val % M; return *this; }

	friend static_mint operator+ (const static_mint &lhs, const static_mint &rhs) { return static_mint(lhs) += rhs; }
	friend static_mint operator- (const static_mint &lhs, const static_mint &rhs) { return static_mint(lhs) -= rhs; }
	friend static_mint operator* (const static_mint &lhs, const static_mint &rhs) { return static_mint(lhs) *= rhs; }
	friend static_mint operator/ (const static_mint &lhs, const static_mint &rhs) { return static_mint(lhs) /= rhs; }
	friend bool operator==(const static_mint &lhs, const static_mint &rhs) { return lhs.val == rhs.val; }
	friend bool operator!=(const static_mint &lhs, const static_mint &rhs) { return lhs.val != rhs.val; }

	static_mint &operator++() { return *this += 1; }
	static_mint &operator--() { return *this -= 1; }
	static_mint operator++(int) { static_mint result(*this); *this += 1; return result; }
	static_mint operator--(int) { static_mint result(*this); *this -= 1; return result; }

	template <typename T> explicit operator T() const { return T(val); }

	friend std::ostream &operator<<(std::ostream &os, const static_mint &m) {
		return os << m.val;
	}

	friend std::istream &operator>>(std::istream &is, static_mint &m) {
		long long x; is >> x; m = x;
		return is;
	}
};

template <typename>
struct is_mint : public std::false_type { };

template <int M>
struct is_mint<static_mint<M>> : public std::true_type { };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = static_mint<998244353>;

	int n, m;
	cin >> n >> m;

	vector<string> a(n);
	for (auto &s : a) cin >> s;

	int w = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			w += a[i][j] == 'o';
		}
	}

	vector<mint> two(w + 1), inv(w + 1);
	two[0] = 1, inv[0] = 1;
	for (int i = 1; i <= w; i++) {
		two[i] = two[i - 1] + two[i - 1];
		inv[i] = two[i].inv();
	}

	vector<mint> lens(w + 1), dp(w + 1);

	for (int i = 1; i <= w; i++) {
		lens[i] = two[w - i] * (i / 2) + lens[i - 1];
	}

	mint sum = 0;
	for (int i = 1; i <= w; i++) {
		dp[i] = dp[i - 1] + (i / 2) + inv[w - i + 1] * lens[i - 1] + sum;
		sum += dp[i - 1];
	}

	mint ans = 0;
	for (int rot = 0; rot < 2; rot++) {
		for (int i = 0; i < n; i++) {
			int len = 0;
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '*') {
					ans += two[w - len] * dp[len];
					len = 0;
				} else {
					len += 1;
				}
			}
			ans += two[w - len] * dp[len];
		}
		swap(n, m);
		vector<string> new_a(n, string(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				new_a[i][j] = a[j][i];
			}
		}
		a.swap(new_a);
	}
	cout << ans << '\n';
	return 0;
}