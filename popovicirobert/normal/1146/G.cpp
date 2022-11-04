#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = (int) 1e9 + 7;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}*/

using namespace std;

const int MAXN = 50;

int dp[MAXN + 1][MAXN + 1][MAXN + 1];
int l[MAXN + 1], r[MAXN + 1], x[MAXN + 1], c[MAXN + 1];
int m;

inline int get(int a, int b, int h, int pos) {
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        if(h > x[i] && a <= l[i] && r[i] <= b && l[i] <= pos && pos <= r[i]) {
            ans += c[i];
        }
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, h;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> h >> m;

    for(i = 1; i <= m; i++) {
        cin >> l[i] >> r[i] >> x[i] >> c[i];
    }

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= h; j++) {
            dp[i][i][j] = max(dp[i][i][j - 1], j * j - get(i, i, j, i));
        }
    }

    for(int len = 1; len < n; len++) {
        for(int a = 1; a + len <= n; a++) {
            int b = a + len;

            for(j = 0; j <= h; j++) {

                for(i = a; i <= b; i++) {
                    int fine = get(a, b, j, i);
                    int cur = j * j - fine;

                    if(i > a) {
                        cur += dp[a][i - 1][j];
                    }
                    if(i < b) {
                        cur += dp[i + 1][b][j];
                    }
                    dp[a][b][j] = max(dp[a][b][j], cur);
                }

            }

            for(j = 1; j <= h; j++) {
                dp[a][b][j] = max(dp[a][b][j], dp[a][b][j - 1]);
            }

        }
    }

    int ans = 0;
    for(j = 0; j <= h; j++) {
        ans = max(ans, dp[1][n][j]);
    }

    cout << ans;

    return 0;
}