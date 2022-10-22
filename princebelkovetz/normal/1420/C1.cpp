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
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
signed main() {
	int tt; cin >> tt;
	while (tt--) {
		int n, q; cin >> n >> q;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		vector <vector <int>> dp(n + 1, vector <int>(2));
		for (int i = 0; i < n; ++i) {
			dp[i + 1][0] = max(dp[i][0], dp[i][1] + a[i]);
			dp[i + 1][1] = max(dp[i][1], dp[i][0] - a[i]);
		}
		cout << max(dp[n][0], dp[n][1]) << '\n';
	}
	return 0;
}