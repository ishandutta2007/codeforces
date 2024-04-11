#include <bits/stdc++.h>
using namespace std;

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
		t[x << 1] = f(t[x << 1], lazy[x]);
		t[x << 1 | 1] = f(t[x << 1 | 1], lazy[x]);
		lazy[x << 1] = f(lazy[x << 1], lazy[x]);
		lazy[x << 1 | 1] = f(lazy[x << 1 | 1], lazy[x]);
		lazy[x] = e;
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
			t[i] = f(t[i], val);
			lazy[i] = f(lazy[i], val);
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

	int n, m;
	cin >> n >> m;

	vector<int> id(m), l(m), r(m);
	for (int i = 0; i < m; i++) {
		cin >> id[i] >> l[i] >> r[i], --id[i];
	}

	vector<int> values; values.reserve(2 * m);
	for (int i = 0; i < m; i++) {
		values.push_back(l[i]);
		values.push_back(r[i]);
	}

	sort(values.begin(), values.end());
	values.erase(unique(values.begin(), values.end()), values.end());
	int sz = (int) values.size();

	vector<vector<int>> segments(n);
	for (int i = 0; i < m; i++) {
		segments[id[i]].push_back(i);
		l[i] = lower_bound(values.begin(), values.end(), l[i]) - values.begin();
		r[i] = lower_bound(values.begin(), values.end(), r[i]) - values.begin();
	}

	struct node {
		int val, index;
		node() : val(0), index(-1) { }
		node(int x, int i) : val(x), index(i) { }
	};

	segment_tree<node> st(vector<node>(sz), sz, node(), [&](const node &x, const node &y) {
		node res;
		if (x.val >= y.val) {
			res = x;
		} else {
			res = y;
		}
		return res;
	});

	vector<int> dp(n), p(n, -1);
	for (int i = 0; i < n; i++) {
		for (int j : segments[i]) {
			node res = st.query(l[j], r[j]);
			if (1 + res.val > dp[i]) {
				p[i] = res.index;
				dp[i] = 1 + res.val;
			}
		}
		for (int j : segments[i]) {
			st.update(l[j], r[j], node(dp[i], i));
		}
	}

	int mx = max_element(dp.begin(), dp.end()) - dp.begin();

	vector<bool> take(n);
	for (int i = mx; i != -1; i = p[i]) {
		take[i] = true;
	}

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (!take[i]) {
			ans.push_back(i);
		}
	}

	cout << ans.size() << '\n';
	for (int i : ans) cout << i + 1 << ' ';
	cout << '\n';
	return 0;
}