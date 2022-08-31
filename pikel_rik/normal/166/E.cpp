#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vi> vvi;

const int mod = 1000000007;

int dp[5][10000001];

int main() {
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;

	memset(dp, 0, sizeof(dp));

	dp[1][0] = 1;
	dp[2][0] = 0;
	dp[3][0] = 0;
	dp[4][0] = 0;

	for (int i = 0; i + 1 <= n; i++) {
		int sum = ((dp[1][i] + dp[2][i]) % mod + (dp[3][i] + dp[4][i]) % mod) % mod;
		for (int j = 1; j <= 4; j++)
			dp[j][i + 1] = (sum - dp[j][i] + mod) % mod;
	}

	cout << dp[1][n];
	return 0;
}