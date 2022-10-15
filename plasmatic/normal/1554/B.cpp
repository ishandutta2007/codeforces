// ./b-cobb.yml
#include <bits/stdc++.h>
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
#if __cplusplus == 201703L // CPP17 only things
template <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some templates
#endif
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

const int MN = 1e5 + 1, MV = 131072;
int N, K;
pii tp[MV];

void apply(int k, pii &res) {
    if (k > res.fs) {
        res.sn = res.fs;
        res.fs = k;
    }
    else if (k > res.sn)
        res.sn = k;
}

void solve() {
    cin >> N >> K;
    int lim = 2 << __lg(N);
    // cout<<"N="<<(N)<<", "; cout<<"K="<<(K)<<", "; cout<<"lim="<<(lim)<<", "; cout << endl; // db N,K,lim

    fill(tp, tp+lim, pii{0, 0});
    for (auto i = 0; i < N; i++) {
        int x; cin >> x;
        apply(i+1, tp[x]);
    }
    for (auto i = 0; i < 18; i++) {
        for (auto j = 0; j < lim; j++) {
            if ((j >> i) & 1) {
                int alt = j ^ (1 << i);
                apply(tp[alt].fs, tp[j]);
                apply(tp[alt].sn, tp[j]);
            }
        }
    }

    ll ans = -INF;
    for (auto i = 0; i < lim; i++)
        if (tp[i].fs && tp[i].sn)
            maxa(ans, (ll)tp[i].fs * tp[i].sn - K * i);
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