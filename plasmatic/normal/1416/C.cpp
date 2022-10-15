// ./c-xor-inverse.yml
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
    using Data = ll;
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
// template is 1-indexed
template <typename T> struct Ranks {
    vector<T> ranks;
    void init() {
        sort(ranks.begin(), ranks.end());
        ranks.resize(unique(ranks.begin(), ranks.end()) - ranks.begin());
    }
    template <typename It> void init(It st, It en) { ranks = vector<T>(st, en); init(); }
    void add(T v) { ranks.pb(v); }
    int get(T v) { return lower_bound(ranks.begin(), ranks.end(), v) - ranks.begin() + 1; }
    int size() { return ranks.size(); }
};

const int MN = 3e5 + 1, LG = 30;
int N;
ll val[MN], tmp[MN];

ll invcnt(ll v[MN]) {
    Ranks<int> r;
    for (auto i = 1; i <= N; i++) r.add(v[i]);
    r.init();
    BIT<Comp> bit; bit.init(N);
    ll res = 0;
    for (auto i = 1; i <= N; i++) {
        res += bit.query(N) - bit.query(r.get(v[i]));
        bit.update(r.get(v[i]), 1);
    }
    return res;
}

int gbit(ll x, int bit) {
    return (x >> bit) & 1;
}

ostream& operator<<(ostream& out, const tuple<int, int, int> o) {
    out << "(fs=" << get<0>(o) << ", sn=" << get<1>(o) << ")";
    return out;
}

hashmap<int, int, chash> cnt[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    for (auto i = 1; i <= N; i++)
        cin >> (val[i]);

#define __DB i<6

    ll txor = 0;
    vector<tuple<int, int, int>> seq; seq.eb(1, N, 0);
    for (auto i = LG; i >= 0; i--) {
        // if (__DB) {
        //     cout<<"i="<<(i)<<", "; cout << "seq=["; for (auto __x:seq)cout<<__x<<", "; cout<<"], "; cout << endl; // db i,I:seq
        // }
        vector<tuple<int, int, int>> nxt;
        vector<ll> invc(2);
        cnt[0].clear(); cnt[1].clear();
        for (auto &P : seq) {
            int l, r, preon; tie(l, r, preon) = P;
            // calc inversions
            for (auto j = l; j <= r; j++) {
                int cbit = gbit(val[j], i);
                for (auto k = 0; k < 2; k++) {
                    ll add = 0;
                    // if (!preon) add += cnt[1][0] + cnt[1][1];
                    if (cbit == k) add += cnt[!cbit][preon];
                    invc[k] += add;
                }
                cnt[cbit][preon]++;
            }

            // push next
            int pre = l;
            for (auto j = l+1; j <= r; j++) {
                if (gbit(val[j], i) != gbit(val[pre], i)) {
                    nxt.eb(pre, j - 1, (preon << 1) | gbit(val[pre], i));
                    pre = j;
                }
            }
            nxt.eb(pre, r, (preon << 1) | gbit(val[pre], i));
        }

        // if (__DB) {
        //     cout<<"i="<<(i)<<", "; cout << "invc=["; for (auto __x:invc)cout<<__x<<", "; cout<<"], "; cout << endl; // db i,I:invc
        // }
        if (invc[1] < invc[0]) {
            txor ^= 1LL << i;
            // for (auto &P : nxt)
            //     get<2>(P) ^= 1;
        }

        seq.swap(nxt);
    }

    for (auto i = 1; i <= N; i++) tmp[i] = val[i] ^ txor;
    cout << (invcnt(tmp)) << ' ' << (txor) << '\n';

    return 0;
}