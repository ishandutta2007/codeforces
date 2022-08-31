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

	using mint = static_mint<998244353>;

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> g(n);
		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v, --u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		vector<int> divisors;
		for (int i = 1; i * i <= n - 1; i++) {
			if ((n - 1) % i == 0) {
				divisors.push_back(i);
				if ((n - 1) / i != i) {
					divisors.push_back((n - 1) / i);
				}
			}
		}

		vector<mint> ans(n + 1);
		ans[1] = mint(2).pow(n - 1);

		for (int k : divisors) {
			if (k == 1) {
				continue;
			}
			vector<int> a(n);
			auto dfs = [&](int u, int p, const auto &self) -> void {
				for (int v : g[u]) {
					if (v != p) {
						self(v, u, self);
					}
				}
				if (p != -1) {
					if (a[u] % k != 0) {
						a[u] += 1;
					} else {
						a[p] += 1;
					}
				}
			};
			dfs(0, -1, dfs);

			bool divisible = true;
			for (int u = 0; u < n; u++) {
				divisible &= a[u] % k == 0;
			}
			if (divisible) {
				ans[k] = 1;
			}
		}

		for (int i = n; i >= 1; i--) {
			for (int j = 2 * i; j <= n; j += i) {
				ans[i] -= ans[j];
			}
		}

		for (int i = 1; i <= n; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}