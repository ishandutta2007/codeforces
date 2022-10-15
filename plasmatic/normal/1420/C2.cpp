// ./c2-pokmon-army-hard-version.yml
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

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N + 1), flag(N + 1);
    for (auto i = 1; i <= N; i++)
        cin >> (A[i]);
    vector<int> old(all(A));

    ll csum = 0;
    for (auto i = 1; i <= N; i++) {
        if (A[i] > A[i - 1]) {
            flag[i] = true;
            csum += A[i] - A[i - 1];
        }
    }

    cout << (csum) << '\n';

    auto fix = [&] (int x) {
        if (x > N) return;
        if (flag[x]) {
            csum += (A[x] - A[x - 1]) - (old[x] - old[x - 1]);
        }

        bool inc = A[x] > A[x - 1];
        if (flag[x] && !inc) {
            csum -= A[x] - A[x - 1];
            flag[x] ^= 1;
        }
        if (!flag[x] && inc) {
            csum += A[x] - A[x - 1];
            flag[x] ^= 1;
        }
    };

    while (Q--) {
        int l, r;
        cin >> l >> r;

        swap(A[l], A[r]);
        vector<int> v{l, l + 1, r, r + 1};
        UNIQUE(v);
        for (auto x : v) fix(x);
        swap(old[l], old[r]);
        // cout<<"l="<<(l)<<", "; cout<<"r="<<(r)<<", "; cout << "A=["; for (auto x:A)cout<<x<<", "; cout<<"], "; cout << endl; // db l,r,I:A
        // cout << "flag=["; for (auto x:flag)cout<<x<<", "; cout<<"], "; cout << endl; // db I:flag
        cout << (csum) << '\n';
    }
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