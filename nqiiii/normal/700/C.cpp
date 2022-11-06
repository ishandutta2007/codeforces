#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000, maxM = 30000, inf = 2147483647;
int n, m, s, t;
struct Edge {
    int to, len, id;
};
vector<Edge> g[maxN + 10];
int len[maxM + 10];
int dfn[maxN + 10], dfsCnt, low[maxN + 10];
int fa[maxN + 10], faId[maxN + 10];
int ans = inf, ansCnt, ansId[3], ban;
bool isB[maxM + 10];

void Dfs(int p, int faEg) {
    dfn[p] = low[p] = ++dfsCnt;
    for (int i = 0; i < g[p].size(); ++i) {
        Edge e = g[p][i];
        if (e.id != faEg && e.id != ban) 
            if (!dfn[e.to]) {
                fa[e.to] = p; faId[e.to] = e.id;
                Dfs(e.to, e.id);
                low[p] = min(low[p], low[e.to]);
                if (low[e.to] > dfn[p]) isB[e.id] = 1;
            } else low[p] = min(low[p], dfn[e.to]);
    }
}

int TFa[maxN + 10], TDfn[maxN + 10], TLow[maxN + 10], TDfsCnt;
int TIsB[maxM + 10], TFaId[maxN + 10];

void TDfs(int p, int faEg) {
    TDfn[p] = TLow[p] = ++TDfsCnt;
    for (int i = 0; i < g[p].size(); ++i) {
        Edge e = g[p][i];
        if (e.id != faEg && e.id != ban) 
            if (!TDfn[e.to]) {
                TFa[e.to] = p; TFaId[e.to] = e.id;
                TDfs(e.to, e.id);
                TLow[p] = min(TLow[p], TLow[e.to]);
                if (TLow[e.to] > TDfn[p]) TIsB[e.id] = 1;
            } else TLow[p] = min(TLow[p], TDfn[e.to]);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    scanf("%d%d", &s, &t);
    for (int i = 1; i <= m; ++i) {
        int l, r, w; scanf("%d%d%d", &l, &r, &w);
        g[l].push_back((Edge){r, w, i}); g[r].push_back((Edge){l, w, i});
        len[i] = w;
    }
    Dfs(s, 0);
    if (!dfn[t]) {
        printf("0\n0"); return 0;
    }
    for (int i = t; i != s; i = fa[i])
        if (isB[faId[i]]) {
            if (len[faId[i]] < ans) {
                ans = len[faId[i]];
                ansId[ansCnt = 1] = faId[i];
            }
        } else {
            TDfsCnt = 0;
            ban = faId[i];
            for (int j = 1; j <= n; ++j) TDfn[j] = 0;
            for (int j = 1; j <= m; ++j) TIsB[j] = 0;
            TDfs(s, 0);
            for (int j = t; j != s; j = TFa[j])
                if (TIsB[TFaId[j]] && len[faId[i]] + len[TFaId[j]] < ans) {
                    ans = len[faId[i]] + len[TFaId[j]];
                    ansCnt = 2;
                    ansId[1] = faId[i]; ansId[2] = TFaId[j];
                }
        }
    if (ans == inf) printf("-1");
    else {
        printf("%d\n%d\n", ans, ansCnt);
        for (int i = 1; i <= ansCnt; ++i) printf("%d ", ansId[i]);
    }
}