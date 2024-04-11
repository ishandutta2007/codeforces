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

const int maxn = 600 * 1000 + 10,
      maxl = 20;
int par[maxn][maxl],
    stim[maxn],
    ftim[maxn],
    sum[maxn],
    frm[maxn],
    too[maxn],
    wei[maxn],
    fen[maxn],
    dsu[maxn],
    h[maxn],
    n, m, tim;
vector<int> adj[maxn];

void dfslca(int u, int p = -1) {
    stim[u] = tim++;
    par[u][0] = p;
    for (int j = 1; j < maxl; j++)
        if (par[u][j - 1] == -1)
            par[u][j] = -1;
        else
            par[u][j] = par[par[u][j - 1]][j - 1];
    for (int e: adj[u]) {
        int v = frm[e] ^ too[e] ^ u;
        if (v == p)
            continue;
        h[v] = h[u] + 1;
        sum[v] = sum[u] ^ wei[e];
        dfslca(v, u);
    }
    ftim[u] = tim;
}

bool ispar(int u, int v) {
    if (u == -1) return true;
    return stim[u] <= stim[v] and stim[v] < ftim[u];
}

int lca(int u, int v) {
    if (h[u] > h[v]) swap(u, v);
    if (ispar(u, v)) return u;
    for (int i = maxl - 1; i >= 0; i--)
        if (!ispar(par[u][i], v))
            u = par[u][i];
    return par[u][0];
}

int get(int idx) {
    int sum = 0;
    for (idx++; idx != 0; idx -= idx & -idx)
        sum += fen[idx];
    return sum;
}

void sadd(int val, int idx) {
    for (idx++; idx < maxn; idx += idx & -idx)
        fen[idx] += val;
}

void add(int st, int en) {
    sadd(+1, st);
    sadd(-1, en);
}

int root(int u) {
    return dsu[u] < 0 ? u : dsu[u] = root(dsu[u]);
}

bool merge(int u, int v) {
    if ((u = root(u)) == (v = root(v)))
        return false;
    if (dsu[u] > dsu[v])
        swap(u, v);
    dsu[u] += dsu[v];
    dsu[v] = u;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(dsu, -1, sizeof dsu);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> frm[i] >> too[i] >> wei[i];
        frm[i]--, too[i]--;
        if (merge(frm[i], too[i])) {
            adj[frm[i]].PB(i);
            adj[too[i]].PB(i);
        }
    }
    {
        int cnt = m;
        for (int i = 1; i < n; i++)
            if (merge(0, i)) {
                frm[cnt] = 0;
                too[cnt] = i;
                adj[0].PB(cnt);
                adj[i].PB(cnt);
                cnt++;
            }
    }
    dfslca(0);
    for (int i = 0; i < m; i++) {
        int u = frm[i];
        int v = too[i];
        int w = wei[i];
        if (h[u] > h[v]) swap(u, v);
        if (u == par[v][0]) {
            cout << "YES\n";
            continue;
        }
        int p = lca(u, v);
        if (get(stim[u]) + get(stim[v]) - 2 * get(stim[p]) > 0 or sum[u] ^ sum[v] ^ w != 1) {
            cout << "NO\n";
            continue;
        }
        while (u != p) {
            add(stim[u], ftim[u]);
            u = par[u][0];
        }
        while (v != p) {
            add(stim[v], ftim[v]);
            v = par[v][0];
        }
        cout << "YES\n";
    }
    return 0;
}