#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

const int N = 105;

int dp[N][N][2][2];

int calc(int i, int j, int p, int t) {
	if (dp[i][j][p][t] != -1) return dp[i][j][p][t];
	if (i == 0 && j == 0) {
		if (p == 1) return dp[i][j][p][t] = 0;
		return dp[i][j][p][t] = 1;
	}
	if (i == 0) {
		if (t == 0)
			return dp[i][j][p][t] = calc(i, j - 1, p ^ 1, t ^ 1);
		return dp[i][j][p][t] = calc(i, j - 1, p, t ^ 1);
	}
	if (j == 0) {
		return dp[i][j][p][t] = calc(i - 1, j, p, t ^ 1);
	}
	if (t == 0) {
		return dp[i][j][p][t] = max(
			calc(i - 1, j, p, t ^ 1),
			calc(i, j - 1, p ^ 1, t ^ 1)
		);
	}
	return dp[i][j][p][t] = min(
		calc(i - 1, j, p, t ^ 1),
		calc(i, j - 1, p, t ^ 1)
	);
}

void solve() {
	int n;
	int c[2] = {};
	cin >> n;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		c[(x % 2 + 2) % 2]++;
	}
	if (calc(c[0], c[1], 0, 0) == 1) {
		cout << "Alice\n";
		return;
	}
	cout << "Bob\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for (int x = 0; x < 2; x++) for (int y = 0; y < 2; y++) {
		dp[i][j][x][y] = -1;
	}
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}