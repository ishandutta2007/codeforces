// ./f-lanterns.yml
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

struct segtree {
    vector<int> seg;
    int N;
    void init(int N0) { N0++;
        N = 1;
        while (N < N0) N *= 2;
        seg.assign(N*2, INF);
    }
    void update(int x, int v) { x++;
        x += N-1;
        seg[x] = min(seg[x], v);
        for (x >>= 1; x; x >>= 1)
            seg[x] = min(seg[x*2], seg[x*2+1]);
    }
    int query(int l, int r) { l++; r++;
        l += N-1;
        r += N-1;
        int res = INF;
        for (; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) {
                res = min(res, seg[l]);
                l++;
            }
            if (!(r & 1)) {
                res = min(res, seg[r]);
                r--;
            }
        }
        return res;
    }
};

struct Par {
    int p, t;
};

const int MN = 3e5 + 10, LG = 20;
int N, 
    P[MN];

int dp[MN];
Par par[MN];
segtree bestt;

int tb[LG][MN];
int query(int l, int r) {
    if (l > r) return -INF;
    int sz = r - l + 1, bit = __lg(sz);
    return max(tb[bit][l], tb[bit][r - (1 << bit) + 1]);
}

void solve() {
    cin >> (N);
    for (auto i = 1; i <= N; i++) cin >> P[i];

    for (auto i = 0; i < LG; i++) fill(tb[i], tb[i]+N+1, -INF); // RESET
    // build sparse table
    for (auto i = 1; i <= N; i++) tb[0][i] = P[i] ? i + P[i] : -INF;
    for (auto i = 1; i < LG; i++) {
        int jmp = 1 << (i-1), end = N-(1<<i)+1;
        for (auto j = 1; j <= end; j++) 
            tb[i][j] = max(tb[i-1][j], tb[i-1][j+jmp]);
    }

    // init stuff
    fill(dp, dp+N+1, -INF);
    fill(par, par+N+1, Par{-1, -1});
    bestt.init(N);
    dp[0] = 0; par[0] = {-1, 0}; bestt.update(0, 0);
    // do DP
    for (auto i = 1; i <= N; i++) {
        // transition type II
        if (dp[i-1] >= i) {
            int alt = max(dp[i-1], i+P[i]);
            if (alt > dp[i]) {
                dp[i] = alt;
                par[i] = {i-1, 1};
            }
        }
        // transition type I
        int q = bestt.query(max(0, i-P[i]-1), N);
        if (q != INF) {
            int alt = max({dp[q], query(q+1, i-1), i-1});
            if (alt > dp[i]) {
                dp[i] = alt;
                par[i] = {q, 2};
            }
        }
        dp[i] = min(dp[i], N);
        if (dp[i] >= 0)
            bestt.update(dp[i], i);
    }

    if (dp[N] < N) {
        cout << ("NO") << '\n';
        return;
    }
    string ans(N, 'R');
    for (auto x = N; x > 0; ) {
        auto p = par[x];
        if (p.t == 2) ans[x-1] = 'L';
        x = p.p;
    }
    cout << ("YES") << '\n';
    cout << (ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}