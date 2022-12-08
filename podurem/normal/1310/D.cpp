#include <bits/stdc++.h>

using namespace std;
#ifdef SIR
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define err(...) 42
#endif
typedef long long ll;

#define multitest false

void solve();
int main() {
#ifdef SIR
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    if (multitest) cin >> t;
    for (int it = 1; it <= t; ++it) solve();
    return 0;
}

// CONSTANTS HERE

const int dd = 83;

int A[dd][dd];
int mn[5][dd][dd];
int lft[5];
int used[dd];

int get(int i, int j, int k) {
    return A[i][k] + A[k][j];
}

void upd_mn(int i, int j, int k) {
    for (int l = 0; l < 5; ++l) {
        if (mn[l][i][j] == -1 || get(i, j, mn[l][i][j]) > get(i, j, k)) {
            for (int p = 3; p >= l; --p) {
                mn[p + 1][i][j] = mn[p][i][j];
            }
            mn[l][i][j] = k;
            break;
        }
    }
}

int ans = (int)2e9;

int dp[6][5], V[5][5];

void uin(int &a, int b) {
    if (a > b) a = b;
}

void upd_ans(int sz, int k) {
    for (int i = 0; i < k + 1; ++i) for (int j = 0; j < sz; ++j) {
            dp[i][j] = (int)2e9;
        }

    for (int i = 0; i < sz; ++i) for (int j = 0; j < sz; ++j) {
            int x = 0;
            while (used[mn[x][lft[i]][lft[j]]]) ++x;
            V[i][j] = get(lft[i], lft[j], mn[x][lft[i]][lft[j]]);
        }

    dp[0][0] = 0;
    for (int j = 0; j < k; ++j) for (int i = 0; i < sz; ++i) if (dp[j][i] != (int)2e9) {
                for (int l = 0; l < sz; ++l) {
                    int v = V[i][l];
                    uin(dp[j + 1][l], dp[j][i] + v);
                }
            }
    uin(ans, dp[k][0]);
}

void gen(int need, int t, int last, int n, int rl) {
    if (t == need) {
        if (rl != n) upd_ans(rl, need);
        return;
    }
    gen(need, t + 1, last, n, rl);
    for (int nw = last + 1; nw < n; ++nw) {
        lft[rl] = nw;
        used[nw] = 1;
        gen(need, t + 1, nw, n, rl + 1);
        used[nw] = 0;
    }
}

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
            for (int l = 0; l < 5; ++l) mn[l][i][j] = -1;
        }
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
            for (int l = 0; l < n; ++l) if (i != l && j != l) {
                    upd_mn(i, j, l);
                }
        }

    lft[0] = 0;
    used[0] = 1;
    gen(k / 2, 1, 0, n, 1);

    cout << ans << "\n";
}