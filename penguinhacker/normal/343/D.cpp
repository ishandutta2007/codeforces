#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5;
int n, tin[mxN], tout[mxN], st1[1<<20], st2[1<<20], timer;
vector<int> adj[mxN];

void dfs(int u=0, int p=-1) {
	tin[u]=timer++;
	for (int v : adj[u])
		if (v^p)
			dfs(v, u);
	tout[u]=timer-1;
}

void upd1(int ql, int qr, int x, int u=1, int l=0, int r=n-1) {
	if (ql<=l&&r<=qr) {
		st1[u]=x;
		return;
	}
	int mid=(l+r)/2;
	if (ql<=mid)
		upd1(ql, qr, x, 2*u, l, mid);
	if (qr>mid)
		upd1(ql, qr, x, 2*u+1, mid+1, r);
}

int qry1(int i, int u=1, int l=0, int r=n-1) {
	if (l==r)
		return st1[u];
	int mid=(l+r)/2;
	if (i<=mid)
		return max(st1[u], qry1(i, 2*u, l, mid));
	return max(st1[u], qry1(i, 2*u+1, mid+1, r));
}

void upd2(int i, int x, int u=1, int l=0, int r=n-1) {
	if (l==r) {
		st2[u]=x;
		return;
	}
	int mid=(l+r)/2;
	if (i<=mid)
		upd2(i, x, 2*u, l, mid);
	else
		upd2(i, x, 2*u+1, mid+1, r);
	st2[u]=max(st2[2*u], st2[2*u+1]);
}

int qry2(int ql, int qr, int u=1, int l=0, int r=n-1) {
	if (ql<=l&&r<=qr)
		return st2[u];
	int mid=(l+r)/2;
	return max(ql<=mid?qry2(ql, qr, 2*u, l, mid):0, qr>mid?qry2(ql, qr, 2*u+1, mid+1, r):0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	int q; cin >> q;
	for (int i=1; i<=q; ++i) {
		int t, u;
		cin >> t >> u, --u;
		if (t==1) {
			upd1(tin[u], tout[u], i);
		} else if (t==2) {
			upd2(tin[u], i);
		} else {
			cout << (qry1(tin[u])>qry2(tin[u], tout[u])?1:0) << "\n";
		}
	}
	return 0;
}