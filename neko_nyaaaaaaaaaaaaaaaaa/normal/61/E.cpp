#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, x;
vector<int> a(1000001);
vector<int> tree[4000001];

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
		return lower_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
	}

	int mid = l + r >> 1, left = node << 1, right = left|1;

	return query(left, l, mid, i, j, k) + query(right, mid+1, r, i, j, k);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);

	ll ans = 0;
      for (int i = 2; i < n; i++) {
            ll l = i - 1 - query(1, 1, n, 1, i-1, a[i]);
            ll r = query(1, 1, n, i+1, n, a[i]);
            ans += l*r;
      }
      cout << ans;

	return 0;
}