#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	//dp[i] = min cost of filling in all >= i
	//dp[i] = min cost of filling in all >= i when router at i

	constexpr long long inf = (long long)1e15;

	vector<array<long long, 2>> dp(n + 1, {inf, inf});
	dp[n][0] = 0, dp[n][1] = inf;

	array<deque<int>, 2> d;
	d[0] = d[1] = {n};
	for (int i = n - 1; i >= 0; i--) {
		if (!d[1].empty()) {
			int j = d[1].front();
			dp[i][0] = min(dp[i][0], dp[j][1]);
		}
		if (s[i] == '0') {
			dp[i][0] = min(dp[i][0], i + 1 + dp[i + 1][0]);
		} else {
			dp[i][1] = min(dp[i][1], i + 1 + dp[d[0].front()][0]);
			dp[i][0] = min(dp[i][0], dp[i][1]);
		}
		for (int j = 0; j < 2; j++) {
			auto &q = d[j];
			while (!q.empty() && dp[q.back()][j] >= dp[i][j]) {
				q.pop_back();
			}
			q.push_back(i);
			if (q.front() == i + k + !j) {
				q.pop_front();
			}
		}
//		cout << dp[i][0] << ' ' << dp[i][1] << '\n';
	}
	cout << dp.front()[0] << '\n';
	return 0;
}