#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	int ans = 0;
	for (int i = 1; i < n; i++) {
		ans = __gcd(ans, abs(a[i] - a[i-1]));
	}
	//cout << ans << '\n';

	int g1 = k % ans;
	int g2 = a[0] % ans;
	if (g1 < 0) g1 += ans;
	if (g2 < 0) g2 += ans;

	if (g1 != g2) cout << "NO\n";
	else cout << "YES\n";
}
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}