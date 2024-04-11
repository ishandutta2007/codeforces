#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n; cin >> n;
	vector<int> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];
		
		vector<vector<int>> dp(508, vector<int>(508));
		for (int i = 0; i <= n; i++) {
			dp[i][i] = 1;
		}

		for (int k = 2; k <= n; k++) {
			for (int i = 0, j = k-1; j < n; i++, j++) {
				dp[i][j] = 1 + dp[i + 1][j];
				if (s[i] == s[i + 1]) {
					dp[i][j] = min(1 + dp[i + 2][j], dp[i][j]);
				}
				for (int q = i + 2; q <= j; q++) {
					if (s[i] == s[q]) {
						dp[i][j] = min(dp[i+1][q-1] + dp[q+1][j], dp[i][j]);
					}
				}
			}
            }
            
            cout << dp[0][n - 1] << endl;
	
	return 0;
}