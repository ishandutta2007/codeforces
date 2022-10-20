#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, k;
vector<int> adj[N];
int d[N];
int par[N];
int res[N];

void dfs(int u, int p, int len) {
    d[u] = len;
    par[u] = p;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, len + 1);
    }
}

void go(int u, int p, int x, int y, int len, int flag, int color, int f) {
    if (len >= k && !f) {
        cout << "No" << endl;
        exit(0);
    }
    if (!f) {
        if (flag) res[u] = (color + k - 1) % k;
        else res[u] = (color + 1) % k;
    }
    for (int v : adj[u]) {
        if (v == p || v == x || v == y) continue;
        go(v, u, x, y, len + 1, flag, res[u], 0);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    int root = 1;
    for (int i = 1; i <= n; i++) {
        if (d[i] > d[root]) {
            root = i;
        }
    }
    dfs(root, 0, 0);
    vector<int> ls;
    int root2 = 1;
    for (int i = 1; i <= n; i++) {
        if (d[i] > d[root2]) {
            root2 = i;
        }
    }

    if (k == 2) {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++) {
            if (d[i] & 1) cout << 1 << ' ';
            else cout << 2 << ' ';
        }
        cout << endl;
        return 0;
    }

    ls.push_back(root2);
    while (root2 != root) {
        root2 = par[root2];
        ls.push_back(root2);
    }
    
    if (ls.size() < k) {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++) cout << 1 << ' ';
            cout << endl;
        return 0;
    }

    for (int i = 0; i < ls.size(); i++) {
        res[ls[i]] = i % k;
    }

    for (int i = 0; i < ls.size(); i++) {
        int u = ls[i];
        int pre = i > 0 ? ls[i - 1] : -1;
        int suf = i + 1 < ls.size() ? ls[i + 1] : -1;
        int len = min(i + 1, (int)ls.size() - i);
        int flag = (i + 1) < ((int)ls.size() - i);
        go(u, 0, pre, suf, len, flag, i % k, 1);
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++) {
        cout << res[i] + 1 << ' ';
    }
    cout << endl;
    return 0;
}