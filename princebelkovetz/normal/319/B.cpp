#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#define int long long
#define endl "\n"
#define debug(x) cout << #x << " actually equals " << x << endl

using namespace std;
const int mxN = 1e5 + 7;


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(3);
	int n, ans = 0, cur = 0; cin >> n;
	vector <int> a(n), stack, dp(n, 1);
	for (auto& x : a) cin >> x;
	for (int i = 0; i < n; ++i) {

		while (stack.size() and a[stack[stack.size() - 1]] < a[i]) {
			dp[i] = max(dp[i], dp[stack[stack.size() - 1]] + 1);
			stack.pop_back();
		}
		if (!stack.size()) dp[i] = 0;
		stack.push_back(i);
		ans = max(dp[i], ans);
	}
	cout << ans << endl;
	return 0;
}