#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> tree(600000);
vector<int> a(600000);

void build(int node, int start, int end, int xr) {
	if (start == end) {
		tree[node] = a[start];
	} else {
		int mid = (start + end)/2;
		
		build(2*node, start, mid, !xr);
		build(2*node + 1, mid+1, end, !xr);
		
		if (xr) {
			tree[node] = tree[2*node] | tree[2*node + 1];
		} else {
			tree[node] = tree[2*node] ^ tree[2*node + 1];
		}
	}
}

void update(int node, int start, int end, int ind, int val, int xr) {
	if (start == end) {
		a[ind] = val;
		tree[node] = val;
	} else {
		int mid = (start + end)/2;
		
		if (start <= ind && ind <= mid) {update(2*node, start, mid, ind, val, !xr);}
		else {update(2*node+1, mid+1, end, ind, val, !xr);}
		
		if (xr) {
			tree[node] = tree[2*node] | tree[2*node + 1];
		} else {
			tree[node] = tree[2*node] ^ tree[2*node + 1];
		}
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= (1 << n); i++) {
		cin >> a[i];
	}
	int xr = (n % 2);
	build(1, 1, (1 << n), xr);
	
	while (m--) {
		int p, b; cin >> p >> b;
		update(1, 1, (1 << n), p, b, xr);
		cout << tree[1] << '\n';
	}
	
	return 0;
}