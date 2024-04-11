#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp[101][101][2][2];

int go(int o, int z, int alsum, int turn) {
	if (o == 0 && z == 0) {
		return (alsum == turn);
	}
	if (dp[o][z][alsum][turn] != -1) {
		return dp[o][z][alsum][turn];
	}

	int isWin = 0;
	if (o > 0) {
		if (turn == 0) {
			if (!go(o-1, z, 1-alsum, 1-turn)) {
				isWin = 1;
			}
		} else {
			if (!go(o-1, z, alsum, 1-turn)) {
				isWin = 1;
			}
		}
	}
	if (z > 0) {
		if (!go(o, z-1, alsum, 1-turn)) {
			isWin = 1;
		}
	}
	return (dp[o][z][alsum][turn] = isWin);
}

void solve() {
	int n; cin >> n;
	int o = 0, z = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x % 2) o++;
		else z++;
	}

	if (go(o, z, 0, 0)) {
		cout << "Alice\n";
	} else {
		cout << "Bob\n";
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof(dp));

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}