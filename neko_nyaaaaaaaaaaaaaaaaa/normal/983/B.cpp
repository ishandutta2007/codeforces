#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[5001][5001];

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> dp[0][i];
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= n - i; j++) {
			dp[i][j] = dp[i-1][j] ^ dp[i-1][j+1];
		}
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
      		dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i - 1][j + 1]});
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		cout << dp[r-l-1][l] << '\n';
	}
	
	return 0;
}