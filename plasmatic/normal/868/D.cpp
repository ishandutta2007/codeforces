// d-huge-strings.yml
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

const int MN = 101, MK = 12 + 1;
int N, M, 
    ans[MN * 2];
string strs[MN * 2], pre[MK][MN * 2], suf[MK][MN * 2];
ll sz[MN * 2];
set<string> mid[MK][MN * 2];

void fullcalc(int i) {
    for (auto j = 1; j <= min(MK - 1, SZ(strs[i])); j++) {
        for (auto k = 0; k < SZ(strs[i])-j+1; k++)
            mid[j][i].insert(strs[i].substr(k, j));
        if (SZ(mid[j][i]) == (1 << j)) {
            ans[i] = j; }
        pre[j][i] = strs[i].substr(0, j);
        suf[j][i] = strs[i].substr(SZ(strs[i]) - j, j);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    for (auto i = 0; i < N; i++) {
        cin >> (strs[i]);
        sz[i] = SZ(strs[i]);
        fullcalc(i);
    }

    cin >> (M);
    for (auto i = N; i < N + M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        if (sz[a] < MK && sz[b] < MK) {
            strs[i] = strs[a] + strs[b];
            sz[i] = sz[a] + sz[b];
            for (auto j = 1; j < MK; j++) {
                mid[j][i].insert(all(mid[j][a]));
                mid[j][i].insert(all(mid[j][b]));
            }
            fullcalc(i);
        }
        else {
            strs[i] = strs[a] + strs[b];
            strs[i] = strs[i].substr(0, MK - 1) + strs[i].substr(SZ(strs[i]) - MK + 1, MK - 1);
            sz[i] = min(LLINF, sz[a] + sz[b]);
            for (auto j = 1; j < MK; j++) {
                pre[j][i] = strs[i].substr(0, j);
                suf[j][i] = strs[i].substr(SZ(strs[i]) - j, j);

                mid[j][i] = mid[j][a];
                mid[j][i].insert(all(mid[j][b]));
                for (auto k = 1; k < j; k++) {
                    if (sz[a] >= k && sz[b] >= j - k)
                        mid[j][i].insert(suf[k][a] + pre[j - k][b]); }
            }

            for (auto j = 1; j < MK; j++)
                if (SZ(mid[j][i]) == (1 << j))
                    ans[i] = j;
        }

        cout << (ans[i]) << '\n';
    }

    return 0;
}