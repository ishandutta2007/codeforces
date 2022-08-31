#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 107;
const int mod = 1e9 + 7;
int n, m, dp[N][N][N], Pow[N];
char s[N];
int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	L(i, 1, n) {
		dp[0][i][i - 1] = dp[1][i][i - 1] = 1;
		if(s[i] == '0') dp[0][i][i] = 1;
		else dp[1][i][i] = 1;
	}
	Pow[0] = Pow[1] = 2;
	L(i, 2, m) {
		Pow[i] = 1ll * Pow[i - 1] * Pow[i - 2] % mod;
		L(j, 1, n) L(k, j - 1, n) L(l, j - 1, k) {
			if(l == 0) (dp[i][1][k] += 1ll * Pow[i - 1] * dp[i - 2][1][k] % mod) %= mod;
			else if(l == n) (dp[i][j][n] += 1ll * dp[i - 1][j][n] * Pow[i - 2] % mod) %= mod;
			else (dp[i][j][k] += 1ll * dp[i - 1][j][l] * dp[i - 2][l + 1][k] % mod) %= mod;
		}
	}
	printf("%d\n", dp[m][1][n]);
	return 0;
}