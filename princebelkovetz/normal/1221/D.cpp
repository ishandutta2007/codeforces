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
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		vector <int> a(n), b(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i] >> b[i];
		vector <vector <int>> dp(n, vector <int>(3, -1));
		dp[0][0] = 0;
		dp[0][1] = b[0], dp[0][2] = 2 * b[0];
		for (int i = 1; i < n; ++i) {
			for (int x = 0; x < 3; ++x) {
				for (int y = 0; y < 3; ++y) {
					if (a[i - 1] + x == a[i] + y) continue;
					if (dp[i][y] == -1)
						dp[i][y] = dp[i - 1][x] + b[i] * y;
					else
						dp[i][y] = min(dp[i][y], dp[i - 1][x] + b[i] * y);
				}
			}
		}
		int ans = 2e18;
		if (dp[n - 1][0] != -1) ans = min(ans, dp[n - 1][0]);
		if (dp[n - 1][1] != -1) ans = min(ans, dp[n - 1][1]);
		if (dp[n - 1][2] != -1) ans = min(ans, dp[n - 1][2]);
		cout << ans << '\n';
	}
	return 0;
}