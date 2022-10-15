// ./e-anton-and-ira.yml
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

const int MN = 2001;
int N, 
    P[MN], idOf[MN];
bool done[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    for (auto i = 1; i <= N; i++)
        cin >> (P[i]);
    for (auto i = 1; i <= N; i++) {
        int x;
        cin >> x;
        idOf[x] = i;
    }

    int _ans = 0;
    for (auto i = 1; i <= N; i++) {
        P[i] = idOf[P[i]];
        _ans += abs(i - P[i]);
    }

    vector<pii> ans;

    int left = N;
    for (auto i = 1; i <= N; i++) {
        done[i] = P[i] == i;
        left -= done[i];
    }

    while (left > 0) {
        int mx = -INF, mxi = -1;
        for (auto i = 1; i <= N; i++) {
            if (!done[i] && P[i] > mx) {
                mx = P[i];
                mxi = i;
            }
        }

        int pre = mxi;
        for (auto i = mxi+1; i <= mx; i++) {
            if (!done[i] && P[i] <= pre) {
                swap(P[pre], P[i]);
                ans.eb(pre, i);
                pre = i;
            }
        }

        for (auto i = 1; i <= N; i++) {
            if (!done[i] && P[i] == i) {
                done[i] = true;
                left--;
            }
        }
    }

    cout << (_ans / 2) << '\n';
    cout << (SZ(ans)) << '\n';
    for (auto p : ans)
        cout << (p.fs) << ' ' << (p.sn) << '\n';

    return 0;
}