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

namespace bitwise_convolution {
	template <typename T>
	void fwht_xor(std::vector<T> &a) {
		int n = (int) a.size();
		for (int l = 1; l < n; l <<= 1) {
			for (int i = 0; i < n; i += 2 * l) {
				for (int j = 0; j < l; j++) {
					T v = a[i + j + l];
					a[i + j + l] = a[i + j] - v;
					a[i + j] = a[i + j] + v;
				}
			}
		}
	}

	template <typename T>
	std::vector<T> xor_convolution(std::vector<T> a, std::vector<T> b) {
		int n = 1;
		while (n < (int) a.size() && n < (int) b.size()) {
			n <<= 1;
		}
		a.resize(n), b.resize(n);
		fwht_xor(a), fwht_xor(b);
		T inv_n = 1 / T(n);
		for (int i = 0; i < n; i++) {
			a[i] *= b[i] * inv_n;
		}
		fwht_xor(a);
		return a;
	}

	template <typename T>
	void fwht_and(std::vector<T> &a, bool invert = false) {
		int n = (int) a.size();
		for (int l = 1; l < n; l <<= 1) {
			for (int i = 0; i < n; i += 2 * l) {
				for (int j = 0; j < l; j++) {
					if (invert) {
						a[i + j] -= a[i + j + l];
					} else {
						a[i + j] += a[i + j + l];
					}
				}
			}
		}
	}

	template <typename T>
	std::vector<T> and_convolution(std::vector<T> a, std::vector<T> b) {
		int n = 1;
		while (n < (int) a.size() && n < (int) b.size()) {
			n <<= 1;
		}
		a.resize(n), b.resize(n);
		fwht_and(a), fwht_and(b);
		for (int i = 0; i < n; i++) {
			a[i] *= b[i];
		}
		fwht_and(a, true);
		return a;
	}

	template <typename T>
	std::vector<T> or_convolution(std::vector<T> a, std::vector<T> b) {
		int n = 1;
		while (n < (int) a.size() && n < (int) b.size()) {
			n <<= 1;
		}
		a.resize(n), b.resize(n);
		for (int i = 0; i < n; i++) {
			int j = ~i & (n - 1);
			if (i < j) {
				swap(a[i], a[j]);
				swap(b[i], b[j]);
			}
		}
		fwht_and(a), fwht_and(b);
		for (int i = 0; i < n; i++) {
			a[i] *= b[i];
		}
		fwht_and(a, true);
		for (int i = 0; i < n; i++) {
			int j = ~i & (n - 1);
			if (i < j) {
				swap(a[i], a[j]);
			}
		}
		return a;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = static_mint<1000000007>;
	using bitwise_convolution::fwht_xor;

	struct edge { int u, v, w; };

	int n, m;
	cin >> n >> m;

	vector<edge> e(m);
	vector<vector<int>> g(n);

	for (int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		g[--e[i].u].push_back(i);
		g[--e[i].v].push_back(i);
	}

	vector<int> d(n), p(n, -1);
	vector<vector<int>> tours;

	auto dfs = [&](int u, const auto &self) -> void {
		for (int i : g[u]) {
			int v = e[i].u ^ e[i].v ^ u;
			if (p[v] == -1) {
				d[v] = 1 + d[u], p[v] = i;
				self(v, self);
			} else if (d[v] + 1 < d[u]) {
				tours.push_back({e[i].w});
				int prev = u;
				for (int j = p[u]; prev != v;) {
					tours.back().push_back(e[j].w);
					prev = e[j].u ^ e[j].v ^ prev;
					j = p[prev];
				}
			}
		}
	};

	p[0] = -2;
	dfs(0, dfs);

	int total_xor_sum = 0;
	for (int i = 0; i < m; i++) {
		total_xor_sum ^= e[i].w;
	}

	vector<mint> f(1 << 17);
	f[total_xor_sum] = 1;

	for (auto &tour : tours) {
		vector<mint> cnt(1 << 17);
		for (int w : tour) {
			cnt[w] = 1;
		}
		f = bitwise_convolution::xor_convolution(f, cnt);
		for (int i = 0; i < (1 << 17); i++) {
			f[i] = bool(f[i]);
		}
	}

	int target_xor = (1 << 17);
	for (int i = 0; i < (1 << 17); i++) {
		if (f[i]) {
			target_xor = i;
			break;
		}
	}

	vector<mint> a(1 << 17);
	a[total_xor_sum] = 1, fwht_xor(a);

	for (auto &tour : tours) {
		vector<mint> cnt(1 << 17);
		for (int w : tour) {
			cnt[w] += 1;
		}

		fwht_xor(cnt);
		for (int i = 0; i < (1 << 17); i++) {
			a[i] *= cnt[i];
		}
	}

	fwht_xor(a);

	mint invn = mint(1 << 17).inv();
	for (auto &x : a) {
		x *= invn;
	}

	cout << target_xor << ' ' << a[target_xor] << '\n';
	return 0;
}