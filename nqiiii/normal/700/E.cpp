#include <bits/stdc++.h>
using namespace std;
const int maxN = 200000, maxC = 10000000;
int n;
char s[maxN + 10];
struct Node {
    int tr[26], fa, maxL, pos;
    bool is;
}a[maxN * 2 + 10];
int np = 1, ndCnt = 1;
int dfn[maxN * 2 + 10], dfsCnt;
int ed[maxN * 2 + 10];
vector<int> g[maxN * 2 + 10];
int val[maxN + 10], rt[maxN + 10];
int lc[maxC + 10], rc[maxC + 10], tot[maxC + 10];
int tNdCnt, ans;
int f[maxN * 2 + 10], bd[maxN * 2 + 10];

void Insert(int c) {
    int p = np; np = ++ndCnt;
    a[np].maxL = a[np].pos = a[p].maxL + 1; a[np].is = 1;
    while (p && !a[p].tr[c]) {
        a[p].tr[c] = np; p = a[p].fa;
    }
    if (p) {
        int q = a[p].tr[c];
        if (a[p].maxL + 1 == a[q].maxL) a[np].fa = q;
        else {
            int nq = ++ndCnt; a[nq] = a[q];
            a[nq].maxL = a[p].maxL + 1; a[q].fa = a[np].fa = nq;
            a[nq].is = 0;
            while (a[p].tr[c] == q) {
                a[p].tr[c] = nq; p = a[p].fa;
            }
        }
    } else a[np].fa = 1;
}

void Dfs(int p) {
    dfn[p] = dfsCnt + 1;
    if (a[p].is) {
        val[++dfsCnt] = a[p].maxL;
    }
    for (int i = 0; i < g[p].size(); ++i)
        Dfs(g[p][i]);
    ed[p] = dfsCnt;
}

void BuildTree(int &p, int ls, int rs) {
    p = ++tNdCnt;
    if (ls != rs) {
        int mid = (ls + rs) / 2;
        BuildTree(lc[p], ls, mid);
        BuildTree(rc[p], mid + 1, rs);
    }
}

void Add(int &p, int cmp, int k, int ls, int rs) {
    p = ++tNdCnt; lc[p] = lc[cmp]; rc[p] = rc[cmp];
    tot[p] = tot[cmp] + 1;
    if (ls != rs) {
        int mid = (ls + rs) / 2;
        if (k <= mid) Add(lc[p], lc[cmp], k, ls, mid);
        else Add(rc[p], rc[cmp], k, mid + 1, rs);
    }
}

int Query(int p, int l, int r, int ls, int rs) {
    if (l == ls && r == rs) return tot[p];
    else {
        int mid = (ls + rs) / 2;
        if (r <= mid) return Query(lc[p], l, r, ls, mid);
        else if (l > mid) return Query(rc[p], l, r, mid + 1, rs);
        else return Query(lc[p], l, mid, ls, mid) + Query(rc[p], mid + 1, r, mid + 1, rs);
    }
}

void Dp(int p) {
    for (int i = 0; i < g[p].size(); ++i) {
        int e = g[p][i];
        int l = a[e].pos - a[e].maxL + 1 + a[a[bd[p]].fa].maxL;
        int r = a[e].pos;
        int v = Query(rt[ed[bd[p]]], l, r, 1, n) - Query(rt[dfn[bd[p]] - 1], l, r, 1, n);
        if (v >= 2 || p == 1) {
            f[e] = f[p] + 1; bd[e] = e;
        } else {
            f[e] = f[p]; bd[e] = bd[p];
        }
        ans = max(ans, f[e]);
        Dp(e);
    }
}

int main() {
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i <= n; ++i) Insert(s[i] - 'a');
    for (int i = 2; i <= ndCnt; ++i)
        g[a[i].fa].push_back(i);
    Dfs(1);
    BuildTree(rt[0], 1, n);
    for (int i = 1; i <= dfsCnt; ++i)
        Add(rt[i], rt[i - 1], val[i], 1, n);
    Dp(1); printf("%d", ans);
}