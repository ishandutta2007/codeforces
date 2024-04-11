#include <bits/stdc++.h>
using namespace std;

const int MAXN = 250009;

int n, a[MAXN];
pair<int, int> tr[4*MAXN];

// max, min

pair<int, int> merge(pair<int, int> x, pair<int, int> y) {
	if (x.first == -1) return y;
	if (y.first == -1) return x;

	pair<int, int> ans = x;
	if (a[y.first] > a[x.first]) ans.first = y.first;
	if (a[y.second] < a[x.second]) ans.second = y.second;
	return ans;
}

void build(int v, int s, int e) {
	if (s == e) {
		tr[v] = {s, s};
	} else {
		int mid = (s+e)/2;
		build(2*v, s, mid);
		build(2*v+1, mid+1, e);

		tr[v] = merge(tr[2*v], tr[2*v+1]);
	}
}

pair<int, int> query(int v, int s, int e, int l, int r) {
	if (r < s || e < l) {
		return {-1, -1};
	}
	if (l <= s && e <= r) {
		return tr[v];
	}
	int mid = (s+e)/2;
	return merge(query(2*v, s, mid, l, r), query(2*v+1, mid+1, e, l, r));
}

int res;

bool inside(int l, int r, int x) {
	if (l > r) swap(l, r);
	return x > l && x < r;
}

void solve(int l, int r) {
	if (l+1 == r) {
		//cout << l << ' ' << r << '\n';
		res++; return;
	}

	auto [mx, mn] = query(1, 1, n, l+1, r-1);
	if (inside(a[l], a[r], a[mx]) && inside(a[l], a[r], a[mn])) {
		//cout << l << ' ' << r << '\n';
		res++; return;
	}

	if (a[mx] > max(a[l], a[r])) {
		solve(l, mx); solve(mx, r);
	} else if (a[mn] < min(a[l], a[r])) {
		solve(l, mn); solve(mn, r);
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << "0\n";
		return;
	}
	build(1, 1, n);

	res = 0;
	solve(1, n);
	cout << res << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}