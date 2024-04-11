#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int M = 1e9+7;

int nCk[1001][1001];

void init() {
	nCk[0][0] = 1;
	for (int i = 1; i <= 1000; i++) {
		nCk[i][0] = 1; 
		for (int j = 1; j <= i; j++) {
			nCk[i][j] = (nCk[i-1][j] + nCk[i-1][j-1]) % M;
		}
	}
}

int dp[61][3005];

int go(int bt, int allow, int &n, int &k, int &z) {
	if (bt == -1) return 1;
	if (dp[bt][allow] != -1) return dp[bt][allow];

	int st = (z >> bt) & 1LL;
	int ans = 0;
	for (int i = st; i <= n; i += 2) {
		if (i <= allow) {
			int nxt_allow = allow - i;
			nxt_allow *= 2; 
			if ((k >> (bt-1)) & 1) nxt_allow++;
			nxt_allow = min(nxt_allow, 2000LL);
			ans = (ans + nCk[n][i]*go(bt-1, nxt_allow, n, k, z)) % M;
		}
	}
	return dp[bt][allow] = ans;
}

int solve(int n, int k, int z) {
	memset(dp, -1, sizeof(dp));
	int ans = go(60, 0, n, k, z);
	return ans;	
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();

	int n, l, r, z; 	
	cin >> n >> l >> r >> z;
	int ans = solve(n, r, z);
	ans = (ans - solve(n, l-1, z)) % M;
	ans += M; ans %= M;
	cout << ans << '\n';

	return 0;
}