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

int n, m, q;
char c[(1 << 19) + 5][2][6];
bool t[(1 << 19) + 5];

void pu(int o) {
    rep(k, 0, 1) rep(i, 0, m) c[o][k ^ t[o]][i] = c[lc][k][c[rc][k][i]];
}
void bld(int l, int r, int o) {
    if(l == r) {
        ll x;
        cin >> x;
        rep(i, 0, 1) rep(j, 0, m - i) c[o][i ^ (x & 1)][j] = min(j + 1, m);
    } else bld(lch), bld(rch), pu(o);
}
void flip(int L, int R, int l, int r, int o) {
    if(L <= l && r <= R) return t[o] ^= 1, swap(c[o][0], c[o][1]), void();
    if(L <= mid) flip(L, R, lch);
    if(R > mid) flip(L, R, rch);
    pu(o);
}
int qry(int L, int R, bool f, int x, int l, int r, int o) {
    if(L <= l && r <= R) return c[o][f][x];
    f ^= t[o];
    if(R > mid) x = qry(L, R, f, x, rch);
    if(L <= mid) x = qry(L, R, f, x, lch);
    return x;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> q;
    bld(1, n, 1);
    int t, l, r; ll d;
    while(q--) {
        cin >> t >> l >> r;
        if(t == 1) cin >> d, d & 1 ? flip(l, r, 1, n, 1) : void();
        else cout << 1 + !qry(l, r, 0, m, 1, n, 1) << '\n';
    }
}