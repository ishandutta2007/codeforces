// ./c-trees-of-tranquillity.yml
#include "bits/stdc++.h"
using namespace std;

// Defines
#define fs first
#define sn second
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
#ifdef __GNUG__
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
#endif
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

// Thanks wesley thanks wesley thanks wesley
// RMQ + Increment query
struct Comp {
    using Data = int;
    using Lazy = int;
    const Data vdef = 0;
    const Lazy ldef = 0;
    Data merge(Data l, Data r) const { return max(l, r); }
    Lazy mergeLazy(Lazy l, Lazy r) const { return l + r; }
    void applyLazy(Data &to, Lazy &v, int l, int r) { to += v; }
};
#define MID int mid = (l + r) / 2, lhs = i + 1, rhs = i + (mid - l + 1) * 2;
template <class Comp> struct LazySegmentTree {
    using Data = typename Comp::Data; using Lazy = typename Comp::Lazy; Comp C;
    int N;
    vector<Data> seg; vector<Lazy> lazy;
    void init(int n0) {
        N = n0;
        seg.assign(2 * N + 2, C.vdef);
        lazy.assign(2 * N + 2, C.ldef);
    }
    void push(int i, int l, int r) {
        if (lazy[i] != C.ldef) {
            MID;
            C.applyLazy(seg[i], lazy[i], l, r);
            if (l != r) {
                lazy[lhs] = C.mergeLazy(lazy[lhs], lazy[i]);
                lazy[rhs] = C.mergeLazy(lazy[rhs], lazy[i]);
            }
            lazy[i] = C.ldef;
        }
    }
    Data _query(int ql, int qr, int i, int l, int r) {
        if (ql > r || qr < l) return C.vdef;
        push(i, l, r);
        if (l >= ql && r <= qr) return seg[i];
        MID;
        return C.merge(_query(ql, qr, lhs, l, mid), _query(ql, qr, rhs, mid + 1, r));
    }
    Data _update(int ql, int qr, Lazy v, int i, int l, int r) {
        push(i, l, r);
        if (ql > r || qr < l) return seg[i];
        if (l >= ql && r <= qr) {
            lazy[i] = v;
            push(i, l, r);
            return seg[i];
        }
        MID;
        return seg[i] = C.merge(_update(ql, qr, v, lhs, l, mid), _update(ql, qr, v, rhs, mid + 1, r));
    }
    Data query(int ql, int qr) { return _query(ql, qr, 1, 1, N); }
    void update(int ql, int qr, Lazy v) { _update(ql, qr, v, 1, 1, N); }
};

const int MN = 3e5 + 1;
int N,
    in[MN], out[MN], ctr = 0;
vector<int> g1[MN], g2[MN];
// LazySegmentTree<Comp> seg;

void dfs2(int c) {
    in[c] = ++ctr;
    for (auto to : g2[c])
        dfs2(to);
    out[c] = ++ctr;
}

using T = tuple<int, int, int>;
set<T> locs;
int dp[MN];
void dfs(int c, int p) {
    T cur{in[c], out[c], c}, repl{-1, -1, -1};
    auto nxt = locs.upper_bound(cur);
    if (get<0>(*nxt) > out[c]) { // there does not exist smaller segment!
        auto pre = prev(nxt);
        if (get<1>(*pre) > out[c]) {
            repl = *pre;
            locs.erase(pre);
        }
        locs.insert(cur);
    }

    // cout<<"c="<<(c)<<", "; cout<<"p="<<(p)<<", "; cout << endl; // db c,p
    // for (auto [l,r,k]:locs) {
    //     cout<<"l="<<(l)<<", "; cout<<"r="<<(r)<<", "; cout<<"k="<<(k)<<", "; cout << endl; // db l,r,k
    // }

    dp[c] = locs.size()-2;
    for (auto to : g1[c]) {
        dfs(to, c);
    }

    if (locs.count(cur)) locs.erase(cur);
    if (repl != T{-1, -1, -1}) {
        locs.insert(repl);
    }
}

void solve() {
    cin >> N;
    for (auto i = 2; i <= N; i++) {
        int p; cin >> p;
        g1[p].pb(i);
    }
    for (auto i = 2; i <= N; i++) {
        int p; cin >> p;
        g2[p].pb(i);
    }

    dfs2(1);
    locs.emplace(-INF, -INF, -1);
    locs.emplace(INF, INF, -1);
    dfs(1, -1);
    int ans = *max_element(dp, dp+N+1);
    cout << (ans) << '\n';

    // reset
    for (auto i = 1; i <= N; i++) {
        g1[i].clear();
        g2[i].clear();
        in[i] = out[i] = 0;
        ctr = 0;
        dp[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}