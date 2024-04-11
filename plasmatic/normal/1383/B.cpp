// b-gamegame.yml
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

const int MN = 1e5 + 1, LG = 31;
int N;
ll val[MN];

void solve() {
    vector<ll> cnt(LG);
    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < LG; j++)
            if ((val[i] >> j) & 1)
                cnt[j]++;
    }
    ll fs = 0, sn = 0;
    for (auto i = 0; i < LG; i++) {
        if (cnt[i] % 2) {
            int n0 = N - cnt[i];
            int d = (cnt[i] + 1) / 2;
            if (d % 2 == 0) {
                if (n0 % 2) fs |= 1LL << i;
                else sn |= 1LL << i;
            }
            else fs |= 1LL << i;
        }
    }
    if (fs > sn)
        cout << ("WIN") << '\n';
    else if (fs == sn)
        cout << ("DRAW") << '\n';
    else
        cout << ("LOSE") << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        // Input
        cin >> (N);
        for (auto i = 0; i < N; i++)
            cin >> (val[i]);
        
        solve();

        // Reset
    }
}