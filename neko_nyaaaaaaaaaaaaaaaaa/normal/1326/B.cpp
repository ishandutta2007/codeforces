#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int mx = a[0];
	cout << mx << ' ';
	for (int i = 1; i < n; i++) {
		int nxt = mx + a[i];
		cout << nxt << ' ';
		mx = max(mx, nxt);
	}

	return 0;
}