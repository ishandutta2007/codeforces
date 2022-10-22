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

const int N = 1.5e5 + 5;

int n, a[N], b[N];
ll sum, ans[N];
struct node {
    int v, c, v2;
    void pu(const node& a, const node& b) {
        v = min(a.v, b.v), c = 0;
        v2 = min(a.v2, b.v2);
        if(v == a.v) c += a.c;
        else v2 = min(v2, a.v);
        if(v == b.v) c += b.c;
        else v2 = min(v2, b.v);
    }
} t[N * 4];

struct {
    int c[N];
    void add(int i, int v) {
        if(i) for(; i <= n; i += i & -i) c[i] += v;
    }
    int qry(int i, int r = 0) {
        for(; i; i &= i - 1) r += c[i];
        return r;
    }
} t1, t2;
void pu(int o) { t[o].pu(t[lc], t[rc]); }
void bld(int l, int r, int o) {
    t[o] = {0x3f3f3f3f, 0, 0x3f3f3f3f};
    if(l < r) bld(lch), bld(rch), pu(o);
}
void pd(int);
void dfs(int o, int v, bool ty) {
    if(v <= t[o].v) return;
    if(v < t[o].v2) {
        if(ty) {
            sum -= t[o].c * ll(t1.qry(v) - t1.qry(t[o].v));
            t2.add(t[o].v, t[o].c), t2.add(t[o].v = v, -t[o].c);
        } else t[o].v = v;
        return;
    }
    pd(o), dfs(lc, v, ty), dfs(rc, v, ty), pu(o);
}
void pd(int o) { dfs(lc, t[o].v, 0), dfs(rc, t[o].v, 0); }
void ins(int i, int l, int r, int o) {
    if(l == r) t[o].v = 0, t[o].c = 1;
    else pd(o), i <= mid ? ins(i, lch) : ins(i, rch), pu(o);
}
void upd(int L, int l, int r, int o) {
    if(L <= l) return dfs(o, L, 1);
    pd(o);
    if(L <= mid) upd(L, lch);
    upd(L, rch), pu(o);
}

int main() {
    cin >> n;
    rep(i, 1, n) scanf("%d", &a[i]);
    rep(kase, 1, 2) {
        sum = 0, mem(t1.c, 0), mem(t2.c, 0), bld(1, n, 1);
        rep(i, 1, n) b[a[i]] = i;
        rep(i, 1, n) {
            t1.add(b[i], 1), t2.add(b[i], 1);
            sum += t2.qry(n) - t2.qry(b[i] - 1) + t1.qry(b[i] - 1);
            upd(b[i], 1, n, 1), ins(b[i], 1, n, 1);
            ans[i] += sum;
        }
        reverse(a + 1, a + n + 1);
    }
    rep(i, 1, n) printf("%lld\n", ans[i] - i);
}