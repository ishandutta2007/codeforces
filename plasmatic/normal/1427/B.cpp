// ./b-chess-cheater.yml
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

void solve() {
    int N, K; string s;
    cin >> N >> K >> s;
    vector<int> ind;
    for (auto i = 0; i < N; i++)
        if (s[i] == 'W')
            ind.pb(i);

    if (ind.empty()) {
        cout << (max(0, 2*K-1)) << '\n';
        return;
    }

    int ans = 0;
    for (auto i = 0; i < N; i++) {
        if (s[i] == 'W') {
            ans++;
            if (i > 0 && s[i - 1] == 'W') ans++;
        }
    }

    vector<int> gap;
    for (auto i = 1; i < SZ(ind); i++)
        gap.pb(ind[i] - ind[i - 1] - 1);
    sort(all(gap));

    // cout<<"ans="<<(ans)<<", "; cout << "ind=["; for (auto __x:ind)cout<<__x<<", "; cout<<"], "; cout << "gap=["; for (auto __x:gap)cout<<__x<<", "; cout<<"], "; cout << endl; // db ans,I:ind,I:gap

    for (auto &x : gap) {
        if (x == 0) continue;
        if (K >= x) {
            ans += 2 * x + 1;
            K -= x;
        }
        else {
            ans += 2 * K;
            K = 0;
        }
    }
    if (!ind.empty()) {
        int leftgap = min(K, ind[0] + (N - ind.back() - 1));
        ans += leftgap * 2;
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