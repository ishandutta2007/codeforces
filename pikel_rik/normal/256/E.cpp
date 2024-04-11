#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 777777777;
const double pi = acos(-1.0);
const int inf = INT_MAX;

template<typename T>
struct matrix {
	int n, m;
	vector<vector<T>> mat;

	matrix() : n(), m() {}
	matrix(int n, int m, const T val = T()) : n(n), m(m), mat(n, vector<T>(m, val)) {}
	matrix(initializer_list<vector<T>> list): mat(list) {
		n = mat.size();
		m = mat.front().size();
	}

	matrix operator+(const matrix &rhs) {
		matrix res(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res[i][j] = mat[i][j] + rhs[i][j];
		return res;
	}

	matrix operator-(const matrix &rhs) {
		matrix res(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res[i][j] = mat[i][j] - rhs[i][j];
		return res;
	}

	matrix operator*(const matrix &rhs) {
		matrix res(n, rhs.m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < rhs.m; j++)
				for (int k = 0; k < m; k++) res[i][j] += mat[i][k] * rhs[k][j];
		return res;
	}

	matrix operator+=(const matrix &rhs) { return *this = *this + rhs; }
	matrix operator-=(const matrix &rhs) { return *this = *this - rhs; }
	matrix operator*=(const matrix &rhs) { return *this = *this * rhs; }

	vector<T> &operator[](int idx) { return mat[idx]; }
	const vector<T> &operator[](int idx) const { return mat[idx]; }
};

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

template<typename T>
struct segment_tree {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<T> t;
	T e;
	F f;

	segment_tree() : n(), e(), f() {}

	template<typename U>
	segment_tree(const U &arr, int n, T e, F f): n(n), t(4 * n), e(e), f(f) {
		build(arr, 1, 0, n - 1);
	}

	template<typename U>
	void build(const U &arr, int i, int l, int r) {
		if (l == r) {
			t[i] = T(arr[l]);
			return;
		}
		int mid = (l + r) >> 1;
		build(arr, i << 1, l, mid);
		build(arr, i << 1 | 1, mid + 1, r);
		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	template<typename U>
	void update(int idx, U val) {
		update_helper(idx, val, 1, 0, n - 1);
	}

	template<typename U>
	void update_helper(int idx, U val, int i, int l, int r) {
		if (l == r) {
			t[i] = T(val);
			return;
		}
		int mid = (l + r) >> 1;
		if (idx <= mid)
			update_helper(idx, val, i << 1, l, mid);
		else update_helper(idx, val, i << 1 | 1, mid + 1, r);
		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	T query(int ql, int qr) {
		return query_helper(ql, qr, 1, 0, n - 1);
	}

	T query_helper(int ql, int qr, int i, int l, int r) {
		if (ql > r or qr < l)
			return e;
		if (ql <= l and r <= qr)
			return t[i];
		int mid = (l + r) >> 1;
		T x = query_helper(ql, qr, i << 1, l, mid), y = query_helper(ql, qr, i << 1 | 1, mid + 1, r);
		return f(x, y);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = modular::static_mint<777777777>;

	int n, m;
	cin >> n >> m;

	matrix<mint> w(3, 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> w[i][j];
		}
	}

	vector<matrix<mint>> paths(n);
	paths[0] = matrix<mint>(3, 3);
	for (int i = 0; i < 3; i++) paths[0][i][i] = 1;

	for (int i = 1; i < n; i++) {
		paths[i] = paths[i - 1] * w;
	}

	vector<int> a(n, -1);
	set<int> s = {-1, n};

	segment_tree<mint> st(vector<int>(n, 1), n, 1, [&](auto x, auto y) {
		return x * y;
	});

	auto ways = [&](int i, int j) -> mint {
		return paths[j - i][a[i]][a[j]];
	};

	auto remove = [&](int i) -> void {
		auto it = s.find(i);
		auto prv = prev(it), nxt = next(it);
		if (*prv != -1) {
			st.update(i, 1);
		}
		if (*nxt != n) {
			st.update(*nxt, 1);
		}
		if (*prv != -1 && *nxt != n) {
			st.update(*nxt, ways(*prv, *nxt));
		}
		a[i] = -1;
		s.erase(it);
	};

	auto insert = [&](int i, int t) -> void {
		auto it = s.insert(i).first;
		a[i] = t;
		auto prv = prev(it), nxt = next(it);
		if (*prv != -1 && *nxt != n) {
			st.update(*nxt, 1);
		}
		if (*prv != -1) {
			st.update(i, ways(*prv, i));
		}
		if (*nxt != n) {
			st.update(*nxt, ways(i, *nxt));
		}
	};

	int v, t;
	while (m--) {
		cin >> v >> t;
		--v; --t;

		if (a[v] != t) {
			if (a[v] != -1) {
				remove(v);
			}
			if (t != -1) {
				insert(v, t);
			}
		}

		if (s.size() == 2) {
			mint ans = 0;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					ans += paths[n - 1][i][j];
				}
			}
			cout << ans << '\n';
		} else {
			mint ans = st.query(0, n - 1);
			int nxt = *next(s.begin());
			if (nxt != 0) {
				mint temp = 0;
				for (int i = 0; i < 3; i++) {
					a[0] = i;
					temp += ways(0, nxt);
				}
				a[0] = -1;
				ans *= temp;
			}
			int prv = *next(s.rbegin());
			if (prv != n - 1) {
				mint temp = 0;
				for (int i = 0; i < 3; i++) {
					a[n - 1] = i;
					temp += ways(prv, n - 1);
				}
				a[n - 1] = -1;
				ans *= temp;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}