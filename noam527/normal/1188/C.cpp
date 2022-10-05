#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n, k;
int dp[1005][1005] = {};
int a[1005];

int calc(int X) {
	if (OO) cout << "X " << X << '\n';
	int nxt = 0;
	for (int j = 0; j <= k; j++) dp[0][j] = 0;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		while (a[nxt] + X <= a[i]) nxt++;
		dp[i][0] = 1;
		for (int j = 1; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[nxt - 1][j - 1]) % md;
			if (OO) cout << i << " " << j << ": " << dp[i][j] << '\n';
		}
	}
	if (OO) cout << dp[n][k] << '\n';
	return dp[n][k];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	a[0] = -md;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= 100000 / (k - 1); i++)
		ans = (ans + calc(i)) % md;
	finish(ans);
}