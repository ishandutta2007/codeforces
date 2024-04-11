#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#define int long long
#define ull unsigned long long
#define ld double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mod = 1e9 + 7;
int bpow(int a, int b) {
	if (!b) return 1;
	if (b & 1) return (a * bpow(a, b - 1)) % mod;
	int t = bpow(a, b / 2);
	return (t * t) % mod;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a)
			cin >> x;
		sort(a.begin(), a.end());
		vector <vector <int>> dp(n + 1, vector <int>(2 * n + 1, mod));
		for (int i = 0; i <= 2 * n; ++i)
			dp[0][i] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 2 * n; ++j) {
				dp[i][j] = mod;
				for (int k = 0; k < j; ++k) {
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(a[i - 1] - j));
				}
			}
		}
		int ans = mod;
		for (auto x : dp[n]) ans = min(ans, x);
		cout << ans << '\n';
	}
	return 0;
}