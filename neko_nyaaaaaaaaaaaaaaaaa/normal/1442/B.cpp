#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 998244353;

void remap(int n, vector<int> &a, vector<int> &b) {
	map<int, int> id;
	for (int i = 0; i < n; i++) {
		id[a[i]] = i;
	}
	for (int i = 0; i < b.size(); i++) {
		b[i] = id[b[i]] + 1;
	}
}

void solve() {
	int n, k; cin >> n >> k;
	vector<int> A(n), b(k);
	for (auto &i: A) cin >> i;
	for (auto &i: b) cin >> i;

	remap(n, A, b);

	vector<int> a(n+1);
	for (int i = 0; i < k; i++) {
		a[b[i]] = 1;
	}

	long long ans = 1;
	for (int i: b) {
		int choices = 0;
		if (i-1 > 0 && i-1 <= n && a[i-1] == 0) choices++;
		if (i+1 > 0 && i+1 <= n && a[i+1] == 0) choices++;

		ans = (ans * choices) % M;
		a[i] = 0;
	} 
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}