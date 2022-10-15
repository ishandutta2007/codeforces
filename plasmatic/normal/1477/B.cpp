// ./b-nezzar-and-binary-string.yml
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
    const Lazy ldef = INF;
    Data merge(Data l, Data r) const { return l + r; }
    Lazy mergeLazy(Lazy l, Lazy r) const { return r; }
    void applyLazy(Data &to, Lazy &v, int l, int r) { to = (r - l + 1) * v; }
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

const int MN = 2e5 + 1;
int N, Q,
    L[MN], R[MN];
string s, f;

void solve() {
    cin >> (N) >> (Q) >> (s) >> (f);
    for (auto i = 0; i < Q; i++) cin >> L[i] >> R[i];
    LazySegmentTree<Comp> seg;
    seg.init(N);
    for (auto i = 0; i < N; i++) seg.update(i+1, i+1, f[i] - '0');
    // for (auto i = 1; i <= N; i++) {
    //     cout<<"i="<<(i)<<", "; cout<<"seg.query(i,i)="<<(seg.query(i,i))<<", "; cout << endl; // db i,seg.query(i,i)
    // }
    // cout<<"s="<<(s)<<", "; cout<<"f="<<(f)<<", "; cout << endl; // db s,f
    for (auto i = Q-1; i >= 0; i--) {
        int cnt1 = seg.query(L[i], R[i]), sz = R[i] - L[i] + 1, cnt0 = sz - cnt1;
        // cout<<"i="<<(i)<<", "; cout<<"L[i]="<<(L[i])<<", "; cout<<"R[i]="<<(R[i])<<", "; cout<<"sz="<<(sz)<<", "; cout<<"cnt1="<<(cnt1)<<", "; cout<<"cnt0="<<(cnt0)<<", "; cout << endl; // db i,L[i],R[i],sz,cnt1,cnt0
        if (sz % 2 == 0 && cnt0 == cnt1) {
            cout << ("NO") << '\n';
            return;
        }
        // if cnt0 < cnt1, we must update to 1
        seg.update(L[i], R[i], cnt0 < cnt1);
    }
    for (auto i = 0; i < N; i++) {
        int have = seg.query(i+1, i+1), want = s[i] - '0';
        if (have != want) {
            cout << ("NO") << '\n';
            return;
        }
    }
    cout << ("YES") << '\n';
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