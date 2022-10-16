#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 998244353;

int modpow(int n, int k) {
	int ans = 1;
	while (k) {
		if (k % 2) ans = (ans*n) % M;
		n = (n*n) % M; k /= 2;
	}
	return ans;
}

void solve() {
	int n, m, k, q; cin >> n >> m >> k >> q;
	vector<pair<int, int>> a(q);
	for (int i = 0; i < q; i++) {
		cin >> a[i].first >> a[i].second;
	}
	reverse(a.begin(), a.end());

	int cc = 0;
	set<int> row, col;
	for (auto [x, y]: a) {
		if (row.count(x) && col.count(y)) continue;
		if (row.size() == n || col.size() == m) continue;
		cc++;
		row.insert(x);
		col.insert(y);
	}

	cout << modpow(k, cc) << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}