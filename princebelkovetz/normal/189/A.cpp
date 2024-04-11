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
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
int fastpow(int a, int b) {
	if (!b) return 1ll;
	if (b % 2 == 1) return fastpow(a, b - 1) * a;
	int t = fastpow(a, b / 2);
	return t * t;
} 
struct op {
	int l, r, d;
};
void solve() {
	int n; vector <int> a(3);
	cin >> n >> a[0] >> a[1] >> a[2];
	sort(a.begin(), a.end());
	vector <bool> dp(n + 1); vector <int> prev(n + 1, 0);

	dp[0] = true;
	for (int i = 1; i <= n; ++i) {
		if (i >= a[0] and dp[i - a[0]]) {
			dp[i] = true;
			prev[i] = max(prev[i - a[0]] + 1, prev[i]);
		}
		if (i >= a[1] and dp[i - a[1]]) {
			dp[i] = true;
			prev[i] = max(prev[i - a[1]] + 1, prev[i]);
		}
		if (i >= a[2] and dp[i - a[2]]) {
			dp[i] = true;
			prev[i] = max(prev[i - a[2]] + 1, prev[i]);
		}
	}
	/*for (auto x : dp) cout << x << " ";
	cout << endl;
	for (auto x : prev) cout << x << " ";*/

	cout << prev[n] << endl;

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