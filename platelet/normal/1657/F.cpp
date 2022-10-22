#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for (int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 4e5 + 5, M = N * 12;

int n, q, d[N], fa[N];
char buf[N];
int idx, tp, sid, dfn[M], scc[M], stk[M];
vector<int> T[N], G[M];

void add(int u, int v, bool x, bool y) {
    G[u << 1 | !x].pb(v << 1 | y);
    G[v << 1 | !y].pb(u << 1 | x);
}
int dfs(int u) {
    int low = dfn[u] = ++idx;
    stk[++tp] = u;
    for(int v : G[u]) if(!dfn[v]) low = min(low, dfs(v));
    else if(!scc[v]) low = min(low, dfn[v]);
    if(low == dfn[u]) {
        int v; sid++;
        do scc[v = stk[tp--]] = sid; while(v != u);
    }
    return low;
}
int read() {
    int c, r = 0;
    while((c = getchar()) < 48);
    while(c > 47) r = r * 10 + c - 48, c = getchar();
    return r;
}
void Dfs(int u) {
    for(int v : T[u]) if(v != fa[u])
        d[v] = d[u] + 1, fa[v] = u, Dfs(v);
}

int main() {
    cin >> n >> q;
    int u, v;
    rep(i, 2, n) u = read(), v = read(), T[u].pb(v), T[v].pb(u);
    Dfs(1);
    rep(k, n * 5 + 1, n * 5 + q) {
        int u = read(), v = read();
        scanf("%s", buf);
        auto rbuf = buf + strlen(buf) - 1;
        int l = 0, r = 0;
        if(d[u] < d[v]) swap(u, v);
        auto lnk = [&](int u, int off, bool dir) {
            rep(i, 0, 4) {
                add(k, u * 5 - i, dir, buf[off] - 97 >> i & 1);
                add(k, u * 5 - i, !dir, rbuf[-off] - 97 >> i & 1);
            }
        };
        while(d[u] > d[v]) lnk(u, l++, 0), u = fa[u];
        while(u != v) lnk(u, l++, 0), lnk(v, r++, 1), u = fa[u], v = fa[v];
        lnk(u, l, 0);
    }
    rep(i, 1, n * 5 + q << 1 | 1) if(!dfn[i]) dfs(i);
    rep(i, 1, n * 5 + q) if(scc[i << 1] == scc[i << 1 | 1]) cout << "NO", exit(0);
    cout << "YES\n";
    rep(i, 1, n) {
        int ans = 0;
        rep(j, 0, 4) if(scc[i * 5 - j << 1 | 1] < scc[i * 5 - j << 1]) ans |= 1LL << j;
        putchar(ans + 97);
    }
}