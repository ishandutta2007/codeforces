#include<bits/stdc++.h>

using namespace std;

const int N = 110;
const int M = 45;
const int zer = 22;
const int mod = 1e9 + 7;

int n, k;
int f[N][M];
vector < int > g[N];

int w[N][2];

void dfs_solve(int v, int p) {
    if(p) g[v].erase(find(g[v].begin(), g[v].end(), p));
    for(int s : g[v]) {
        dfs_solve(s, v);
    }

    /// paint v -> f[v][0]
    f[v][zer + k] = 1;
    for(int s : g[v]) {
        int tot = 0;
        for(int i = 0; i < M; ++i) {
            if(zer - i > k) continue;
            tot += f[s][i];
            tot %= mod;
        }
        f[v][zer + k] = (1LL * f[v][zer + k] * tot) % mod;
    }

    /// does not paint v -> f[v][i][j]...
    for(int j = 0; j < zer; ++j) {
        memset(w, 0, sizeof w);
        w[0][(j == zer - 1)] = 1;
        for(int i = 0; i < g[v].size(); ++i) {
            int s = g[v][i];
            for(int t = 0; t < 2; ++t) {
                for(int x = 0; x < M; ++x) {
                    int nt = t;
                    if(x < zer) {
                        if(x - 1 < j) continue;
                        nt |= (x - 1 == j);
                    }
                    else {
                        if(x - zer >= zer - j) continue;
                    }
                    w[i + 1][nt] += 1LL * f[s][x] * w[i][t] % mod;
                    w[i + 1][nt] %= mod;
                }
            }
        }
        f[v][j] = w[g[v].size()][1];
    }

    for(int j = zer; j < zer + k; ++j) {
        memset(w, 0, sizeof w);
        w[0][0] = 1;
        for(int i = 0; i < g[v].size(); ++i) {
            int s = g[v][i];
            for(int t = 0; t < 2; ++t) {
                for(int x = 0; x < M; ++x) {
                    int nt = t;
                    if(x < zer) {
                        if(zer - x > j - zer) continue;
                    }
                    else {
                        if(x - 1 > j) continue;
                        nt |= (x - 1 == j);
                    }
                    w[i + 1][nt] += 1LL * f[s][x] * w[i][t] % mod;
                    w[i + 1][nt] %= mod;
                }
            }
        }
        f[v][j] = w[g[v].size()][1];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("inp", "r")) freopen("inp", "r", stdin);

    cin >> n >> k;
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs_solve(1, 0);

    int ans = 0;
    for(int i = zer; i < M; ++i) {
        ans += f[1][i];
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}