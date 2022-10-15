// a-the-brand-new-function.yml
#include "bits/stdc++.h"
using namespace std;

// Defines
#define pb push_back
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
template <typename C> int SZ(C &v) { return v.size(); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1e5 + 1, LG = 21;
int N,
    val[MN], lst[LG];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    for (auto i = 1; i <= N; i++)
        cin >> (val[i]);

    vector<int> pres;

    memset(lst, -1, sizeof lst);
    for (auto i = 1; i <= N; i++) {
        if (!val[i]) pres.pb(0);

        for (auto j = 0; j < LG; j++)
            if ((val[i] >> j) & 1)
                lst[j] = i;
        map<int, vector<int>, greater<int>> bits;
        for (auto j = 0; j < LG; j++)
            bits[lst[j]].pb(j);

        int cur = 0;
        for (auto &p : bits) {
            if (p.first == -1) break;
            for (auto &x : p.second)
                cur |= 1 << x;
            pres.pb(cur);
        }
    }

    sort(all(pres));
    pres.resize(unique(all(pres)) - pres.begin());
    cout << (SZ(pres)) << '\n';

    return 0;
}