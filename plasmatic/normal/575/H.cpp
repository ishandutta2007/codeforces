// ./h-bots.yml
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

const ll MOD = 1e9 + 7;
ll madd(ll a, ll b, ll mod = MOD) { return (a + b) % mod; }
ll msub(ll a, ll b, ll mod = MOD) { return (a - b + mod) % mod; }
ll mmul(ll a, ll b, ll mod = MOD) { return (a * b) % mod; }
ll fpow(ll x, ll y, ll mod = MOD) {
    if (!y) return 1LL;
    return mmul(fpow(mmul(x, x, mod), y >> 1, mod), (y & 1) ? x : 1LL, mod);
}
ll mdiv(ll x, ll y, ll mod = MOD) { return mmul(x, fpow(y, mod - 2, mod), mod); }
// N choose R
vector<ll> fact, invf;
void init_nchooser(int MN) {
    fact.resize(MN + 1); invf.resize(MN + 1);
    fact[0] = invf[0] = 1LL;
    for (int i = 1; i <= MN; i++) {
        fact[i] = mmul(fact[i - 1], i);
        invf[i] = mdiv(1, fact[i]);
    }
}
ll choose(ll N, ll K) { return mmul(fact[N], mmul(invf[K], invf[N - K])); }
ll permute(ll N, ll K) { return mmul(fact[N], invf[N - K]); }

// maintain SUM(K choose L..R)
// - first l..r set bits in K
// - first l..r set bits not in K -> ((l-1)..(r-1) bits set in K), K+1th bit set)
int l = 1, r = 1, k = 1;
ll cur = 1;
void extend(int nl, int nr, int nk) { // all must be monotonous
    while (k < nk) {
        cur = madd(cur, madd(cur, msub(choose(k, l - 1), choose(k, r))));
        k++;
    }
    while (l < nl) {
        cur = msub(cur, choose(k, l));
        l++;
    }
    while (r < nr) {
        r++;
        cur = madd(cur, choose(k, r));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    init_nchooser(2 * N);

    ll ans = 1;
    for (auto i = 1; i <= 2*N; i++) {
        int lb = max(0, i - N), rb = min(N, i);
        extend(max(lb, 1), rb, i);
        ans = madd(ans, cur);
        if (lb == 0) ans = madd(ans, 1); // k choose 0
    }
    cout << (ans) << '\n';

    return 0;
}