#include <bits/stdc++.h>
using namespace std;
 
const int INF = 100000007;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	int n, m; cin >> n >> m;
	vector<int> dp(m+1, INF);
	dp[0] = 0;
	
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		int x, s; cin >> x >> s;
		a[i] = {x - s, x + s};
	}
	sort(a.begin(), a.end());

	for (auto [l, r]: a) {
		vector<tuple<int, int, int>> in;
		for (int i = 0; i <= m; i++) {
			// expand by i
			int L = max(1, l - i), R = min(m, r + i), cost = i + dp[L - 1];
			in.emplace_back(cost, L, R);
		}
		sort(in.begin(), in.end());

		vector<int> nxt = dp;
		set<int> ids;
		for (int i = 1; i <= m; i++) {
			ids.insert(i);
		}

		for (auto [c, L, R]: in) {
			for (auto it = ids.lower_bound(L); it != ids.end() && *it <= R;) {
				nxt[*it] = min(c, nxt[*it]);
				it = ids.erase(it);
			}
		}

		swap(dp, nxt);
	}
	cout << dp[m] << '\n';
 
	return 0;
}