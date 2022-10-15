// ./d-points.yml
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

struct Qu {
    int T;
    pii p;
};

const int MN = 2e5 + 1;
const string QMP_MP[3] = {"remove", "add", "find"};
int Q;

vector<int> ranks;
int get(int x) { return lower_bound(all(ranks), x) - ranks.begin() + 1; }

set<pii> bit[MN];
void upd(int sf, pii &p, bool t) { sf = SZ(ranks) - sf + 1;
    for (; sf <= SZ(ranks); sf += sf & -sf) {
        if (t) bit[sf].insert(p);
        else bit[sf].erase(p);
    }
}
pii query(int x, pii &p) { x = SZ(ranks) - x + 1;
    pii res{INF, INF};
    for (; x; x -= x & -x) {
        auto ptr = bit[x].lower_bound({p.fs + 1, p.sn + 1});
        if (ptr != bit[x].end()) mina(res, *ptr);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, int> QMP;
    for (auto i = 0; i < 3; i++)
        QMP[QMP_MP[i]] = i;

    cin >> (Q);
    
    vector<Qu> qus;
    for (auto i = 0; i < Q; i++) {
        string s; int x, y;
        cin >> s >> x >> y;
        ranks.pb(y);
        qus.pb({QMP[s], mpr(x, y)});
    }
    sort(all(ranks));
    ranks.resize(unique(all(ranks)) - ranks.begin());

    for (auto &q : qus) {
        if (q.T <= 1) {
            upd(get(q.p.sn), q.p, q.T); }
        else {
            pii ans = query(get(q.p.sn) + 1, q.p);
            if (ans.fs == INF && ans.sn == INF) cout << (-1) << '\n';
            else cout << (ans.fs) << ' ' << (ans.sn) << '\n';
        }
    }

    return 0;
}