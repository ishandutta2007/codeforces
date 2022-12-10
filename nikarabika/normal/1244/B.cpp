//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int solve() {
	int n;
	string s;
	cin >> n >> s;
	int first = 1e5,
		last = -1;
	for (int i = 0; i < n; i++)
		if (s[i] == '1')
			smin(first, i), last = i;
	int dp[3][n + 5];
	memset(dp, 0, sizeof dp);
	for (int j = 0; j < n; j++)
		dp[0][j] = max(2 * (j - first + 1), 0);
	for (int j = 0; j < n; j++)
		dp[1][j] = max((j == 0 ? 0 : max(dp[0][j - 1], dp[1][j - 1])) + s[j] - '0' + 1, dp[0][j]);
	int ans = 0;
	for (int j = 0; j < n; j++) {
		int val;
		val = max(0, 2 * (last - j + 1));
		smax(ans, (j ? dp[1][j - 1] : 0) + val);
	}
	smax(ans, dp[1][n - 1]);
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}