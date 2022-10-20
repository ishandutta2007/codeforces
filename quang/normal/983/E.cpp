#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int LOG = 20;

int n, m, q;
vector<int> adj[N];
vector<int> has[N];
vector<pair<int, int> > check[N];
int lv[N];
int in[N], out[N], cnt;
int par[LOG][N];
int minPar[LOG][N];
int res[N];

void dfs(int u, int p) {
    in[u] = ++cnt;
    lv[u] = lv[p] + 1;
    par[0][u] = p;
    for (int i = 1; i < LOG; i++) {
        par[i][u] = par[i - 1][par[i - 1][u]];
    }
    for (int v : adj[u]) {
        dfs(v, u);
    }
    out[u] = cnt;
}

int lca(int u, int v) {
    if (lv[u] < lv[v]) {
        swap(u, v);
    }
    int h = lv[u] - lv[v];
    for (int i = LOG - 1; i >= 0; i--) {
        if (h & (1 << i)) {
            u = par[i][u];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = LOG - 1; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}

inline int minimize(int u, int v) {
    return lv[u] < lv[v] ? u : v;
}

void dfsBuildFirstMinPar(int u, int p) {
    for (int v : adj[u]) {
        dfsBuildFirstMinPar(v, u);
        minPar[0][u] = minimize(minPar[0][u], minPar[0][v]);
    }
}

void dfsBuildMinPar(int u, int p) {
    for (int i = 1; i < LOG; i++) {
        minPar[i][u] = minPar[i - 1][minPar[i - 1][u]];
    }
    for (int v : adj[u]) {
        dfsBuildMinPar(v, u);
    }
}

pair<int, int> getMinPar(int u, int w) {
    int h = 0;
    for (int i = LOG - 1; i >= 0; i--) {
        if (lv[minPar[i][u]] > lv[w]) {
            h |= (1 << i);
            u = minPar[i][u];
        }
    }
    return make_pair(u, h);
}

struct BIT {
    int t[N];

    BIT() {
        memset(t, 0, sizeof t);
    }

    void add(int x, int v = 1) {
        while (x < N) {
            t[x] += v;
            x += (x & -x);
        }
    }

    int get(int x) {
        int res = 0;
        while (x) {
            res += t[x];
            x -= (x & -x);
        }
        return res;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
} t;

void dfsCheck(int u, int p) {
    vector<int> foo(check[u].size());
    for (int i = 0; i < check[u].size(); i++) {
        foo[i] = t.get(in[check[u][i].first], out[check[u][i].first]);
    }
    for (int v : has[u]) {
        t.add(in[v]);
        // cerr << "update " << u << " " << v << endl;
    }
    for (int v : adj[u]) {
        dfsCheck(v, u);
    }
    // cerr << u << endl;
    for (int i = 0; i < check[u].size(); i++) {
        int bar = t.get(in[check[u][i].first], out[check[u][i].first]);
        // cerr << bar << " " << foo[i] << " " << check[u][i].first << " " << check[u][i].second << endl;
        if (bar > foo[i]) {
            res[check[u][i].second]++;
        } else {
            res[check[u][i].second] += 2;
        }
    }
    // cerr << endl;
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int u;
        scanf("%d", &u);
        adj[u].push_back(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        minPar[0][i] = i;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (lv[u] < lv[v]) {
            swap(u, v);
        }
        int w = lca(u, v);
        minPar[0][u] = minimize(minPar[0][u], w);
        minPar[0][v] = minimize(minPar[0][v], w);
        if (v != w) {
            has[u].push_back(v);
            has[v].push_back(u);
        }
    }
    //     for (int i = 1; i <= n; i++) {
    //     cout << minPar[0][i] << " ";
    // }
    // cout << endl;
    dfsBuildFirstMinPar(1, 0);
    dfsBuildMinPar(1, 0);
    // for (int i = 1; i <= n; i++) {
    //     cout << minPar[0][i] << " ";
    // }
    // cout << endl;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (lv[u] < lv[v]) {
            swap(u, v);
        }
        int w = lca(u, v);
        if (w == v) {
            pair<int, int> uu = getMinPar(u, w);
            if (lv[minPar[0][uu.first]] <= lv[w]) {
                res[i] = uu.second + 1;
            } else {
                res[i] = -1;
            }
        } else {
            pair<int, int> uu = getMinPar(u, w);
            pair<int, int> vv = getMinPar(v, w);
            // cout << uu.second << " " << vv.second << endl;
            int foo = uu.second + vv.second;
            if (lv[minPar[0][uu.first]] > lv[w] || lv[minPar[0][vv.first]] > lv[w]) {
                res[i] = -1;
            } else {
                res[i] = foo;
                check[uu.first].push_back(make_pair(vv.first, i));
            }
        }
    }
    dfsCheck(1, 0);
    for (int i = 1; i <= q; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}