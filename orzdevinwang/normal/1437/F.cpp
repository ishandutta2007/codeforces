#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair 
const int N = 5007;
const int mod = 998244353;
int n, a[N], cnt[N], dp[N][N], sum[N];
int main() {
    scanf("%d", &n);
    L(i, 1, n) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    L(i, 1, n) {
        L(j, 1, i) if(a[j] * 2 <= a[i]) cnt[i] = j; else break;
    }
    dp[0][0] = 1;
    L(i, 1, n) {
        R(j, n, 1) {
            if(cnt[j] + 1 < i) break;
            (dp[i][j] += 1ll * (cnt[j] - i + 2) * dp[i - 1][j] % mod) %= mod;
        }
        sum[0] = dp[i - 1][0];
        L(j, 1, n) {
            sum[j] = (sum[j - 1] + dp[i - 1][j]) % mod;
            (dp[i][j] += sum[cnt[j]]) %= mod;
        }
    }
    int ans = 0;
    L(i, 1, n) (ans += dp[n][i]) %= mod;
    printf("%d\n", ans);
	return 0;
}