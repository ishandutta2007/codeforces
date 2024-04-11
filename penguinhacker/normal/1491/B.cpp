#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, v, h, a[100];

void solve() {
	cin >> n >> v >> h;
	for (int i = 0; i < n; ++i) cin >> a[i];
	int ans = h + min(h, v);
	for (int i = 0; i + 1 < n; ++i) {
		if (abs(a[i] - a[i + 1]) > 1) {
			ans = 0;
			break;
		}
		if (a[i] != a[i + 1]) {
			ans = min(h, v);
		}
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