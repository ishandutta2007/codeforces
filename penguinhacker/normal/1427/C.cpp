#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int INF = 1e9;
int n, r;
ar<int, 3> e[100001]; //time, x, y

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> n;
	e[0] = {0, 1, 1};
	for (int i = 1; i <= n; ++i) {
		cin >> e[i][0] >> e[i][1] >> e[i][2];
	}
	int best = -INF;
	vector<int> dp(n + 1, -INF);
	dp[0] = 0;
	for (int lb = 0, i = 1; i <= n; ++i) {
		while (lb < i && e[i][0] - e[lb][0] >= 2 * (r - 1)) {
			best = max(best, dp[lb++]);
		}
		dp[i] = best + 1;
		for (int j = lb; j < i; ++j) {
			if (abs(e[i][1] - e[j][1]) + abs(e[i][2] - e[j][2]) <= e[i][0] - e[j][0]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	cout << *max_element(dp.begin(), dp.end());
	return 0;
}