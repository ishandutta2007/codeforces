// ./d1-frequency-problem-easy-version.yml
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

const int MN = 2e5 + 1;
int N, 
    val[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    vector<int> fre(101);
    for (auto i = 1; i <= N; i++) {
        cin >> val[i];
        fre[val[i]]++;
    }
    int mfre = *max_element(fre.begin(), fre.end()), biggest = -1;
    for (auto i = 1; i <= 100; i++) {
        if (fre[i] == mfre) {
            if (biggest == -1) biggest = i;
            else {
                cout << N << "\n";
                return 0;
            }
        }
    }

    int ans = 0;
    for (auto i = 1; i <= 100; i++) {
        if (i == biggest) continue;
        vector<int> psum(N+1), fst(2*N+1, -1), lst(2*N+1, -1);
        int D = N;
        fst[D] = 0;

        for (auto j = 1; j <= N; j++) {
            psum[j] = psum[j-1];
            if (val[j] == biggest) psum[j]--;
            else if (val[j] == i) psum[j]++;
            if (fst[psum[j]+D] == -1) fst[psum[j]+D] = j;
        }
        for (auto j = N; j >= 1; j--)
            if (lst[psum[j]+D] == -1)
                lst[psum[j]+D] = j;
        for (auto j = 0; j <= 2*N; j++)
            if (fst[j] != -1 && lst[j] != -1 && fst[j] != lst[j])
                ans = max(ans, lst[j] - fst[j]);
    }

    cout << (ans) << '\n';

    return 0;
}