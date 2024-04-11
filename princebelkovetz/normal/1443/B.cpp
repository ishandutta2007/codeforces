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
const int mod = 998244353;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt --> 0) {
		int a, b; cin >> a >> b;
		string s; cin >> s;
		int n = s.size();
		vector <vector <int>> dp(n + 1, vector <int>(2));
		dp[0][0] = 0;
		dp[0][1] = mod;
		for (int i = 1; i <= n; ++i) {
			if (s[i - 1] == '1') {
				dp[i][1] = min(dp[i - 1][0] + a, dp[i - 1][1]);
				dp[i][0] = mod;
			}
			else {
				dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
				dp[i][1] = min(dp[i - 1][0] + b + a, dp[i - 1][1] + b);
			}
		}
		cout << min(dp[n][0], dp[n][1]) << '\n';
	}
	return 0;
}