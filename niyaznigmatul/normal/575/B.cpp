#include <bits/stdc++.h>

using namespace std;

int const MOD = 1000000007;
int const K = 20;
int const N = 1234567;

void add(int & a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

struct edge {
    int from, to, type;
};

vector<edge> edges[N];
int pp[K][N], en[N], T = 0, ex[N], parent[N], s1[N], s2[N];
int two[N];
int ans;

void dfs(int v, int pv) {
    en[v] = T++;
    parent[v] = pv;
    pp[0][v] = pv < 0 ? v : pv;
    for (int i = 1; i < K; i++) {
        pp[i][v] = pp[i - 1][pp[i - 1][v]];
    }
    for (edge & e : edges[v]) {
        if (e.to == pv) continue;
        dfs(e.to, v);
    }
    ex[v] = T;
}

bool anc(int v, int u) {
    return en[v] <= en[u] && ex[u] <= ex[v];
}

int lca(int v, int u) {
    if (anc(v, u)) return v;
    for (int i = K - 1; i >= 0; i--) 
        if (!anc(pp[i][v], u))
            v = pp[i][v];
    return parent[v];
}

void dfs2(int v, int pv) {
    for (edge & e : edges[v]) {
        if (e.to == pv) continue;
        dfs2(e.to, v);
        if (e.type == 1) {
            add(ans, two[s1[e.to]]);
        } else if (e.type == -1) {
            add(ans, two[s2[e.to]]);
        }
        s1[v] += s1[e.to];
        s2[v] += s2[e.to];
    }
}

int main() {
    two[0] = 1;
    for (int i = 1; i < N; i++) {
        add(two[i], two[i - 1]);
        add(two[i], two[i - 1]);
    }
    for (int i = 0; i < N; i++) add(two[i], MOD - 1);
    int n;
    scanf("%d", &n);
    for (int i = 0; i + 1 < n; i++) {
        int v, u, type;
        scanf("%d%d%d", &v, &u, &type);
        --v;
        --u;
        edges[v].push_back({v, u, type});
        edges[u].push_back({u, v, -type});
    }
    dfs(0, -1);
    int m;
    scanf("%d", &m);
    int cur = 0;
    for (int i = 0; i < m; i++) {
        int ncur;
        scanf("%d", &ncur);
        --ncur;
        s1[cur]++;
        int v = lca(cur, ncur);
        s1[v]--;
        s2[ncur]++;
        s2[v]--;
        cur = ncur;
    }
    ans = 0;
    dfs2(0, -1);
    printf("%d\n", ans);
}