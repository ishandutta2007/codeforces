#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 998244353, N = 1e5 + 2, bb = 32;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector <int> a(n);
	for (auto& x : a) cin >> x;
	 
	vector <int> dp(n + 1, mod);

	dp[0] = 0;

	int ans = 0;

	for (int i = 0; i < n; ++i) {
		int id = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
		ans = max(ans, id);
		dp[id] = min(dp[id], a[i]);
	}

	cout << ans << '\n';


	return 0;
}