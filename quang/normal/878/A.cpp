#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n;
bool dp[2][10][N];

bool getBit(int v, int pos) {
	return (v >> pos) & 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < 10; i++) {
		dp[0][i][0] = 0;
		dp[1][i][0] = 1;
	}
	for (int i = 1; i <= n; i++) {
		char u;
		int v;
		cin >> u >> v;
		if (u == '^') {
			for (int j = 0; j < 10; j++) {
				dp[0][j][i] = dp[0][j][i - 1] ^ getBit(v, j);
				dp[1][j][i] = dp[1][j][i - 1] ^ getBit(v, j); 
			}
		} else if (u == '&') {
			for (int j = 0; j < 10; j++) {
				dp[0][j][i] = dp[0][j][i - 1] & getBit(v, j);
				dp[1][j][i] = dp[1][j][i - 1] & getBit(v, j); 
			}
		} else {
			for (int j = 0; j < 10; j++) {
				dp[0][j][i] = dp[0][j][i - 1] | getBit(v, j);
				dp[1][j][i] = dp[1][j][i - 1] | getBit(v, j); 
			}
		}
	}
	int res1 = 0, res2 = 0, res3 = 0;
	res1 = (1 << 10) - 1;
	for (int j = 0; j < 10; j++) {
		if (dp[0][j][n] == 0 && dp[1][j][n] == 1) {

		} else if (dp[0][j][n] == 0 && dp[1][j][n] == 0) {	
			res1 ^= (1 << j);
		} else if (dp[0][j][n] == 1 && dp[1][j][n] == 1) {
			res2 ^= (1 << j);
		} else {
			res3 ^= (1 << j);
		}
	}
	cout << 3 << endl;
	cout << "& " << res1 << endl;
	cout << "| " << res2 << endl;
	cout << "^ " << res3 << endl;
	return 0;
}