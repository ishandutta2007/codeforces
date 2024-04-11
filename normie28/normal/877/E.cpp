#include <bits/stdc++.h>
using namespace std;
 
const int N = 200200;
 
int n, p, q, u, v, i, a[N], b[N], l[N], r[N], seg[N * 4], lzy[N * 4];
string s;
vector<int> edges[N];
 
void dfs(int u = 1) {
	b[i] = a[u];
	l[u] = i++;
	for (int v : edges[u]) dfs(v);
	r[u] = i;
}
 
int build(int id = 1, int l = 0, int r = n) {
	if (l == r - 1) return seg[id] = b[l];
 
	int lChild = id * 2;
	int rChild = id * 2 + 1;
	int mid = (l + r) / 2;
 
	return seg[id] = build(lChild, l, mid) + build(rChild, mid, r);
}
 
inline void updateNode(int id, int l, int r) {
	lzy[id] ^= 1;
	seg[id] = (r - l) - seg[id];
}
 
inline void shift(int id, int l, int r) {
	int lChild = id * 2;
	int rChild = id * 2 + 1;
	int mid = (l + r) / 2;
 
	if (lzy[id] == 0) {
		return;
	}
 
	updateNode(lChild, l, mid);
	updateNode(rChild, mid, r);
 
	lzy[id] = 0;
}
 
int update(int x, int y, int id = 1, int l = 0, int r = n) {
	if (x >= r || y <= l) return seg[id];
 
	if (x <= l && y >= r) {
		updateNode(id, l, r);
		return seg[id];
	}
 
	shift(id, l, r);
 
	int lChild = id * 2;
	int rChild = id * 2 + 1;
	int mid = (l + r) / 2;
 
	return seg[id] = update(x, y, lChild, l, mid) + update(x, y, rChild, mid, r);
}
 
int get(int x, int y, int id = 1, int l = 0, int r = n) {
	if (x >= r || y <= l) return 0;
	if (x <= l && y >= r) return seg[id];
 
	shift(id, l, r);
 
	int lChild = id * 2;
	int rChild = id * 2 + 1;
	int mid = (l + r) / 2;
 
	return get(x, y, lChild, l, mid) + get(x, y, rChild, mid, r);
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (i = 2; i <= n; ++i) {
		cin>>p;
		edges[p].push_back(i);
	}
	for (i = 1; i <= n; ++i) {
		cin>>a[i];
	}
	i = 0;
	dfs();
	build();
	cin >> q;
	while (q--) {
		cin>>s>>u;
 
		if (s[0] == 'p')
			update(l[u], r[u]);
		else
			cout<< get(l[u], r[u])<<endl;
	}
	return 0;
}