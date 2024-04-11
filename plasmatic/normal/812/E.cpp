// ./e-sagheer-and-apple-tree.yml
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

/*

Why does the editorial strategy of only considering blue nodes work? (Recall that blue nodes have the same depth parity as leaf nodes, and red nodes have the opposite, and also that the Nimber of the game is the XOR of all blue nodes)

We can use a similar reasoning to Nim with addition, where the winning player can just play Nim like normal, and can always undo a losing player's addition move.

Consider the following:

Note that we denote winning as the current game state having a non-zero XOR sum of blue piles.  We can prove that only blue piles matter by showing how a winning player will always win the full game (when including red piles).

- The winning player plays Nim like normal with only blue piles
- If the losing player makes a move on a red node, the winning player can undo that change by moving the same number of apples from the blue node the losing player added to onto any of its children (or nowhere, if the blue node was a leaf).  This preserves the state of the blue piles thus undoing the move made, meaning that the state of the red nodes is irrelavent.  Also note that if a player is winning by Nim standards (XOR blue nodes != 0), it's obviously not optimal to make a move on a red node.
- If either player makes a move on a blue node that isn't a leaf node, it's the same as making the move on a leaf node as we already established that the state of red nodes does not matter.

As sagheer goes second, he wants the Nimber of the game to be 0.  Now we can just solve the problem with simple DFS and math.

XorSum = S

S ^ v ^ w = 0
S ^ v = w

*/

const int MN = 1e5 + 1, MV = 1e7 + 1;
int N, ldep,
    A[MN];
vector<int> g[MN], nvals[2];
map<int, int> cnt;

void dfs(int c, int dep = 0) {
    if (g[c].empty()) ldep = dep & 1;
    nvals[dep & 1].pb(A[c]);
    for (int to : g[c])
        dfs(to, dep + 1);
}

ll tri(ll x) { return (x * (x - 1)) / 2; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    for (auto i = 1; i <= N; i++)
        cin >> (A[i]);
    for (auto i = 2; i <= N; i++) {
        int p;
        cin >> p;
        g[p].pb(i);
    }
    dfs(1);

    int txor = 0;
    for (auto &x : nvals[ldep])
        txor ^= x;

    // We want to make txor==0
    ll ans = 0;
    if (txor == 0) 
        ans += tri(SZ(nvals[0])) + tri(SZ(nvals[1]));
    for (auto &x : nvals[!ldep])
        cnt[x]++;
    for (auto &x : nvals[ldep])
        ans += cnt[txor ^ x];

    cout << (ans) << '\n';

    return 0;
}