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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<string> a(n);
	for (auto &x : a) cin >> x;

	int m = a[0].length();

	const int sq = 1000;

	if (n <= sq) {
		int ans = 0;
		vector<vector<int>> freq(n, vector<int>(26));

		for (int i = 0; i < n; i++) {
			for (auto &ch : a[i]) {
				freq[i][ch - 'a']++;
			}
			for (int j = 0; j < i; j++) {
				if (freq[i] != freq[j]) {
					ans += 1337;
				} else {
					int pref = 0, suf = m - 1;
					for (; a[i][pref] == a[j][pref]; pref++);
					for (; a[i][suf] == a[j][suf]; suf--);

					if (is_sorted(a[i].begin() + pref, a[i].begin() + suf + 1)) {
						ans += 1;
					} else if (is_sorted(a[j].begin() + pref, a[j].begin() + suf + 1)) {
						ans += 1;
					} else {
						ans += 2;
					}
				}
			}
		}
		cout << ans << '\n';
	} else {
		constexpr int mod = 856803667;
		constexpr int base = 43;
		using mint = static_mint<mod>;

		constexpr int mod1 = 998244353;
		constexpr int base1 = 123;
		using mint1 = static_mint<mod1>;

		vector<mint> pw(m + 1), inv(m + 1);
		pw[0] = inv[0] = 1;

		for (int i = 1; i <= m; i++) {
			pw[i] = base * pw[i - 1];
			inv[i] = pw[i].inv();
		}

		vector<mint1> pw1(m + 1), inv1(m + 1);
		pw1[0] = inv1[0] = 1;

		for (int i = 1; i <= m; i++) {
			pw1[i] = base1 * pw1[i - 1];
			inv1[i] = pw1[i].inv();
		}

		long long ans = 0;
		vector<vector<mint>> pref(n, vector<mint>(m));
		vector<vector<mint1>> pref1(n, vector<mint1>(m));

		map<array<int, 26>, pair<int, vector<vector<vector<pair<int, int>>>>>> mp;

		for (int i = 0; i < n; i++) {
			array<int, 26> freq = {};
			for (auto &ch : a[i]) {
				freq[ch - 'a']++;
			}

			auto &mp_elem = mp[freq];
			ans += 1337ll * (i - mp_elem.first) + 2 * mp_elem.first;
			mp_elem.first += 1;
			if (mp_elem.second.empty()) {
				mp_elem.second.assign(m, vector<vector<pair<int, int>>>(m));
			}

			for (int j = 0; j < m; j++) {
				pref[i][j] = (a[i][j] - 'a' + 1) * pw[j];
				pref[i][j] += (j == 0 ? 0 : pref[i][j - 1]);
			}

			for (int j = 0; j < m; j++) {
				pref1[i][j] = (a[i][j] - 'a' + 1) * pw1[j];
				pref1[i][j] += (j == 0 ? 0 : pref1[i][j - 1]);
			}

			for (int j = 0; j < m; j++) {
				bool sorted = true;
				for (int k = j + 1; k < m; k++) {
					sorted &= a[i][k] >= a[i][k - 1];
					mint val = 0;
					val += (j == 0 ? 0 : pref[i][j - 1]);
					val += (k + 1 == m ? 0 : (pref[i][m - 1] - pref[i][k]) * inv[k - j + 1]);
					mint1 val1 = 0;
					val1 += (j == 0 ? 0 : pref1[i][j - 1]);
					val1 += (k + 1 == m ? 0 : (pref1[i][m - 1] - pref1[i][k]) * inv1[k - j + 1]);
					if (sorted) {
						mp_elem.second[j][k].emplace_back(val.val, val1.val);
					}
				}
			}
		}

		for (auto &[freq, mp_elem] : mp) {
			for (int j = 0; j < m; j++) {
				for (int k = j; k < m; k++) {
					sort(mp_elem.second[j][k].begin(), mp_elem.second[j][k].end());
				}
			}
		}

		for (int i = 0; i < n; i++) {
			array<int, 26> freq = {};
			for (auto &ch : a[i]) {
				freq[ch - 'a']++;
			}

			auto &mp_elem = mp[freq];
			for (int j = 0; j < m; j++) {
				char mn = a[i][j], mx = a[i][j];
				for (int k = j + 1; k < m; k++) {
					mn = min(mn, a[i][k]);
					mx = max(mx, a[i][k]);
					mint val = 0;
					val += (j == 0 ? 0 : pref[i][j - 1]);
					val += (k + 1 == m ? 0 : (pref[i][m - 1] - pref[i][k]) * inv[k - j + 1]);
					mint1 val1 = 0;
					val1 += (j == 0 ? 0 : pref1[i][j - 1]);
					val1 += (k + 1 == m ? 0 : (pref1[i][m - 1] - pref1[i][k]) * inv1[k - j + 1]);
					if (mn != a[i][j] && mx != a[i][k]) {
						ans -= binary_search(mp_elem.second[j][k].begin(), mp_elem.second[j][k].end(), make_pair(val.val, val1.val));
					}
				}
			}
		}

		cout << ans << '\n';
	}
	return 0;
}