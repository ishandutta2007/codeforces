#include <bits/stdc++.h>
using namespace std;

struct segment_tree {
	struct node {
		int mx, mn, cur;
		node() : mx(), mn(), cur() {}
		node(char c) {
			if (c == '+') {
				mx = mn = cur = 1;
			} else {
				mx = mn = cur = -1;
			}
		}

		friend node operator+(const node &x, const node &y) {
			node res;
			res.mx = max(x.mx, x.cur + y.mx);
			res.mn = min(x.mn, x.cur + y.mn);
			res.cur = x.cur + y.cur;
			return res;
		}
	};

	int n;
	vector<node> t;
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

	node query(int ql, int qr) {
		node final;
		query_helper(ql, qr, final, 1, 0, n - 1);
		return final;
	}

	void query_helper(int ql, int qr, node &ans, int i, int l, int r) {
		if (r < ql || qr < l) {
			ans = ans + t[i];
			return;
		}
		if (ql <= l && r <= qr)
			return;
		int mid = (l + r) >> 1;
		query_helper(ql, qr, ans, i << 1, l, mid);
		query_helper(ql, qr, ans, i << 1 | 1, mid + 1, r);
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

		string s;
		cin >> s;
		segment_tree st(s, n);

		int l, r;
		while (m-- > 0) {
			cin >> l >> r;
			auto now = st.query(--l, --r);
			cout << now.mx - now.mn + 1 << '\n';
		}
	}
	return 0;
}