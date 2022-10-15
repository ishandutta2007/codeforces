// d-minimax-problem.yml
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
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 3e5 + 1, MM = 9;
int N, M,
    val[MN][MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (M);
    for (auto i = 0; i < N; i++)
        for (auto j = 0; j < M; j++)
            cin >> (val[i][j]);
    auto check = [&] (int req) -> pair<int, int> {
        vector<pair<int, bool>> av(1 << M);
        for (auto i = 0; i < N; i++) {
            int msk = 0;
            for (auto j = M-1; j >= 0; j--)
                msk = (msk << 1) | (val[i][j] >= req);
            av[msk] = {i, true};
        }
        int msub = 1 << M;
        for (auto i = msub-1; i >= 0; i--) {
            if (av[i].second) {
                int j = i;
                do {
                    j = (j - 1) & i;
                    av[j] = av[i];
                } while (j);
            }
        }
        for (auto i = 0; i < N; i++) {
            int msk = 0;
            for (auto j = M-1; j >= 0; j--)
                msk = (msk << 1) | (val[i][j] < req);
            if (av[msk].second)
                return {i, av[msk].first};
        }
        return {-1, -1};
    };
    int l = 0, r = INF;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid) != mpr(-1, -1))
            l = mid;
        else
            r = mid;
    }
    auto ans = check(l);
    cout << (ans.first+1) << ' ' << (ans.second+1) << '\n';

    return 0;
}