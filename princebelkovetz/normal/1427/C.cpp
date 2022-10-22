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
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int inf = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int r, n; cin >> r >> n;
	vector <vector <int>> a(n + 1, vector <int>(3, 1));
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j)
			cin >> a[i][j];
	}
	vector <int> dp(n + 1, -inf);
	int curmax = 0;
	a[0][0] = 0;
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i - 1; j >= 0 and j >= i - 2 * r - 1; --j) {
			if (abs(a[j][1] - a[i][1]) + abs(a[j][2] - a[i][2]) <= a[i][0] - a[j][0]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (i >= 2 * r + 1) {
			curmax = max(curmax, dp[i - 2 * r - 1]);
			dp[i] = max(dp[i], curmax + 1);
		}
	}
	int ans = 0;
	for (auto x : dp) ans = max(x, ans);
	cout << ans << '\n';
	return 0;
}