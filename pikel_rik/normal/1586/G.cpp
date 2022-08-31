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

template<typename T>
struct fenwick_tree {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<T> bit;
	F f;

	fenwick_tree() : n(), f() {}
	fenwick_tree(int n, F f = plus<T>()) : n(n), bit(n + 1, 0), f(f) {}

	void add(int i, T val) {
		for (++i; i <= n; i += i & -i) {
			bit[i] = f(bit[i], val);
		}
	}

	T query(int i) {
		T ans = 0;
		for (++i; i; i -= i & -i) {
			ans = f(ans, bit[i]);
		}
		return ans;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i], --a[i], --b[i];
	}

	vector<int> ind(n);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [&](int i, int j) {
		return b[i] < b[j];
	});

	using mint = static_mint<1000000007>;

	vector<mint> dp1(n), dp2(n);
	fenwick_tree<mint> ft(2 * n);

	for (int ii = 0; ii < n; ii++) {
		//want to compute two parameters
		//want to compute dp1[i] which is the minimum number of time travels to complete the ith task for the first time
		//want to compute dp2[i] which is the minimum number of time travels to go to bi + 1
		int i = ind[ii], j = (ii != 0 ? ind[ii - 1] : -1);
		if (ii == 0) {
			dp1[i] = 1;
		} else {
			dp1[i] = dp1[j] + dp2[j] + 1;
		}
		dp2[i] = ft.query(b[i]) - ft.query(a[i]);
		ft.add(a[i], 1 + dp2[i]);
//		cout << i + 1 << ' ' << a[i] << ' ' << b[i] << ' ' << dp1[i] << ' ' << dp2[i] << '\n';
	}

	int t;
	cin >> t;

	vector<int> s(t);
	for (int i = 0; i < t; i++) {
		cin >> s[i], --s[i];
	}

	sort(s.begin(), s.end(), [&](int i, int j) {
		return b[i] > b[j];
	});

	mint ans = 0;

	int j = n - 1, covered = -1;
	for (int i : s) {
		while (j >= 0 && b[ind[j]] >= b[i]) {
			ft.add(a[ind[j]], -(1 + dp2[ind[j]]));
			j -= 1;
		}
		if (a[i] > covered) {
			ans += 1 + ft.query(b[i]) - (covered == -1 ? 0 : ft.query(covered));
			covered = a[i];
		}
	}

	cout << ans << '\n';
	return 0;
}