#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 500 + 5;

int n, x, a[N], dp[N][N], dp1[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> x;
		for (int i = 1; i <= n; i++) cin >> a[i];

		vector<int> temp(a + 1, a + n + 1);
		temp.push_back(x);
		temp.push_back(0);

		sort(temp.begin(), temp.end());
		temp.erase(unique(temp.begin(), temp.end()), temp.end());

		for (int j : temp) {
			for (int xx : temp) {
				dp[j][xx] = dp1[j][xx] = INT_MAX;
			}
		}

		dp[0][x] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j : temp) {
				for (int xx : temp) {
					dp1[j][xx] = INT_MAX;
				}
			}
			for (int j : temp) {
				for (int xx : temp) {
					if (dp[j][xx] == INT_MAX) continue;
					if (a[i] > xx && xx >= j) {
						dp1[xx][a[i]] = min(dp1[xx][a[i]], 1 + dp[j][xx]);
					}
					if (a[i] >= j) {
						dp1[a[i]][xx] = min(dp1[a[i]][xx], dp[j][xx]);
					}
				}
			}
			for (int j : temp) {
				for (int xx : temp) {
					dp[j][xx] = dp1[j][xx];
				}
			}
		}

		int ans = INT_MAX;
		for (int j : temp) {
			for (int xx : temp) {
				ans = min(ans, dp[j][xx]);
			}
		}
		cout << (ans == INT_MAX ? -1 : ans) << '\n';
	}
	return 0;
}