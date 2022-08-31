#include <bits/stdc++.h>
using namespace std;

struct segment_tree {
	struct node {
		char lc, rc;
		array<array<int, 10>, 10> cnt;
		node() : lc(), rc() { }
		node(char c) : lc(c), rc(c) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					cnt[i][j] = 0;
				}
			}
		}

		friend node operator+(const node &x, const node &y) {
			node res;
			res.lc = x.lc, res.rc = y.rc;
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					res.cnt[i][j] = x.cnt[i][j] + y.cnt[i][j];
				}
			}
			res.cnt[x.rc - 'a'][y.lc - 'a']++;
			return res;
		}
	};

	int n;
	vector<node> t;
	vector<int> lazy;
	segment_tree() : n() {}

	template<typename U>
	segment_tree(const U &arr, int n): n(n), t(4 * n), lazy(4 * n, -1) {
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

	void push(int x, int l, int r) {
		if (lazy[x] != -1) {
			int mid = (l + r) >> 1;
			t[x << 1] = t[x << 1 | 1] = node(lazy[x] + 'a');
			t[x << 1].cnt[lazy[x]][lazy[x]] += (mid - l);
			t[x << 1 | 1].cnt[lazy[x]][lazy[x]] += (r - mid - 1);
			lazy[x << 1] = lazy[x << 1 | 1] = lazy[x];
			lazy[x] = -1;
		}
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
			t[i] = node(val + 'a');
			t[i].cnt[val][val] += r - l;
			lazy[i] = val;
			return;
		}
		push(i, l, r);
		int mid = (l + r) >> 1;
		update_helper(ql, qr, val, i << 1, l, mid);
		update_helper(ql, qr, val, i << 1 | 1, mid + 1, r);

		t[i] = t[i << 1] + t[i << 1 | 1];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	string s;
	cin >> s;

	segment_tree st(s, n);
	while (m--) {
		int t;
		cin >> t;

		if (t == 1) {
			int l, r; char c;
			cin >> l >> r >> c;
			st.update(--l, --r, c - 'a');
		} else {
			string p;
			cin >> p;
			array<int, 10> pos;
			for (int i = 0; i < k; i++) {
				pos[p[i] - 'a'] = i;
			}

			int ans = 1;
			for (int i = 0; i < k; i++) {
				for (int j = 0; j < k; j++) {
					ans += st.t[1].cnt[i][j] * (pos[i] >= pos[j]);
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}