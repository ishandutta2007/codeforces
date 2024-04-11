// f-yet-another-minimization-problem.yml
#include "bits/stdc++.h"
using namespace std;

// Defines
#define pb push_back
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
template <typename C> int SZ(C &v) { return v.size(); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1e5 + 1, MK = 21;
int N, K;
ll val[MN], dp[MK][MN];

// track pairs that are same
int cqid = 0, cl = 1, cr = 0, qid[MN];
ll ccost = 0, cnt[MN];
void reset() { cqid++; ccost = 0; cl = 1; cr = 0; }
ll& get(int x) {
    if (qid[x] != cqid) { qid[x] = cqid; cnt[x] = 0; }
    return cnt[x];
}
void ins(int x) {
    ccost += get(x)++; }
void rem(int x) {
    ccost -= --get(x); }
void move(int l, int r) {
    // Extend right
    while (cr < r) ins(val[++cr]); // ins new value
    while (cl < l) rem(val[cl++]); // rem old value
    // Extend left
    while (cl > l) ins(val[--cl]); // ins new value
    while (cr > r) rem(val[cr--]); // rem old value
}

// assume [dr, l] has already been filled
void solve(int row, int dl, int dr, int l, int r) {
    if (l > r) return;
    int besti = -1, mid = (l + r) / 2;
    ll bestv = LLINF;
    for (auto i = min(mid - 1, dr); i >= dl; i--) {
        move(i + 1, mid);
        ll alt = dp[row - 1][i] + ccost;
        if (alt < bestv) {
            bestv = alt;
            besti = i;
            dp[row][mid] = alt;
        }
    }

    solve(row, besti, dr, mid + 1, r); // right before left
    solve(row, dl, besti, l, mid - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (K);
    for (auto i = 1; i <= N; i++)
        cin >> (val[i]);

    for (auto i = 0; i <= K; i++) {
        fill(dp[i] + 1, dp[i] + N + 1, LLINF); }

    for (auto i = 1; i <= K; i++) {
        solve(i, 0, N, 1, N); }

    cout << (dp[K][N]) << '\n';

    return 0;
}