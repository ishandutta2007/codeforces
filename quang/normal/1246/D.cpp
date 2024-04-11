#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
vector<int> adj[N];
int lv[N];
int maxD[N];
int par[N];
vector<int> res, ids;

void dfs(int u) {
    maxD[u] = lv[u];
    for (int v : adj[u]) {
        lv[v] = lv[u] + 1;
        par[v] = u;
        dfs(v);
        maxD[u] = max(maxD[u], maxD[v]);
    }   
}

void go(int u, int p) {
    int last = ids.empty() ? -1 : ids.back();
    while (last != p) {
        res.push_back(u);
        last = par[last];
    }
    ids.push_back(u);

    sort(adj[u].begin(), adj[u].end(), [&](int x, int y) {
        return maxD[x] < maxD[y];
    });

    for (int v : adj[u]) {
        go(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u;
        cin >> u;
        adj[u].push_back(i);
    }
    par[0] = -1;
    dfs(0);
    go(0, -1);
    for (int u : ids) cout << u << ' ';
        cout << '\n';
    cout << res.size() << '\n';
    for (int u : res) cout << u << ' ';
        cout << '\n';
    return 0;
}