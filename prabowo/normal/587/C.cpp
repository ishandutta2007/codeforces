#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int LN = 18;

const int A = 10;

int n, m, q;
vector<int> edges[N];

int depth[N];
int par[LN][N];
vector<int> sparse[LN][N];

vector<int> merge(vector<int> &u, vector<int> v, int a=A) {
    vector<int> ret;
    int i = 0, j = 0;

    while (i < u.size() && j < v.size()) {
        if (u[i] < v[j]) {
            ret.push_back(u[i++]);
        } else if (u[i] > v[j]) {
            ret.push_back(v[j++]);
        } else {
            ret.push_back(u[i++]);
            j++;
        }
    }

    while (i < u.size()) ret.push_back(u[i++]);
    while (j < v.size()) ret.push_back(v[j++]);

    if (ret.size() > a) ret.resize(a);
    return ret;
}

void dfs(int u, int p, int d) {
    par[0][u] = p;
    depth[u] = d;

    for (int v: edges[u]) {
        if (v == p) continue;
        dfs(v, u, d+1);
    }
}

void read() {
    scanf("%d %d %d", &n, &m, &q);

    for (int i=1; i<n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u, --v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for (int i=0; i<m; i++) {
        int c;
        scanf("%d", &c);

        sparse[0][--c].push_back(i);
    }
}

void init() {
    dfs(0, 0, 0);

    for (int i=0; i<n; i++) if (sparse[0][i].size() > A) {
        sparse[0][i].resize(A);
    }

    for (int i=1; i<LN; i++) for (int j=0; j<n; j++) {
        par[i][j] = par[i-1][par[i-1][j]];
        sparse[i][j] = merge(sparse[i-1][j], sparse[i-1][par[i-1][j]]);
    }
}

vector<int> solve(int u, int v, int a) {
    if (depth[v] < depth[u]) swap(u, v);

    vector<int> ret;
    while (depth[u] < depth[v]) {
        int ctz = __builtin_ctz(depth[v] - depth[u]);
        ret = merge(ret, sparse[ctz][v], a);
        v = par[ctz][v];
    }

    if (u == v) {
        ret = merge(ret, sparse[0][u], a);
        return ret;
    }

    for (int i=LN-1; i>=0; i--) {
        if (par[i][u] == par[i][v]) continue;
        ret = merge(ret, merge(sparse[i][u], sparse[i][v], a), a);
        u = par[i][u];
        v = par[i][v];
    }

    ret = merge(ret, merge(sparse[0][u], sparse[0][v]), a);
    ret = merge(ret, sparse[0][par[0][u]], a);
    return ret;
}

int main() {
    read();
    init();
    
    while (q--) {
        int u, v, a;
        scanf("%d %d %d", &u, &v, &a);
        --u, --v;

        vector<int> res = solve(u, v, a);

        printf("%d", (int) res.size());
        for (int u: res) printf(" %d", u+1);
        printf("\n");
    }

    return 0;
}