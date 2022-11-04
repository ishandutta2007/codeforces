#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = 50;

vector < vector < vector < vector <int> > > > dp;
int aux[MAXN + 1][MAXN + 1][MAXN + 1][3];

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}

int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i, n, T;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> T;

    vector <int> t(n + 1), g(n + 1), fr(3);
    for(i = 1; i <= n; i++) {
        cin >> t[i] >> g[i];
        g[i]--;
        fr[g[i]]++;
    }

    dp.resize(T + 1);
    for(int a = 0; a <= T; a++) {
        dp[a].resize(fr[0] + 1);
        for(int b = 0; b <= fr[0]; b++) {
            dp[a][b].resize(fr[1] + 1);
            for(int c = 0; c <= fr[1]; c++) {
                dp[a][b][c].resize(fr[2] + 1);
            }
        }
    }

    vector <int> cnt(3);
    int sumt = 0;

    for(i = 1; i <= n; i++) {
        if(t[i] > T) {
            continue;
        }
        sumt += t[i];
        sumt = min(sumt, T);

        cnt[g[i]]++;

        int da = (g[i] == 0), db = (g[i] == 1), dc = (g[i] == 2);

        for(int tt = sumt; tt >= t[i]; tt--) {
            for(int a = da; a <= cnt[0]; a++) {
                for(int b = db; b <= cnt[1]; b++) {
                    for(int c = dc; c <= cnt[2]; c++) {
                        add(dp[tt][a][b][c],
                            dp[tt - t[i]][a - da][b - db][c - dc]);
                    }
                }
            }
        }
        add(dp[t[i]][g[i] == 0][g[i] == 1][g[i] == 2], 1);
    }

    aux[1][0][0][0] = 1;
    aux[0][1][0][1] = 1;
    aux[0][0][1][2] = 1;

    for(int a = 0; a <= n; a++) {
        for(int b = 0; b <= n; b++) {
            for(int c = 0; c <= n; c++) {
                for(int x = 0; x < 3; x++) {
                    if(a > 0 && x != 0) {
                        add(aux[a][b][c][0], aux[a - 1][b][c][x]);
                    }
                    if(b > 0 && x != 1) {
                        add(aux[a][b][c][1], aux[a][b - 1][c][x]);
                    }
                    if(c > 0 && x != 2) {
                        add(aux[a][b][c][2], aux[a][b][c - 1][x]);
                    }
                }
            }
        }
    }

    vector <int> fact(n + 1, 1);
    for(i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }

    int ans = 0;
    for(int a = 0; a <= cnt[0]; a++) {
        for(int b = 0; b <= cnt[1]; b++) {
            for(int c = 0; c <= cnt[2]; c++) {
                int cur = dp[T][a][b][c];
                mul(cur, (1LL * aux[a][b][c][0] + 1LL * aux[a][b][c][1] + 1LL * aux[a][b][c][2]) % MOD);
                mul(cur, fact[a]);
                mul(cur, fact[b]);
                mul(cur, fact[c]);
                add(ans, cur);
            }
        }
    }

    cout << ans;

    //cin.close();
    //cout.close();
    return 0;
}