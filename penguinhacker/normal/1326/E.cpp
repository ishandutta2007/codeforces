#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

struct seg_tree {
	const int ID=0;
	int n;
	vector<int> seg, lazy;
	seg_tree(int _n) : n(_n) {
		seg.assign(4*n, ID);
		lazy.assign(4*n, 0);
	}

	int combine(int a, int b) {return max(a, b);}
	void push(int u, int l, int r) {
		seg[u]+=lazy[u];
		if (l!=r) lazy[2*u]+=lazy[u], lazy[2*u+1]+=lazy[u];
		lazy[u]=0;
	}
	void pull(int u) {seg[u]=combine(seg[2*u], seg[2*u+1]);}

	void build(int a[], int u, int l, int r) {
		if (l==r) { seg[u]=a[l]; return; }
		int mid=(l+r)/2;
		build(a, 2*u, l, mid), build(a, 2*u+1, mid+1, r);
		pull(u);
	}
	void build(int a[]) {build(a, 1, 0, n-1);}

	void upd(int x, int y, int val, int u, int l, int r) {
		push(u, l, r); if (l>y||r<x) return;
		if (x<=l&&r<=y) { lazy[u]+=val; push(u, l, r); return; }
		int mid=(l+r)/2; upd(x, y, val, 2*u, l, mid), upd(x, y, val, 2*u+1, mid+1, r);
		pull(u);
	}
	void upd(int x, int y, int val) {upd(x, y, val, 1, 0, n-1);}

	int qry(int x, int y, int u, int l, int r) {
		push(u, l, r); if (l>y||r<x) return ID;
		if (x<=l&&r<=y) return seg[u];
		int mid=(l+r)/2;
		return combine(qry(x, y, 2*u, l, mid), qry(x, y, 2*u+1, mid+1, r));
	}
	int qry(int x, int y) {return qry(x, y, 1, 0, n-1);}
};

const int mxN=300000;
int n, a[mxN], pos[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	seg_tree t(n);
	for (int i=0; i<n; ++i)
		cin >> a[i], --a[i], pos[a[i]]=i;
	int ans=n-1;
	t.upd(0, pos[ans], 1);
	for (int i=0; i<n; ++i) {
		cout << ans+1 << '\n';
		int x; cin >> x, --x;
		t.upd(0, x, -1);
		while(t.qry(0, n-1)<=0)
			t.upd(0, pos[--ans], 1);
	}
	return 0;
}