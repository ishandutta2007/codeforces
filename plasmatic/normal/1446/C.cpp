// ./c-xor-tree.yml
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
// // PBDS order statistic tree
// #include <ext/pb_ds/assoc_container.hpp> // Common file 
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds; 
// template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// // HashSet
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
// struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
// template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
// template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
// // More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 2e5 + 1;
int N,
    best[MN];
ll val[MN];

int solve(vector<ll> v, int bit = 29) {
    if (SZ(v) <= 2) return 0;

    vector<ll> lhs, rhs;
    for (auto &x : v) {
        if ((x >> bit) & 1)
            rhs.pb(x);
        else
            lhs.pb(x);
    }

    // sort(all(lhs)); sort(all(rhs));
    // cout<<"bit="<<(bit)<<", "; cout << "v=["; for (auto __x:v)cout<<__x<<", "; cout<<"], "; cout << endl; // db bit,I:v
    // cout << "lhs=["; for (auto __x:lhs)cout<<__x<<", "; cout<<"], "; cout << "rhs=["; for (auto __x:rhs)cout<<__x<<", "; cout<<"], "; cout << endl; // db I:lhs,I:rhs

    return min(solve(lhs, bit - 1) + max(0, SZ(rhs) - 1)
        ,solve(rhs, bit - 1) + max(0, SZ(lhs) - 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    for (auto i = 0; i < N; i++)
        cin >> (val[i]);

    vector<ll> vv(val, val + N);
    int ans = solve(vv);
    cout << (ans) << '\n';

    return 0;
}