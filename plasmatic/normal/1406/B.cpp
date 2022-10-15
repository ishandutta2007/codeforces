// ./b-maximum-product.yml
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<ll> v(N), neg, pos;
        bool has0 = false;
        for (auto &x : v) {
            cin >> x;
            if (x < 0) neg.pb(-x);
            else if (x > 0) pos.pb(x);
            else has0 = true;
        }
        sort(all(neg));
        sort(all(pos));
        ll best = has0 ? 0 : -LLINF;
        for (auto i = 0; i <= 5; i++) {
            if (i > SZ(neg) || 5 - i > SZ(pos)) continue;
            bool fmin = i & 1;
            ll mul = fmin ? -1 : 1, mprod = 1;
            for (auto j = 0; j < i; j++) {
                if (fmin) mprod *= neg[j];
                else mprod *= neg[SZ(neg) - j - 1];
            }
            for (auto j = 0; j < 5 - i; j++) {
                if (fmin) mprod *= pos[j];
                else mprod *= pos[SZ(pos) - j - 1];
            }
            maxa(best, mprod * mul);
        }
        cout << (best) << '\n';
    }

    return 0;
}