#include <bits/stdc++.h>
using namespace std;

template<int M>
struct static_mint {
	static_assert(0 < M, "Module must be positive");

	int val;

	static_mint() : val() {}

	static_mint(long long x) : val(x % M) { if (val < 0) val += M; }

	static_mint pow(long long n) const {
		static_mint ans = 1, x(*this);
		for (; n > 0; n /= 2) {
			if (n & 1) ans *= x;
			x *= x;
		}
		return ans;
	}

	static_mint inv() const {
		return pow(M - 2);
	}

	static_mint operator+() const {
		static_mint m;
		m.val = val;
		return m;
	}

	static_mint operator-() const {
		static_mint m;
		m.val = (val == 0 ? 0 : M - val);
		return m;
	}

	static_mint &operator+=(const static_mint &m) {
		if ((val += m.val) >= M) val -= M;
		return *this;
	}

	static_mint &operator-=(const static_mint &m) {
		if ((val -= m.val) < 0) val += M;
		return *this;
	}

	static_mint &operator*=(const static_mint &m) {
		val = (long long) val * m.val % M;
		return *this;
	}

	static_mint &operator/=(const static_mint &m) {
		val = (long long) val * m.inv().val % M;
		return *this;
	}

	friend static_mint operator+(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) += rhs;
	}

	friend static_mint operator-(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) -= rhs;
	}

	friend static_mint operator*(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) *= rhs;
	}

	friend static_mint operator/(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) /= rhs;
	}

	friend bool operator==(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val == rhs.val;
	}

	friend bool operator!=(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val != rhs.val;
	}

	static_mint &operator++() {
		return *this += 1;
	}

	static_mint &operator--() {
		return *this -= 1;
	}

	static_mint operator++(int) {
		static_mint result(*this);
		*this += 1;
		return result;
	}

	static_mint operator--(int) {
		static_mint result(*this);
		*this -= 1;
		return result;
	}

	template<typename T>
	explicit operator T() const {
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

	using mint = static_mint<1000000007>;

	constexpr int N = 1000;

	int n, m, r;
	cin >> n >> m >> r;

	vector<mint> fact(n + 1), inv(n + 1);

	fact[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = i * fact[i - 1];
		inv[i] = fact[i].inv();
	}

	auto C = [&](int n, int k) -> mint {
		if (0 <= k && k <= n) {
			return fact[n] * inv[k] * inv[n - k];
		} else {
			return 0;
		}
	};

	vector<vector<int>> grid(N, vector<int>(N));

	vector<int> x(n), y(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> b[i];
		--x[i], --y[i];
		grid[x[i]][y[i]] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i > 0) {
				grid[i][j] += grid[i - 1][j];
			}
			if (j > 0) {
				grid[i][j] += grid[i][j - 1];
			}
			if (i > 0 && j > 0) {
				grid[i][j] -= grid[i - 1][j - 1];
			}
		}
	}

	auto query = [&](int x1, int x2, int y1, int y2) -> int {
		x1 = max(x1, 0), x2 = min(x2, N - 1);
		y1 = max(y1, 0), y2 = min(y2, N - 1);
		int sum = grid[x2][y2];
		if (x1 > 0) {
			sum -= grid[x1 - 1][y2];
		}
		if (y1 > 0) {
			sum -= grid[x2][y1 - 1];
		}
		if (x1 > 0 && y1 > 0) {
			sum += grid[x1 - 1][y1 - 1];
		}
		return sum;
	};

	mint ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int take_i = query(x[i] - r, x[i] + r, y[i] - r, y[i] + r);
			int take_j = query(x[j] - r, x[j] + r, y[j] - r, y[j] + r);
			int x_left = max(x[i], x[j]) - r, x_right = min(x[i], x[j]) + r;
			int y_left = max(y[i], y[j]) - r, y_right = min(y[i], y[j]) + r;

			int take_both = 0;
			if (x_left <= x_right && y_left <= y_right) {
				take_both = query(x_left, x_right, y_left, y_right);
			}
			int take_either = take_i + take_j - take_both;
			mint ways = C(n - take_either, m);
			ways += C(n - take_j, m) - C(n - take_either, m);
			ways += C(n - take_i, m) - C(n - take_either, m);
			ans += mint(b[i]) * b[j] * (C(n, m) - ways);
		}
	}
	cout << ans << '\n';
	return 0;
}