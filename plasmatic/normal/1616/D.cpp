// ./d-keep-the-average-high.yml
#include <bits/stdc++.h>
#define DEBUG 0
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

// Template is 1-indexed
// Default Comp: RMQ + Set query
// Functions merge and applyUpdate should be implemented left to right
struct Comp {
    using Data = ll;
    using Update = ll;
    const Data vdef = -LLINF;
    Data merge(Data l, Data r) { return max(l, r); }
    void applyUpdate(Data &l, Update &r) { l = r; }
};
#define MID int mid = (l + r) / 2, lhs = i + 1, rhs = i + (mid - l + 1) * 2;
template <class Comp> struct SegmentTree {
    using Data = typename Comp::Data; using Update = typename Comp::Update; Comp C;
    int N;
    vector<Data> seg;
    void init(int n0) {
        N = n0;
        seg.assign(2 * N + 2, C.vdef);
    }
    Data _query(int ql, int qr, int i, int l, int r) {
        if (ql > r || qr < l) return C.vdef;
        if (l >= ql && r <= qr) return seg[i];
        MID;
        return C.merge(_query(ql, qr, lhs, l, mid), _query(ql, qr, rhs, mid + 1, r));
    }
    Data _update(int q, Update v, int i, int l, int r) {
        if (q > r || q < l) return seg[i];
        if (l == q && r == q) {
            C.applyUpdate(seg[i], v);
            return seg[i];
        }
        MID;
        return seg[i] = C.merge(_update(q, v, lhs, l, mid), _update(q, v, rhs, mid + 1, r));
    }
    Data query(int ql, int qr) { return _query(ql, qr, 1, 1, N); }
    void update(int q, Update v) { _update(q, v, 1, 1, N); }
};
using ST = SegmentTree<Comp>;

const int MN = 50001;
int N;
ll X,
   A[MN], psum[MN];

int dp[MN][2], R[MN];

void solve() {
    cin >> N;
    for (auto i = 1; i <= N; i++) 
        cin >> A[i];
    cin >> X;

    // psa rnq
    ST rmq; rmq.init(N);
    ll cur = 0;
    for (auto i = 1; i <= N; i++) {
        cur += A[i] - X;
        rmq.update(i, cur);
        psum[i] = cur;
        if (DEBUG) { cout<<"i="<<(i)<<", "; cout<<"psum[i]="<<(psum[i])<<", "; cout << endl; } //__RAW_DEBUG_LINE__:db i,psum[i]
    }

    // 2ptr
    int r = 0;
    for (auto l = 1; l <= N; l++) {
        maxa(r, l);
        while (r < N && psum[r+1] - rmq.query(l-1, r-1) >= 0 && psum[r+1] - psum[l-1] >= 0)
            r++;

        if (DEBUG) { cout<<"l="<<(l)<<", "; cout<<"r="<<(r)<<", "; cout << endl; } //__RAW_DEBUG_LINE__:db l,r

        R[l] = r;
    }

    // min skip
    // 0 -> can sel
    // 1 -> just did sel, can't sel again
    for (auto i = 0; i <= N; i++)
        for (auto j = 0; j < 2; j++)
            dp[i][j] = INF;
    dp[0][0] = dp[0][1] = 0;
    // dp
    for (auto i = 0; i < N; i++) {
        // nosel
        mina(dp[i+1][0], dp[i][1]+1);
        mina(dp[i+1][0], dp[i][0]+1);
        // sel
        mina(dp[R[i+1]][1], dp[i][0]);

        if (DEBUG) { cout<<"i="<<(i)<<", "; cout<<"dp[i][0]="<<(dp[i][0])<<", "; cout<<"dp[i][1]="<<(dp[i][1])<<", "; cout << endl; } //__RAW_DEBUG_LINE__:db i,dp[i][0],dp[i][1]
    }

    int ans = N - min(dp[N][0], dp[N][1]);
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