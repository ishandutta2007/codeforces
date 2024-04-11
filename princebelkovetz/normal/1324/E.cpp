#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#define int long long
#define endl "\n"
#define debug(x) cout << #x << " actually equals " << x << endl
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
using namespace std;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(3);
	int n, h, l, r; cin >> n >> h >> l >> r;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	vector <vector <int>> dp(n + 1, vector <int>(h, -1));
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < h; ++j) {
			if (dp[i][j] < 0) continue;
			int jj = (j + a[i]) % h;
			dp[i + 1][jj] = max(dp[i][j] + (int)(l <= jj and jj <= r), dp[i + 1][jj]);
			jj += h - 1; jj %= h;
			dp[i + 1][jj] = max(dp[i][j] + (int)(l <= jj and jj <= r), dp[i + 1][jj]);
		}
	}
	int ans = 0;
	for (auto x : dp[n]) ans = max(ans, x);
	cout << ans << endl;
	return 0;
}