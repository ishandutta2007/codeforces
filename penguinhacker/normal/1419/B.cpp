#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll x;
void solve() {
	cin >> x;
	int ans = 0;
	for (int i = 1; ; ++i) {
		ll cur = (1 << i) - 1;
		ll cost = cur * (cur + 1) / 2;
		if (cost > x) {
			break;
		}
		x -= cost;
		++ans;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}