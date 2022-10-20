#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int MOD = 11;
const int INV2 = 6;

inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}

inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}

inline int mul(int u, int v) {
    return u * v % MOD;
}

int n;
char s[N];
int id[N];
long long dp[2][MOD][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> (s + 1);
    n = strlen(s + 1);
    memset(dp, 0, sizeof dp);
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        int c = s[i] - '0';
        // cerr << "inside " << i << ' ' << c << endl;
        for (int l = 0; l <= 1; l++) {
            for (int x = c + 1; x < MOD; x++) {
                if (!dp[l][x][i - 1]) continue;
                int idNum = l ? 9 : 10;
                int idNum1 = l ? 10 : 9;
                int newX = ((x * (x - 1) / 2 + idNum - idNum1 * (idNum1 + 1) / 2 + c + 1) % MOD + MOD) % MOD;
                dp[l ^ 1][newX][i] += dp[l][x][i - 1];
            }
        }
        if (c) {
            dp[1][c][i]++;
        }
        for (int l = 0; l <= 1; l++) {
            for (int x = 0; x < MOD; x++) {
                res += dp[l][x][i];
                // if (dp[l][x][i] != 0) cout << l << ' ' << x << ' '  << dp[l][x][i] << endl;
            }
        }
        // cout << res << endl;
    }
    cout << res << endl;
    return 0;
}