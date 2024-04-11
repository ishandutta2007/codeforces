#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int MOD=1e9+7;

int t, n;
pair<ll, bool> dp[2000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i=3; i<=2000000; ++i) {
		dp[i].first=2*dp[i-2].first+dp[i-1].first;
		if (!dp[i-2].second&&!dp[i-1].second) {
			++dp[i].first;
			dp[i].second=1;
		}
		dp[i].first%=MOD;
	}

	cin >> t;
	while(t--) {
		cin >> n;
		cout << 4*dp[n].first%MOD << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/