#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
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

/*int fact[], invfact[];

inline void prec(int n) {
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    invfact[n] = lgput(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--) {
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
    }
}

inline int comb(int n, int k) {
    if(n < k) return 0;
    return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
}*/

using namespace std;

const int MAXN = 50;

int dp[MAXN + 1][MAXN + 1][MAXN + 1][MAXN + 1];
int sp[MAXN + 1][MAXN + 1];
char mat[MAXN + 1][MAXN + 1];

inline int get(int l1, int c1, int l2, int c2) {
    return sp[l2][c2] - sp[l1 - 1][c2] - sp[l2][c1 - 1] + sp[l1 - 1][c1 - 1];
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for(i = 1; i <= n; i++) {
        cin >> mat[i] + 1;
        for(j = 1; j <= n; j++) {
            sp[i][j] = sp[i - 1][j] + sp[i][j - 1] - sp[i - 1][j - 1] + (mat[i][j] == '#');
        }
    }

    for(int lx = 0; lx < n; lx++) {
        for(int ly = 0; ly < n; ly++) {
            for(int x1 = 1; x1 + lx <= n; x1++) {
                for(int y1 = 1; y1 + ly <= n; y1++) {
                    int x2 = x1 + lx, y2 = y1 + ly;

                    dp[x1][y1][x2][y2] = (get(x1, y1, x2, y2) > 0 ? max(lx, ly) + 1 : 0);

                    for(int k = y1; k < y2; k++) {
                        dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], dp[x1][y1][x2][k] + dp[x1][k + 1][x2][y2]);
                    }
                    for(int k = x1; k < x2; k++) {
                        dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], dp[x1][y1][k][y2] + dp[k + 1][y1][x2][y2]);
                    }
                }
            }
        }
    }

    cout << dp[1][1][n][n];

    return 0;
}