#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = 5005;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
    if(x < 0)
        x += MOD;
}

int dp[2][MAXN + 1];

inline void update(int l, int r, int val, int i) {
    if(l > r) {
        return ;
    }
    dp[1 - i & 1][l] += val;
    mod(dp[1 - i & 1][l]);
    dp[1 - i & 1][r + 1] -= val;
    mod(dp[1 - i & 1][r + 1]);
}

int main() {
    //ifstream cin("C.in");
    //ofstream cout("C.out");
    int i, j, n, a, b, k;
    ios::sync_with_stdio(false);
    cin >> n >> a >> b >> k;
    dp[0][a] = 1;
    dp[0][a + 1] = MOD - 1;
    for(i = 0; i < k; i++) {
        memset(dp[1 - i & 1], 0, sizeof(dp[1 - i & 1]));
        for(j = 1; j <= n; j++) {
            dp[i & 1][j] += dp[i & 1][j - 1];
            mod(dp[i & 1][j]);
            int l = max(0, j - abs(j - b) + 1);
            int r = j - 1;
            update(l, r, dp[i & 1][j], i);
            l = j + 1;
            r = min(n, j + abs(j - b) - 1);
            update(l, r, dp[i & 1][j], i);
        }
    }
    int ans = 0;
    for(i = 1; i <= n; i++) {
        dp[k & 1][i] += dp[k & 1][i - 1];
        mod(dp[k & 1][i]);
        ans += dp[k & 1][i];
        mod(ans);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}