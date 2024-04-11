#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define L first
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define R second
#define smin(x, y) (x) = min((x), (y))
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

const int maxn = 200 * 1000 + 10;
vector<int> adj[maxn],
    tadj[maxn];
set<int> in[maxn],
    out[maxn];
int mark[maxn],
    par[maxn],
    siz[maxn],
    h[maxn],
    frm[maxn],
    too[maxn],
    n, m, q;

int root(int u) {
    return par[u] < 0 ? u : par[u] = root(par[u]);
}

void merge(int u, int v) {
    if ((u = root(u)) == (v = root(v)))
        return;
    if (par[u] > par[v])
        swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return;
}

int dfs(int u, int ep = -1) {
    mark[u] = 1;
    int res = h[u];
    for (int e: adj[u]) if (e ^ ep) {
        int v = frm[e] ^ too[e] ^ u;
        if (mark[v] == 1)
            smin(res, h[v]);
        else if (mark[v] == 0) {
            h[v] = h[u] + 1;
            int vup = dfs(v, e);
            if (vup <= h[u])
                merge(u, v);
            smin(res, vup);
        }
    }
    mark[u] = 2;
    return res;
}

bool bad = false;
void tdfs(int u, int p = -1) {
    mark[u] = true;
    for (int i = 0; i < sz(tadj[u]); i++)
        if (tadj[u][i] == p)
            tadj[u].erase(tadj[u].begin() + i);
    siz[u] = 1;
    for (int v: tadj[u]) {
        tdfs(v, u);
        siz[u] += siz[v];
    }
    sort(all(tadj[u]), [](int i, int j) { return siz[i] > siz[j]; });
    if (sz(tadj[u])) {
        int v = tadj[u][0];
        in[u].swap(in[v]);
        out[u].swap(out[v]);
    }
    for (int v: tadj[u]) {
        for (int qid: in[v])
            if (out[u].count(qid))
                out[u].erase(qid);
            else
                in[u].insert(qid);
        in[v].clear();
        for (int qid: out[v])
            if (in[u].count(qid))
                in[u].erase(qid);
            else
                out[u].insert(qid);
        out[v].clear();
    }
    if (sz(out[u]) and sz(in[u])) {
        bad = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(par, -1, sizeof par);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        cin >> frm[i] >> too[i];
        frm[i]--, too[i]--;
        adj[frm[i]].PB(i);
        adj[too[i]].PB(i);
    }
    for (int i = 0; i < n; i++)
        if (!mark[i])
            dfs(i);
    for (int i = 0; i < m; i++) {
        int u = root(frm[i]);
        int v = root(too[i]);
        if (u != v) {
            tadj[u].PB(v);
            tadj[v].PB(u);
        }
    }
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        u = root(u), v = root(v);
        if (u == v) continue;
        out[u].insert(i);
        in[v].insert(i);
    }
    memset(mark, false, sizeof mark);
    for (int i = 0; i < n; i++)
        if (!mark[i] and par[i] < 0) {
            tdfs(i);
            if (sz(in[i]) or sz(out[i]))
                bad = true;
        }
    if (bad)
        cout << "No\n";
    else
        cout << "Yes\n";
    return 0;
}