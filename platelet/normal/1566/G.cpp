#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define fi first
#define se second

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n, m;
map<int, int> G[N];
set<pair<int, int>> e[N];
multiset<ll> s;
set<tuple<int, int, int>> S;

auto kth(int u, int k) {
    for(auto it = e[u].begin();; it++) if(!--k) return *it;
}
void ins(int u) { s.insert((ll)kth(u, 1).fi + kth(u, 2).fi + kth(u, 3).fi); }
void era(int u) { s.erase(s.find((ll)kth(u, 1).fi + kth(u, 2).fi + kth(u, 3).fi)); }
void upd(int u, int k = 4) {
    for(auto [w, v] : e[u]) {
        auto chk = [](int u, int v, int w) {
            if(u > v) swap(u, v);
            S.erase(tuple(w, u, v));
            if(pair(w, v) <= kth(u, 3) && pair(w, u) <= kth(v, 3))
                S.insert(tuple(w, u, v));
        };
        chk(u, v, w);
        if(!--k) break;
    }
}
void add(int u, int v, int w) {
    G[u][v] = G[v][u] = w, era(u), era(v);
    e[u].emplace(w, v), e[v].emplace(w, u), upd(u), upd(v), ins(u), ins(v);
}
void del(int u, int v) {
    int w = G[u][v]; G[u].erase(v), G[v].erase(u), era(u), era(v);
    e[u].erase(pair(w, v)), e[v].erase(pair(w, u));
    S.erase(tuple(w, min(u, v), max(u, v)));
    upd(u), upd(v), ins(u), ins(v);
}
void solve() {
    ll as = 3e9;
    auto it = S.begin(); auto [w1, u1, v1] = *it;
    rep(i, 1, 5) {
        if(++it == S.end()) break;
        auto [w2, u2, v2] = *it;
        if(u1 ^ u2 && u1 ^ v2 && v1 ^ u2 && v1 ^ v2) {
            as = min(as, (ll)w1 + w2); break;
        }
    }
    auto x = e[u1].begin();
    rep(i, 1, 2) {
        if(++x == e[u1].end()) break;
        auto y = e[v1].begin();
        rep(j, 1, 2) {
            if(++y == e[v1].end()) break;
            if(x -> se ^ y -> se) as = min(as, 0ll + x -> fi + y -> fi);
        }
    }
    if(s.size()) as = min(as, *s.begin());
    printf("%lld\n", as);
}
int main() {
#ifdef local
    freopen("in", "r", stdin);
#endif
    cin >> n >> m;
    rep(i, 1, n) {
        rep(j, 1, 4) e[i].emplace(INT_MAX, j);
        ins(i);
    }
    int u, v, w;
    while(m--) scanf("%d%d%d", &u, &v, &w), add(u, v, w);
    solve();
    for(cin >> m; m--; solve()) {
        scanf("%d", &u);
        if(u == 0) scanf("%d%d", &u, &v), del(u, v);
        else scanf("%d%d%d", &u, &v, &w), add(u, v, w);
    }
}