// ./f-scalar-queries.yml
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
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const ll MOD = 1e9 + 7;
ll fix(ll &&x) { x %= MOD; if (x < 0) x += MOD; return x; }
ll fix(ll &x) { x %= MOD; if (x < 0) x += MOD; return x; }
ll fpow(ll x, ll y, ll mod = MOD) {
    if (!y) return 1LL;
    return fpow(x * x % mod, y >> 1, mod) * ((y & 1) ? x : 1LL) % mod;
}
ll inv(ll x, ll mod = MOD) { return fpow(x, mod - 2, mod); }
// Thanks wesley thanks wesley thanks wesley
// RMQ + Increment query
struct Comp {
    using Data = ll;
    using Lazy = ll;
    const Data vdef = 0;
    const Lazy ldef = 0;
    Data merge(Data l, Data r) const { return l + r; }
    Lazy mergeLazy(Lazy l, Lazy r) const { return l + r; }
    void applyLazy(Data &to, Lazy &v, int l, int r) { to += v * ll(r - l + 1); }
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
    Data query(int ql, int qr) { return fix(_query(ql, qr, 1, 1, N)); }
    void update(int ql, int qr, Lazy v) { _update(ql, qr, v, 1, 1, N); }
};

const int MN = 5e5 + 1;
int N,
    val[MN];
LazySegmentTree<Comp> fwd, back;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    vector<pii> vs;
    for (auto i = 1; i <= N; i++) {
        cin >> (val[i]);
        vs.eb(val[i], i);
    }
    sort(all(vs));
    fwd.init(N); back.init(N);
    ll ans = 0;
    for (auto p : vs) {
        back.update(1, p.sn, 1);
        // cout<<"ans="<<(ans)<<", "; cout<<"p.fs="<<(p.fs)<<", "; cout<<"p.sn="<<(p.sn)<<", "; cout << endl; // db ans,p.fs,p.sn
        // for (auto i = 1; i <= p.sn; i++) {
        //     cout<<"i="<<(i)<<", "; cout<<"back.query(i,i)="<<(back.query(i,i)-back.query(p.sn+1,p.sn+1))<<", "; cout << endl; // db i,back.query(i,i)
        // }
        // for (auto i = p.sn; i <= N; i++) {
        //     cout<<"i="<<(i)<<", "; cout<<"fwd.query(i,i)="<<(fwd.query(i,i)-fwd.query(p.sn-1,p.sn-1))<<", "; cout << endl; // db i,fwd.query(i,i)
        // }

        // left contribution of other subarrays
        ans += p.fs * fix(fix(back.query(1, p.sn) - back.query(p.sn+1, p.sn+1) * (p.sn)) * (N - p.sn + 1));
        // right contribution of other subarrays
        ans += p.fs * fix(fix(fwd.query(p.sn, N) - fwd.query(p.sn-1, p.sn-1) * (N-p.sn+1)) * p.sn);
        fix(ans);

        fwd.update(p.sn, N, 1);
    }
    cout << (ans) << '\n';

    return 0;
}