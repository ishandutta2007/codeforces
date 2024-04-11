#include <bits/stdc++.h>
using namespace std;

namespace modular {
	template <typename>
	struct is_modular : std::false_type { };

	template<int M>
	struct static_mint {
		static_assert(0 < M, "Module must be positive");

		using mint = static_mint;
		constexpr static int get_mod() { return M; }

		int val;
		static_mint(): val() {}
		static_mint(long long x) : val(x % M) { if (val < 0) val += M; }
		mint pow(long long n) const { mint ans = 1, x(*this); while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
		mint inv() const { return pow(M - 2); }

		friend mint pow(const mint &m, long long n) { return m.pow(n); }
		friend mint inv(const mint &m) { return m.inv(); }

		mint operator+() const { mint m; m.val = val; return m; }
		mint operator-() const { mint m; m.val = M - val; return m; }
		mint &operator+=(const mint &m) { if ((val += m.val) >= M) val -= M; return *this; }
		mint &operator-=(const mint &m) { if ((val -= m.val) < 0) val += M; return *this; }
		mint &operator*=(const mint &m) { val = (long long) val * m.val % M; return *this; }
		mint &operator/=(const mint &m) { val = (long long) val * m.inv().val % M; return *this; }

		friend mint operator+ (const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
		friend mint operator- (const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
		friend mint operator* (const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
		friend mint operator/ (const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }
		friend bool operator==(const mint &lhs, const mint &rhs) { return lhs.val == rhs.val; }
		friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs.val != rhs.val; }

		mint &operator++() { return *this += 1; }
		mint &operator--() { return *this -= 1; }
		mint operator++(int) { mint result(*this); *this += 1; return result; }
		mint operator--(int) { mint result(*this); *this -= 1; return result; }

		template <typename T> explicit operator T() const { return T(val); }

		friend std::ostream &operator<<(std::ostream &os, const mint &m) {
			return os << m.val;
		}

		friend std::istream &operator>>(std::istream &is, mint &m) {
			long long x; is >> x; m = x;
			return is;
		}
	};

	template <int M>
	struct is_modular<static_mint<M>> : std::true_type { };

	struct dynamic_mint {
		static int M;
		static void set_mod(int m) { assert(0 < m); M = m; }
		static int get_mod() { return M; }

		using mint = dynamic_mint;

		int val;
		dynamic_mint(): val() {}
		dynamic_mint(long long x) : val(x % M) { if (val < 0) { val += M; } }
		mint pow(long long n) const { mint ans = 1, x(*this); while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
		mint inv() const { return pow(M - 2); }

		friend mint pow(const mint &m, long long n) { return m.pow(n); }
		friend mint inv(const mint &m) { return m.inv(); }

		mint operator+() const { mint m; m.val = val; return m; }
		mint operator-() const { mint m; m.val = M - val; return m; }
		mint &operator+=(const mint &m) { if ((val += m.val) >= M) val -= M; return *this; }
		mint &operator-=(const mint &m) { if ((val -= m.val) < 0) val += M; return *this; }
		mint &operator*=(const mint &m) { val = (long long) val * m.val % M; return *this; }
		mint &operator/=(const mint &m) { val = (long long) val * m.inv().val % M; return *this; }

		friend mint operator+ (const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
		friend mint operator- (const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
		friend mint operator* (const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
		friend mint operator/ (const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }
		friend bool operator==(const mint &lhs, const mint &rhs) { return lhs.val == rhs.val; }
		friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs.val != rhs.val; }

		mint &operator++() { return *this += 1; }
		mint &operator--() { return *this -= 1; }
		mint operator++(int) { mint result(*this); *this += 1; return result; }
		mint operator--(int) { mint result(*this); *this -= 1; return result; }

		template <typename T> explicit operator T() const { return T(val); }

		friend std::ostream &operator<<(std::ostream &os, const mint &m) {
			return os << m.val;
		}

		friend std::istream &operator>>(std::istream &is, mint &m) {
			long long x; is >> x; m = x;
			return is;
		}
	};

	int dynamic_mint::M;

	template <>
	struct is_modular<dynamic_mint> : std::true_type { };
}

namespace string_hashing {
	template <int B, int M>
	struct rolling_hash {
		using mint = modular::static_mint<M>;

		static std::vector<mint> pw, inv_pw;
		std::vector<mint> pref;

		rolling_hash() { }
		rolling_hash(const std::string &s) : pref(s.size()) {
			assert(!s.empty());
			while (pw.size() < s.size()) {
				pw.push_back(B * pw.back());
				inv_pw.push_back(pw.back().inv());
			}
			pref[0] = s[0] - 'a' + 1;
			for (int i = 1; i < s.size(); i++) {
				pref[i] = pw[i] * (s[i] - 'a' + 1) + pref[i - 1];
			}
		}

		mint substr(int i, int j) const {
			return (pref[j] - (i == 0 ? 0 : pref[i - 1])) * inv_pw[i];
		}

		mint operator()() const {
			return pref.back();
		}
	};

	template <int B, int M>
	std::vector<modular::static_mint<M>> rolling_hash<B, M>::pw(1, 1);

	template <int B, int M>
	std::vector<modular::static_mint<M>> rolling_hash<B, M>::inv_pw(1, 1);

	template <int B1, int M1, int B2, int M2>
	struct double_rolling_hash {
		using mint1 = modular::static_mint<M1>;
		using mint2 = modular::static_mint<M2>;

		rolling_hash<B1, M1> h1;
		rolling_hash<B2, M2> h2;

		double_rolling_hash(const std::string &s) : h1(s), h2(s) { }

		std::pair<mint1, mint2> substr(int i, int j) const {
			return std::make_pair(h1.substr(i, j), h2.substr(i, j));
		}

		std::pair<mint1, mint2> operator()() const {
			return std::make_pair(h1.pref.back(), h2.pref.back());
		}
	};
}

constexpr int mod = 1000000007, hash_mod = 539873869;
using mint = modular::static_mint<mod>;
using str_hash = string_hashing::rolling_hash<31, hash_mod>;

int n, q, lg;
string s0, t, t_s[21], x;
mint two[100001], inv_two[100001], pref[100001][26], dp[500003][22];
str_hash hash_t[21], hash_x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	two[0] = 1, two[1] = 2;
	inv_two[0] = 1, inv_two[1] = two[1].inv();
	for (int i = 2; i < 100001; i++) {
		two[i] = two[i - 1] + two[i - 1];
		inv_two[i] = inv_two[1] * inv_two[i - 1];
	}

	cin >> n >> q;
	cin >> s0 >> t;

	lg = min(n + 1, 21);
	for (int i = 1; i < lg; i++) {
		t_s[i] = t_s[i - 1] + t[i - 1] + t_s[i - 1];
		hash_t[i] = str_hash(t_s[i]);
	}

	for (int i = lg; i <= n; i++) {
		copy(pref[i - 1], pref[i - 1] + 26, pref[i]);
		pref[i][t[i - 1] - 'a'] += two[n - i];
	}

	while (q--) {
		int k;
		cin >> k;

		string w;
		cin >> w;

		mint ans = 0;
		for (int st = 0; st <= int(s0.length()); st++) {
			bool matched = true;
			x.clear();
			for (int j = 0, i = st; j < int(w.length()); j++) {
				if (i == s0.length()) {
					x += w[j], i = 0;
				} else {
					matched &= w[j] == s0[i++];
				}
			}

			if (matched) {
				if (x.empty()) {
					ans += two[k];
				} else {
					hash_x = str_hash(x);
					int m = int(x.length());
					for (int i = (int)m - 1; i >= 0; i--) {
						for (int j = 0; j <= lg; j++) {
							dp[i][j] = 0;
						}
						if (k >= 1 && x[i] == t[0]) {
							if (i + 1 != m) {
								dp[i][1] += dp[i + 1][2];
							} else {
								dp[i][1] = two[k - 1];
							}
						}
						for (int j = 2; j < lg; j++) {
							if (k < j) {
								continue;
							}
							int len = t_s[j - 1].length();
							if (i + 1 == m) {
								if (x[i] == t[j - 1]) {
									dp[i][j] = two[k - j];
								}
							} else if (i + 1 + len >= m) {
								if (x[i] == t[j - 1] && hash_x.substr(i + 1, m - 1) == hash_t[j - 1].substr(0, m - i - 2)) {
									dp[i][j] = two[k - j];
								}
							} else {
								if (x[i] == t[j - 1] && hash_x.substr(i + 1, i + len) == hash_t[j - 1]()) {
									dp[i][j] += dp[i + len + 1][j + 1];
								}
							}
						}
						if (k >= lg) {
							if (i + 1 == m) {
								dp[i][lg] = pref[k][x[i] - 'a'] * inv_two[n - k];
							} else if (hash_x.substr(i + 1, m - 1) == hash_t[lg - 1].substr(0, m - i - 2)) {
								dp[i][lg] = pref[k][x[i] - 'a'] * inv_two[n - k];
							}
						}
						for (int j = lg - 1; j >= 0; j--) {
							dp[i][j] += dp[i][j + 1];
						}
					}
					ans += dp[0][0];
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}