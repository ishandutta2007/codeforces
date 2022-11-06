#include <bits/stdc++.h>
using namespace std;
const int maxn = 40, mod = 1000000007;
int dp[maxn + 10][maxn + 10], n, ans = 0, p2[maxn + 10];
 
int add(int x, int y) {
    x += y; return x < mod ? x : x - mod;
}
void addto(int &x, int y) {
    x += y; if (x >= mod) x -= mod;
}
int mul(int x, int y) {
    return 1ll * x * y % mod;
}
 
int calc2(int n, int l) {
    memset(dp, 0, sizeof dp);
    dp[32][0] = 1;
    for (int i = 32; i >= 1; --i) {
        for (int j = 0; j <= 32; ++j)
            if (i - 1 <= l) {
                addto(dp[i - 1][j + 1], dp[i][j]);
                addto(dp[i - 1][j], mul(dp[i][j], p2[j + 1]));
            } else if (n >> (i - 1) & 1) {
                addto(dp[i - 1][j + 1], dp[i][j]);
                addto(dp[i - 1][j], mul(dp[i][j], p2[j]));
            } else addto(dp[i - 1][j], mul(dp[i][j], p2[max(j, 1)]));
    }
    int ans = 0;
    for (int i = 0; i <= 32; ++i) ans = add(ans, dp[0][i]);
    return ans;
}
 
int main() {
    p2[1] = 1;
    for (int i = 2; i <= maxn; ++i) p2[i] = add(p2[i - 1], p2[i - 1]);
    scanf("%d", &n); ++n;
    for (int i = 0; i <= 31; ++i)
        if (n >> i & 1) ans = add(ans, calc2(n ^ (1 << i), i - 1));
    printf("%d", ans);
}