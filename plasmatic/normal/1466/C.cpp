// ./c-canine-poetry.yml
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

const int MC = 27;
int N;
    // cdp[MC][MC], ndp[MC][MC], globmin[26];
string s;

void solve() {
    cin >> (s);
    N = SZ(s);

    // memset(cdp, 0x3f, sizeof cdp);
    // cdp[26][26] = 0;
    // for (auto i = 0; i < N; i++) {
    //     memset(ndp, 0x3f, sizeof ndp);
    //     memset(globmin, 0x3f, sizeof globmin);
    //
    //     for (auto j = 0; j < 27; j++) {
    //         for (auto k = 0; k < 27; k++) { // s[i] -> s[i], anything other than j/k
    //             for (auto l = 0; l < 26; l++) {
    //                 if (l != j && l != k)
    //                     mina(ndp[k][l], cdp[j][k] + (l != (s[i] - 'a')));
    //             }
    //         }
    //     }
    //     swap(cdp, ndp);
    // }
    //
    // int ans = INF;
    // for (auto i = 0; i < 27; i++)
    //     for (auto j = 0; j < 27; j++)
    //         mina(ans, cdp[i][j]);
    // cout << (ans) << '\n';
    
    int ans = 0;
    bitset<26> take;
    for (auto i = 0; i < N; i++) {
        take.reset();
        for (int j = max(0, i-2); j < i; j++)
            take[s[j] - 'a'] = true;
        if (take[s[i] - 'a']) {
            ans++;
            for (int j = i+1; j <= min(N-1, i+2); j++)
                take[s[j] - 'a'] = true;
            for (auto k = 0; k < 26; k++) {
                if (!take[k]) {
                    s[i] = k + 'a';
                    break;
                }
            }
        }
    }
    cout << (ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}