#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 0;
using namespace std;

int maxbit(int x) {
	while (x != (x & -x)) x ^= (x & -x);
	return x;
}

int dp[2][32][32];

int calc(int u, int v, int i, int j, int grab) {
	if (i == -1) {
		if (j == -1) return 1;
		if ((v & -v) <= (1 << j)) return 0;
		return 1;
	}
	if (j == -1) {
		if (grab) return 1;
		if ((u & -u) <= (1 << i)) return 0;
		return 1;
	}
	if (dp[grab][i][j] != -1) return dp[grab][i][j];
	if ((u & (1 << i)) == 0) {
		return dp[grab][i][j] = calc(u, v, i - 1, j, grab);
	}
	if ((v & (1 << j)) == 0) {
		return dp[grab][i][j] = calc(u, v, i, j - 1, grab);
	}
	if (grab) {
		if (calc(u, v, i - 1, j, grab)) return dp[grab][i][j] = 1;
	}
	if (i > j) return dp[grab][i][j] = 0;
	if (i == j) {
		if (calc(u, v, i - 1, j - 1, 0)) return dp[grab][i][j] = 1;
	}
	if (i < j) {
		if (calc(u, v, i - 1, j - 1, 1)) return dp[grab][i][j] = 1;
	}
	return dp[grab][i][j] = 0;
}

void solve() {
	for (int i = 0; i < 32; i++) for (int j = 0; j < 32; j++) dp[0][i][j] = dp[1][i][j] = -1;
	int u, v;
	cin >> u >> v;
	if (calc(u, v, 31, 31, 0)) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}