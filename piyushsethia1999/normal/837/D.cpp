#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }
int dp[300][7004];
int ma[300];
int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int k; cin >> k;
	memset(dp, 0x8f, sizeof(dp)); dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		long long x; cin >> x;
		int t = 0;
		int f = 0;
		while (x % 2ll == 0) {
			x /= 2ll;
			t++;
		} 
		while (x % 5ll == 0) {
			x /= 5ll;
			f++;
		} 
		for (int j = k - 1; j >= 0; --j) {
			for (int o = (min(ma[j], 7000 - f)); o >= 0; --o)
				dp[j + 1][o + f] = max(dp[j + 1][o + f], dp[j][o] + t);
			ma[j] = min(ma[j] + f, 7000);
		}
		ma[k] = min(ma[k] + f, 7000);
	}
	int y = 0;
	for (int i = 0; i <= ma[k]; ++i) y = max(y, min(i, dp[k][i]));
	cout << y;
}