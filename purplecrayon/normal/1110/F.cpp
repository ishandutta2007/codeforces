#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

int n, q, st[MAXN], en[MAXN];
vector<pair<int, ll>> adj[MAXN];
vector<ar<int, 3>> qs[MAXN];
ll ans[MAXN];

ll a[MAXN];
ll t[4*MAXN], lzy[4*MAXN];

void build(int v, int tl, int tr) {
    if (tl == tr) t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm), build(2*v+1, tm+1, tr);
        t[v] = min(t[2*v], t[2*v+1]);
    }
}
void build() {
    build(1, 0, n-1);
}
void push(int v, int tl, int tr, ll x) {
    if (!x) return;
    t[v] += x;
    if (tl != tr) {
        lzy[2*v] += x;
        lzy[2*v+1] += x;
    }
}
void app(int v, int tl, int tr) {
    push(v, tl, tr, lzy[v]), lzy[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, ll x) {
    app(v, tl, tr);
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r) {
        push(v, tl, tr, x);
        return;
    }
    int tm = (tl + tr) / 2;
    upd(2*v, tl, tm, l, r, x), upd(2*v+1, tm+1, tr, l, r, x);
    t[v] = min(t[2*v], t[2*v+1]);
}
void upd(int l, int r, ll x) {
    upd(1, 0, n-1, l, r, x);
}
ll qry(int v, int tl, int tr, int l, int r) {
    app(v, tl, tr);
    if (r < tl || l > tr) return INF;
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    return min(qry(2*v, tl, tm, l, r), qry(2*v+1, tm+1, tr, l, r));
}
ll qry(int l, int r) {
    return qry(1, 0, n-1, l, r);
}

void dfs_one(int c, ll d) {
    if (!sz(adj[c])) {
        a[c] = d;
        st[c] = en[c] = c;
    } else {
        a[c] = INF;
        st[c] = MOD, en[c] = -1;
    }
    for (auto [nxt, w] : adj[c]) {
        dfs_one(nxt, d + w);
        st[c] = min(st[c], st[nxt]);
        en[c] = max(en[c], en[nxt]);
    }
}
void dfs_two(int c) {
    for (auto [l, r, i] : qs[c]) {
        ans[i] = qry(l, r);
    }
    for (auto [nxt, w] : adj[c]) {
        upd(0, n-1, +w);
        upd(st[nxt], en[nxt], -2*w);
        dfs_two(nxt);
        upd(0, n-1, -w);
        upd(st[nxt], en[nxt], +2*w);
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int p; ll w; cin >> p >> w, --p;
        adj[p].emplace_back(i, w);
    }
    for (int qt = 0; qt < q; qt++) {
        int c, l, r; cin >> c >> l >> r, --c, --l, --r;
        qs[c].push_back({l, r, qt});
    }
    dfs_one(0, 0);
    build();
    dfs_two(0);

    for (int qt = 0; qt < q; qt++) {
        cout << ans[qt] << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}