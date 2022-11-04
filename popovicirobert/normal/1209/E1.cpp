#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long



#if 0
const int MOD = ;

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
}

inline int inv(int x) {
    return lgput(x, MOD - 2);
}
#endif

#if 0
int fact[], invfact[];

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
}
#endif

using namespace std;

const int INF = 1e9;

int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int t, i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;

        vector < vector <int> > mat(n + 1, vector <int>(m + 1));
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                cin >> mat[i][j];
            }
        }

        vector < vector <int> > best(m + 1, vector <int>(1 << n));
        for(j = 1; j <= m; j++) {
            for(int conf = 0; conf < (1 << n); conf++) {
                for(int o = 1; o <= n; o++) {
                    int p = o, cur = 0;
                    for(i = 0; i < n; i++) {
                        if(conf & (1 << i)) {
                            cur += mat[p][j];
                        }
                        p++;
                        if(p == n + 1)
                            p -= n;
                    }
                    best[j][conf] = max(best[j][conf], cur);
                }
            }
        }

        vector < vector <int> > dp(m + 1, vector <int>(1 << n, -INF));
        dp[0][0] = 0;

        for(i = 0; i < m; i++) {
            for(int conf = 0; conf < (1 << n); conf++) {
                if(dp[i][conf] == -INF) continue;

                dp[i + 1][conf] = max(dp[i][conf], dp[i + 1][conf]);
                for(int c = 0; c < (1 << n); c++) {
                    if((conf & c) == 0) {
                        dp[i + 1][c | conf] = max(dp[i + 1][c | conf], dp[i][conf] + best[i + 1][c]);
                    }
                }
            }
        }

        cout << dp[m][(1 << n) - 1] << "\n";
    }

    return 0;
}