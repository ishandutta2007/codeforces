#include <bits/stdc++.h>
using namespace std;

int n, mod;
int C[410][410];
int dp[410][410], f[410];

void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int main() {
	cin >> n >> mod;
	for (int i = 0; i <= 405; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
	for (int i = 1; i <= 405; i++) {
		for (int j = 1; j <= i; j++) {
			add(f[i], C[i - 1][j - 1]);
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 1; i + k + 1 <= n + 1; k++) {
				add(dp[i + k + 1][j + k], 1ll * dp[i][j] * f[k] % mod * C[j + k][k] % mod);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		add(ans, dp[n + 1][i]);
	}
	cout << ans << endl;
	return 0;
}