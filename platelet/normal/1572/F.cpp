#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define mid ((l + r) >> 1)
#define lc (o << 1)
#define rc (o << 1 | 1)
#define lch l, mid, lc
#define rch mid + 1, r, rc

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, q; ll c1[N], c2[N];
struct node {
    int v, c, v2;
    void pu(const node& a, const node& b) {
        v = max(a.v, b.v), c = 0;
        v2 = max(a.v2, b.v2);
        if(v == a.v) c += a.c;
        else v2 = max(v2, a.v);
        if(v == b.v) c += b.c;
        else v2 = max(v2, b.v);
    }
} t[N * 4];

void add(int i, ll v) {
    for(ll w = i * v; i <= n; i += i & -i)
        c1[i] += v, c2[i] += w;
}
ll qry(int i, ll r = 0) {
    for(int j = i; j; j &= j - 1)
        r += c1[j] * (i + 1) - c2[j];
    return r;
}
void pu(int o) { t[o].pu(t[lc], t[rc]); }
void pd(int);
void bld(int l, int r, int o) {
    if(l == r) t[o] = {l + 1, 1}, add(l, 1), add(l + 1, -1);
    else bld(lch), bld(rch), pu(o);
}
void dfs(int o, int v, bool ty) {
    if(v >= t[o].v) return;
    if(v > t[o].v2) {
        if(ty) add(t[o].v, t[o].c), add(v, -t[o].c);
        t[o].v = v;
        return;
    }
    pd(o), dfs(lc, v, ty), dfs(rc, v, ty), pu(o);
}
void pd(int o) { dfs(lc, t[o].v, 0), dfs(rc, t[o].v, 0); }
void ins(int i, int v, int l, int r, int o) {
    if(l == r) add(t[o].v, 1), add(v, -1), t[o] = {v, 1};
    else pd(o), i <= mid ? ins(i, v, lch) : ins(i, v, rch), pu(o);
}
void upd(int R, int l, int r, int o) {
    if(r <= R) return dfs(o, R, 1);
    pd(o);
    if(R > mid) upd(R, rch);
    upd(R, lch), pu(o);
}

int main() {
    cin >> n >> q;
    bld(1, n, 1);
    int p, a, b;
    while(q--) {
        scanf("%d%d%d", &p, &a, &b);
        if(p == 1) upd(a, 1, n, 1), ins(a, b + 1, 1, n, 1);
        else printf("%lld\n", qry(b) - qry(a - 1));
    }
}