#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
using namespace std;
const int N = 3333;
const int mod = 1e9 + 7;
int n, m, dp[N][N];
char s[N][N];
int get(int stx, int sty, int enx, int eny) {
	if(s[enx][eny] == '#' || s[stx][sty] == '#') return 0;
	memset(dp, 0, sizeof(dp));
	dp[stx][sty] = 1;
	L(i, stx, enx) {
		L(j, sty, eny) {
			if(s[i][j] == '#') continue;
			(dp[i + 1][j] += dp[i][j]) %= mod;
			(dp[i][j + 1] += dp[i][j]) %= mod;
		}
	}
	return dp[enx][eny];
}
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, n) scanf("%s", s[i] + 1);
	printf("%lld\n", (1ll * get(1, 2, n - 1, m) * get(2, 1, n, m - 1) % mod - 1ll * get(1, 2, n, m - 1) * get(2, 1, n - 1, m) % mod + mod) % mod);
	return 0;
}