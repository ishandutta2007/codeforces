#include <bits/stdc++.h>
using namespace std;

struct segment_tree {
	struct node {
		array<int, 60> a;
		node() { a.fill(0); }
		node(int x) {
			for (int i = 0; i < 60; i++) {
				a[i] = (i % x == 0) + 1;
			}
		}
		friend node operator+(const node &x, const node &y) {
			node res;
			for (int i = 0; i < 60; i++) {
				res.a[i] = x.a[i] + y.a[(i + x.a[i]) % 60];
			}
			return res;
		}
	};

	int n;
	std::vector<node> t;
	segment_tree() : n() {}

	template<typename U>
	segment_tree(const U &arr, int n): n(n), t(4 * n) {
		build(arr, 1, 0, n - 1);
	}

	template<typename U>
	void build(const U &arr, int i, int l, int r) {
		if (l == r) {
			t[i] = node(arr[l]);
			return;
		}
		int mid = (l + r) >> 1;
		build(arr, i << 1, l, mid);
		build(arr, i << 1 | 1, mid + 1, r);
		t[i] = t[i << 1] + t[i << 1 | 1];
	}

	template<typename U>
	void update(int idx, U val) {
		update_helper(idx, val, 1, 0, n - 1);
	}

	template<typename U>
	void update_helper(int idx, U val, int i, int l, int r) {
		if (l == r) {
			t[i] = node(val);
			return;
		}
		int mid = (l + r) >> 1;
		if (idx <= mid)
			update_helper(idx, val, i << 1, l, mid);
		else update_helper(idx, val, i << 1 | 1, mid + 1, r);
		t[i] = t[i << 1] + t[i << 1 | 1];
	}

	int query(int ql, int qr) {
		return query_helper(ql, qr, 0, 1, 0, n - 1);
	}

	int query_helper(int ql, int qr, int time, int i, int l, int r) {
		if (ql > r || qr < l)
			return time;
		if (ql <= l && r <= qr)
			return time + t[i].a[time % 60];
		int mid = (l + r) >> 1;
		time = query_helper(ql, qr, time, i << 1, l, mid);
		return query_helper(ql, qr, time, i << 1 | 1, mid + 1, r);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	segment_tree st(a, n);

	int q;
	cin >> q;

	char c;
	int x, y;
	while (q--) {
		cin >> c >> x >> y;
		if (c == 'A') {
			--x, --y;
			cout << st.query(x, y - 1) << '\n';
		} else {
			st.update(--x, y);
		}
	}
	return 0;
}