#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define putsl puts("")
using namespace std;
const int N = 1e5 + 7;
const int M = 320;
const int mod = 1e9 + 7;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N];
void init(int mx) {
	fac[0] = 1;
	L(i, 1, mx) fac[i] = (ll) fac[i - 1] * i % mod;
	ifac[mx] = qpow(fac[mx]);
	R(i, mx, 1) ifac[i - 1] = (ll) ifac[i] * i % mod;
}
int n, m, x, ans, dp[2][M][M]; // queue
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> x;
	init(n);
	if(n > m) return puts("0"), 0;
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	L(i, 1, m) {
		int now = (i & 1);
		L(a, 0, n) L(b, 0, n) dp[now][a][b] = 0;
		L(j, 0, n) L(k, 0, n) {
			if(x != i) {
				(dp[now][j][k] += dp[now ^ 1][j][k]) %= mod;
				if(j) (dp[now][j - 1][k] += dp[now ^ 1][j][k]) %= mod;
			} 
			(dp[now][j + 1][k + 1] += dp[now ^ 1][j][k]) %= mod; 
			(dp[now][j][k + 1] += dp[now ^ 1][j][k]) %= mod; // 
		}
	}
	ans = (ll) dp[m & 1][0][n] * fac[n] % mod;
	printf("%d\n", ans);
	return 0;
}