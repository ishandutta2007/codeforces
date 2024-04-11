// ./a-avoid-trygub.yml
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

int order[26];

void solve() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    sort(all(s), [&] (const char a, const char b) { return order[a-'a'] < order[b-'a']; });
    cout << (s) << '\n';    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(order, -1, sizeof order);
    order['b'-'a'] = 0;
    order['u'-'a'] = 1;
    order['g'-'a'] = 2;
    order['y'-'a'] = 3;
    order['r'-'a'] = 4;
    order['t'-'a'] = 5;
    int st = 6;
    for (auto i = 0; i < 26; i++)
        if (order[i] == -1)
            order[i] = st++;
    // cout<<"order=["; for(int __i=0; __i<(26); __i++)cout<<order[__i]<<", "; cout<<"], ";cout << endl; // db A:26:order

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}