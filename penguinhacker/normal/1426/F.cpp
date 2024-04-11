#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	vector<ll> dp(4);
	dp[0] = 1;
	for (char c : s) {
		if (c == 'a') {
			dp[1] = (dp[1] + dp[0]) % MOD;
		}
		else if (c == 'b') {
			dp[2] = (dp[2] + dp[1]) % MOD;
		}
		else if (c == 'c') {
			dp[3] = (dp[3] + dp[2]) % MOD;
		}
		else if (c == '?') {
			vector<ll> nxt = dp;
			nxt[3] = (dp[3] * 3 + dp[2]) % MOD;
			nxt[2] = (dp[2] * 3 + dp[1]) % MOD;
			nxt[1] = (dp[1] * 3 + dp[0]) % MOD;
			nxt[0] = (dp[0] * 3) % MOD;
			swap(dp, nxt);
		}
		else assert(0);
	}
	cout << dp[3];
	return 0;
}