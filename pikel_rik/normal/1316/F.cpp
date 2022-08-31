#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 3e5 + 5;

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

using mint = modular::static_mint<1000000007>;

mint two[N];
vector<int> temp;

struct segment_tree {
	struct node {
		int sz;
		mint sum_l, sum_r, ans;
		node() : sz() { }
		node(int x, int n) : sz(n) {
			ans = n * two[n - 1] - two[n] + 1;
			ans *= (ll)temp[x] * temp[x] % mod;
			sum_l = sum_r = temp[x] * (two[n] - 1);
		}

		friend node operator+(const node &x, const node &y) {
			if (!x.sz) return y;
			if (!y.sz) return x;
			node res;
			res.sz = x.sz + y.sz;
			res.ans = x.ans * two[y.sz] + y.ans * two[x.sz] + x.sum_r * y.sum_l;
			res.sum_l = two[y.sz] * x.sum_l + y.sum_l;
			res.sum_r = x.sum_r + two[x.sz] * y.sum_r;
			return res;
		}
	};

	int n;
	vector<node> t;
	segment_tree() : n() {}

	segment_tree(int n): n(n), t(4 * n) { }

	template<typename U>
	void update(int idx, U val) {
		update_helper(idx, val, 1, 0, n - 1);
	}

	template<typename U>
	void update_helper(int idx, U val, int i, int l, int r) {
		if (l == r) {
			t[i] = node(l, t[i].sz + val);
			return;
		}
		int mid = (l + r) >> 1;
		if (idx <= mid)
			update_helper(idx, val, i << 1, l, mid);
		else update_helper(idx, val, i << 1 | 1, mid + 1, r);
		t[i] = t[i << 1] + t[i << 1 | 1];
	}

	node query(int ql, int qr) {
		return query_helper(ql, qr, 1, 0, n - 1);
	}

	node query_helper(int ql, int qr, int i, int l, int r) {
		if (r < ql || qr < l)
			return node();
		if (ql <= l && r <= qr)
			return t[i];
		int mid = (l + r) >> 1;
		node x = query_helper(ql, qr, i << 1, l, mid), y = query_helper(ql, qr, i << 1 | 1, mid + 1, r);
		return x + y;
	}
};

int n, q, p[N], a[N];
mint inv_n;

mint compute() {
	copy(p, p + n, a);
	sort(a, a + n);
	mint ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans = ans + two[i + n - j - 1] * a[i] * a[j];
		}
	}
	return ans * inv_n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	two[0] = 1;
	for (int i = 1; i < N; i++) {
		two[i] = 2 * two[i - 1];
	}

	cin >> n; inv_n = two[n].inv();
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		temp.push_back(p[i]);
	}

	cin >> q;
	vector<pair<int, int>> queries(q);
	for (int i = 0; i < q; i++) {
		cin >> queries[i].first >> queries[i].second;
		--queries[i].first;
		temp.push_back(queries[i].second);
	}

	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());

	segment_tree st(temp.size());

	for (int i = 0; i < n; i++) {
		int idx = lower_bound(temp.begin(), temp.end(), p[i]) - temp.begin();
		st.update(idx, 1);
	}

	cout << st.t[1].ans * inv_n << '\n';

	for (auto&[i, x] : queries) {
		int idx = lower_bound(temp.begin(), temp.end(), p[i]) - temp.begin();
		st.update(idx, -1);
		p[i] = x;
		idx = lower_bound(temp.begin(), temp.end(), p[i]) - temp.begin();
		st.update(idx, 1);
		cout << st.t[1].ans * inv_n << '\n';
	}
	return 0;
}