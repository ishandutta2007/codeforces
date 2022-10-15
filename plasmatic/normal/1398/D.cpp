// ./d-colored-rectangles.yml
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

const int MN = 201;
int N[3], val[3][MN], dp[MN][MN][MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (auto i = 0; i < 3; i++)
        cin >> (N[i]);
    for (auto i = 0; i < 3; i++) {
        for (auto j = 0; j < N[i]; j++)
            cin >> (val[i][j]);
        sort(val[i], val[i] + N[i], greater<int>());
    }

    int ans = 0;
    for (auto i = 0; i <= N[0]; i++) {
        for (auto j = 0; j <= N[1]; j++) {
            for (auto k = 0; k <= N[2]; k++) {
                int &res = dp[i][j][k], vi = val[0][i - 1], vj = val[1][j - 1], vk = val[2][k - 1];
                if (i > 0 && k > 0) maxa(res, dp[i - 1][j][k - 1] + vi * vk);
                if (i > 0 && j > 0) maxa(res, dp[i - 1][j - 1][k] + vi * vj);
                if (j > 0 && k > 0) maxa(res, dp[i][j - 1][k - 1] + vj * vk);
                maxa(ans, res);
                // cout<<"i="<<(i)<<", "; cout<<"j="<<(j)<<", "; cout<<"k="<<(k)<<", "; cout<<"res="<<(res)<<", "; cout << endl; // db i,j,k,res
            }
        }
    }
    cout << (ans) << '\n';

    return 0;
}