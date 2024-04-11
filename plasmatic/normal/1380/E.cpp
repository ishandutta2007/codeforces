// ./e-merging-towers.yml
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

struct Seg {
    int l, r, x;
    bool operator<(const Seg &o) const {
        return l == o.l ? x < o.x : l < o.l;
    }
};

ostream& operator<<(ostream& out, const Seg o) {
    out << "(l=" << o.l << ", r=" << o.r << ", x=" << o.x << ")";
    return out;
}

const int MN = 2e5 + 10;
int N, M,
    val[MN];
set<Seg> segs;

struct DSU {
    vector<int> dsu;
    vector<unordered_set<int>> ind;
    void init(int N) {
        dsu.resize(N + 1);
        ind.resize(N + 1);
        iota(dsu.begin(), dsu.end(), 0);
    }
    int rt(int x) { return dsu[x] == x ? x : dsu[x] = rt(dsu[x]); }
    void merge(int x, int y) { // x -> y
        int rx = rt(x), ry = rt(y);
        if (SZ(ind[ry]) < SZ(ind[rx])) ind[rx].swap(ind[ry]);
        ind[ry].insert(all(ind[rx]));
        ind[rx].clear();
        dsu[rx] = ry;
    }
    unordered_set<int>& gind(int x) { return ind[rt(x)]; }
    bool same(int a, int b) {
        if (a == -1 || b == -1) return false;
        return rt(a) == rt(b);
    }
};

DSU dsu;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (M);
    for (auto i = 1; i <= N; i++)
        cin >> (val[i]);

    segs.insert({-INF, -1, -1});
    segs.insert({INF, -1, -1});
    dsu.init(N);
    int pre = 1;
    for (auto i = 1; i <= N; i++) {
        if (val[i] != val[pre]) {
            segs.insert({pre, i - 1, val[pre]});
            dsu.ind[val[pre]].insert(pre);
            pre = i;
        }
    }
    segs.insert({pre, N, val[pre]});
    dsu.ind[val[pre]].insert(pre);

    cout << (SZ(segs)-3) << '\n';
    for (auto i = 1; i < M; i++) {
        int a, b;
        cin >> a >> b;
        
        // cout<<"a="<<(a)<<", "; cout<<"b="<<(b)<<", "; cout << "segs=["; for (auto x:segs)cout<<x<<", "; cout<<"], "; cout << endl; // db a,b,I:segs

        int oa = a, ob = b;
        if (SZ(dsu.gind(a)) < SZ(dsu.gind(b))) swap(a, b);
        auto oi = dsu.gind(b);
        dsu.merge(ob, oa);
        for (auto x : oi) {
            auto pre = segs.lower_bound({x, -1, -1}), ptr = pre, nxt = pre; pre--; nxt++;
            // cout<<"*pre="<<(*pre)<<", "; cout<<"*ptr="<<(*ptr)<<", "; cout<<"*nxt="<<(*nxt)<<", "; cout << endl; // db *pre,*ptr,*nxt
            Seg nv{ptr->l, ptr->r, ptr->x};
            if (dsu.same(pre->x, a)) {
                nv.l = pre->l;
                // cout << "dsu.gind(a)=["; for (auto x:dsu.gind(a))cout<<x<<", "; cout<<"], "; cout<<"pre->l="<<(pre->l)<<", "; cout << endl; // db I:dsu.gind(a),pre->l
                dsu.gind(a).erase(pre->l);
                segs.erase(pre);
            }
            if (dsu.same(nxt->x, a)) {
                nv.r = nxt->r;
                // cout << "dsu.gind(a)=["; for (auto x:dsu.gind(a))cout<<x<<", "; cout<<"], "; cout<<"nxt->l="<<(nxt->l)<<", "; cout << endl; // db I:dsu.gind(a),nxt->l
                dsu.gind(a).erase(nxt->l);
                segs.erase(nxt);
            }
            // cout << "dsu.gind(b)=["; for (auto x:dsu.gind(b))cout<<x<<", "; cout<<"], "; cout<<"ptr->l="<<(ptr->l)<<", "; cout << endl; // db I:dsu.gind(b),ptr->l
            dsu.gind(b).erase(ptr->l);
            segs.erase(ptr);
            segs.insert(nv);
            dsu.gind(b).insert(nv.l);
        }

        cout << (SZ(segs)-3) << '\n';
    }

    return 0;
}