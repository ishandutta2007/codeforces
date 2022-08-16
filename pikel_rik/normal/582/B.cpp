#include <bits/stdc++.h>
using namespace std;

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

	int n, T;
	cin >> n >> T;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<int> temp = a;
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	for (auto &x : a) {
		x = lower_bound(temp.begin(), temp.end(), x) - temp.begin();
	}

	int sz = temp.size();
	matrix<int> dp(n, n), pw(sz, sz);

	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}

	for (int i = 0; i < sz; i++) {
		pw[i][i] = 1;
	}

	for (int l = 2; l <= n; l++) {
		for (int i = 0; i + l <= n; i++) {
			if (a[i] <= a[i + l - 1]) {
				dp[i][i + l - 1] = 2;
				for (int j = i; j <= i + l - 1; j++) {
					if (a[i] <= a[j] && a[j] <= a[i + l - 1]) {
						dp[i][i + l - 1] = max(dp[i][i + l - 1], dp[i][j] + dp[j][i + l - 1] - 1);
					}
				}
				pw[a[i]][a[i + l - 1]] = max(pw[a[i]][a[i + l - 1]], dp[i][i + l - 1]);
			}
		}
	}

	for (int l = 1; l < sz; l++) {
		for (int i = 0; i + l <= sz; i++) {
			if (i > 0) {
				pw[i - 1][i + l - 1] = max(pw[i - 1][i + l - 1], pw[i][i + l - 1]);
			}
			if (i + l < sz) {
				pw[i][i + l] = max(pw[i][i + l], pw[i][i + l - 1]);
			}
		}
	}

	matrix<int> ans(sz, sz);
	for (int i = 0; i < sz; i++) {
		ans[i][i] = 0;
	}

	auto multiply = [&](const matrix<int> &x, const matrix<int> &y) -> matrix<int> {
		matrix<int> z(sz, sz);
		for (int i = 0; i < sz; i++) {
			for (int j = i; j < sz; j++) {
				for (int k = i; k <= j; k++) {
					z[i][j] = max(z[i][j], x[i][k] + y[k][j]);
				}
			}
		}
		return z;
	};

	while (T) {
		if (T & 1) ans = multiply(ans, pw);
		pw = multiply(pw, pw);
		T /= 2;
	}

	int final = 0;
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			final = max(final, ans[i][j]);
		}
	}
	cout << final << '\n';
	return 0;
}