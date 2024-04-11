#include <bits/stdc++.h>
using namespace std;

struct segtree_lazy {
	int n;
	vector<int> tree, lazy;

	segtree_lazy(int n) {
		tree.resize(4*n + 4); lazy.resize(4*n + 4, -1); this->n = n;
	}

	void push(int node, int start, int end) {
		if (lazy[node] != -1) {
			tree[node] = (end-start+1)*lazy[node];
			if(start != end) {
				lazy[node*2] = lazy[node];
				lazy[node*2+1] = lazy[node]; 
			}
			lazy[node] = -1;
		}
	}

	void update(int node, int start, int end, int l, int r, int val) {
		push(node, start, end);
		if (start > end || start > r || end < l) {return;}

		if (start >= l && end <= r) {
			lazy[node] = val;
			push(node, start, end);
			return;
		}

		int mid = (start + end) / 2;
		update(node*2, start, mid, l, r, val);
		update(node*2 + 1, mid + 1, end, l, r, val);

		tree[node] = tree[2*node] + tree[2*node+1];
	}

	int query(int node, int start, int end, int l, int r) {
		push(node, start, end);
		if (start > end || start > r || end < l) {return 0;}

		if (start >= l && end <= r) {return tree[node];}

		int mid = (start + end)/2;
		int p1 = query(node*2, start, mid, l, r);
		int p2 = query(node*2 + 1, mid+1, end, l, r);
		return p1 + p2;
	}

	void update(int l, int r, int val) {
		update(1, 0, n-1, l, r, val);
	}

	int query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}
};

void solve() {
	int n, q; cin >> n >> q;
	string s, f; cin >> s >> f;

	vector<pair<int, int>> que;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		que.emplace_back(l, r);
	}
	reverse(que.begin(), que.end());

	segtree_lazy st(n+1);
	for (int i = 0; i < n; i++) {
		if (f[i] == '1') {
			st.update(i+1, i+1, 1);
		}
	}

	for (auto [l, r]: que) {
		int sz = (r-l+1);
		int sum = st.query(l, r);

		if (sum+sum == sz) {
			cout << "NO\n"; return;
		}

		if (sum+sum > sz) {
			// there are more ones, set everything to one
			st.update(l, r, 1);
		} else {
			// more zeroes
			st.update(l, r, 0);
		}
	}

	for (int i = 0; i < n; i++) {
		int val = s[i] - '0';
		if (st.query(i+1, i+1) != val) {
			cout << "NO\n"; return;
		}
	}
	cout << "YES\n";
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}