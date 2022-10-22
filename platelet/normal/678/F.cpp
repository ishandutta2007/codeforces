#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for (int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define mid ((l + r) >> 1)
#define lch l, mid, lc[o]
#define rch mid + 1, r, rc[o]

using namespace std;
using ll = long long;

const int N = 3e5 + 5, inf = 1e9 + 1;

struct line {
    int k, b;
    ll operator ()(int x) {
        return k < inf ? (ll)k * x + b : -0x3f3f3f3f3f3f3f3f;
    }
} c[N << 5];
int n, a[N], b[N];
int idx, lc[N << 5], rc[N << 5];
vector<line> v[N << 2];

void push(int L, int R, line x, int l, int r, int o) {
    if(L <= l && r <= R) return v[o].pb(x);
    if(L <= mid) push(L, R, x, l, mid, o << 1);
    if(R > mid) push(L, R, x, mid + 1, r, o << 1 | 1);
}
void ins(line x, int l, int r, int& o, int oo) {
    c[o = ++idx] = c[oo], lc[o] = lc[oo], rc[o] = rc[oo];
    if(c[o](mid) < x(mid)) swap(c[o], x);
    if(x(l) > c[o](l)) ins(x, lch, lc[oo]);
    else if(x(r) > c[o](r)) ins(x, rch, rc[oo]);
}
ll qry(int x, int l, int r, int o) {
    if(l == r) return c[o](x);
    return max(x <= mid ? qry(x, lch) : qry(x, rch), c[o](x));
}
void solve(int l, int r, int o, int rt) {
    int bef = idx;
    for(line x : v[o]) ins(x, -inf, inf, rt, rt);
    if(l == r) {
        if(a[l] == inf) if(rt) cout << qry(b[l], -inf, inf, rt) << '\n';
        else cout << "EMPTY SET\n";
    } else solve(l, mid, o << 1, rt), solve(mid + 1, r, o << 1 | 1, rt);
    idx = bef;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int t;
    rep(i, 1, n) {
        cin >> t;
        if(t == 1) cin >> a[i] >> b[i];
        if(t == 3) a[i] = inf, cin >> b[i];
        if(t == 2) cin >> t, push(t, i, {a[t], b[t]}, 1, n, 1), a[t] = a[i] = inf + 1;
    }
    rep(i, 1, n) if(a[i] < inf) push(i, n, {a[i], b[i]}, 1, n, 1);
    c[0].k = inf, solve(1, n, 1, 0);
}