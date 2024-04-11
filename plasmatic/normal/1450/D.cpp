// ./d-rating-compression.yml
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

// Template is 1-indexed (by default).  Can be made 0-indexed by modifying Comp
// Default: Point increment and prefix sum query
struct Comp {
    using Data = int;
    const Data vdef = 0;
    void applyUpdate(Data &to, Data &v) { to += v; }
    int transformInd(int idx, int N) { return idx; }
};
template <typename Comp> struct BIT {
    using Data = typename Comp::Data; Comp C;
    int N; vector<Data> bit;
    void init(int n0) {
        N = n0;
        bit.assign(N + 1, C.vdef);
    }
    void update(int x, Data v) {
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

const int MN = 3e5 + 10;
int N,
    P[MN], dif[MN];
vector<int> dieTime[MN];

void solve() {
    cin >> (N);
    map<int, vector<int>> pos;
    for (auto i = 1; i <= N; i++) {
        cin >> P[i];
        pos[P[i]].pb(i);
    }

    set<int> inds; inds.insert(0); inds.insert(N+1);
    for (auto i = 1; i <= N; i++) {
        int maxlife = 1; // <3
        for (auto idx : pos[i]) {
            auto nxt = inds.upper_bound(idx), pre = nxt; pre--; assert(*pre != idx);
            int dif = *nxt - *pre;
            maxa(maxlife, dif);
        }
        dieTime[maxlife].pb(i);

        for (auto idx : pos[i]) inds.insert(idx);
    }

    BIT<Comp> rem; rem.init(N);
    for (auto i = 1; i <= N; i++)
        rem.update(i, 1);

    partial_sum(dif, dif + N + 5, dif);
    for (auto i = 1; i <= N; i++) {
        for (auto x : dieTime[i]) rem.update(x, -1);

        int want = N - i + 1, have = rem.query(want);
        // cout<<"i="<<(i)<<", "; cout<<"want="<<(want)<<", "; cout<<"have="<<(have)<<", "; cout << endl; // db i,want,have
        cout << (have == want);
    }
    cout << '\n';

    // reset
    for (auto i = 1; i <= N+10; i++) dieTime[i].clear();
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