#include <bits/stdc++.h>
using namespace std;

int n, m, t = 0;
vector<int> tree(800008);
vector<vector<int>> adj(200002);

vector<int> lv(200002);
vector<int> fi(200002);
vector<int> se(200002);
vector<int> tr(1);

void dfs(int now, int prev) {
	lv[now] = lv[prev] + 1; t++;
	fi[now] = t;
	tr.push_back(now);
	
	for (auto u: adj[now]) {
		if (u != prev) dfs(u, now);
	}
	se[now] = t;
}

int query(int node, int start, int end, int l, int r) {
	if (l > end || r < start) return 0;
	if (l <= start && r >= end) return tree[node];
	
	int mid = (start+end)/2;
	
	return query(2*node, start, mid, l, r) + query(2*node+1, mid+1, end, l, r);
}

void update(int node, int start, int end, int index, int val) {
	if (start == end) {
		tree[node] += val;
	} else {
		int mid = (start + end)/2;
		
		if (start <= index && index <= mid) {update(2*node, start, mid, index, val);}
		else {update(2*node+1, mid+1, end, index, val);}
		
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	cin >> n >> m;
	vector<int> tmp(200002);
	for (int i = 1; i <= n; i++) {
		cin >> tmp[i];
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, 0);
	
	while (m--) {
		int q; cin >> q;
		if (q == 2) {
			int x; cin >> x;
			int k = query(1, 1, n+1, 1, fi[x]);
			if (lv[x] & 1) k *= -1;
			
			cout << k + tmp[x] << '\n';
		} else {
			int x, val; cin >> x >> val;
			if (lv[x] & 1) val *= -1;
			
			update(1, 1, n+1, fi[x], val);
			update(1, 1, n+1, se[x] + 1, -val);
		}
	}
	
	return 0;
}