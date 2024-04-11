// ./d2-seating-arrangements-hard-version.yml
#include <bits/stdc++.h>
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
#if __cplusplus == 201703L // CPP17 only things
template <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some templates
#endif
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

ostream& operator<<(ostream& out, const pii o) {
    out << "(fs=" << o.fs << ", sn=" << o.sn << ")";
    return out;
}

// Template is 1-indexed (by default).  Can be made 0-indexed by modifying Comp
// Example: update = point increment, range sum
// In the function applyUpdate, updates are applied from `v` to `to`
struct Comp {
    using Data = int;
    const Data vdef = 0;
    void applyUpdate(Data &to, Data &v) { to += v; }
    int transformInd(int idx, int N) { return idx+1; } // support 0, -1
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

const int MN = 301;
int N, M,
    A[MN*MN], target[MN*MN];
BIT<Comp> bit[MN];

void solve() {
    cin >> N >> M;

    map<int, vector<int>> idx, canGo;
    vector<int> vals;
    for (auto i = 0; i < N*M; i++) {
        cin >> A[i];
        idx[A[i]].pb(i);
        vals.pb(A[i]);
    }
    sort(all(vals));
    for (auto i = 0; i < N*M; i++)
        canGo[vals[i]].pb(i);

    for (auto &[k, p] : canGo) {
        vector<pii> ord;
        for (auto x : p) ord.eb(x/M, -(x%M));
        sort(all(ord));
        auto &v = idx[k];
        
        // cout<<"k="<<(k)<<", "; cout << endl; // db k
        // cout << "ord=["; for (auto __x:ord)cout<<__x<<", "; cout<<"], "; cout << "v=["; for (auto __x:v)cout<<__x<<", "; cout<<"], "; cout << endl; // db I:ord,I:v

        for (auto i = 0; i < SZ(ord); i++) {
            target[v[i]] = ord[i].fs*M - ord[i].sn;
        }
    }

    // reset BIT
    int ans = 0;
    for (auto i = 0; i < N; i++)
        bit[i].init(M);

    for (auto i = 0; i < N*M; i++) {
        int tr = target[i]/M, tc = target[i]%M;

        ans += bit[tr].query(tc);
        bit[tr].update(tc, 1);
    }

    cout << (ans) << '\n';
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