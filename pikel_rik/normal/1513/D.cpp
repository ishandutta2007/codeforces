#include <bits/stdc++.h>
using namespace std;

struct union_find {
	int n, c;
	std::vector<int> p, r;

	union_find() : n(), c() {}
	union_find(int n) : n(n), c(n), p(n), r(n, 1) {
		iota(p.begin(), p.end(), 0);
	}

	int count() const noexcept {
		return c;
	}

	int find(int x) {
		return x == p[x] ? x : p[x] = find(p[x]);
	}

	bool merge(int x, int y) {
		int l1 = find(x);
		int l2 = find(y);
		if (l1 == l2)
			return false;
		if (r[l1] >= r[l2]) {
			r[l1] += r[l2];
			p[l2] = l1;
		} else {
			p[l1] = l2;
			r[l2] += r[l1];
		}
		c -= 1;
		return true;
	}
};

template<typename T>
struct sparse_table {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<std::vector<T>> mat;
	F f;
	sparse_table() : n(), f() {}

	template<typename U>
	sparse_table(const U& arr, int n, F f): n(n), f(f), mat((int) log2(n) + 1) {
		mat[0].resize(n);
		for (int i = 0; i < n; i++)
			mat[0][i] = T(arr[i]);
		for (int j = 1; j < mat.size(); j++) {
			mat[j].resize(n - (1 << j) + 1);
			for (int i = 0; i + (1 << j) <= n; i++) {
				mat[j][i] = f(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
			}
		}
	}

	T query(int l, int r) {
		int j = 32 - __builtin_clz(r - l + 1) - 1;
		return f(mat[j][l], mat[j][r + 1 - (1 << j)]);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, p;
		cin >> n >> p;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		vector<int> l(n), r(n), st;
		for (int i = 0; i < n; i++) {
			while (!st.empty() && a[i] <= a[st.back()]) {
				st.pop_back();
			}
			l[i] = st.empty() ? -1 : st.back();
			st.push_back(i);
		}

		st.clear();
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && a[i] <= a[st.back()]) {
				st.pop_back();
			}
			r[i] = st.empty() ? n : st.back();
			st.push_back(i);
		}

		sparse_table<int> g(a, n, [&](int x, int y) {
			return __gcd(x, y);
		});

		vector<vector<int>> add(n), rem(n);

		for (int i = 0; i < n; i++) {
			int lo = l[i] + 1, hi = i;
			while (lo < hi) {
				int mid = lo + (hi - lo) / 2;
				if (g.query(mid, i) == a[i]) {
					hi = mid;
				} else lo = mid + 1;
			}

			add[lo].push_back(a[i]);

			lo = i, hi = r[i] - 1;
			while (lo < hi) {
				int mid = lo + (hi - lo + 1) / 2;
				if (g.query(i, mid) == a[i]) {
					lo = mid;
				} else hi = mid - 1;
			}

			rem[lo].push_back(a[i]);
		}

		multiset<int> s = {p};

		long long ans = 0;
		for (int i = 0; i + 1 < n; i++) {
			for (int x : add[i]) {
				s.insert(x);
			}
			for (int x : rem[i]) {
				s.erase(s.find(x));
			}
			ans += *s.begin();
		}
		cout << ans << '\n';
	}
	return 0;
}