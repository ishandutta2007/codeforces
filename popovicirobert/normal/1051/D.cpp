#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 998244353;
const int MAXN = 1000;

ll dp[MAXN + 1][2 * MAXN + 1][4];

inline void mod(ll &x) {
    x %= MOD;
}

inline ll get(int l, int c, int k) {
    if(c >= 0)
        return dp[l - 1][c][k];
    return 0;
}

int main() {
    //ifstream cin("D.in");
    //ofstream cout("D.out");
    int i, j, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    dp[1][1][0] = dp[1][1][3] = dp[1][2][1] = dp[1][2][2] = 1;
    for(i = 2; i <= n; i++) {
        for(j = 1; j <= 2 * i; j++) {
            dp[i][j][0] += get(i, j, 0) + get(i, j, 1) + get(i, j, 2) + get(i, j - 1, 3);
            mod(dp[i][j][0]);
            dp[i][j][1] += get(i, j - 1, 0) + get(i, j, 1) + get(i, j - 2, 2) + get(i, j - 1, 3);
            mod(dp[i][j][1]);
            dp[i][j][2] += get(i, j - 1, 0) + get(i, j - 2, 1) + get(i, j, 2) + get(i, j - 1, 3);
            mod(dp[i][j][2]);
            dp[i][j][3] += get(i, j - 1, 0) + get(i, j, 1) + get(i, j, 2) + get(i, j, 3);
            mod(dp[i][j][3]);
        }
    }
    ll ans = 0;
    for(i = 0; i < 4; i++) {
        ans += dp[n][k][i];
        mod(ans);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}