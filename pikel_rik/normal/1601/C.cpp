#include <bits/stdc++.h>
using namespace std;

template <typename T>
long long inversions(std::vector<T> v) {
	int n = (int) v.size();

	std::vector<T> temp(n);
	auto merge = [&](int l, int m, int r) -> long long {
		long long inversions = 0;
		for (int i = l, j = m; i != m || j != r;) {
			if (j == r || (i < m && v[i] <= v[j])) {
				temp[i - l + j - m] = v[i];
				i += 1;
			} else {
				temp[i - l + j - m] = v[j];
				inversions += m - i;
				j += 1;
			}
		}
		std::copy(temp.begin(), temp.begin() + r - l, v.begin() + l);
		return inversions;
	};

	auto merge_sort = [&](int l, int r, auto &&self) -> long long {
		if (r - l <= 1) {
			return 0;
		} else {
			int m = (l + r) >> 1;
			long long inversions = 0;
			inversions += self(l, m, self);
			inversions += self(m, r, self);
			inversions += merge(l, m, r);
			return inversions;
		}
	};

	return merge_sort(0, n, merge_sort);
}

template<typename T, typename L = T>
struct segment_tree {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<T> t;
	std::vector<L> lazy;
	T e;
	F f;

	segment_tree() : n(), e(), f() { }

	template<typename U>
	segment_tree(const std::vector<U> &v, int n, T e, F f): n(n), t(4 * n), lazy(4 * n), e(e), f(f) {
		build(v, 1, 0, n - 1);
	}

	template<typename U>
	void build(const std::vector<U> &v, int i, int l, int r) {
		if (l == r) {
			t[i] = T(v[l]);
			return;
		}
		int mid = (l + r) >> 1;
		build(v, i << 1, l, mid);
		build(v, i << 1 | 1, mid + 1, r);
		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	void push(int x, int l, int r) {
		if (lazy[x]) {
			t[x << 1] += lazy[x];
			t[x << 1 | 1] += lazy[x];
			lazy[x << 1] += lazy[x];
			lazy[x << 1 | 1] += lazy[x];
			lazy[x] = 0;
		}
	}

	template<typename U>
	void update(int idx, const U &val) {
		update_helper(idx, val, 1, 0, n - 1);
	}

	template<typename U>
	void update_helper(int idx, const U &val, int i, int l, int r) {
		if (l == r) {
			t[i] = T(val);
			return;
		}
		push(i, l, r);
		int mid = (l + r) >> 1;
		if (idx <= mid)
			update_helper(idx, val, i << 1, l, mid);
		else update_helper(idx, val, i << 1 | 1, mid + 1, r);
		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	template<typename U>
	void update(int ql, int qr, const U &val) {
		update_helper(ql, qr, val, 1, 0, n - 1);
	}

	template<typename U>
	void update_helper(int ql, int qr, const U &val, int i, int l, int r) {
		if (r < ql || qr < l)
			return;
		if (ql <= l && r <= qr) {
			t[i] += val;
			lazy[i] += val;
			return;
		}
		push(i, l, r);
		int mid = (l + r) >> 1;
		update_helper(ql, qr, val, i << 1, l, mid);
		update_helper(ql, qr, val, i << 1 | 1, mid + 1, r);

		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	T query(int ql, int qr) {
		return query_helper(ql, qr, 1, 0, n - 1);
	}

	T query_helper(int ql, int qr, int i, int l, int r) {
		if (r < ql || qr < l)
			return e;
		if (ql <= l && r <= qr)
			return t[i];
		push(i, l, r);
		int mid = (l + r) >> 1;
		T x = query_helper(ql, qr, i << 1, l, mid), y = query_helper(ql, qr, i << 1 | 1, mid + 1, r);
		return f(x, y);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> a(n), b(m);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];

		long long ans = inversions(a);

		segment_tree<int> st(vector<int>(n + 1), n + 1, (int) 1e8, [](int x, int y) {
			return x < y ? x : y;
		});

		vector<int> ind(n);
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return a[i] < a[j];
		});

		sort(b.begin(), b.end());

		for (int i = 0; i < n; i++) {
			st.update(i + 1, n, 1);
		}

		int prev = 0;
		for (int i = 0, j = 0; j < m; j++) {
			if (j > 0 && b[j - 1] == b[j]) {
				ans += prev;
				continue;
			}
			while (i < n && a[ind[i]] < b[j]) {
				st.update(ind[i] + 1, n, -1);
				st.update(0, ind[i], 1);
				i += 1;
			}
			int eq = i;
			while (eq < n && a[ind[eq]] == b[j]) {
				st.update(ind[eq] + 1, n, -1);
				eq += 1;
			}
			ans += (prev = st.t[1]);
			while (i < eq) {
				st.update(0, ind[i], 1);
				i += 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}