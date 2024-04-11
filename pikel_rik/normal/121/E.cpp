#include <bits/stdc++.h>
using namespace std;

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

	int query(int sum) {
		return query_helper(sum, 1, 0, n - 1);
	}

	int query_helper(int sum, int i, int l, int r) {
		if (l == r)
			return l;
		int mid = (l + r) >> 1;
		if (t[i << 1] >= sum)
			return query_helper(sum, i << 1, l, mid);
		return query_helper(sum - t[i << 1], i << 1 | 1, mid + 1, r);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> lucky_nums;
	for (int i = 1; i <= 10000; i++) {
		bool ok = true;
		for (int n = i; n; n /= 10) {
			ok &= n % 10 == 4 || n % 10 == 7;
		}
		if (ok) {
			lucky_nums.push_back(i);
		}
	}

	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<vector<pair<int, int>>> add(n), rem(n);

	vector<string> s(m);
	vector<int> l(m), r(m);

	for (int i = 0, d; i < m; i++) {
		cin >> s[i] >> l[i] >> r[i];
		--l[i], --r[i];
		if (s[i] == "add") {
			cin >> d;
			add[l[i]].emplace_back(d, i);
			rem[r[i]].emplace_back(d, i);
		}
	}

	segment_tree<int> st(vector<int>(m + 1), m + 1, 0, [&](int x, int y) {
		return x + y;
	});

	vector<vector<int>> add1(m), rem1(m);
	for (int i = 0; i < n; i++) {
		for (auto&[d, j] : add[i]) {
			st.update(j, d);
		}

		for (int x : lucky_nums) {
			if (a[i] == x) {
				int q2 = st.query(1);
				//0, q2 - 1
				if (0 <= q2 - 1) {
					add1[0].emplace_back(i);
					rem1[q2 - 1].emplace_back(i);
				}
			} else if (a[i] < x) {
				int q1 = st.query(x - a[i]), q2 = st.query(x - a[i] + 1);
				if (q1 + 1 <= q2 - 1 && st.query(0, q1) == x - a[i]) {
					add1[q1 + 1].emplace_back(i);
					rem1[q2 - 1].emplace_back(i);
				}
			}
		}

		for (auto&[d, j] : rem[i]) {
			st.update(j, 0);
		}
	}

	vector<int> ans(m);
	st = segment_tree<int>(vector<int>(n), n, 0, [&](int x, int y) {
		return x + y;
	});

	vector<int> cnt(n);
	for (int i = 0; i < m; i++) {
		for (int j : add1[i]) {
			if (cnt[j] == 0) {
				st.update(j, 1);
			}
			cnt[j] += 1;
		}

		if (s[i] == "count") {
			ans[i] = st.query(l[i], r[i]);
		}

		for (int j : rem1[i]) {
			cnt[j] -= 1;
			if (cnt[j] == 0) {
				st.update(j, 0);
			}
		}
	}

	for (int i = 0; i < m; i++) {
		if (s[i] == "count") {
			cout << ans[i] << '\n';
		}
	}
	return 0;
}