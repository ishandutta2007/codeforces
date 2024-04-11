#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;

int N, dp[5005][5005];
const int M = 1000000007;
char C[5005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> C[i];
	for (int i = 0; i < N; i++) dp[N][i] = i + 1;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++)
			if (C[i] == 'f') dp[i][j] = (dp[i + 1][j + 1] - dp[i + 1][j]) % M;
			else dp[i][j] = dp[i + 1][j];
		for (int j = 0; j < i; j++)
			dp[i][j] += j ? dp[i][j - 1] : 0, dp[i][j] %= M;
	}
	while (dp[1][0] < 0) dp[1][0] += M;
	cout << dp[1][0] << '\n';
}