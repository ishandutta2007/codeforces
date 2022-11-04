#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


#if 1
const int MOD = (int) 1e9 + 7;

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

#define cnt first
#define sum second

const int MAXN = 3005;

pair <int, ll> dp[MAXN + 1][MAXN + 1][2], dp2[MAXN + 1][2];

vector <int> g[MAXN + 1];
int sz[MAXN + 1];

int votes[MAXN + 1];

inline void upd(pair <int, ll> &x, pair <int, ll> y) {
    if(x.cnt < y.cnt || (x.cnt == y.cnt && x.sum < y.sum)) {
        x = y;
    }
}

void dfs(int nod, int par) {
    dp[nod][0][1] = {0, votes[nod]};
    dp[nod][1][0] = {votes[nod] > 0, 0};

    sz[nod] = 1;

    for(auto it : g[nod]) {
        if(it != par) {
            dfs(it, nod);

            for(int i = 0; i <= sz[nod] + sz[it]; i++) {
                for(int j = 0; j < 2; j++) {
                    dp2[i][j] = {-1e9, 1e18};
                }
            }

            for(int sza = sz[nod]; sza >= 0; sza--) {
                for(int a = 0; a < 2; a++) {
                    for(int szb = sz[it]; szb >= 0; szb--) {
                        for(int b = a; b >= 0; b--) {
                            upd(dp2[sza + szb][a | b], {dp[nod][sza][a].cnt + dp[it][szb][b].cnt,
                                                        dp[nod][sza][a].sum + dp[it][szb][b].sum});
                        }
                    }
                }
            }

            sz[nod] += sz[it];
            for(int i = 0; i <= sz[nod]; i++) {
                for(int j = 0; j < 2; j++) {
                    dp[nod][i][j] = dp2[i][j];
                }
            }
            for(int i = 0; i <= sz[nod]; i++) {
                upd(dp[nod][i + 1][0], {dp[nod][i][1].cnt + (dp[nod][i][1].sum > 0), 0});
            }
        }
    }
}

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int t, i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {
        cin >> n >> m;

        for(i = 1; i <= n; i++) {
            cin >> votes[i];
            g[i].clear();
        }
        for(i = 1; i <= n; i++) {
            int x;
            cin >> x;
            votes[i] = x - votes[i];
        }

        for(i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        for(i = 0; i <= n; i++) {
            for(j = 0; j <= n; j++) {
                for(int p = 0; p < 2; p++) {
                    dp[i][j][p] = {-1e9, 1e18};
                }
            }
        }

        dfs(1, 0);

        cout << dp[1][m][0].cnt << "\n";
    }

    return 0;
}