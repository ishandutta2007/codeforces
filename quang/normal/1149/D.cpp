#include <bits/stdc++.h>

using namespace std;

const int N = 77;
const int X = 17;

int n, m, a, b;
int root[N];
int dp[N][1 << X];
int used[N][1 << X];
int cnt = 0;
int id[N];
vector<int> adj[2][N];
int res[N];

int getRoot(int u) {
    return root[u] > 0 ? root[u] = getRoot(root[u]) : u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> a >> b;
    memset(root, -1, sizeof root);
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        int id = (c == b);
        adj[id][u].push_back(v);
        adj[id][v].push_back(u);
        if (c == a) {
            int uu = getRoot(u);
            int vv = getRoot(v);
            if (uu != vv) {
                root[vv] += root[uu];
                root[uu] = vv;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (root[i] <= -4) {
            id[i] = cnt++;
        } else id[i] = -1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << cnt); j++) {
            dp[i][j] = 1e9;
        }   
    }
    int initMask = id[getRoot(1)];
    if (initMask == -1) initMask = 0;
    else initMask = (1 << initMask);
    dp[1][initMask] = 0;
    priority_queue<tuple<int, int, int>> q;
    q.push({0, 1, initMask});
    for (int i = 1; i <= n; i++) res[i] = 1e9;
    while (!q.empty()) {
        int len, u, mask;
        tie(len, u, mask) = q.top();
        q.pop();
        if (used[u][mask]) continue;
        used[u][mask] = 1;
        res[u] = min(res[u], -len);
        for (int v : adj[0][u]) {
            if (dp[v][mask] > dp[u][mask] + a) {
                dp[v][mask] = dp[u][mask] + a;
                q.push({-dp[v][mask], v, mask});
            }
        }
        for (int v : adj[1][u]) {
            if (getRoot(v) == getRoot(u)) continue;
            int idV = id[getRoot(v)];
            if (idV != -1 && ((mask >> idV) & 1) == 1) continue;
            int newMask = mask | (idV == -1 ? 0 : (1 << idV));
            if (dp[v][newMask] > dp[u][mask] + b) {
                dp[v][newMask] = dp[u][mask] + b;
                q.push({-dp[v][newMask], v, newMask});
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
        cout << endl;
    return 0;
}