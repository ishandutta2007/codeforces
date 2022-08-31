#include <bits/stdc++.h>
using namespace std;

template<int M>
struct static_mint {
	static_assert(0 < M, "Module must be positive");

	int val;

	constexpr static_mint() : val() {}

	constexpr static_mint(long long x) : val(x % M) { if (val < 0) val += M; }

	constexpr static_mint pow(long long n) const {
		static_mint ans = 1, x(*this);
		for (; n > 0; n /= 2) {
			if (n & 1) ans *= x;
			x *= x;
		}
		return ans;
	}

	constexpr static_mint inv() const {
		return pow(M - 2);
	}

	constexpr static_mint operator+() const {
		static_mint m;
		m.val = val;
		return m;
	}

	constexpr static_mint operator-() const {
		static_mint m;
		m.val = (val == 0 ? 0 : M - val);
		return m;
	}

	constexpr static_mint &operator+=(const static_mint &m) {
		if ((val += m.val) >= M) val -= M;
		return *this;
	}

	constexpr static_mint &operator-=(const static_mint &m) {
		if ((val -= m.val) < 0) val += M;
		return *this;
	}

	constexpr static_mint &operator*=(const static_mint &m) {
		val = (long long) val * m.val % M;
		return *this;
	}

	constexpr static_mint &operator/=(const static_mint &m) {
		val = (long long) val * m.inv().val % M;
		return *this;
	}

	constexpr friend static_mint operator+(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) += rhs;
	}

	constexpr friend static_mint operator-(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) -= rhs;
	}

	constexpr friend static_mint operator*(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) *= rhs;
	}

	constexpr friend static_mint operator/(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) /= rhs;
	}

	constexpr friend bool operator==(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val == rhs.val;
	}

	constexpr friend bool operator!=(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val != rhs.val;
	}

	constexpr static_mint &operator++() {
		return *this += 1;
	}

	constexpr static_mint &operator--() {
		return *this -= 1;
	}

	constexpr static_mint operator++(int) {
		static_mint result(*this);
		*this += 1;
		return result;
	}

	constexpr static_mint operator--(int) {
		static_mint result(*this);
		*this -= 1;
		return result;
	}

	template<typename T>
	constexpr explicit operator T() const {
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

	int t;
	cin >> t;

	constexpr int N = 200000 + 5;

	vector<mint> fact(N + 1); fact[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = i * fact[i - 1];
	}

	vector<mint> inv(N + 1);
	for (int i = 0; i <= N; i++) {
		inv[i] = fact[i].inv();
	}

	auto C = [&](int n, int k) -> mint {
		return fact[n] * inv[k] * inv[n - k];
	};

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		int mx = *max_element(a.begin(), a.end());
		int cnt = count(a.begin(), a.end(), mx);

		if (cnt == 1) {
			int cnt_less = count(a.begin(), a.end(), mx - 1);
			if (cnt_less == 0) {
				cout << 0 << '\n';
			} else {
				mint ans = 0;

				map<int, int> mp;
				for (int i = 0; i < n; i++) {
					if (a[i] < mx - 1) {
						mp[a[i]] += 1;
					}
				}

				for (int last = 0; last < n; last++) {
					if (last + 1 <= cnt_less) {
						continue;
					}
					int left = last + 1 - cnt_less;
					ans += fact[n - 1 - cnt_less] * C(last, cnt_less - 1) * fact[cnt_less] * left;
				}
				cout << ans << '\n';
			}
		} else {
			cout << fact[n] << '\n';
		}
	}
	return 0;
}