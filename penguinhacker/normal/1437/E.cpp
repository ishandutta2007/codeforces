#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

template<class T> struct seg_tree {
	const T ID=1e9;
	int n;
	vector<T> seg, lazy;
	seg_tree(int _n) : n(_n) {
		seg.assign(4*n, ID);
		lazy.assign(4*n, 0);
	}

	void push(int u, int l, int r) {
		seg[u]+=lazy[u];
		if (l!=r) lazy[2*u]+=lazy[u], lazy[2*u+1]+=lazy[u];
		lazy[u]=0;
	}
	void pull(int u) {seg[u]=min(seg[2*u], seg[2*u+1]);}

	void build(int a[], int u, int l, int r) {
		if (l==r) { seg[u]=a[l]; return; }
		int mid=(l+r)/2;
		build(a, 2*u, l, mid), build(a, 2*u+1, mid+1, r);
		pull(u);
	}
	void build(int a[]) {build(a, 1, 0, n-1);}

	void upd(int x, int y, T val, int u, int l, int r) {
		push(u, l, r); if (l>y||r<x) return;
		if (x<=l&&r<=y) { lazy[u]+=val; push(u, l, r); return; }
		int mid=(l+r)/2; upd(x, y, val, 2*u, l, mid), upd(x, y, val, 2*u+1, mid+1, r);
		pull(u);
	}
	void upd(int x, int y, T val) {upd(x, y, val, 1, 0, n-1);}

	void set(int ind, T val, int u, int l, int r) {
		push(u, l, r); if (l>ind||r<ind) return;
		if (l==r) { seg[u]=min(seg[u], val); return; }
		int mid=(l+r)/2; set(ind, val, 2*u, l, mid), set(ind, val, 2*u+1, mid+1, r);
		pull(u);
	}
	void set(int ind, T val) {set(ind, val, 1, 0, n-1);}

	T qry(int x, int y, int u, int l, int r) {
		push(u, l, r); if (l>y||r<x) return ID;
		if (x<=l&&r<=y) return seg[u];
		int mid=(l+r)/2;
		return min(qry(x, y, 2*u, l, mid), qry(x, y, 2*u+1, mid+1, r));
	}
	T qry(int x, int y) {return qry(x, y, 1, 0, n-1);}
};



const int mxN = 500000, INF = 1e9;
int n, k, ans = 0;
vector<int> a;

void solve(int l, int r) {
	//cerr << l << " " << r << "\n";
	if (a[r] - a[l] < 0) {cout << -1; exit(0);}
	vector<int> d;
	for (int i = l; i <= r; ++i) d.push_back(a[i]);
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end()) - d.begin());

	auto Get = [&](int x) {
		return lower_bound(d.begin(), d.end(), x) - d.begin();
	};
	int sz = d.size();
	seg_tree<int> t(sz);
	t.set(Get(a[l]), 0);
	for (int i = l + 1; i <= r; ++i) {
		int x = Get(a[i]);
		t.upd(0, sz - 1, 1);
		t.set(x, t.qry(0, x) - 1);
	}
	int ret = t.qry(Get(a[r]), Get(a[r]));
	//cout << ret << "\n";
	ans += ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	a.resize(n + 2);
	vector<int> b(k + 2);
	a[0] = -INF, a[n + 1] = INF + 2 * mxN;
	b[0] = 0, b[k + 1] = n + 1;
	for (int i = 1; i <= n; ++i) cin >> a[i], a[i] -= i;
	for (int i = 1; i <= k; ++i) cin >> b[i];
	for (int i = 1; i <= k + 1; ++i) solve(b[i - 1], b[i]);
	cout << ans;
	return 0;
}