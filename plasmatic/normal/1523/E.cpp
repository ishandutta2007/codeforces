// ./e-crypto-lights.yml
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

const ll MOD = 1e9 + 7;
ll fix(ll &&x) { x %= MOD; if (x < 0) x += MOD; return x; }
ll fix(ll &x) { x %= MOD; if (x < 0) x += MOD; return x; }
ll fpow(ll x, ll y, ll mod = MOD) {
    if (!y) return 1LL;
    return fpow(x * x % mod, y >> 1, mod) * ((y & 1) ? x : 1LL) % mod;
}
ll inv(ll x, ll mod = MOD) { return fpow(x, mod - 2, mod); }
// N choose R
vector<ll> fact, invf;
void init_nchooser(int MN) {
    fact.resize(MN + 1); invf.resize(MN + 1);
    fact[0] = 1LL;
    for (int i = 1; i <= MN; i++) fact[i] = fix(fact[i - 1] * i);
    invf[MN] = inv(fact[MN]);
    for (auto i = MN-1; i >= 0; i--) invf[i] = fix(invf[i + 1] * (i + 1));
}
ll choose(ll N, ll K) { return fix(fact[N] * fix(invf[K] * invf[N - K])); }
ll permute(ll N, ll K) { return fix(fact[N] * invf[N - K]); }

const int MN = 1e5 + 1;
int N, K;

void solve() {
    cin >> N >> K;

    // first i-1 blocks are size K, last block is size 1
    // remove (K-1)*(i-1) blocks
    ll ans = 1; // add 1 since this counts the last addition before the constraint is violated
    for (auto i = 1; i <= N; i++) {
        if (N - ll(K-1) * (i-1) >= i) {
            ll valid = choose(N-(K-1)*(i-1), i), tot = choose(N, i);
            ans += fix(valid * inv(tot));
            fix(ans);
        }
    }
    cout << (ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init_nchooser(MN);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}