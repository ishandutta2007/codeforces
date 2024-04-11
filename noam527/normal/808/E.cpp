/*
Time: O(N lg N), Memory: O(max(N, M))
Using: Greedy (after sorting), DP.
*/
#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

ll dp[300001][3];
int n, m, w, c;
vector<vector<ll>> t(3);

void solve() {
	dp[0][0] = 0, dp[0][1] = t[0].size(), dp[0][2] = t[1].size();
	if (t[0].size() > 0)
		dp[1][0] = t[0][t[0].size() - 1], dp[1][1] = t[0].size() - 1, dp[1][2] = t[1].size();
	else
		dp[1][0] = 0, dp[1][1] = t[0].size(), dp[1][2] = t[1].size();
	for (int i = 2; i <= m; i++) {
		if (dp[i - 1][1] == 0) {
			if (dp[i - 2][2] == 0)
				dp[i][0] = dp[i - 1][0], dp[i][1] = 0, dp[i][2] = 0;
			else if (dp[i - 2][0] + t[1][dp[i - 2][2] - 1] > dp[i - 1][0])
				dp[i][0] = dp[i - 2][0] + t[1][dp[i - 2][2] - 1], dp[i][1] = dp[i - 2][1], dp[i][2] = dp[i - 2][2] - 1;
			else
				dp[i][0] = dp[i - 1][0], dp[i][1] = dp[i - 1][1], dp[i][2] = dp[i - 1][2];
		}
		else {
			if (dp[i - 2][2] == 0)
				dp[i][0] = dp[i - 1][0] + t[0][dp[i - 1][1] - 1], dp[i][1] = dp[i - 1][1] - 1, dp[i][2] = dp[i - 1][2];
			else if (dp[i - 1][0] + t[0][dp[i - 1][1] - 1] > dp[i - 2][0] + t[1][dp[i - 2][2] - 1])
				dp[i][0] = dp[i - 1][0] + t[0][dp[i - 1][1] - 1], dp[i][1] = dp[i - 1][1] - 1, dp[i][2] = dp[i - 1][2];
			else
				dp[i][0] = dp[i - 2][0] + t[1][dp[i - 2][2] - 1], dp[i][1] = dp[i - 2][1], dp[i][2] = dp[i - 2][2] - 1;
		}
	}
	//for (int i = 0; i <= m; i++) cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
	int lim = m;
	ll mx = dp[lim][0], sum = 0;
	lim -= 3;
	for (int i = t[2].size() - 1; i >= 0 && lim >= 0; i--, lim -= 3)
		sum += t[2][i], mx = max(mx, sum + dp[lim][0]);
	cout << mx << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> w >> c, t[w - 1].push_back(c);
	for (int i = 0; i < 3; i++) sort(t[i].begin(), t[i].end());
	solve();
	return 0;
}