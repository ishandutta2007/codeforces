// ./f-clear-the-string.yml
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

const int MN = 501;
int N,
    dp[MN][MN][26], dpMin[MN][MN], same[MN][MN];
string s;

// int getdp(int l, int r) {
//     if (l > r) return 0;
//     if (l < 0 || r >= N) return 0;
//     return dp[l][r];
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (s);
    for (auto i = 0; i < N; i++) {
        bool good = true;
        for (auto j = i; j < N; j++) {
            good &= s[j] == s[i];
            same[i][j] = good ? (s[j] - 'a') : -1;
        }
    }
    for (int len = 1; len <= N; len++) {
        int end = N-len;
        for (auto l = 0; l <= end; l++) {
            int r = l+len-1;
            for (auto i = 0; i < 26; i++)
                dp[l][r][i] = same[l][r] == i ? 1 : INF;
            for (auto j = l; j < r; j++) {
                for (auto i = 0; i < 26; i++) {
                    mina(dp[l][r][i], min({dp[l][j][i] + !(same[j+1][r] == i) * dpMin[j+1][r],
                                               !(same[l][j] == i) * dpMin[l][j] + dp[j+1][r][i],
                                               dpMin[l][j] + dpMin[j+1][r] + 1}));
                    // cout<<"l="<<(l)<<", "; cout<<"r="<<(r)<<", "; cout<<"i="<<(i)<<", "; cout<<"dp[l][r][i]="<<(dp[l][r][i])<<", "; cout << endl; // db l,r,i,dp[l][r][i]
                }
            }
        }
        for (auto l = 0; l <= end; l++) {
            int r = l+len-1;
            dpMin[l][r] = *min_element(dp[l][r], dp[l][r] + 26);
        }
    }

    cout << (dpMin[0][N-1]) << '\n';

    return 0;
}