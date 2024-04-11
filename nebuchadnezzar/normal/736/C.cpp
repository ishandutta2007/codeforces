#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);
const int MAXN = 105, MAXK = 22;
const ll MOD = 1e9 + 7;

ll d[MAXN][MAXK][MAXK];
int n, k;
vector<int> graph[MAXN];

int decr(int val) {
    if (val == k + 1) {
        return k + 1;
    }
    return val - 1;
}

int tmp[MAXK][MAXK];

int dfs(int v, int p) {
    d[v][k + 1][k] = 1;
    d[v][0][k + 1] = 1;
    for (int to : graph[v]) {
        if (to != p) {
            dfs(to, v);
            memset(tmp, 0, sizeof tmp);
            for (int i = 0; i <= k + 1; ++i) {
                for (int j = 0; j <= k + 1; ++j) {
                    for (int i2 = 0; i2 <= k + 1; ++i2) {
                        for (int j2 = 0; j2 <= k + 1; ++j2) {
                            if (decr(j2) >= i) {
                                if (decr(j) >= i2) {
                                    tmp[min(i, i2 + 1)][k + 1] = (tmp[min(i, i2 + 1)][k + 1] + d[v][i][j] * d[to][i2][j2]) % MOD;
                                } else {
                                    tmp[min(i, i2 + 1)][j] = (tmp[min(i, i2 + 1)][j] + d[v][i][j] * d[to][i2][j2]) % MOD;
                                }
                            } else {
                                if (j2 > 0) {
                                    if (decr(j) >= i2) {
                                        tmp[min(i, i2 + 1)][decr(j2)] = (tmp[min(i, i2 + 1)][decr(j2)] + d[v][i][j] * d[to][i2][j2]) % MOD;
                                    } else {
                                        tmp[min(i, i2 + 1)][min(j, decr(j2))] = (tmp[min(i, i2 + 1)][min(j, decr(j2))] + d[v][i][j] * d[to][i2][j2]) % MOD;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for (int i = 0; i <= k + 1; ++i) {
                for (int j = 0; j <= k + 1; ++j) {
                    d[v][i][j] = tmp[i][j];
                }
            }
        }
    }
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        graph[a].puba(b);
        graph[b].puba(a);
    }

    dfs(0, -1);

    /*
    for (int i = 0; i < n; ++i) {
        cerr << "i: " << i << endl;
        for (int j1 = 0; j1 <= k + 1; ++j1) {
            for (int j2 = 0; j2 <= k + 1; ++j2) {
                cerr << d[i][j1][j2] << " ";
            }   
            cerr << endl;
        }
        cerr << endl;
    }*/

    ll ans = 0;

    for (int i = 0; i <= k + 1; ++i) {
        ans = (ans + d[0][i][k + 1]) % MOD;
    }

    cout << ans << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}