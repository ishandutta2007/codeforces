// ./e-magical-permutation.yml
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
#ifdef __GNUG__
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
#endif
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 2e5 + 1, LG = 18;
int N;
vector<int> bybit[MN];

int basisCnt = 0, basis[LG];
vector<int> basisVals;

void add(int k) {
    int ok = k;
    for (auto i = LG-1; i >= 0; i--) {
        if ((k >> i) & 1) {
            if (basis[i]) k ^= basis[i];
            else {
                basis[i] = k;
                basisVals.pb(ok);
                basisCnt++;
                return;
            }
        }
    }
}

vector<int> gray(int k) {
    if (k == 0) return vector<int>{0, 1};
    auto ch = gray(k-1), ch2 = ch;
    reverse(all(ch2));
    for (auto &x : ch2) x |= 1 << k;
    ch.insert(ch.end(), all(ch2));
    return ch;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (auto i = 0; i < N; i++) {
        int x; cin >> x;
        bybit[__lg(x)].pb(x);
    }

    int ans = 0;
    vector<int> v(1);
    for (auto i = 0; i < LG; i++) {
        for (auto x : bybit[i])
            add(x);

        if (basisCnt == i+1) {
            ans = i+1;
            v.clear();

            for (auto msk : gray(i)) {
                int res = 0;
                for (auto j = 0; j < LG; j++)
                    if ((msk >> j) & 1)
                        res ^= basisVals[j];
                v.pb(res);
            }
        }
    }

    cout << (ans) << '\n';
    for (auto x : v) cout << x << ' ';
    cout << '\n';

    return 0;
}