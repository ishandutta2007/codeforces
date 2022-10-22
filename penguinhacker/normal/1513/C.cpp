#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=1e9+7;
int n, m, dp[200001][10];

void solve() {
	cin >> n >> m;
	int ans=0;
	while(n) {
		ans=(ans+dp[m][n%10])%M;
		n/=10;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(dp[0], dp[0]+10, 1);
	for (int i=1; i<=200000; ++i)
		for (int j=0; j<10; ++j)
			dp[i][j]=i+j<10?1:(dp[i-(10-j)][0]+dp[i-(10-j)][1])%M;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}