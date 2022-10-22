#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define INF INT_MAX

struct node {
	int best=INF;
	int a[9];
	node() {fill(a, a+9, INF);}
	node(int x) {
		int temp=x;
		for (int i=0; i<9; ++i) {
			a[i]=(temp%10)?x:INF;
			temp/=10;
		}
	}
	node combine(node o) {
		node ret;
		ret.best=min(best, o.best);
		for (int i=0; i<9; ++i) {
			int x=a[i], y=o.a[i];
			ret.a[i]=min(x, y);
			if (x<INF&&y<INF)
				ret.best=min(ret.best, x+y);
		}
		return ret;
	}
};

struct seg_tree {
	int n;
	vector<node> seg;
	seg_tree(int _n) : n(_n) {seg.assign(4*n, node());}

	void pull(int u) {seg[u]=seg[2*u].combine(seg[2*u+1]);}

	void build(int a[], int u, int l, int r) {
		if (l==r) {seg[u]=node(a[l]); return;}
		int mid=(l+r)/2;
		build(a, 2*u, l, mid), build(a, 2*u+1, mid+1, r);
		pull(u);
	}
	void build(int a[]) {build(a, 1, 0, n-1);}
	void upd(int x, int val, int u, int l, int r) {
		if (l>x||r<x) return;
		if (l==r) {seg[u]=node(val); return;}
		int mid=(l+r)/2;
		upd(x, val, 2*u, l, mid), upd(x, val, 2*u+1, mid+1, r);
		pull(u);
	}
	void upd(int x, int val) {upd(x, val, 1, 0, n-1);}
	node qry(int x, int y, int u, int l, int r) {
		if (l>y||r<x) return node();
		if (x<=l&&r<=y) return seg[u];
		int mid=(l+r)/2;
		node a=qry(x, y, 2*u, l, mid), b=qry(x, y, 2*u+1, mid+1, r);
		return a.combine(b);
	}
	int qry(int x, int y) {node temp=qry(x, y, 1, 0, n-1); return temp.best==INF?-1:temp.best;}
};

int n, m, a[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	seg_tree tree(n);
	tree.build(a);
	while(m--) {
		int type, x, y;
		cin >> type >> x >> y;
		if (type==1) {
			tree.upd(x-1, y);
		}
		if (type==2) {
			cout << tree.qry(x-1, y-1) << '\n';
		}
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/