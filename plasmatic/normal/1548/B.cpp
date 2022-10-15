// ./b-integers-have-friends.yml
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

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

// Sparse table is 1-indexed
// Comparator for range MIN query
// When calling init, st should point to the start (0-indexed).  (i.e. if you stored data in A[1], A[2], ..., you should call init with (A+1, A+N+1)
// However, queries are 1-indexed and inclusive
struct Comp {
    using Data = ll;
    Data merge(Data a, Data b) { return gcd(a, b); }
};
template <class Comp> struct SparseTable {
    using Data = typename Comp::Data; Comp C;
    vector<vector<Data>> tb;
    int N, lg;
    template <typename It> void init(It st, It end) {
        N = end-st; lg = __lg(N);
        tb.assign(lg+1, vector<Data>(N+1));
        copy(st, end, tb[0].begin()+1);
        for (auto i = 1; i <= lg; i++) {
            int jmp = 1 << (i-1), end = N - (1<<i) + 1;
            for (auto j = 1; j <= end; j++)
                tb[i][j] = C.merge(tb[i-1][j], tb[i-1][j+jmp]);
        }
    }
    Data query(int l, int r) {
        int bit = __lg(r-l+1);
        return C.merge(tb[bit][l], tb[bit][r-(1<<bit)+1]);
    }
};

const int MN = 2e5 + 1;
int N;
ll A[MN], d[MN];

void solve() {
    cin >> N;
    for (auto i = 0; i < N; i++) {
        cin >> A[i];
        if (i > 0) d[i-1] = abs(A[i]-A[i-1]);
    }

    if (N == 1) {
        cout << (1) << '\n';
        return;
    }

    // cout<<"d=["; for(int __i=0; __i<(N-1); __i++)cout<<(d)[__i]<<", "; cout<<"], ";cout << endl; // db A:N-1:d

    int ans = 0, r = 0;
    SparseTable<Comp> st; st.init(d, d+N-1);
    for (auto i = 1; i < N; i++) {
        r = max(r, i-1);
        while (r+1 < N && st.query(i, r+1) > 1)
            r++;
        // cout<<"i="<<(i)<<", "; cout<<"r="<<(r)<<", "; cout << endl; // db i,r
        maxa(ans, r-i+1);
    }

    cout << (ans+1) << '\n';
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