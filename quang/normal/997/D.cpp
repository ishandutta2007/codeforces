#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) {
        u -= MOD;
    }
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) {
        u += MOD;
    }
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) {
            res = mul(res, u);
        }
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

const int N = 4010;
const int K = 80;

int k;

struct Tree {
    int n;
    vector<int> adj[N];

    Tree() {
        memset(dp, 0, sizeof dp);
    }

    void read() {
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    int numChild[N];
    bool dead[N];
    int f[K][N], g[K][N];
    int dp[K];

    void dfsInit(int u, int p, vector<int> &ls) {
        ls.push_back(u);
        numChild[u] = 1;
        for (int v : adj[u]) {
            if (v == p || dead[v]) {
                continue;
            }
            dfsInit(v, u, ls);
            numChild[u] += numChild[v];
        }
    }

    int findCentroid(int u, int p, int sz) {
        for (int v : adj[u]) {
            if (v == p || dead[v]) {
                continue;
            }
            if (2 * numChild[v] > sz) {
                return findCentroid(v, u, sz);
            }
        }
        return u;
    }

    void go(int u) {
        vector<int> ls;
        dfsInit(u, 0, ls);
        u = findCentroid(u, 0, numChild[u]);
        for (int i = 0; i <= k; i++) {
            for (int v : ls) {
                f[i][v] = g[i][v] = 0;
            }
        }
        f[0][u] = g[0][u] = 1;
        for (int i = 0; i < k; i++) {
            for (int v : ls) {
                if (f[i][v]) {
                    for (int x : adj[v]) {
                        if (dead[x] || x == u) {
                            continue;
                        }
                        f[i + 1][x] = add(f[i + 1][x], f[i][v]);
                    }
                }
                if (g[i][v]) {
                    for (int x : adj[v]) {
                        if (dead[x]) {
                            continue;
                        }
                        g[i + 1][x] = add(g[i + 1][x], g[i][v]);
                    }
                }
            }
        }

        for (int i = 0; i <= k; i++) {
            for (int j = 0; j + i <= k; j++) {
                for (int v : ls) {
                    dp[i + j] = add(dp[i + j], mul(f[i][v], g[j][v]));
                }
            }
        }

        ls.clear();
        dead[u] = 1;
        for (int v : adj[u]) {
            if (!dead[v]) {
                go(v);
            }
        }
    }

    int* getAns() {
        go(1);
        return dp;
    }
} t1, t2;

int c[K][K];

int main() {
    scanf("%d %d %d", &(t1.n), &(t2.n), &k);
    t1.read();
    t2.read();
    int* a = t1.getAns();
    int* b = t2.getAns();
    int res = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 | j == i) {
                c[i][j] = 1;
            } else {
                c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
            }
        }
    }
    for (int i = 0; i <= k; i++) {
        res = add(res, mul(mul(a[i], b[k - i]), c[k][i]));
    }
    cout << res << endl;
    return 0;
}