#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
vector<int> adj[N];
int a[N][N];
vector<tuple<int, int, int>> res;
int child[N];

void dfsInit(int u, int p) {
    if (adj[u].size() == 1) {
        child[u] = u;
        return;
    }
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p) {
            adj[u].erase(adj[u].begin() + i);
            i--;
            continue;
        }
        dfsInit(v, u);
        child[u] = child[v];
    }
}

int find(int u, int v) {
    if (adj[u][0] == v) return child[adj[u][1]];
    return child[adj[u][0]];
}

bool go(int u, int need, int val) {
    if (u == need) return 1;
    if (adj[u].size() == 1) return 0;
    for (int v : adj[u]) {
        int f = go(v, need, val);
        if (f) {
            a[u][v] -= val;
            a[v][u] -= val;
            return 1;
        }
    }
    return 0;
}

void addPath(int root, int u, int v, int val) {
    res.push_back({u, v, val});
    go(root, u, val);
    go(root, v, val);
}

void dfs(int u, int p) {
    if (adj[u].size() == 1) {
        return;
    }
    int firstChild = adj[u][0];
    for (int i = 1; i < adj[u].size(); i++) {
        int v = adj[u][i];
        int val = a[u][v];
        if (val != 0) {
            addPath(u, child[firstChild], child[v], val);
        }
        dfs(v, u);
    }
    if (a[u][firstChild] != 0) {
        int val = a[u][firstChild] / 2;
        if (adj[u].size() > 2) {
            int v = adj[u][1];
            int w = adj[u][2];
            addPath(u, child[firstChild], child[w], val);
            addPath(u, child[firstChild], child[v], val);
            addPath(u, child[w], child[v], -val);
        } else {
            int v = adj[u][1];
            int w = find(p, u);
            addPath(p, child[firstChild], child[w], val);
            addPath(u, child[firstChild], child[v], val);
            addPath(p, child[w], child[v], -val);
        }
    }
    dfs(firstChild, u);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if (n == 2) {
        int u, v, w;
        cin >> u >> v >> w;
        cout << "YES\n";
        cout << 1 << endl;
        cout << u << ' ' << v << ' ' << w << endl;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v, val;
        cin >> u >> v >> val;
        adj[u].push_back(v);
        adj[v].push_back(u);
        a[u][v] = a[v][u] = val;
    }
    int found = 0;
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 2) {
            found = 1;
        }
        if (adj[i].size() > 2) {
            root = i;
        }
    }
    if (found) {
        cout << "NO" << endl;
        return 0;
    }
    dfsInit(root, 0);
    dfs(root, 0);
    cout << "YES\n";
    cout << res.size() << '\n';
    for (auto now : res) {
        int u, v, val;
        tie(u, v, val) = now;
        cout << u << ' ' << v << ' ' << val << '\n';
    }
    return 0;
}