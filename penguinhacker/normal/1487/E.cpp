#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int INF = 1e9;
int n[4], a[150000][4];
int m[3];
set<pair<int, int>> dp[4], bad[3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 4; ++i) cin >> n[i];
	for (int j = 0; j < 4; ++j) for (int i = 0; i < n[j]; ++i) cin >> a[i][j];
	for (int j = 0; j < 3; ++j) {
		cin >> m[j];
		for (int i = 0; i < m[j]; ++i) {
			int x, y; cin >> x >> y, --x, --y;
			bad[j].emplace(x, y);
		}
	}
	for (int i = 0; i < n[0]; ++i) {
		dp[0].emplace(a[i][0], i);
	}
	for (int j = 1; j < 4; ++j) {
		for (int i = 0; i < n[j]; ++i) {
			for (auto it = dp[j - 1].begin(); it != dp[j - 1].end(); ++it) {
				if (bad[j - 1].find({it->second, i}) == bad[j - 1].end()) {
					dp[j].emplace(it->first + a[i][j], i);
					break;
				}
			}
		}
	}
	int ans = dp[3].empty() ? -1 : dp[3].begin()->first;
	cout << ans;
	return 0;
}