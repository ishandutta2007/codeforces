#ifdef ONPC
    #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

const int MOD = 31607;

int inv[MOD];

template<typename T>
T binpow(T a, T b) {
    T ans = 1;
    while (b) {
        if (b & 1) {
            ans = 1LL * ans * a % MOD;
        }
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return ans;
}

const int N = 21;

const int B = (1 << N);

int pst[B]; // 
int dp[B];
int dp2[N + 1][B];
int pms[B]; // 
int prow[N]; // 
int pcolms[N][B]; // 

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    for (int i = 0; i < MOD; i++) {
        inv[i] = binpow(i, MOD - 2);
    }
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j] = 1LL * a[i][j] * inv[10000] % MOD;
        }
    }
    int BB = (1 << n);
    int total_ans = 1;
    for (int d1 = 0; d1 <= 1; d1++) {
        for (int d2 = 0; d2 <= 1; d2++) {
            vector<vector<int>> b = a;
            if (d1) {
                for (int i = 0; i < n; i++) {
                    a[i][i] = 1;
                }
            }
            if (d2) {
                for (int i = 0; i < n; i++) {
                    a[i][n - i - 1] = 1;
                }
            }
            for (int i = 0; i < n; i++) {
                prow[i] = 1;
                for (int j = 0; j < n; j++) {
                    prow[i] = 1LL * prow[i] * a[i][j] % MOD;
                }
            }
            for (int ms = 0; ms < BB; ms++) {
                if (ms > 0) {
                    int i = 31 - __builtin_clz(ms);
                    pms[ms] = 1LL * pms[ms ^ (1 << i)] * prow[i] % MOD;
                    for (int j = 0; j < n; j++) {
                        pcolms[j][ms] = 1LL * pcolms[j][ms ^ (1 << i)] * a[i][j] % MOD;
                    }
                    int prod = 1;
                    for (int j = 0; j < n; j++) {
                        prod = 1LL * prod * (MOD + 1 - pcolms[j][ms]) % MOD;
                    }
                    pst[ms] = prod;
                } else {
                    pms[ms] = 1;
                    for (int j = 0; j < n; j++) {
                        pcolms[j][ms] = 1;
                    }
                    pst[ms] = 0;
                }
            }

            for (int ms = 0; ms < BB; ms++) {
                if (ms == 0) {
                    dp[0] = 0;
                    for (int i = 0; i <= n; i++) {
                        dp2[i][0] = 0;
                    }
                    continue;
                }
                dp2[0][ms] = 0;
                for (int i = 0; i < n; i++) {
                    if ((ms & (1 << i))) {
                        dp2[i + 1][ms] = dp2[i][ms] + dp2[i][(ms ^ (1 << i))];
                        if (dp2[i + 1][ms] >= MOD) {
                            dp2[i + 1][ms] -= MOD;
                        }
                    } else {
                        dp2[i + 1][ms] = dp2[i][ms];
                    }
                }

                dp[ms] = (pst[ms] + MOD - (1LL * pms[ms] * dp2[n][ms] % MOD)) % MOD;

                int val = 1LL * dp[ms] * inv[pms[ms]] % MOD;
                for (int i = 0; i <= n; i++) {
                    dp2[i][ms] += val;
                    if (dp2[i][ms] >= MOD) {
                        dp2[i][ms] -= MOD;
                    }
                }
            }
            
            int ans = dp[BB - 1];
            a = b;
            if (d1) {
                for (int i = 0; i < n; i++) {
                    ans = 1LL * ans * a[i][i] % MOD;
                }
            }
            if (d2) {
                for (int i = 0; i < n; i++) {
                    int j = n - i - 1;
                    if (j != i || !d1) {
                        ans = 1LL * ans * a[i][j] % MOD;
                    }
                }
            }
            //cout << d1 << ' ' << d2 << ' ' << ans * 16 % MOD << ' ' << dp[1] * 4 % MOD << ' ' << dp[2] * 4 % MOD << endl;
            if (d1 + d2 == 1) {
                total_ans = (total_ans + ans) % MOD;
            } else {
                total_ans = (total_ans + MOD - ans) % MOD;
            }
        }
    }
    cout << total_ans % MOD << '\n';
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1e9;
    //cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}