// ./b-make-them-equal.yml
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

const int MN = 1e4 + 1;

void solve() {
    int N;
    cin >> N;
    vector<ll> v(N + 1); ll tsum = 0;
    for (auto i = 1; i <= N; i++) {
        cin >> (v[i]);
        tsum += v[i];
    }

    if (tsum % N) {
        cout << (-1) << '\n';
        return;
    }
    ll want = tsum / N;

    vector<tuple<int, int, int>> ans;
    for (auto i = 2; i <= N; i++) {
        int missing = i - (v[i] % i);
        if (v[1] >= missing) {
            // cout<<"[add]: "; cout<<"i="<<(i)<<", "; cout << endl; // db l:add,i
            ans.eb(1, i, missing);
            v[1] -= missing; v[i] += missing;
        }

        ll mulp = v[i] / i;
        ans.eb(i, 1, mulp);
        v[i] -= mulp * i; v[1] += mulp * i;

        if (v[i] > want) {
            cout << (-1) << '\n';
            return;
        }
    }
    for (auto i = 2; i <= N; i++) {
        ll need = want - v[i];
        ans.eb(1, i, need);
    }

    cout << (SZ(ans)) << '\n';
    for (auto &t : ans) {
        int a, b, c; tie(a, b, c) = t;
        cout << (a) << ' ' << (b) << ' ' << (c) << '\n';
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