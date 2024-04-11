#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int n, m, dfn[N * 2], key[N], l2[3126];
ll a[N * 2], st[12][3126], pre[N * 2], suf[N * 2];
ll *p = st[0], d[84][84];
ll D[N][2]; int K[N][2];

int eid, he[N];
struct { int v, w, nxt; } e[N * 2];

void cmin(ll& a, ll b) { if(b < a) a = b; }
void add(int u, int v, int w) {
    e[++eid] = {v, w, he[u]}, he[u] = eid;
    e[++eid] = {u, w, he[v]}, he[v] = eid;
}

bool dfs(int u, int fa, ll d) {
    int ch = 0;
    dfn[u] = ++m, a[m] = d;
    if(!(m & 63)) *++p = inf;
    if(d < *p) *p = d;
    for(int i = he[u], v; v = e[i].v; i = e[i].nxt) if(!dfn[v]) {
        ch += dfs(v, u, d + e[i].w);
        a[++m] = d;
        if(!(m & 63)) *++p = inf;
        if(d < *p) *p = d;
    } else if(v != fa) key[u] = 1;
    if(ch > 1) key[u] = 1;
    return ch || key[u];
}
void dfs(int u, int fa, int s, ll d) {
    if(K[u][0]) D[u][1] = d, K[u][1] = s;
    else D[u][0] = d, K[u][0] = s;
    for(int i = he[u], v; v = e[i].v; i = e[i].nxt) if(v != fa) {
        if(key[v]) cmin(::d[s][key[v]], d + e[i].w);
        else dfs(v, u, s, d + e[i].w);
    }
}
ll dis(int u, int v) {
    if(u = dfn[u], v = dfn[v]; u > v) swap(u, v);
    ll sum = a[u] + a[v], res = inf;
    if(u >> 6 == v >> 6) {
        for(; u <= v; u++) if(a[u] < res) res = a[u];
    } else {
        res = min(suf[u], pre[v]);
        u >>= 6, v = (v >> 6) - 1;
        if(u < v) {
            int t = l2[v - u];
            res = min({res, st[t][u + (1 << t)], st[t][v]});
        }
    }
    return sum - res * 2;
}
int read() {
    const int M = 1e6;
    static streambuf* in = cin.rdbuf();
    #define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, M), p1 == p2) ? -1 : *p1++)
    static char buf[M], *p1, *p2;
    int c = gc, r = 0;
    while(c < 48) c = gc;
    while(c > 47) r = r * 10 + (c & 15), c = gc;
    return r;
}
void wrt(ll x) {
    static streambuf* out = cout.rdbuf();
    #define pc out -> sputc
    static char c[20]; int sz = 0;
    do c[++sz] = x % 10, x /= 10; while(x);
    while(sz) pc(c[sz--] + 48);
    pc(10);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    mem(d, 63);
    cin >> n >> m;
    int u, v;
    while(m--) u = read(), v = read(), add(u, v, read());
    m = 0, dfs(1, 0, 0), pre[0] = suf[m + 1] = inf;
    rep(i, 1, m) pre[i] = i & 63 ? min(pre[i - 1], a[i]) : a[i];
    per(i, m, 1) suf[i] = ~i & 63 ? min(suf[i + 1], a[i]) : a[i];
    m >>= 6;
    rep(i, 2, m) l2[i] = l2[i >> 1] + 1;
    rep(i, 1, 12) rep(j, 1 << i, m)
        st[i][j] = min(st[i - 1][j], st[i - 1][j - (1 << i - 1)]);
    m = 0;
    rep(i, 1, n) if(key[i]) key[i] = ++m;
    rep(i, 1, n) if(key[i]) dfs(i, 0, key[i], 0);
    rep(k, 1, m) rep(i, 1, m) rep(j, 1, m)
        cmin(d[i][j], d[i][k] + d[k][j]);
    m = read();
    while(m--) {
        u = read(), v = read();
        wrt(min({dis(u, v)
        , D[u][0] + D[v][0] + d[K[u][0]][K[v][0]]
        , D[u][0] + D[v][1] + d[K[u][0]][K[v][1]]
        , D[u][1] + D[v][0] + d[K[u][1]][K[v][0]]
        , D[u][1] + D[v][1] + d[K[u][1]][K[v][1]]
        }));
    }
}