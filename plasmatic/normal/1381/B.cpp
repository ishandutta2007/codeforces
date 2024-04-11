// b-unmerge.yml
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

const int MN = 4001;
int N,
    val[MN];
bool dp[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        cin >> (N); N *= 2;
        for (auto i = 1; i <= N; i++)
            cin >> (val[i]);

        int half = N / 2;
        deque<int> dq;
        for (auto i = N; i >= 1; i--) {
            while (!dq.empty() && val[dq.back()] < val[i])
                dq.pop_back();
            dq.pb(i);
        }
        // cout << "dq=["; for (auto x:dq)cout<<x<<", "; cout<<"], "; cout << endl; // db I:dq

        fill(dp, dp + N + 1, false);
        dp[0] = true;
        int pre = N + 1;
        while (!dq.empty()) {
            int tp = dq.front(), sz = pre - tp; dq.pop_front();
            // cout<<"tp="<<(tp)<<", "; cout<<"sz="<<(sz)<<", "; cout << endl; // db tp,sz
            for (auto i = N; i >= sz; i--)
                dp[i] |= dp[i - sz];
            pre = tp;
        }

        cout << (dp[half] ? "YES" : "NO") << '\n';
    }

    return 0;
}