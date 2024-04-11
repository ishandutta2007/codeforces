#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>

using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n, k; cin >> n >> k;
	vector <vector <int>> a(k, vector <int>(n));
	for (auto& x : a)
		for (auto& y : x) cin >> y;
	vector <vector <int>> g(n);
	vector <vector <int>> ids(k, vector <int>(n));
	for (int j = 0; j < k; ++j) {
		for (int i = 0; i < n; ++i) {
			ids[j][a[j][i] - 1] = i;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			bool ok = true;
			for (int s = 0; s < k; ++s)
				if (ids[s][j] <= ids[s][i]) ok = false;
			if (ok) g[i].push_back(j);
		}
	}
	vector <int> dp(n, 1);
	for (int i = 0; i < n; ++i) {
		for (auto x : g[a[0][i] - 1])
			dp[x] = max(dp[x], dp[a[0][i] - 1] + 1);
	}
	int ans = 0;
	for (auto& x : dp) ans = max(ans, x);
	cout << ans << '\n';
}