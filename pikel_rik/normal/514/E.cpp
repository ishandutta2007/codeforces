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

template<typename T>
struct matrix : std::vector<std::vector<T>> {
	int n, m;
	matrix() : n(), m() {}
	matrix(int n, int m, const T val = T()) : n(n), m(m), std::vector<std::vector<T>> (n, std::vector<T>(m, val)) { }
	matrix(std::initializer_list<std::vector<T>> l): std::vector<std::vector<T>>(l) {
		n = l.size();
		if (l.size()) {
			m = l.begin()->size();
		}
	}

	matrix &operator+=(const matrix &mat) {
		assert(n == mat.n && m == mat.m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				(*this)[i][j] += mat[i][j];
			}
		}
		return *this;
	}

	matrix &operator-=(const matrix &mat) {
		assert(n == mat.n && m == mat.m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				(*this)[i][j] -= mat[i][j];
			}
		}
		return *this;
	}

	matrix &operator*=(const matrix &mat) {
		assert(m == mat.n);
		matrix res(n, mat.m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < mat.m; j++) {
				for (int k = 0; k < m; k++) {
					res[i][j] += (*this)[i][k] * mat[k][j];
				}
			}
		}
		this->swap(res);
		return *this;
	}

	matrix &operator*=(const T &val) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				(*this)[i][j] *= val;
			}
		}
		return *this;
	}

	friend matrix operator+(matrix a, const matrix &b) {
		a += b;
		return a;
	}

	friend matrix operator-(matrix a, const matrix &b) {
		a -= b;
		return a;
	}

	friend matrix operator*(matrix a, const matrix &b) {
		a *= b;
		return a;
	}

	friend matrix operator*(matrix a, const T &val) {
		a *= val;
		return a;
	}

	friend matrix operator*(const T &val, matrix a) {
		a *= val;
		return a;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = static_mint<1000000007>;

	int n, x;
	cin >> n >> x;

	vector<int> cnt(101);
	for (int i = 0, d; i < n; i++) {
		cin >> d, cnt[d] += 1;
	}

	matrix<mint> m(101, 101);

	m[0][0] = 1 + cnt[1];
	for (int i = 1; i < 100; i++) {
		m[i][0] = cnt[i + 1] - cnt[i];
	}
	m[100][0] = -cnt[100];

	for (int j = 1; j < 101; j++) {
		m[j - 1][j] = 1;
	}

	matrix<mint> ans(101, 101);
	for (int i = 0; i < 101; i++) ans[0][0] = 1;

	for (; x; x /= 2) {
		if (x & 1) ans *= m;
		m *= m;
	}

	cout << ans[0][0] << '\n';
	return 0;
}