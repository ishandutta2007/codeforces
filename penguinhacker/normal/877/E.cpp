#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 200000;
int n, q, tin[mxN], tout[mxN], timer = 0;
vector<int> adj[mxN];

void dfs(int u = 0) {
	tin[u] = timer++;
	for (int v : adj[u]) dfs(v);
	tout[u] = timer - 1;
}

int a[mxN], ord[mxN], seg[4 * mxN];
bool lazy[4 * mxN];

void build(int u = 1, int l = 0, int r = n - 1) {
	if (l == r) {
		seg[u] = a[ord[l]];
		//cout << l << " " << a[ord[l]] << "\n";
		return;
	}
	int mid = (l + r) / 2;
	build(2 * u, l, mid);
	build(2 * u + 1, mid + 1, r);
	seg[u] = seg[2 * u] + seg[2 * u + 1];
}

void push(int u, int l, int r) {
	if (lazy[u]) {
		seg[u] = (r - l + 1) - seg[u];
		if (l != r) {
			lazy[2 * u] ^= 1;
			lazy[2 * u + 1] ^= 1;
		}
		lazy[u] = 0;
	}
}

void upd(int ql, int qr, int u = 1, int l = 0, int r = n - 1) {
	push(u, l, r);
	if (l > qr || r < ql) return;
	if (ql <= l && r <= qr) {
		lazy[u] = 1;
		push(u, l, r);
		return;
	}
	int mid = (l + r) / 2;
	upd(ql, qr, 2 * u, l, mid);
	upd(ql, qr, 2 * u + 1, mid + 1, r);
	seg[u] = seg[2 * u] + seg[2 * u + 1];
}

int qry(int ql, int qr, int u = 1, int l = 0, int r = n - 1) {
	push(u, l, r);
	if (l > qr || r < ql) return 0;
	if (ql <= l && r <= qr) return seg[u];
	int mid = (l + r) / 2;
	return qry(ql, qr, 2 * u, l, mid) + qry(ql, qr, 2 * u + 1, mid + 1, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int x; cin >> x, --x;
		adj[x].push_back(i);
	}
	dfs();
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		ord[tin[i]] = i;
	}
	build();
	//cout << "SUM: " << seg[1] << "\n";
	cin >> q;
	while(q--) {
		string t; cin >> t;
		int u; cin >> u, --u;
		if (t == "pow") {
			upd(tin[u], tout[u]);
		}
		else if (t == "get") {
			cout << qry(tin[u], tout[u]) << "\n";
		}
	}
	return 0;
}