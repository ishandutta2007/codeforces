#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iomanip>

using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		vector <int> dp(n);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] != '*') continue;
			dp[i] = mod;
			for (int j = i - 1; j >= 0; --j) {
				if (i - j > k) break;
				if (s[j] != '*') continue;
				dp[i] = min(dp[i], dp[j] + 1);
			}
			if (dp[i] == mod) dp[i] = 1;
			ans = max(ans, dp[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}