#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
vector<int> adj[N];
int numChild[N];
int root[N];
vector<tuple<int, int, int>> res;
int val[N];

int getRoot(int u) {
    return root[u] > 0 ? root[u] = getRoot(root[u]) : u;
}

int unite(int u, int v) {
    root[u] += root[v];
    root[v] = u;
    return u;
}

int dfsFindRoot(int u, int p) {
    numChild[u] = 1;
    int fail = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        int foo = dfsFindRoot(v, u);
        if (foo) return foo;
        fail |= (numChild[v] * 2 > n);
        numChild[u] += numChild[v];
    }
    fail |= ((n - numChild[u]) * 2 > n);
    if (!fail) return u;
    return 0;
}

void dfsInit(int u, int p) {
    numChild[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfsInit(v, u);
        numChild[u] += numChild[v];
    }
}

void dfsCalc(int u, int p, int &cur, int delta) {
    cur += delta;
    val[u] = cur;
    res.push_back({u, p, val[u] - val[p]});
    for (int v : adj[u]) {
        if (v == p) continue;
        dfsCalc(v, u, cur, delta);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if (n == 1) {
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n == 2) {
        cout << 1 << ' ' << 2 << ' ' << 1 << endl;
        return 0;
    }
    int centroid = dfsFindRoot(1, 0);
    dfsInit(centroid, 0);
    for (int i = 1; i <= n; i++) {
        root[i] = -numChild[i];
    }
    priority_queue<pair<int, int>> q;
    for (int v : adj[centroid]) {
        q.push({root[v], v});
    }
    while (q.size() > 2) {
        int u = q.top().second;
        q.pop();
        int v = q.top().second;
        q.pop();
        int nxt = unite(u, v);
        q.push({root[nxt], nxt});
    }
    int x = q.top().second;
    q.pop();
    int y = q.top().second;
    q.pop();
    int delta = 1;
    int cur = 0;
    for (int v : adj[centroid]) {
        if (v == x || getRoot(v) == x) {
            dfsCalc(v, centroid, cur, delta);
        }
    }
    cur++;
    delta = cur;
    cur = 0;
    for (int v : adj[centroid]) {
        if (v == y || getRoot(v) == y) {
            dfsCalc(v, centroid, cur, delta);
        }
    }
    for (auto u : res) {
        int x, y, z;
        tie(x, y, z) = u;
        cout << x << ' ' << y << ' ' << z << '\n';
    }
    return 0;
}