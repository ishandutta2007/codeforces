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

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		vector<array<long long, 2>> pref(n);
		pref[0][0] = a[0];

		for (int i = 1; i < n; i++) {
			pref[i] = pref[i - 1];
			pref[i][i % 2] += a[i];
		}

		auto sum = [&](int l, int r, int i = -1) -> long long {
			if (i == -1) {
				long long ans = pref[r][0] + pref[r][1];
				if (l > 0) ans -= pref[l - 1][0] + pref[l - 1][1];
				return ans;
			} else {
				long long ans = pref[r][i];
				if (l > 0) ans -= pref[l - 1][i];
				return ans;
			}
		};

		mint ans = 1;
		for (int st : {0, 1}) {
			for (int i = st; i < n; i++) {
				if (2 * sum(st, i) >= sum(0, n - 1)) {
					break;
				}
				int lo = 0, hi = n;
				while (lo < hi) {
					int mid = lo + (hi - lo + 1) / 2;
					if (i + 2 * mid >= n) {
						hi = mid - 1;
						continue;
					}
					long long now = sum(st, i + 2 * mid) - sum(i + 1, i + 2 * mid, 1 - i % 2);
					if (2 * now < sum(0, n - 1)) {
						lo = mid;
					} else hi = mid - 1;
				}

				ans += 1 + lo;

				if (2 * (sum(st, i) + a[n - 1]) >= sum(0, n - 1) || i >= n - 3) {
					continue;
				}

				lo = 0, hi = n;
				while (lo < hi) {
					int mid = lo + (hi - lo + 1) / 2;
					if (i + 2 * mid > n - 4) {
						hi = mid - 1;
						continue;
					}
					long long now = sum(st, i + 2 * mid) - sum(i + 1, i + 2 * mid, 1 - i % 2) + a[n - 1];
					if (2 * now < sum(0, n - 1)) {
						lo = mid;
					} else hi = mid - 1;
				}

				ans += 1 + lo;
			}
		}

		for (int i = n - 1; i > 1; i--) {
			ans += 2 * sum(i, n - 1) < sum(0, n - 1);
		}

		cout << ans << '\n';
	}
	return 0;
}