#include <bits/stdc++.h>
using namespace std;

struct johnwick_tree{
	int n;
	vector<long long> tree;

	johnwick_tree(int n) {
		this->n = n;
		tree.resize(n+1);
	}

	void update(int p, long long val) {
		for (int i = p; i <= n; i += i & -i) {
			tree[i] += val;
		}
	}

	long long sum(int p) {
		if (p == 0) return 0;
		long long ans = 0;
		for (int i = p; i; i -= i & -i) {
			ans += tree[i];
		}
		return ans;
	}
} tr(100001);

vector<int> a(100001);
vector<int> tree(400001);

void build(int node, int start, int end) {
	if (start > end) return;
	if (start == end) {
		tree[node] = start;
	} else {
		int mid = (start + end)/2;

		build(node*2, start, mid);
		build(node*2 + 1, mid+1, end);

		if (a[tree[node*2]] >= a[tree[node*2 + 1]]) {
			tree[node] = tree[node*2];
		} else {
			tree[node] = tree[node*2 + 1];
		} 
	}
}

int query(int node, int start, int end, int l, int r) {
	if (start > r || end < l) return 0;
	if (start >= l && end <= r) return tree[node];

	int mid = (start + end)/2;

	int p1 = query(node*2, start, mid, l, r);
	int p2 = query(node*2 + 1, mid+1, end, l, r);

	if (a[p1] >= a[p2]) {
		return p1;
	} else {
		return p2;
	}
}

void update(int node, int start, int end, int val, int id) {
	if (start == end) {
		a[id] = val;
		return;
	}

	int mid = (start + end)/2;

	if (id >= start && id <= mid) {
		update(node*2, start, mid, val, id);
	} else {
		update(node*2+1, mid+1, end, val, id);
	}

	if (a[tree[node*2]] >= a[tree[node*2 + 1]]) {
		tree[node] = tree[node*2];
	} else {
		tree[node] = tree[node*2 + 1];
	} 
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		tr.update(i, a[i]);
	}
	build(1, 1, n);

	while (m--) {
		int t; cin >> t;
		if (t == 1) {
			int l, r; cin >> l >> r;
			cout << tr.sum(r) - tr.sum(l-1) << '\n';
		} else if (t == 2) {
			int l, r, x; cin >> l >> r >> x;
			while (1) {
				int id = query(1, 1, n, l, r);
				if (a[id] >= x) {
					int nxt = a[id] % x;

					tr.update(id, -a[id]);
					tr.update(id, nxt);

					update(1, 1, n, nxt, id);
				} else {
					break;
				}
			}
		} else {
			int k, x; cin >> k >> x;

			tr.update(k, -a[k]);
			tr.update(k, x);

			update(1, 1, n, x, k);
		}
	}

	return 0;
}