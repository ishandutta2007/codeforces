// f-restore-the-permutation-by-sorted-segments.yml
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

const int MN = 201;
int N;
bitset<MN> ss[MN];

bool attempt(int st) {
    bitset<MN> used; used[st] = true;
    vector<bitset<MN>> ansHas(N);
    vector<int> ans(N);
    vector<bool> done(N);
    ans[0] = st; ansHas[0][st] = true;
    for (auto i = 1; i < N; i++) {
        bool good = false;
        for (auto j = 0; j < N-1; j++) {
            int pre = i - int(ss[j].count()) + 1;
            if (done[j] || pre < 0) continue;
            bitset<MN> rem = (ss[j] & used) ^ ss[j];
            if (rem.count() == 1 && (ss[j] ^ rem) == ansHas[pre]) {
                if (good) return false;
                ans[i] = rem._Find_first();
                good = done[j] = true;
            }
        }
        if (!good) return false;
        used[ans[i]] = true;
        for (auto j = 0; j <= i; j++) {
            ansHas[j][ans[i]] = true; }
    }
    for (auto x : ans)
        cout << x << ' ';
    cout << '\n';
    return true;
}

void solve() {
    if (N == 2) {
        for (int x = ss[0]._Find_first(); x < MN; x = ss[0]._Find_next(x))
            cout << x << ' ';
        cout << '\n';
        return;
    }

    for (auto i = 1; i <= N; i++) {
        if (attempt(i)) return; }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        // Input
        cin >> (N);
        for (auto i = 0; i < N-1; i++) {
            int n;
            cin >> n;
            for (auto j = 0; j < n; j++) {
                int x;
                cin >> x;
                ss[i][x] = true;
            }
        }
        
        solve();

        // Reset
        for (auto i = 0; i < N-1; i++)
            ss[i].reset();
    }
}