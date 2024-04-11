#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#define endl "\n";
//define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

void solve() {
	int n, cur = 1, l, r, q;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	map <pair <int, int>, pair <int, int>> dp;
	while (cur <= n) {
		for (int i = 0; i < n; i++) {
			if (cur == 1) {
				dp[{i, i}] = { a[i], 0 };
			}
			else {
				l = i;
				r = i + cur - 1;
				dp[{i, i + cur - 1}] = { (dp[{l, r - cur / 2}].first + dp[{r - cur / 2 + 1, r}].first) % 10 , dp[{l, r - cur / 2}].second + dp[{r - cur / 2 + 1, r}].second };
				if (dp[{l, r - cur / 2}].first + dp[{r - cur / 2 + 1, r}].first >= 10) {
					dp[{i, i + cur - 1}].second++;
				}
			}
		}
		cur *= 2;
	}
	/*for (auto x : dp) {
		cout << x.first.first << " " << x.first.second << " " << x.second.first << " " << x.second.second << endl;
	}*/
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> l >> r;
		cout << dp[{l - 1, r - 1}].second << endl;
	}

}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}