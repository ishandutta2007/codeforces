#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

const int N = 5005;

int n, m;
string a, b;
int dp[2][N];

void solve() {
	cin >> n >> m;
	cin >> a >> b;
	int ans = 0;
	for (int j = 0; j < m; j++) {
		dp[0][j] = 0;
		if (j > 0)
			dp[0][j] = max(dp[0][j], dp[0][j - 1] - 1);
		if (a[0] == b[j])
			dp[0][j] = 2;

		ans = max(ans, dp[0][j]);
	}
	for (int i = 1; i < n; i++) {
		dp[i & 1][0] = 0;
		dp[i & 1][0] = max(0, dp[i & 1 ^ 1][0] - 1);
		if (a[i] == b[0])
			dp[i & 1][0] = 2;
		ans = max(ans, dp[i & 1][0]);
		for (int j = 1; j < m; j++) {
			dp[i & 1][j] = 0;
			dp[i & 1][j] = max(dp[i & 1][j], dp[i & 1 ^ 1][j] - 1);
			dp[i & 1][j] = max(dp[i & 1][j], dp[i & 1][j - 1] - 1);
			if (a[i] == b[j])
				dp[i & 1][j] = max(dp[i & 1][j], dp[i & 1 ^ 1][j - 1] + 2);
			ans = max(ans, dp[i & 1][j]);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}