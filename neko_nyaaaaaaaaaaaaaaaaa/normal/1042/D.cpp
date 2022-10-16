#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, x;
vector<int> a(200001);
vector<int> tree[800001];

void build(int node, int l, int r) {
	if(l == r) {
		tree[node].push_back(a[l]);
		return;
	} else {
		int mid = (l + r) >> 1, left = node << 1, right = left|1;

		build(left, l, mid);
		build(right, mid+1, r);

		merge(tree[left].begin(), tree[left].end(), tree[right].begin(), tree[right].end(), back_inserter(tree[node]));
	}
}

int query(int node, int l, int r, int i, int j, int k) {
	if (i > r || l > j) return 0;
	if(i <= l && r <= j) {
		return lower_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();	// this is for query less than or equal, change to lower bound if query strictly less
	}

	int mid = l + r >> 1, left = node << 1, right = left|1;

	return query(left, l, mid, i, j, k) + query(right, mid+1, r, i, j, k);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> x;
	vector<int> k(n+1);
	for (int i = 1; i <= n; i++) {
            cin >> k[i];
            a[i] = a[i-1] + k[i];
	}
	build(1, 1, n);

	int ans = 0;
	for (int i = 0; i <= n; i++) {
            if (i != n) ans += query(1, 1, n, i+1, n, a[i] + x);
	}
	cout << ans;

	return 0;
}