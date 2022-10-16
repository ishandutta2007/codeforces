#include <bits/stdc++.h>
using namespace std;

#define int long long

int tree[800008][22];
int lazy[800008];

void update(int node, int start, int end, int l, int r, int x) {
	if (lazy[node]) {
		for (int i = 0; i < 20; i++) {
			if (lazy[node] & (1 << i)) {
				tree[node][i] = (end - start + 1) - tree[node][i];
			} 
		}
		
		if (start != end) {
			lazy[2*node] ^= lazy[node];
			lazy[2*node + 1] ^= lazy[node];
		}
		
		lazy[node] = 0;
	}
	
	if (start > end || start > r || end < l) {return;}
	
	if (start >= l && end <= r) {
		for (int i = 0; i < 20; i++) {
			if (x & (1 << i)) {
				tree[node][i] = (end - start + 1) - tree[node][i];
			}
		}
		
		if (start != end) {
			lazy[2*node] ^= x;
			lazy[2*node + 1] ^= x;
		}
		
		return;
	}
	
	int mid = (start + end)/2;
	update(node*2, start, mid, l, r, x);  
	update(node*2 + 1, mid + 1, end, l, r, x);  
	
	for (int i = 0; i < 20; i++) {
		tree[node][i] = tree[2*node + 1][i] + tree[2*node][i];
	}
}

int query(int node, int start, int end, int l, int r) {
	if (lazy[node]) {
		for (int i = 0; i < 20; i++) {
			if (lazy[node] & (1 << i)) {
				tree[node][i] = (end - start + 1) - tree[node][i];
			}
		}
		
		if (start != end) {
			lazy[node*2] ^= lazy[node];
			lazy[node*2+1] ^= lazy[node];
		}
		
		lazy[node] = 0;
	}
	
	if (start > end || start > r || end < l) {return 0;}
	
	if (start >= l && end <= r) {
		int ans = 0;
		for (int i = 0; i < 20; i++) {
			ans += tree[node][i]*(1 << i);
		}
		return ans;
	}
	
	int mid = (start + end)/2;
	int p1 = query(node*2, start, mid, l, r);
	int p2 = query(node*2 + 1, mid+1, end, l, r);
	return p1+p2;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		update(1, 1, n, i, i, x);
	}
	
	int m; cin >> m;
	while (m--) {
		int q; cin >> q;
		if (q == 1) {
			int l, r; cin >> l >> r;
			cout << query(1, 1, n, l, r) << '\n';
		} else {
			int l, r, x;
			cin >> l >> r >> x;
			update(1, 1, n, l, r, x);
		}
	}
	
	return 0;
}