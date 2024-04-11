#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 0;
using namespace std;

const int N = 505;

int n;
int a[N];
int dp[2][N][N][2];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
		dp[0][i][j][0] = dp[0][i][j][1] = dp[1][i][j][0] = dp[1][i][j][1] = -md;
	dp[0][0][0][0] = 0;
	for (int j = 1; j <= n; j++) dp[0][j][1][0] = j * a[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= i + 1; k++) {
				int x;
				// first iteration
				x = -md;
				if (k <= i) x = dp[i & 1 ^ 1][j][k][0];
				dp[i & 1][j][k][0] = x;

				if (OO) {
					cout << "dp[" << i << "][" << j << "][" << k << "][0] = " << dp[i & 1][j][k][0] << '\n';
				}

				// second iteration
				x = -md;
				if (0 < j && j <= i + 1 && 0 <= k - j + i && k - j + i <= i)
					x = max(x, a[i] + dp[i & 1 ^ 1][j - 1][k - j + i][0]);
				if (0 < j && j <= n)
					x = max(x, a[i] + dp[i & 1][j - 1][k][1]);
				dp[i & 1][j][k][1] = x;
				if (dp[i & 1][j][k][0] < x)
					dp[i & 1][j][k][0] = x;
				if (OO) {
					cout << "dp[" << i << "][" << j << "][" << k << "][1] = " << dp[i & 1][j][k][1] << '\n';
				}
			}
		}
	}
	int res = -md;
	for (int j = 0; j <= n; j++) {
		for (int k = 0; k <= n; k++) {
			res = max(res, dp[(n - 1) & 1][j][k][0]);
		}
	}
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}