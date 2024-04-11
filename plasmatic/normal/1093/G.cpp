// ./g-multidimensional-queries.yml
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
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

struct MinComp {
    using Data = int;
    using Update = int;
    const Data vdef = INF;
    Data merge(Data l, Data r)  { return min(l, r); }
    void applyUpdate(Data &l, Update &r) { l = r; }
};
struct MaxComp {
    using Data = int;
    using Update = int;
     Data vdef = -INF;
    Data merge(Data l, Data r)  { return max(l, r); }
    void applyUpdate(Data &l, Update &r) { l = r; }
};
#define MID int mid = (l + r) / 2, lhs = i + 1, rhs = i + (mid - l + 1) * 2;
template <class Comp> struct SegmentTree {
    using Data = typename Comp::Data; using Update = typename Comp::Update; Comp C;
    int N;
    vector<Data> seg;
    void init(int n0) {
        N = n0;
        seg.assign(2 * N + 2, C.vdef);
    }
    Data _query(int ql, int qr, int i, int l, int r) {
        if (ql > r || qr < l) return C.vdef;
        if (l >= ql && r <= qr) return seg[i];
        MID;
        return C.merge(_query(ql, qr, lhs, l, mid), _query(ql, qr, rhs, mid + 1, r));
    }
    Data _update(int q, Update v, int i, int l, int r) {
        if (q > r || q < l) return seg[i];
        if (l == q && r == q) {
            C.applyUpdate(seg[i], v);
            return seg[i];
        }
        MID;
        return seg[i] = C.merge(_update(q, v, lhs, l, mid), _update(q, v, rhs, mid + 1, r));
    }
    Data query(int ql, int qr) { return _query(ql, qr, 1, 1, N); }
    void update(int q, Update v) { _update(q, v, 1, 1, N); }
};

const int MN = 2e5 + 1, MK = 5;
int N, K, Q,
    val[MN][MK];
SegmentTree<MinComp> mint[1 << MK];
SegmentTree<MaxComp> maxt[1 << MK];

void setTree(int x) {
    for (auto i = 0; i < (1<<K); i++) {
        int s = 0;
        for (auto j = 0; j < K; j++) {
            int mul = ((i >> j) & 1) ? 1 : -1;
            s += mul * val[x][j];
        }
        mint[i].update(x, s);
        maxt[i].update(x, s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (K);
    int msub = 1 << K;

    for (auto i = 0; i < msub; i++) {
        mint[i].init(N);
        maxt[i].init(N);
    }
    for (auto i = 1; i <= N; i++) {
        for (auto j = 0; j < K; j++)
            cin >> (val[i][j]);
        setTree(i);
    }

    cin >> (Q);
    while (Q--) {
        int T;
        cin >> T;

        if (T == 1) {
            int x;
            cin >> x;
            for (auto i = 0; i < K; i++)
                cin >> (val[x][i]);
            setTree(x);
        }
        else {
            int l, r;
            cin >> l >> r;

            int ans = -INF;
            for (auto i = 0; i < msub; i++)
                maxa(ans, maxt[i].query(l, r) - mint[i].query(l, r));
            cout << (ans) << '\n';
        }
    }

    return 0;
}