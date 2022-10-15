// ./b-dzy-loves-fft.yml
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

ll _x;
ll getNextX() {
    _x = (_x * 37 + 10007) % 1000000007;
    return _x;
}

const int MN = 1e5 + 1;
int N, _d, 
    A[MN], B[MN];

void initAB() {
    for (int i = 0; i < N; i = i + 1) A[i] = i + 1;
    for (int i = 0; i < N; i = i + 1) swap(A[i], A[getNextX() % (i + 1)]);
    for (int i = 0; i < N; i = i + 1){
        if (i < _d) B[i] = 1;
        else B[i] = 0;
    }
    for (int i = 0; i < N; i = i + 1) swap(B[i], B[getNextX() % (i + 1)]);
}

const int PRO = 100;
int ans[MN], idx[MN];
vector<int> ind1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (_d) >> (_x);
    initAB();

    for (auto i = 0; i < N; i++) {
        idx[A[i]] = i;
        if (B[i]) ind1.pb(i);
    }

    for (auto i = 0; i < N; i++) {
        // Data is generated randomly
        // The probability of B[j]=1 for any j is 50%, thus for any cell P(x)=N is 50%, P(x)=N-1 is 25%, etc.
        // So we can just check down to a threshold, and brute force otherwise
        for (int j = N; j >= max(1, N-PRO); j--) {
            if (idx[j] <= i && B[i - idx[j]]) {
                ans[i] = j;
                break;
            }
        }
        if (ans[i] == 0) {
            for (auto j : ind1)
                if (i - j >= 0)
                    maxa(ans[i], A[i - j]);
        }
    }

    for (auto i = 0; i < N; i++)
        cout << (ans[i]) << '\n';

    return 0;
}