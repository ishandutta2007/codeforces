#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int d, m;
		cin >> d >> m;
		vector<int> dp(31);
		int ans = 0;
		for (int i = 0; i <= 30; ++i) {
			ll x = min(1 << i, d - (1 << i) + 1);
			if (x <= 0) {
				break;
			}
			dp[i] = x * (ans + 1) % m;
			ans = (ans + dp[i]) % m;
		}
		cout << ans << "\n";
	}
	return 0;
}