#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--) 
using namespace std;
const int N = 444;
const int mod = 1e9 + 7;
int n, dp[N][N], bb[N];
int main() {
	scanf("%d", &n);
	dp[1][1] = 1;
	L(i, 2, n) {
        fill(bb, bb + n + 1, 0);
		L(j, 1, n) L(k, 0, j) (bb[j] += 1ll * dp[i - 1][k] * dp[i - 1][j - k] % mod) %= mod;
		dp[i][1] = 1;
        L(j, 1, n) {
			int t = 0;
			(dp[i][j] += (2ll * j + 1) * bb[j] % mod) %= mod;
            (dp[i][j] += (4ll * j + 2) % mod * dp[i - 1][j] % mod) %= mod;
			(dp[i][j] += 1ll * j * (j + 1) % mod * bb[j + 1] % mod) %= mod;
            (dp[i][j] += 2ll * j * (j + 1) % mod * dp[i - 1][j + 1] % mod) %= mod;
			(dp[i][j] += bb[j - 1] % mod) %= mod;
            (dp[i][j] += 2ll * dp[i - 1][j - 1] % mod) %= mod;
		}
	}
	printf("%d\n", dp[n][1]);
	return 0;
}