// 1.yml
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

/*
Kuroni's very smart and very orz blog (https://codeforces.com/blog/entry/77298)

Some details
- We always assume the final right function is y=b (slope=0)
- The PQ maintains the list of slope changes (slope is non-decreasing) so each change is (+1 to slope at x=pos)
    - When you push an element into the PQ, that "decreases" all of the slopes before that position by 1 (think about what happens when the final slope is always assumed to be 0)
- Create g_i(x) and convert g_i(x) to f_i(x) using observation
- Instead of maintaining the answer directly, I thought it was more straightforward to backtrack to find the answer

*/

const int MN = 1e6 + 1;
int N;
ll val[MN];
priority_queue<ll> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    for (auto i = 0; i < N; i++) {
        ll x;
        cin >> x;
        x -= i;

        val[i] = x;
        pq.push(x);

        if (x < pq.top()) {
            pq.pop();
            pq.push(x);
        }
    }

    ll minv = *min_element(val, val + N), lft = 0, ans = 0; // lft = f_N(min_val)
    for (auto i = 0; i < N; i++)
        lft += val[i] - minv;

    ll pre = INF, curSlope = 0;
    while (!pq.empty()) {
        ll nxt = pq.top(); pq.pop();
        ans += curSlope * (pre - nxt);
        curSlope--;
        pre = nxt;
    }

    cout << (ans + lft) << '\n';

    return 0;
}