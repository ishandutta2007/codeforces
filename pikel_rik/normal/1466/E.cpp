#include <bits/stdc++.h>
using namespace std;

namespace modular {
	template <typename>
	struct is_modular : std::false_type { };

	template<int M>
	struct static_mint {
		static_assert(0 < M, "Module must be positive");

		using mint = static_mint;
		inline constexpr static int get_mod() { return M; }

		int val;
		static_mint(): val() {}
		static_mint(long long x) : val(x % M) { if (val < 0) val += M; }
		inline mint pow(long long n) const { mint ans = 1, x(*this); while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
		inline mint inv() const { return pow(M - 2); }

		inline friend mint pow(const mint &m, long long n) { return m.pow(n); }
		inline friend mint inv(const mint &m) { return m.inv(); }

		inline mint operator+() const { mint m; m.val = val; return m; }
		inline mint operator-() const { mint m; m.val = M - val; return m; }
		inline mint &operator+=(const mint &m) { if ((val += m.val) >= M) val -= M; return *this; }
		inline mint &operator-=(const mint &m) { if ((val -= m.val) < 0) val += M; return *this; }
		inline mint &operator*=(const mint &m) { val = (long long) val * m.val % M; return *this; }
		inline mint &operator/=(const mint &m) { val = (long long) val * m.inv().val % M; return *this; }

		inline friend mint operator+ (const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
		inline friend mint operator- (const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
		inline friend mint operator* (const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
		inline friend mint operator/ (const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }
		inline friend bool operator==(const mint &lhs, const mint &rhs) { return lhs.val == rhs.val; }
		inline friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs.val != rhs.val; }

		inline mint &operator++() { return *this += 1; }
		inline mint &operator--() { return *this -= 1; }
		inline mint operator++(int) { mint result(*this); *this += 1; return result; }
		inline mint operator--(int) { mint result(*this); *this -= 1; return result; }

		template <typename T> inline explicit operator T() const { return T(val); }

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	constexpr int mod = 1'000'000'007;
	using mint = modular::static_mint<mod>;

	vector<mint> two = {1};
	while (two.size() < 200) {
		two.push_back(two.back() * 2);
	}

	auto choose2 = [&](long long x) -> long long {
		return (x * x - x) / 2;
	};

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<long long> a(n);
		vector<int> cnt(60);
		for (auto &x : a) {
			cin >> x;
			for (int j = 0; j < 60; j++) {
				if (x & (1ll << j)) {
					cnt[j] += 1;
				}
			}
		}

		mint ans = 0;
		for (auto &x : a) {
			mint term1 = 0, term2 = 0;
			for (int j = 0; j < 60; j++) {
				if (x & (1ll << j)) {
					term1 += cnt[j] * two[j];
					term2 += n * two[j];
				} else {
					term2 += cnt[j] * two[j];
				}
			}
			ans += term1 * term2;
		}
		cout << ans << '\n';
	}
	return 0;
}