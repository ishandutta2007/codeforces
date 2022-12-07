#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

int n, k;
int a[maxn];
int ans[maxn];
vector<int> g[maxn];

int fdown[maxn][42], f[maxn][42];

void dfs_prepare(int v, int p) {
    fdown[v][0] = a[v];
    for(int s : g[v]) if (s != p) {
        dfs_prepare(s, v);
        for(int j = 0; j < 2 * k; ++j) {
            fdown[v][(j+1) % (2*k)] ^= fdown[s][j];
        }
    }
}

void dfs_solve(int v, int p) {
    int res = 0;
    for(int j = k; j < 2*k; ++j) {
        res ^= fdown[v][j] ^ f[v][j];
    }
    ans[v] = !!res;

    for(int s : g[v]) if (s != p) {
        for(int j = 0; j < 2 * k; ++j) {
            fdown[v][(j+1) % (2*k)] ^= fdown[s][j];
        }
        for(int j = 0; j < 2 * k; ++j) {
            f[s][(j+1) % (2*k)] ^= fdown[v][j] ^ f[v][j];
        }
        dfs_solve(s, v);
        for(int j = 0; j < 2 * k; ++j) {
            fdown[v][(j+1) % (2*k)] ^= fdown[s][j];
        }
    }
}

int main() {
    cin >> n >> k;
    for(int i = 0; i + 1 < n; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i < n; ++i) cin >> a[i];
    dfs_prepare(0, -1);
    dfs_solve(0, -1);


    for(int i = 0; i < n; ++i) cout << ans[i] << " ";
    cout << endl;

    return 0;
}