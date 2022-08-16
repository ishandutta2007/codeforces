#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct segment_tree {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<T> t;
	std::vector<long long> lazy;
	T e;
	F f;

	segment_tree() : n(), e(), f() {}

	template<typename U>
	segment_tree(const U &arr, int n, T e, F f): n(n), t(4 * n), lazy(4 * n), e(e), f(f) {
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

	void push(int x, int l, int r) {
		t[x << 1] += lazy[x];
		t[x << 1 | 1] += lazy[x];
		lazy[x << 1] += lazy[x];
		lazy[x << 1 | 1] += lazy[x];
		lazy[x] = 0;
	}

	template<typename U>
	void update(int ql, int qr, U val) {
		update_helper(ql, qr, val, 1, 0, n - 1);
	}

	template<typename U>
	void update_helper(int ql, int qr, U val, int i, int l, int r) {
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

	int n;
	cin >> n;

	vector<int> h(n), b(n);
	for (auto &x : h) cin >> x, --x;
	for (auto &x : b) cin >> x;

	segment_tree<long long> st(b, n, LLONG_MIN, [&](const auto &x, const auto &y) {
		return x > y ? x : y;
	});

	vector<int> sm;
	for (int i = 0; i < n; i++) {
		while (!sm.empty() && h[sm.back()] > h[i]) {
			int l = sm.size() == 1 ? 0 : sm[sm.size() - 2] + 1;
			st.update(l, sm.back(), b[i] - b[sm.back()]);
			sm.pop_back();
		}
		sm.push_back(i);
		if (i + 1 != n) {
			st.update(i + 1, i + 1, st.query(0, i));
		}
	}

	cout << st.t[1] << '\n';
	return 0;
}