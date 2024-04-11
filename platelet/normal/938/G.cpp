#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid (l + r >> 1)
#define lch l, mid, lc
#define rch mid + 1, r, rc

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, m, q, qx[N], qy[N], fa[N], sz[N], w[N];
int tp, stk[N], bas[20][30];
vector<tuple<int, int, int>> c[N * 4];
map<int, pair<int, int>> lst[N];

int find(int x) {
    while(fa[x]) x = fa[x];
    return x;
}
int sum(int x, int r = 0) {
    while(fa[x]) r ^= w[x], x = fa[x];
    return r;
}
void push(int L, int R, auto&& e, int l, int r, int o) {
    if(L <= l && r <= R) return c[o].pb(e);
    if(L <= mid) push(L, R, e, lch);
    if(R > mid) push(L, R, e, rch);
}
void solve(int d, int l, int r, int o) {
    memcpy(bas[d], bas[d - 1], 120);
    int nw = tp;
    for(auto [u, v, w] : c[o])
        if(w ^= sum(u) ^ sum(v); (u = find(u)) != (v = find(v))) {
            if(sz[u] < sz[v]) swap(u, v);
            fa[v] = u, sz[u] += sz[v], ::w[v] = w, stk[++tp] = v;
        } else {
            per(i, 29, 0) if(w >> i & 1) if(bas[d][i]) w ^= bas[d][i];
            else { bas[d][i] = w; break; }
        }
    if(l == r) {
        if(qx[l]) {
            int ans = sum(qx[l]) ^ sum(qy[l]);
            per(i, 29, 0) if(ans >> i & 1) ans ^= bas[d][i];
            cout << ans << '\n';
        }
        return;
    }
    solve(d + 1, lch), solve(d + 1, rch);
    while(tp > nw) {
        int v = stk[tp--], u = fa[v];
        fa[v] = w[v] = 0, sz[u] -= sz[v];
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    int t, x, y;
    while(m--) cin >> x >> y >> t, lst[x][y] = {1, t};
    cin >> q;
    rep(i, 1, q) {
        cin >> t;
        if(t == 3) cin >> qx[i] >> qy[i];
        if(t == 2) {
            cin >> x >> y;
            auto [t, w] = lst[x][y];
            push(t, i, tuple(x, y, w), 1, q, 1);
            lst[x].erase(y);
        }
        if(t == 1) cin >> x >> y >> t, lst[x][y] = {i, t};
    }
    rep(u, 1, n) for(auto [v, w] : lst[u])
        push(w.first, q, tuple(u, v, w.second), 1, q, 1);
    rep(i, 1, n) sz[i] = 1;
    solve(1, 1, q, 1);
}