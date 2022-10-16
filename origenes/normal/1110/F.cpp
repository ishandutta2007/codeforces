#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 512345;
const ll inf = 0x3f3f3f3f3f3f3f3f;

struct Seg {
    int l, r;
    ll val, lzy;
} T[maxn << 2];

void build(int o, int l, int r) {
    T[o].l = l, T[o].r = r;
    T[o].val = inf;
    T[o].lzy = 0;
    if (l != r) {
        int m = l + r >> 1;
        build(o << 1, l, m);
        build(o << 1 | 1, m + 1, r);
    }
}

void add(int o, int l, int r, ll v) {
    if (l <= T[o].l && T[o].r <= r) {
        T[o].lzy += v;
        return;
    }
    // push down the lazy symbol
    T[o << 1].lzy += T[o].lzy;
    T[o << 1 | 1].lzy += T[o].lzy;
    T[o].lzy = 0;
    int m = T[o].l + T[o].r >> 1;
    if (l <= m) add(o << 1, l, r, v);
    if (r > m) add(o << 1 | 1, l, r, v);
    // push up the value
    T[o].val = min(T[o << 1].val + T[o << 1].lzy, T[o << 1 | 1].val + T[o << 1 | 1].lzy);
}

ll query(int o, int l, int r) {
    if (l <= T[o].l && T[o].r <= r) return T[o].val + T[o].lzy;
    // push down the lazy symbol
    T[o << 1].lzy += T[o].lzy;
    T[o << 1 | 1].lzy += T[o].lzy;
    T[o].lzy = 0;
    int m = T[o].l + T[o].r >> 1;
    ll ret = inf;
    if (l <= m) ret = min(ret, query(o << 1, l, r));
    if (r > m) ret = min(ret, query(o << 1 | 1, l, r));
    // push up the value
    T[o].val = min(T[o << 1].val + T[o << 1].lzy, T[o << 1 | 1].val + T[o << 1 | 1].lzy);
    return ret;
}

vector<pii> G[maxn];
vector<pair<pii, int>> qry[maxn];
int in[maxn], out[maxn], clk;
ll dis[maxn], ans[maxn];

void dfs(int u, int par) {
    in[u] = ++clk;
    for (auto _v : G[u]) {
        int v = _v._1, w = _v._2;
        if (v == par) continue;
        dis[v] = dis[u] + w;
        dfs(v, u);
    }
    out[u] = clk;
    // set leaf val to dis
    if (in[u] == out[u]) add(1, in[u], in[u], dis[u] - inf);
}

void dfs2(int u, int par) {
    for (auto _q : qry[u]) {
        int st = _q._1._1, en = _q._1._2, id = _q._2;
        ans[id] = query(1, st, en);
    }
    for (auto _v : G[u]) {
        int v = _v._1, w = _v._2;
        if (v == par) continue;
        add(1, 1, clk, w);
        add(1, in[v], out[v], -2 * w);
        dfs2(v, u);
        // backtracking
        add(1, in[v], out[v], 2 * w);
        add(1, 1, clk, -w);
    }
}

int n, q;

int main() {
    build(1, 1, 1 << 19);
    scanf("%d%d", &n, &q);
    FOR(i, 2, n) {
        int p, w;
        scanf("%d%d", &p, &w);
        G[i].eb(p, w);
        G[p].eb(i, w);
    }
    FOR(i, 1, n) sort(all(G[i]));
    dfs(1, 0);
    REP(i, q) {
        int v, l, r;
        scanf("%d%d%d", &v, &l, &r);
        qry[v].eb(mp(l, r), i);
    }
    dfs2(1, 0);
    REP(i, q) printf("%lld\n", ans[i]);
}