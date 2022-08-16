#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

namespace modular {
	template <typename>
	struct is_modular : std::false_type { };

	template <typename>
	struct modulus : std::integral_constant<int, 0> { };

	template<int M>
	struct static_mint {
		static_assert(0 < M, "Module M must be positive");

		int val;
		static_mint(): val() {}
		static_mint(long long x) : val(x % M) { if (val < 0) { val += M; } }
		static_mint pow(long long n) const { static_mint ans = 1, x = val; while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
		static_mint inv() const { return pow(M - 2); }

		static_mint operator+() const { static_mint m; m.val = val; return m; }
		static_mint operator-() const { static_mint m; m.val = M - val; return m; }
		static_mint &operator+=(const static_mint &m) { if ((val += m.val) >= M) val -= M; return *this; }
		static_mint &operator-=(const static_mint &m) { if ((val -= m.val) < 0) val += M; return *this; }
		static_mint &operator*=(const static_mint &m) { val = (long long) val * m.val % M; return *this; }
		static_mint &operator/=(const static_mint &m) { val = (long long) val * m.inv().val % M; return *this; }

		friend static_mint operator+ (static_mint lhs, const static_mint &rhs) { lhs += rhs; return lhs; }
		friend static_mint operator- (static_mint lhs, const static_mint &rhs) { lhs -= rhs; return lhs; }
		friend static_mint operator* (static_mint lhs, const static_mint &rhs) { lhs *= rhs; return lhs; }
		friend static_mint operator/ (static_mint lhs, const static_mint &rhs) { lhs /= rhs; return lhs; }
		friend static_mint operator==(static_mint lhs, const static_mint &rhs) { return lhs.val == rhs.val; }
		friend static_mint operator!=(static_mint lhs, const static_mint &rhs) { return lhs.val != rhs.val; }

		static_mint &operator++() { return *this += 1; }
		static_mint &operator--() { return *this -= 1; }
		static_mint operator++(int) { static_mint result(*this); *this += 1; return result; }
		static_mint operator--(int) { static_mint result(*this); *this -= 1; return result; }

		template <typename T> explicit operator T() const { return T(val); }

		friend std::ostream &operator<<(std::ostream &os, const static_mint &m) {
			os << m.val;
			return os;
		}

		friend std::istream &operator>>(std::istream &is, static_mint &m) {
			long long x; is >> x; m = x;
			return is;
		}
	};

	template <int M>
	struct is_modular<static_mint<M>> : std::true_type { };

	template <int M>
	struct modulus<static_mint<M>> : std::integral_constant<int, M> { };

	struct dynamic_mint {
		static int M;
		static void set_mod(int m) { assert(0 < m); M = m; }

		int val;
		dynamic_mint(): val() {}
		dynamic_mint(long long x) : val(x % M) { if (val < 0) { val += M; } }
		dynamic_mint pow(long long n) const { dynamic_mint ans = 1, x = val; while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
		dynamic_mint inv() const { return pow(M - 2); }

		dynamic_mint operator+() const { dynamic_mint m; m.val = val; return m; }
		dynamic_mint operator-() const { dynamic_mint m; m.val = M - val; return m; }
		dynamic_mint &operator+=(const dynamic_mint &m) { if ((val += m.val) >= M) val -= M; return *this; }
		dynamic_mint &operator-=(const dynamic_mint &m) { if ((val -= m.val) < 0) val += M; return *this; }
		dynamic_mint &operator*=(const dynamic_mint &m) { val = (long long) val * m.val % M; return *this; }
		dynamic_mint &operator/=(const dynamic_mint &m) { val = (long long) val * m.inv().val % M; return *this; }

		friend dynamic_mint operator+ (dynamic_mint lhs, const dynamic_mint &rhs) { lhs += rhs; return lhs; }
		friend dynamic_mint operator- (dynamic_mint lhs, const dynamic_mint &rhs) { lhs -= rhs; return lhs; }
		friend dynamic_mint operator* (dynamic_mint lhs, const dynamic_mint &rhs) { lhs *= rhs; return lhs; }
		friend dynamic_mint operator/ (dynamic_mint lhs, const dynamic_mint &rhs) { lhs /= rhs; return lhs; }
		friend dynamic_mint operator==(dynamic_mint lhs, const dynamic_mint &rhs) { return lhs.val == rhs.val; }
		friend dynamic_mint operator!=(dynamic_mint lhs, const dynamic_mint &rhs) { return lhs.val != rhs.val; }

		dynamic_mint &operator++() { return *this += 1; }
		dynamic_mint &operator--() { return *this -= 1; }
		dynamic_mint operator++(int) { dynamic_mint result(*this); *this += 1; return result; }
		dynamic_mint operator--(int) { dynamic_mint result(*this); *this -= 1; return result; }

		template <typename T> explicit operator T() const { return T(val); }

		friend std::ostream &operator<<(std::ostream &os, const dynamic_mint &m) {
			os << m.val;
			return os;
		}

		friend std::istream &operator>>(std::istream &is, dynamic_mint &m) {
			long long x; is >> x; m = x;
			return is;
		}
	};

	int dynamic_mint::M;

	template <>
	struct is_modular<dynamic_mint> : std::true_type { };
}

using mint = modular::static_mint<1000000007>;

vector<mint> fact = {1}, inv = {1};

mint C(int n, int k) {
    while (fact.size() <= n) {
        fact.push_back(int(fact.size()) * fact.back());
        inv.push_back(fact.back().inv());
    }
	return fact[n] * inv[n - k] * inv[k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<int> a(n), cnt(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[--a[i]]++;
		}

		vector<int> pref(cnt.begin(), cnt.end());
		for (int i = 1; i < n; i++) pref[i] += pref[i - 1];

		mint ans = 0;
		for (int i = 0; i < n; i++) {
			int temp = pref[min(n - 1, i + k)]  - pref[i];
			for (int j = 1; j <= min(m, cnt[i]); j++) {
				if (temp >= m - j) {
					ans += C(cnt[i], j) * C(temp, m - j);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}