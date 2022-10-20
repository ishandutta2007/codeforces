#include <bits/stdc++.h>

using namespace std;

const int N = 500010;
const int LOG = 20;
const long long INF = (1ll << 60);

int n;
int a[N];
vector<int> adj[N];
int par[LOG][N];

void dfs(int u, int p) {
    par[0][u] = p;
    for (int i = 1; i < LOG; i++) {
        par[i][u] = par[i - 1][par[i - 1][u]];
    }
    for (int v : adj[u]) {
        if (v != p) dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int root = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (root == -1 || a[root] > a[i]) root = i;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(root, 0);
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        if (i == root) continue;
        long long foo = INF;
        for (int j = 0; j < LOG; j++) {
            int u = par[j][i];
            if (u == 0) u = root;
            foo = min(foo, 1ll * a[u] * (j + 1));
            if (u == root) break;
        }
        res += foo;
        res += a[i];
    }
    cout << res << endl;
    return 0;
}