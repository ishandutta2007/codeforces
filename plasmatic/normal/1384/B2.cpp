// b2-koa-and-the-beach-hard-version.yml
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

const int MN = 3e5 + 1;
int N;
ll K, L,
   D[MN], canR[MN], canL[MN];
bool full[MN];

void solve() {
    for (auto i = 0; i < N; i++) {
        if (D[i] > L) {
            cout << ("No") << '\n';
            return;
        }
        if (D[i] + K <= L)
            full[i] = true;
        else {
            canL[i] = 2 * K - (L - D[i]);
            canR[i] = (L - D[i]) + 2 * K;
        }
    }

    ll cur = canL[0];
    for (auto i = 1; i < N; i++) {
        // cout<<"i="<<(i)<<", "; cout<<"cur="<<(cur)<<", "; cout<<"canL[i]="<<(canL[i])<<", "; cout<<"canR[i]="<<(canR[i])<<", "; cout << endl; // db i,cur,canL[i],canR[i]
        if (full[i])
            cur = 0;
        else {
            cur = max(cur + 1, canL[i]);
            if (cur > canR[i]) {
                cout << ("No") << '\n';
                return;
            }
        }
    }

    cout << ("Yes") << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        // Input
        cin >> (N) >> (K) >> (L);
        for (auto i = 0; i < N; i++)
            cin >> (D[i]);
        
        solve();

        // Reset
        fill(full, full + N, false);
        fill(canL, canL + N, 0);
        fill(canR, canR + N, 0);
    }
}