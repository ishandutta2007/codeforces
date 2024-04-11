#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

template<class T> struct seg_tree {
	const T ID = 1e9;
	T combine(T a, T b) {
		return min(a, b);
	}

	int n;
	vector<T> seg;
	void init(int _n) {
		n = _n;
		seg.assign(4 * n, ID);
	}

	void pull(int u) {
		seg[u] = combine(seg[2 * u], seg[2 * u + 1]);
	}

	void build(vector<T>& a, int u, int l, int r) {
		if (l == r) {
			seg[u] = a[l];
			return;
		}
		int mid = (l + r) / 2;
		build(a, 2 * u, l, mid);
		build(a, 2 * u + 1, mid + 1, r);
		pull(u);
	}

	void build(vector<T>& a) {
		build(a, 1, 0, n - 1);
	}

	void upd(int x, T val, int u, int l, int r) {
		if (l > x || r < x) return;
		if (l == r) {
			seg[u] = val;
			return;
		}
		int mid = (l + r) / 2;
		upd(x, val, 2 * u, l, mid);
		upd(x, val, 2 * u + 1, mid + 1, r);
		pull(u);
	}

	void upd(int x, T val) {
		upd(x, val, 1, 0, n - 1);
	}

	T qry(int x, int y, int u, int l, int r) {
		if (l > y || r < x) return ID;
		if (x <= l && r <= y) return seg[u];
		int mid = (l + r) / 2;
		return combine(qry(x, y, 2 * u, l, mid), qry(x, y, 2 * u + 1, mid + 1, r));
	}

	T qry(int x, int y) {
		return qry(x, y, 1, 0, n - 1);
	}
};

const int mxN=3e5;
int n, a[mxN], dp[mxN];

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	seg_tree<int> st1, st2;
	st1.init(n);
	st2.init(n);
	st1.upd(0, 0), st2.upd(0, 0);
	vector<int> ic={0}, dc={0};
	for (int i=1; i<n; ++i) {
		dp[i]=dp[i-1]+1;
		vector<int> ri, rd;
		while(ic.size()&&a[i]<a[ic.back()]) {
			ri.push_back(ic.back());
			ic.pop_back();
		}
		while(dc.size()&&a[i]>a[dc.back()]) {
			rd.push_back(dc.back());
			dc.pop_back();
		}
		dp[i]=min(dp[i], st1.qry(dc.size()?dc.back()+1:0, i)+1);
		dp[i]=min(dp[i], st2.qry(ic.size()?ic.back()+1:0, i)+1);
		for (int j : ri)
			st1.upd(j, 1e9);
		for (int j : rd)
			st2.upd(j, 1e9);
		st1.upd(i, dp[i]);
		st2.upd(i, dp[i]);
		ic.push_back(i);
		dc.push_back(i);
	}
	cout << dp[n-1] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}