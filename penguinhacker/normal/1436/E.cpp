#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 200000;
int n, a[mxN];
vector<int> oc[mxN];

struct seg_tree {
	const int ID=-1;
	int n;
	vector<int> seg;
	seg_tree(int _n) : n(_n) {seg.assign(4*n, -1);}

	int combine(int a, int b) {return min(a, b);}
	void pull(int u) {seg[u]=combine(seg[2*u], seg[2*u+1]);}

	void upd(int x, int val, int u, int l, int r) {
		if (l>x||r<x) return;
		if (l==r) {seg[u]=val; return;}
		int mid=(l+r)/2;
		upd(x, val, 2*u, l, mid), upd(x, val, 2*u+1, mid+1, r);
		pull(u);
	}
	void upd(int x, int val) {upd(x, val, 1, 0, n-1);}
	int qry(int ql, int u, int l, int r) {
		if (l == r) return l;
		int mid = (l + r) / 2;
    	if (seg[2 * u] < ql) return qry(ql, 2 * u, l, mid);
    	return qry(ql, 2 * u + 1, mid + 1, r);
	}
	int qry(int ql) {return qry(ql, 1, 0, n-1);}
};

bool good[mxN];
void solve(vector<pair<int, int>> ranges) {
	vector<vector<int>> qry(mxN);
	for (auto x : ranges) {
		int l = x.first, r = x.second;
		assert(0 <= l && l <= r && r < n);
		qry[r].push_back(l);
	}
	seg_tree t(mxN);
	t.upd(0, mxN);
	for (int i = 0; i < n; ++i) {
		t.upd(a[i], i);
		for (int l : qry[i]) {
			int mex = t.qry(l);
			good[mex] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) oc[i] = {-1};
	for (int i = 0; i < n; ++i) cin >> a[i], oc[a[i]].push_back(i);
	for (int i = 1; i <= n; ++i) oc[i].push_back(n);

	vector<pair<int, int>> ranges = {{0, n - 1}};
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < oc[i].size(); ++j) {
			int x = oc[i][j - 1], y = oc[i][j];
			if (y == x + 1) continue;
			ranges.emplace_back(x + 1, y - 1);
		}
	}
	solve(ranges);
	int ans = 1;
	while(good[ans]) ++ans;
	cout << ans;
	return 0;
}