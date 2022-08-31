#include <bits/stdc++.h>
using namespace std;

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

namespace matrix_algebra {
	template<typename T>
	struct matrix : std::vector<std::vector<T>> {
		int n, m;
		matrix() : n(), m() {}
		matrix(int n, int m, const T val = T()) : n(n), m(m), std::vector<std::vector<T>> (n, std::vector<T>(m, val)) { }
		matrix(std::initializer_list<std::vector<T>> list): std::vector<std::vector<T>>(list) {
			n = list.size();
			m = list.front().size();
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

		template <typename U>
		std::enable_if_t<std::is_arithmetic<U>::value, matrix&> operator*=(const U &val) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					(*this)[i][j] *= val;
				}
			}
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

		template <typename U>
		std::enable_if_t<std::is_arithmetic<U>::value, matrix>
		 friend operator*(matrix a, const U &val) {
			a *= val;
			return a;
		}

		template <typename U>
		std::enable_if_t<std::is_arithmetic<U>::value, matrix>
		friend operator*(const U &val, matrix a) {
			a *= val;
			return a;
		}
	};

	template <typename mint>
	int gaussian_elimination(matrix<mint> A, vector<mint> &ans) { //Solves AX = B
		int n = int(A.size());

		vector<int> where(n, -1);
		for (int col = 0, row = 0; col < n && row < n; col++) {
			int sel = row;
			for (int i = row; i < n; i++) {
				if (A[i][col] != 0) {
					sel = i;
					break;
				}
			}
			if (A[sel][col] == 0)
				continue;
			for (int i = col; i <= n; i++) {
				swap(A[sel][i], A[row][i]);
			}
			where[col] = row;

			for (int i = 0; i < n; i++) {
				if (i != row) {
					mint c = A[i][col] / A[row][col];
					for (int j = col; j <= n; j++) {
						A[i][j] -= A[row][j] * c;
					}
				}
			}
			++row;
		}

		for (int i = 0; i < n; i++) {
			if (where[i] != -1) {
				ans[i] = A[where[i]][n] / A[where[i]][i];
			}
		}

		for (int i = 0; i < n; i++) {
			mint sum = 0;
			for (int j = 0; j < n; j++) {
				sum += ans[j] * A[i][j];
			}
			if (sum != A[i][n]) {
				return 0;
			}
		}

		for (int i = 0; i < n; i++) {
			if (ans[i] == -1) {
				return 2;
			}
		}
		return 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = modular::static_mint<998244353>;
	using matrix = matrix_algebra::matrix<mint>;

	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; --u, --v;
		g[u].push_back(v);
	}

	vector<int> grundy(n);
	vector<bool> visited(n);

	auto mex = [&](vector<int> &v) -> int {
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for (int i = 0; i < v.size(); i++) {
			if (v[i] != i) {
				return i;
			}
		}
		return v.size();
	};

	auto dfs = [&](int x, const auto &dfs) -> void {
		visited[x] = true;
		vector<int> v;
		for (int i : g[x]) {
			if (!visited[i]) {
				dfs(i, dfs);
			}
			v.push_back(grundy[i]);
		}
		grundy[x] = mex(v);
	};

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i, dfs);
		}
	}

	int mx = *max_element(grundy.begin(), grundy.end());
	if (mx == 0) {
		cout << 0 << '\n';
		return 0;
	}

	int lg = 32 - __builtin_clz(mx);

	matrix mat(1 << lg, (1 << lg) + 1);
	vector<int> cnt(1 << lg);

	for (int x : grundy) {
		cnt[x]++;
	}

	for (int i = 0; i < (1 << lg); i++) {
		for (int j = 0; j < (1 << lg); j++) {
			mat[i][i ^ j] += cnt[j];
		}
		mat[i][i] -= n + 1;
		mat[i][1 << lg] = -(i != 0);
	}

	vector<mint> solution(1 << lg);
	if (matrix_algebra::gaussian_elimination(mat, solution)) {
		cout << solution[0] << '\n';
	}
	return 0;
}