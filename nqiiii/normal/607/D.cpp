#include <bits/stdc++.h>
using namespace std;
const int maxN = 200000, mod = 1000000007;

int Add(int x, int y) {
    x += y; return x < mod ? x : x - mod;
}

int Mul(int x, int y) {
    return 1ll * x * y % mod;
}

int Fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = Mul(ans, x);
        y >>= 1; x = Mul(x, x);
    }
    return ans;
}

int val[maxN + 10], q, n = 1, op[maxN + 10], x[maxN + 10], y[maxN + 10];
int mul[maxN + 10], dfsCnt, id[maxN + 10];
vector<int> g[maxN + 10];
int dfn[maxN + 10], ed[maxN + 10], dfnBk[maxN + 10];
int fa[maxN + 10];

void Dfs(int p) {
    dfn[p] = ++dfsCnt;
    dfnBk[dfn[p]] = p;
    for (int i = 0; i < g[p].size(); ++i)
        Dfs(g[p][i]);
    ed[p] = dfsCnt;
}

namespace SegTree {
    struct Data {
        int totMul, totVal;
    }a[maxN * 4 + 10];
    int tag[maxN * 4 + 10];
    Data operator + (const Data &a, const Data &b) {
        return (Data){Add(a.totMul, b.totMul), Add(a.totVal, b.totVal)};
    }
    void Build(int p, int ls, int rs) {
        tag[p] = 1;
        if (ls == rs) a[p] = (Data){mul[dfnBk[ls]], Mul(mul[dfnBk[ls]], val[dfnBk[ls]])};
        else {
            int mid = ls + rs >> 1;
            Build(p << 1, ls, mid); Build(p << 1 | 1, mid + 1, rs);
            a[p] = a[p << 1] + a[p << 1 | 1];
        }
    }
    void Apply(int p, int v) {
        tag[p] = Mul(tag[p], v);
        a[p].totMul = Mul(a[p].totMul, v);
        a[p].totVal = Mul(a[p].totVal, v);
    }
    void Push(int p) {
        Apply(p << 1, tag[p]); Apply(p << 1 | 1, tag[p]);
        tag[p] = 1;
    }
    void Change(int p, int l, int r, int v, int ls, int rs) {
        if (l == ls && r == rs) Apply(p, v);
        else {
            int mid = ls + rs >> 1; Push(p);
            if (r <= mid) Change(p << 1, l, r, v, ls, mid);
            else if (l > mid) Change(p << 1 | 1, l, r, v, mid + 1, rs);
            else {
                Change(p << 1, l, mid, v, ls, mid);
                Change(p << 1 | 1, mid + 1, r, v, mid + 1, rs);
            }
            a[p] = a[p << 1] + a[p << 1 | 1];
        }
    }
    void ChangeV(int p, int k, int v, int ls, int rs) {
        if (ls == rs) a[p].totVal = Mul(a[p].totMul, v);
        else {
            int mid = ls + rs >> 1; Push(p);
            if (k <= mid) ChangeV(p << 1, k, v, ls, mid);
            else ChangeV(p << 1 | 1, k, v, mid + 1, rs);
            a[p] = a[p << 1] + a[p << 1 | 1];
        }
    }
    Data Query(int p, int l, int r, int ls, int rs) {
        if (l == ls && r == rs) return a[p];
        else {
            int mid = ls + rs >> 1; Push(p);
            if (r <= mid) return Query(p << 1, l, r, ls, mid);
            else if (l > mid) return Query(p << 1 | 1, l, r, mid + 1, rs);
            else return Query(p << 1, l, mid, ls, mid) + Query(p << 1 | 1, mid + 1, r, mid + 1, rs);
        }
    }
}

int main() {
    scanf("%d%d", &val[1], &q);
    for (int i = 1; i <= q; ++i) {
        scanf("%d%d", &op[i], &x[i]);
        if (op[i] == 1) {
            scanf("%d", &y[i]);
            g[x[i]].push_back(++n); id[i] = n;
            fa[n] = x[i];
        }
    }
    Dfs(1);
    for (int i = 1; i <= n; ++i) mul[i] = 1;
    SegTree::Build(1, 1, n);
    for (int i = 1; i <= q; ++i)
        if (op[i] == 1) {
            SegTree::Change(1, dfn[x[i]], ed[x[i]], Mul(mul[x[i]] + 1, Fpow(mul[x[i]], mod - 2)), 1, n);
            ++mul[x[i]];
            SegTree::ChangeV(1, dfn[id[i]], y[i], 1, n);
        } else {
            int ans = SegTree::Query(1, dfn[x[i]], ed[x[i]], 1, n).totVal;
            if (x[i] != 1) ans = Mul(ans, Fpow(SegTree::Query(1, dfn[fa[x[i]]], dfn[fa[x[i]]], 1, n).totMul, mod - 2));
            printf("%d\n", ans);
        }
}