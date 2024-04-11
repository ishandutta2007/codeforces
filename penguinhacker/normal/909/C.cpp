#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, maxDepth=0;
int dp[5001][5001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(numeric_limits<double>::max_digits10);
	
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	cin >> n;
	bool last = 0; //to check if last one was a for
	for (int i=1; i<=n; ++i) {
		char c;
		cin >> c;
		if (last) {
			for (int j=0; j<=maxDepth; ++j)
				dp[i][j+1] = dp[i-1][j];
			maxDepth++;
		}
		else {
			int curr = 0;
			for (int j=maxDepth; j>=0; --j) {
				curr = (curr+dp[i-1][j])%MOD;
				dp[i][j] = curr;
			}
		}
		if (c == 'f')
			last = 1;
		else
			last = 0;
	}

	int ans = 0;
	for (int i=0; i<=maxDepth; ++i)
		ans = (ans+dp[n][i])%MOD;
	cout << ans;
	return 0;
}