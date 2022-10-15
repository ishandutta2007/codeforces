// a-string-transformation-1.yml
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

// const int MN = 1e5 + 1;
int N;
string s, t;

void extend(vector<bool> &f, vector<bool> &t) {
    for (auto i = 0; i < 20; i++)
        t[i] = t[i] | f[i];
}

void solve() {
    for (auto i = 0; i < N; i++) {
        if (t[i] < s[i]) {
            cout << (-1) << '\n';
            return;
        }
    }

    int ans = 0;
    pair<char, char> mn;
    do {
        mn = {'z', 'z'};
        for (auto i = 0; i < N; i++) {
            if (s[i] != t[i])
                mina(mn, mpr(s[i], t[i]));
        }
        // cout<<"s="<<(s)<<", "; cout<<"t="<<(t)<<", "; cout<<"mn.first="<<(mn.first)<<", "; cout<<"mn.second="<<(mn.second)<<", "; cout << endl; // db s,t,mn.first,mn.second
        if (mn != mpr('z', 'z')) {
            ans++;
            for (auto i = 0; i < N; i++)
                if (s[i] == mn.first && t[i] >= mn.second)
                    s[i] = mn.second;
        }
    } while (mn != mpr('z', 'z'));
    cout << (ans) << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        // Input
        cin >> (N) >> (s) >> (t);
        
        solve();

        // Reset
    }
}