// ./d-rarity-and-new-dress.yml
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

const int MN = 2001;
int N, M,
    dp[MN][MN];
char grid[MN][MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (M);
    for (auto i = 0; i < N; i++)
        cin >> (grid[i]);
    for (auto i = 2; i < N; i++) {
        for (auto j = 1; j < M - 1; j++) {
            int mn = min({dp[i - 1][j], dp[i - 2][j], dp[i - 1][j - 1], dp[i - 1][j + 1]});
            if (grid[i][j] == grid[i - 1][j] && grid[i][j] == grid[i - 2][j] && grid[i][j] == grid[i - 1][j - 1] && grid[i][j] == grid[i - 1][j + 1])
                dp[i][j] = mn + 1;
        }
    }
    ll ans = 0;
    for (auto i = 0; i < N; i++)
        for (auto j = 0; j < M; j++)
            ans += dp[i][j] + 1;
    cout << (ans) << '\n';

    return 0;
}