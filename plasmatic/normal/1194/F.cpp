// f-crossword-expert.yml
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

const int MN = 2e5 + 1;
int N;
ll T,
   val[MN];

/*
Nc0 + Nc1 + ... + NcK
 -> # of ways to set K 1s in a N-bit binary string

If we extend N to N+1 ->
 -> Set (0..K) bits in the first N bits, don't set the N+1th bit
 -> Set (0..K-1) bits in the first N bits, set the N+1th bit

Note: It's easy to show that as we go from 1 crossword to N crosswords, the value of N always increases by 1 each time, and the value of K first increases, and then decreases.
Thus, the extend() function has O(N) performance overall.
 */

// maintain the value of (curN choose 0) + (curN choose 1) + ... + (curN choose K)
ll tot = 0;
int curN = 0, curK = -1;

// first extend N
void extend(int newN, int newK) {
    if (curK > 0) {
        while (curN < newN) {
            tot = madd(tot, msub(tot, choose(curN, curK)));
            curN++;
        }
    }
    else curN = newN; // If curK < 1 then nothing needs to be changed
    while (curK < newK) tot = madd(tot, choose(curN, ++curK));
    while (curK > newK) tot = msub(tot, choose(curN, curK--));
}

ll sto[MN + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (T);
    init_nchooser(N);
    for (auto i = 1; i <= N; i++) {
        cin >> (val[i]);
        val[i] += val[i - 1];
    }

    // sto[i] -> Probability that at least i crosswords will be solved
    for (auto i = 1; i <= N; i++) {
        ll rem = max(ll(-1), min(ll(i), T - val[i]));
        extend(i, rem);
        sto[i] = mdiv(tot, fpow(2, i));
    }

    // Inclusion/Exclusion
    ll ans = 0;
    for (auto i = 1; i <= N; i++) {
        sto[i] = msub(sto[i], sto[i + 1]);
        ans = madd(ans, mmul(sto[i], i));
    }

    cout << (ans) << '\n';

    return 0;
}