// ./d-rectangle-painting-1.yml
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

const int MN = 51;
int N,
    dp[MN][MN][MN][MN], psum[MN][MN];
string grid[MN];

int solve(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) return grid[x1][y1] == '#';
    int &ret = dp[x1][y1][x2][y2];
    if (ret != -1) return ret;
    if (psum[x2][y2] - psum[x1-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1] == 0) return 0;
    ret = max(x2 - x1 + 1, y2 - y1 + 1);
    for (auto i = x1; i < x2; i++)
        mina(ret, solve(x1, y1, i, y2) + solve(i+1, y1, x2, y2));
    for (auto i = y1; i < y2; i++)
        mina(ret, solve(x1, y1, x2, i) + solve(x1, i+1, x2, y2));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    for (auto i = 1; i <= N; i++) {
        cin >> (grid[i]);
        grid[i] = "$" + grid[i];
        for (auto j = 1; j <= N; j++)
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + (grid[i][j] == '#');
    }
    memset(dp, -1, sizeof dp);
    int ans = solve(1, 1, N, N);
    cout << (ans) << '\n';

    return 0;
}