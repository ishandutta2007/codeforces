#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template<typename T> T mo(T x, T y) { x %= y; return x <= 0 ? x + y : x; }

const int MX = 100 * 1000 + 7;

namespace gibbon
{
    const int MAXN = 60000 + 7;
    const int INF = 1000000000;

    struct edge {
        int a, b, cap, flow;
    };

    int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
    vector<edge> e;
    vector<int> g[MAXN];

    void add_edge(int a, int b, int cap) {
        edge e1 = { a, b, cap, 0 };
        edge e2 = { b, a, 0, 0 };
        g[a].push_back((int)e.size());
        e.push_back(e1);
        g[b].push_back((int)e.size());
        e.push_back(e2);
    }

    bool bfs() {
        int qh = 0, qt = 0;
        q[qt++] = s;
        memset(d, -1, n * sizeof d[0]);
        d[s] = 0;
        while (qh < qt && d[t] == -1) {
            int v = q[qh++];
            for (size_t i = 0; i < g[v].size(); ++i) {
                int id = g[v][i],
                    to = e[id].b;
                if (d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }

    int dfs(int v, int flow) {
        if (!flow)  return 0;
        if (v == t)  return flow;
        for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
            int id = g[v][ptr[v]],
                to = e[id].b;
            if (d[to] != d[v] + 1)  continue;
            int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
            if (pushed) {
                e[id].flow += pushed;
                e[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    int dinic() {
        int flow = 0;
        for (;;) {
            if (!bfs())  break;
            memset(ptr, 0, n * sizeof ptr[0]);
            while (int pushed = dfs(s, INF))
                flow += pushed;
        }
        return flow;
    }
}

int u[MX], v[MX], c[MX];
bool inCyc[MX];

vector<int> g[MX];

int pv[MX], pe[MX];
bool was[MX];
int h[MX];

int n, m;

int lptr = 0;

void dfs(int v, int p) {
    was[v] = true;
    for (int e : g[v]) {
        int to = v ^ ::v[e] ^ u[e];
        if (to != p) {
            if (!was[to]) {
                pv[to] = v;
                pe[to] = e;
                h[to] = h[v] + 1;
                dfs(to, v);
            } else if (h[to] < h[v]) {
                vector<int> cyc;
                inCyc[e] = true;
                cyc.push_back(c[e]);
                int vv = v;
                while (vv != to) {
                    inCyc[pe[vv]] = true;
                    cyc.push_back(c[pe[vv]]);
                    vv = pv[vv];
                }
                int cv = lptr + 1;
                lptr++;
                for (int x : cyc) {
                    gibbon::add_edge(cv, m + x, 1);
                }
                gibbon::add_edge(0, cv, cyc.size() - 1);
            }
        }
    }
}

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> c[i];
        g[u[i]].emplace_back(i);
        g[v[i]].emplace_back(i);
    }

    for (int i = 1; i <= n; i++) {
        if (!was[i]) {
            dfs(i, -1);
        }
    }

    for (int i = 0; i < m; i++) {
        if (!inCyc[i]) {
            gibbon::add_edge(0, c[i] + m, 1);
        }
    }
    for (int i = 1; i <= m; i++) {
        gibbon::add_edge(i + m, m + m + 1, 1);
    }
    gibbon::n = gibbon::MAXN - 1;
    gibbon::s = 0;
    gibbon::t = m + m + 1;
    int ans = gibbon::dinic();
    cout << ans << "\n";
    return 0;
}