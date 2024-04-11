// ./c-k-integers.yml
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

// Default: Point increment and prefix sum query
struct Comp {
    using Data = ll;
    const Data vdef = 0;
    void applyUpdate(Data &to, Data &v) { to += v; }
    int transformInd(int idx, int N) { return idx; }
};
template <class Comp> struct BIT {
    using Data = typename Comp::Data; Comp C;
    int N; vector<Data> bit;
    void init(int n0) {
        N = n0;
        bit.assign(N + 1, C.vdef);
    }
    void upd(int x, Data v) {
        x = C.transformInd(x, N);
        for (; x <= N; x += x & -x)
            C.applyUpdate(bit[x], v);
    }
    Data query(int x) {
        x = C.transformInd(x, N);
        Data res = C.vdef;
        for (; x; x -= x & -x)
            C.applyUpdate(res, bit[x]);
        return res;
    }
};

const int MN = 2e5 + 1;
int N,
    val[MN];
pii sval[MN];
BIT<Comp> cntBit, midBit;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    for (auto i = 1; i <= N; i++) {
        cin >> (val[i]);
        sval[i - 1] = mpr(val[i], i);
    }
    sort(sval, sval + N);

    cntBit.init(N); midBit.init(N);
    ll invc = 0;
    os_tree<int> ids;
    for (auto i = 0; i < N; i++) {
        auto p = sval[i]; // val, ind

        // inversions
        invc += cntBit.query(N) - cntBit.query(p.sn);
        cntBit.upd(p.sn, 1);

        // mid
        ids.insert(p.sn);
        midBit.upd(p.sn, p.sn);
        int mid = *ids.find_by_order(i / 2);
        ll cntl = cntBit.query(mid), cntr = cntBit.query(N) - cntBit.query(mid),
           midMove = (cntl * mid - midBit.query(mid)) + ((midBit.query(N) - midBit.query(mid)) - cntr * mid);
        // cout<<"invc="<<(invc)<<", "; cout<<"midMove="<<(midMove)<<", "; cout<<"cntl="<<(cntl)<<", "; cout<<"cntr="<<(cntr)<<", "; cout << endl; // db invc, midMove,cntl,cntr
        midMove -= (cntl * (cntl - 1)) / 2 + (cntr * (cntr + 1)) / 2;

        cout << (invc + midMove) << ' ';
    }
    cout << '\n';

    return 0;
}