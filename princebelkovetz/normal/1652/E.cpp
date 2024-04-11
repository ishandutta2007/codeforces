#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iomanip>
#include <queue>
#include <set>
#include <map>

using namespace std;
#pragma GCC optimize("O3")
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
const int mod = 998244353, N = 1e5 + 2, root = 350;

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	int ans = min(n, 2);
	vector <int> all;
	for (int i = -root; i <= root; ++i) {
		all.clear();
		for (int j = 0; j < n; ++j) {
			all.push_back(a[j] + j * i);
		}
		sort(all.begin(), all.end());
		for (int i = 0; i < all.size(); ) {
			int j = i;
			while (j < all.size() and all[j] == all[i])
				j++;
			ans = max(ans, j - i);
			i = j;
		}
	}
	vector <vector <int>> dp(n), ids(n);
	for (int i = 0; i < n; ++i) {
		vector <pair <int, int>> curDp;
		for (int j = i - 1; j >= 0 and abs(j - i) <= root; --j) {
			if ((a[i] - a[j]) % (i - j) != 0) continue;
			int d = (a[i] - a[j]) / (i - j);
			int id = lower_bound(ids[j].begin(), ids[j].end(), d) - ids[j].begin();
			if (id < ids[j].size() and ids[j][id] == d)
				curDp.push_back({ d, dp[j][id] + 1 });
			else
				curDp.push_back({ d, 2 });
			ans = max(ans, curDp.back().second);
		}
		sort(curDp.begin(), curDp.end());
		for (auto& x : curDp) {
			if (!ids[i].empty() and ids[i].back() == x.first)
				ids[i].pop_back(), dp[i].pop_back();
			ids[i].push_back(x.first);
			dp[i].push_back(x.second);
		}
	}
	cout << n - ans << '\n';


}