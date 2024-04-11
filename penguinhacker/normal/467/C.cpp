#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m, k, sum[5001], dp[5001][5001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m >> k;
    for (int i=1; i<=n; ++i)
        cin >> sum[i], sum[i] += sum[i-1];

    for (int i=1; i<=k; ++i)
        for (int j=m; j<=n; ++j)
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-m]+sum[j]-sum[j-m]);

    cout << dp[k][n];
	return 0;
}