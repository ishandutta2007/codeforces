// f-and-segments.yml
#include "bits/stdc++.h"
using namespace std;

// Defines
#define pb push_back
#define fs first
#define sn second
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
using ll = long long; using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<long, long>;
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
template <typename C> int sz(C &v) { return v.size(); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const ll MOD = 998244353;
ll madd(ll a, ll b, ll mod = MOD) { return (a + b) % mod; }
ll msub(ll a, ll b, ll mod = MOD) { return (a - b + mod) % mod; }
ll mmul(ll a, ll b, ll mod = MOD) { return (a * b) % mod; }
ll fpow(ll x, ll y, ll mod = MOD) {
    if (!y) return 1LL;
    return mmul(fpow(mmul(x, x, mod), y >> 1, mod), (y & 1) ? x : 1LL, mod);
}
ll mdiv(ll x, ll y, ll mod = MOD) { return mmul(x, fpow(y, mod - 2, mod), mod); }

struct Seg {
    int l, r, v;
};

istream& operator>>(istream &in, Seg &o) {
    in >> o.l >> o.r >> o.v;
    return in;
}

const int MN = 5e5 + 10, MK = 31;
int N, M, K,
    onSeg[MN], lbound[MN];
Seg segs[MN];
ll dp[MN], psum[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (K) >> (M);

    for (auto i = 1; i <= M; i++) {
        cin >> (segs[i]); }

    ll ans = 1;
    for (auto i = 0; i < K; i++) {
        fill(psum, psum + N + 1, 0);
        fill(dp, dp + N + 1, 0);
        fill(onSeg, onSeg + N + 1, 0);
        fill(lbound, lbound + N + 1, -1);

        for (auto j = 1; j <= M; j++) {
            if (!((segs[j].v >> i) & 1))
                lbound[segs[j].r] = max(lbound[segs[j].r], segs[j].l);
            else {
                onSeg[segs[j].l]++;
                onSeg[segs[j].r + 1]--;
            }
        }
        partial_sum(onSeg, onSeg + N + 2, onSeg);

        psum[1] = dp[0] = 1LL;
        int preL = 0;
        for (auto j = 1; j <= N + 1; j++) {
            if (!onSeg[j]) {
                dp[j] = msub(psum[j], psum[preL]); }
            if (lbound[j] != -1) {
                preL = max(preL, lbound[j]); }

            psum[j + 1] = madd(psum[j], dp[j]);
        }

        ans = mmul(ans, dp[N + 1]);
    }
    cout << (ans) << '\n';

    return 0;
}