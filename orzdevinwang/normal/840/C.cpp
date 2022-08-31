#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long
const int N = 333;
const int mod = 1e9 + 7;
int n, a[N], dp[2][N][N], cnt;
void get(int &x) { L(i, 2, sqrt(x + 1)) while(!(x % (i * i))) x /= (i * i); }
int main() {
    scanf("%d", &n);
    L(i, 1, n) scanf("%d", &a[i]), get(a[i]);
    sort(a + 1, a + n + 1);
    dp[0][0][0] = 1;
    L(i, 1, n) {
        int t = (i & 1);
        if(a[i] != a[i - 1]) L(j, 0, i) L(k, 1, j) (dp[t ^ 1][j][0] += dp[t ^ 1][j][k]) %= mod, dp[t ^ 1][j][k] = 0;
        if(a[i] != a[i - 1]) cnt = 0;
        memset(dp[t], 0, sizeof(dp[t]));
        L(j, 0, i) L(k, 0, cnt) (dp[t][j + 1][k + 1] += 1ll * (cnt * 2 - k) * dp[t ^ 1][j][k] % mod) %= mod; // aaa / aab / baa
        L(j, 1, i) L(k, 0, cnt) (dp[t][j - 1][k] += 1ll * (j - k) * dp[t ^ 1][j][k] % mod) %= mod; // bab
        L(j, 0, i) L(k, 0, cnt) (dp[t][j][k] += 1ll * (i - cnt * 2 + 2 * k - j) * dp[t ^ 1][j][k] % mod) %= mod; // bac
        cnt ++;
        // if(a[i] != a[i + 1]) L(j, 0, i) L(k, 1, j) (dp[t][j][0] += dp[t][j][k]) %= mod, dp[t][j][k] = 0;
    }
    printf("%d\n", dp[n & 1][0][0]);
	return 0;
}