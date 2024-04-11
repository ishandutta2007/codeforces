// ./c-maximize-the-intersections.yml
#include <bits/stdc++.h>
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
#if __cplusplus == 201703L // CPP17 only things
template <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some templates
#endif
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

const int MN = 201;
int N, K,
    A[MN], B[MN];

bool inter(int i, int j) {
    vector<pii> vs;
    vs.eb(A[i], 0);
    vs.eb(B[i], 0);
    vs.eb(A[j], 1);
    vs.eb(B[j], 1);
    sort(all(vs));

    bool ok = true;
    for (auto i = 0; i < 3; i++)
        ok &= vs[i].sn != vs[i+1].sn;
    return ok;
}

void solve() {
    cin >> N >> K;
    N *= 2;

    vector<bool> tk(N+1);
    for (auto i = 0; i < K; i++) {
        cin >> A[i] >> B[i];
        if (A[i] > B[i]) swap(A[i], B[i]);
        tk[A[i]] = true;
        tk[B[i]] = true;
    }

    int left = N/2-K, ans = left*(left-1) / 2;
    for (auto i = 0; i < K; i++)
        for (auto j = i+1; j < K; j++)
            ans += inter(i, j);

    for (auto i = 0; i < K; i++) {
        int tl = 0, tr = 0;
        for (auto j = A[i]+1; j < B[i]; j++)
            tl += !tk[j];
        for (auto j = B[i] == N ? 1 : B[i]+1; j != A[i]; j = j == N ? 1 : j + 1)
            tr += !tk[j];

        ans += min(tl, tr);
    }

    cout << (ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}