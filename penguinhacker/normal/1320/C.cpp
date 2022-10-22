#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=200000;
struct lazy_seg_tree {
	const int ID=-2e9;
	int n;
	vector<int> seg, lazy;
	lazy_seg_tree(int _n) : n(_n) {
		seg.resize(4*n);
		lazy.resize(4*n);
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

	int qry() {assert(lazy[1]==0); return seg[1];}
};

int n, m, r;
ar<int, 2> att[mxN], def[mxN];
ar<int, 3> enemy[mxN];
int ans=INT_MIN;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;
	for (int i=0; i<n; ++i)
		cin >> att[i][0] >> att[i][1];
	for (int i=0; i<m; ++i)
		cin >> def[i][0] >> def[i][1];
	sort(att, att+n); sort(def, def+m);

	lazy_seg_tree tree(m);
	for (int i=0; i<m; ++i)
		tree.upd(i, i, -def[i][1]);
	for (int i=0; i<r; ++i)
		cin >> enemy[i][0] >> enemy[i][1] >> enemy[i][2];
	sort(enemy, enemy+r);
	int pt=0;
	for (int i=0; i<n; ++i) {
		while(pt<r&&enemy[pt][0]<att[i][0]) {
			int d=enemy[pt][1];
			if (d<def[m-1][0]) {
				ar<int, 2> temp={d+1, -1};
				int place=lower_bound(def, def+m, temp)-def;
				tree.upd(place, m-1, enemy[pt][2]);
			}
			++pt;
		}
		ans=max(ans, tree.qry()-att[i][1]);
	}
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/