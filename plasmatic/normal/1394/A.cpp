// ./a-boboniu-chats-with-du.yml
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

const int MN = 1e5 + 1;
int N, D, M;
ll A[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (D) >> (M);
    vector<ll> small, large;
    for (auto i = 0; i < N; i++) {
        cin >> (A[i]);
        if (A[i] <= M) small.pb(A[i]);
        else large.pb(A[i]);
    }
    sort(all(small), greater<ll>());
    // cout << "small=["; for (auto x:small)cout<<x<<", "; cout<<"], "; cout << endl; // db I:small
    partial_sum(all(small), small.begin());
    sort(all(large), greater<ll>());
    // cout << "large=["; for (auto x:large)cout<<x<<", "; cout<<"], "; cout << endl; // db I:large
    partial_sum(all(large), large.begin());

    ll ans = -LLINF;
    for (auto i = 0; i <= SZ(small); i++) {
        ll cans = i ? small[i - 1] : 0, rem = N - i, use = min((ll)SZ(large), (rem + D) / (D + 1));
        // cout<<"i="<<(i)<<", "; cout<<"cans="<<(cans)<<", "; cout<<"rem="<<(rem)<<", "; cout<<"use="<<(use)<<", "; cout << endl; // db i,cans,rem,use
        cans += use ? large[use - 1] : 0;
        // cout<<"cans="<<(cans)<<", "; cout << endl; // db cans
        maxa(ans, cans);
    }
    cout << (ans) << '\n';

    return 0;
}