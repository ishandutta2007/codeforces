#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<string> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		vector<vector<int>> dp(n, vector<int>(m));

		for (int j = 0; j < m; j++) {
			dp[n - 1][j] = a[n - 1][j] == '*';
		}

		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '*') {
					if (j == 0 || j == m - 1) {
						dp[i][j] = a[i][j] == '*';
					} else {
						dp[i][j] = 1 + min({dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]});
					}
				}
			}
		}

		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += accumulate(dp[i].begin(), dp[i].end(), 0);
		}
		cout << sum << '\n';
	}
	return 0;
}