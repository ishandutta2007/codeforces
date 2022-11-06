#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const int sigSz = 26, maxM = 200000, maxN = 200;
char s[sigSz + 10];
bool sig[sigSz + 10];
int k, p1[maxM + 10], p2[maxM + 10];
int n, m, pos, a[maxN + 10];
bool b1[maxM + 10], b2[maxM + 10];
vector<int> g[maxN * 2 + 10];
int dfn[maxN * 2 + 10], low[maxN * 2 + 10], scc[maxN * 2 + 10];
int scc2[maxN * 2 + 10], sccCnt2;
int dfsCnt, sccCnt, sz[maxN * 2 + 10];
stack<int> stk;

void Dfs(int p) {
    dfn[p] = low[p] = ++dfsCnt;
    stk.push(p);
    for (int i = 0; i < g[p].size(); ++i) {
        int e = g[p][i];
        if (!dfn[e]) {
            Dfs(e); low[p] = min(low[p], low[e]);
        } else if (!scc2[e]) low[p] = min(low[p], dfn[e]);
    }
    if (dfn[p] == low[p]) {
        ++sccCnt2;
        for (;;) {
            int t = stk.top(); stk.pop();
            scc2[t] = sccCnt2;
            if (t == p) break;
        }
    }
}
void Dfss(int p) {
    dfn[p] = low[p] = ++dfsCnt;
    stk.push(p);
    for (int i = 0; i < g[p].size(); ++i) {
        int e = g[p][i];
        if (!dfn[e]) {
            Dfss(e); low[p] = min(low[p], low[e]);
        } else if (!scc[e]) low[p] = min(low[p], dfn[e]);
    }
    if (dfn[p] == low[p]) {
        ++sccCnt;
        for (;;) {
            int t = stk.top(); stk.pop();
            scc[t] = sccCnt;
            if (t == p) break;
        }
    }
}
bool TwoSat() {
    for (int i = 1; i <= sccCnt; ++i) {
        dfn[i] = low[i] = scc2[i] = 0;
    }
    dfsCnt = sccCnt2 = 0;
    for (int i = 1; i <= sccCnt; ++i)
        if (!dfn[i]) Dfs(i);
    for (int i = 1; i <= n; ++i)
        if (scc2[scc[i * 2]] == scc2[scc[i * 2 - 1]]) return 0;
    return 1;
}
bool Check(int p) {
    for (int i = 1; i <= sccCnt; ++i) g[i].clear();
    for (int i = 1; i <= m; ++i) {
        if (scc[p1[i] * 2 - b1[i]] != scc[p2[i] * 2 - b2[i]])
            g[scc[p1[i] * 2 - b1[i]]].push_back(scc[p2[i] * 2 - b2[i]]);
        if (scc[p2[i] * 2 - !b2[i]] != scc[p1[i] * 2 - !b1[i]])
            g[scc[p2[i] * 2 - !b2[i]]].push_back(scc[p1[i] * 2 - !b1[i]]);
    }
    for (int i = 1; i <= p; ++i) 
        if (scc[i * 2 - !sig[a[i]]] != scc[i * 2 - sig[a[i]]])
            g[scc[i * 2 - !sig[a[i]]]].push_back(scc[i * 2 - sig[a[i]]]);
    for (int i = p + 1; i <= n; ++i) {
        int lower = i == p + 1 ? a[i] + 1 : 1;
        bool is0 = 0, is1 = 0;
        for (int j = lower; j <= k; ++j)
            if (sig[j]) is1 = 1;
            else is0 = 1;
        if (!is0 && !is1) return 0;
        if (!is1) g[scc[i * 2 - 1]].push_back(scc[i * 2]);
        if (!is0) g[scc[i * 2]].push_back(scc[i * 2 - 1]);
    }
    return TwoSat();
}
bool Check2(int p) {
    for (int i = 1; i <= sccCnt; ++i) g[i].clear();
    for (int i = 1; i <= m; ++i) {
        if (scc[p1[i] * 2 - b1[i]] != scc[p2[i] * 2 - b2[i]])
            g[scc[p1[i] * 2 - b1[i]]].push_back(scc[p2[i] * 2 - b2[i]]);
        if (scc[p2[i] * 2 - !b2[i]] != scc[p1[i] * 2 - !b1[i]])
            g[scc[p2[i] * 2 - !b2[i]]].push_back(scc[p1[i] * 2 - !b1[i]]);
    }
    for (int i = 1; i <= p; ++i) 
        if (scc[i * 2 - !sig[a[i]]] != scc[i * 2 - sig[a[i]]])
            g[scc[i * 2 - !sig[a[i]]]].push_back(scc[i * 2 - sig[a[i]]]);
    for (int i = p + 1; i <= n; ++i) {
        bool is0 = 0, is1 = 0;
        for (int j = 1; j <= k; ++j)
            if (sig[j]) is1 = 1;
            else is0 = 1;
        if (!is0 && !is1) return 0;
        if (!is1) g[scc[i * 2 - 1]].push_back(scc[i * 2]);
        if (!is0) g[scc[i * 2]].push_back(scc[i * 2 - 1]);
    }
    return TwoSat();
}
int main() {
    scanf("%s", s + 1); k = strlen(s + 1);
    for (int i = 1; i <= k; ++i) sig[i] = s[i] == 'V';
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        char s1[5], s2[5];
        scanf("%d%s%d%s", &p1[i], s1, &p2[i], s2);
        b1[i] = s1[0] == 'V'; b2[i] = s2[0] == 'V';
        g[p1[i] * 2 - b1[i]].push_back(p2[i] * 2 - b2[i]);
        g[p2[i] * 2 - !b2[i]].push_back(p1[i] * 2 - !b1[i]);
    }
    for (int i = 1; i <= n * 2; ++i) if (!dfn[i]) Dfss(i);
    for (int i = 1; i <= n; ++i)
        if (scc[i * 2] == scc[i * 2 - 1]) {
            printf("-1"); return 0;
    }
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) a[i] = s[i] - 'a' + 1;
    for (pos = n; pos >= 1; --pos)
        if (Check(pos)) break;
    for (int i = pos + 1; i <= n; ++i) {
        int lower = i == pos + 1 ? a[i] + 1 : 1;
        bool vis0 = 0, vis1 = 0;
        for (int j = lower; ; ++j) {
            if (j > k) {
                printf("-1"); return 0;
            }
            if (sig[j]) {
                if (vis1) continue;
                else vis1 = 1;
            } else {
                if (vis0) continue;
                else vis0 = 1;
            }
            a[i] = j;
            if (Check2(i)) break;
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%c", a[i] + 'a' - 1);
}