// ./c-monster-invaders.yml
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

/*

Moves:
- use V_i*R_1 + R_3 cost to destroy room
- use R_2+R_1 cost to destroy room but must visit room twice
- use (V_i+2)*R_1 cost to destroy room but must visit room twice

dp[i][3] ->
- 0 went through room normally (only has move 1)
- 1 went to previous room twice by going x -> i-1 -> i -> i-1 -> i.  We get to use c2 for free
    - Exception: with the last room (if only going to once, we can only pay +1D)

*/

const int MN = 1e6 + 1;
int N;
ll R[3], D,
   val[MN], dp[MN][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    for (auto i = 0; i < 3; i++)
        cin >> (R[i]);
    cin >> (D);
    for (auto i = 1; i <= N; i++)
        cin >> (val[i]);

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (auto i = 1; i <= N; i++) {
        ll v = val[i], c1 = v * R[0] + R[2], c2 = min({R[1] + R[0], (v + 2) * R[0], c1});

        // trans dp[0][0]
        for (auto j = 0; j < 2; j++) {
            mina(dp[i][0], dp[i - 1][j] + c1);
            mina(dp[i][1], dp[i - 1][j] + c2 + 2 * D);
        }
        mina(dp[i][0], dp[i - 1][1] + c2);
        if (i == N) { // special case since we don't have to go to dp[N] twice
            mina(dp[i][0], dp[i - 1][1] + c1 - D); 
        }
    }

    ll ans = *min_element(dp[N], dp[N] + 2) + (N - 1) * D;
    cout << (ans) << '\n';

    return 0;
}