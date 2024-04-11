#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, a[100005], dp[100005][4];
string s;

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> N >> s;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = N - 1; i >= 0; i--)
		for (int j = 0; j < 4; j++) {
			int &r = dp[i][j];
			if (j == 0 && s[i] == 'h')
				r = min(dp[i + 1][0] + a[i], dp[i + 1][1]);
			else if (j == 1 && s[i] == 'a')
				r = min(dp[i + 1][1] + a[i], dp[i + 1][2]);
			else if (j == 2 && s[i] == 'r')
				r = min(dp[i + 1][2] + a[i], dp[i + 1][3]);
			else if (j == 3 && s[i] == 'd')
				r = dp[i + 1][3] + a[i];
			else
				r = dp[i + 1][j];
		}
	cout << dp[0][0] << '\n';
}