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
        vector < pair <int, int> > ord;

        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                cin >> mat[i][j];
            }
        }

        for(j = 1; j <= m; j++) {
            int mx = 0;
            for(i = 1; i <= n; i++) {
                mx = max(mx, mat[i][j]);
            }
            ord.push_back({mx, j});
        }

        sort(ord.rbegin(), ord.rend());

        vector <int> dp(1 << n, -INF), new_dp(1 << n);
        dp[0] = 0;

        for(i = 0; i < min(n, m); i++) {

            vector <int> best(1 << n);
            int col = ord[i].second;

            for(int conf = 0; conf < (1 << n); conf++) {
                for(int l = 1; l <= n; l++) {
                    int lin = l, cur = 0;
                    for(int j = 0; j < n; j++) {
                        if(conf & (1 << j)) {
                            cur += mat[lin][col];
                        }
                        lin = lin + 1 - (lin == n) * n;
                    }
                    best[conf] = max(best[conf], cur);
                }
            }

            fill(new_dp.begin(), new_dp.end(), -INF);
            for(int conf = 0; conf < (1 << n); conf++) {
                new_dp[conf] = max(best[conf], dp[conf]);
                for(int cnf = conf; cnf > 0; cnf = conf & (cnf - 1)) {
                    new_dp[conf] = max(new_dp[conf], dp[cnf] + best[cnf ^ conf]);
                }
            }

            swap(dp, new_dp);
        }

        cout << dp[(1 << n) - 1] << "\n";
    }

    return 0;
}