#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a[300000], b[300000];
void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	sort(a, a + n);
	ll ans = 0;
	for (int i = 0; i < n; ++i) ans += b[a[i]];
	ll cur = ans;
	int offset = INT_MAX;
	for (int i = n - 1; i >= 0; --i) {
		offset = min(offset - 1, a[i]);
		if (offset < 0) break;
		cur -= b[a[i]];
		cur += b[n - i - 1];
		ans = min(ans, cur);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}