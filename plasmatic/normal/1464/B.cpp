// ./b-grime-zoo.yml
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

// Template is 1-indexed (by default).  Can be made 0-indexed by modifying Comp
// Default: Point increment and prefix sum query
struct Comp {
    using Data = int;
    const Data vdef = 0;
    void applyUpdate(Data &to, Data &v) { to += v; }
    int transformInd(int idx, int N) { return idx+1; }
};
template <typename Comp> struct BIT {
    using Data = typename Comp::Data; Comp C;
    int N; vector<Data> bit;
    void init(int n0) {
        N = n0;
        bit.assign(N + 1, C.vdef);
    }
    void update(int x, Data v) {
        x = C.transformInd(x, N);
        for (; x <= N; x += x & -x)
            C.applyUpdate(bit[x], v);
    }
    Data query(int x) {
        x = C.transformInd(x, N);
        Data res = C.vdef;
        for (; x; x -= x & -x)
            C.applyUpdate(res, bit[x]);
        return res;
    }
    Data query(int l, int r) {
        return query(r) - query(l-1);
    }
};

int N;
string s;
ll X, Y;

string flip(string s) {
    for (auto &c : s) {
        if (c == '0') c = '1';
        else c = '0';
    }
    return s;
}
ll cntinv(string s) {
    ll ans = 0, cnt1 = 0;
    for (auto c : s) {
        if (c == '0') ans += cnt1;
        else cnt1++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // X = reverse inversions (force max), Y = inversions (force min)
    cin >> (s) >> (X) >> (Y);
    N = SZ(s);

    // 0-1
    string t = s;
    for (auto &c : t) if (c == '?') c = '0';

    BIT<Comp> B[2];
    for (auto i = 0; i < 2; i++) B[i].init(N);
    for (auto i = 0; i < N; i++)
        B[t[i] - '0'].update(i, 1);

    ll cur = cntinv(t) * Y + cntinv(flip(t)) * X, ans = cur;
    for (auto i = 0; i < N; i++) {
        if (s[i] == '?') {
            cur -= Y * B[1].query(i-1) + X * B[1].query(i+1, N-1);
            cur += X * B[0].query(i-1) + Y * B[0].query(i+1, N-1);

            B[0].update(i, -1);
            B[1].update(i, 1);
            mina(ans, cur);
        }
    }

    // 1-0
    t = s;
    for (auto &c : t) if (c == '?') c = '1';

    for (auto i = 0; i < 2; i++) B[i].init(N);
    for (auto i = 0; i < N; i++)
        B[t[i] - '0'].update(i, 1);

    cur = cntinv(t) * Y + cntinv(flip(t)) * X, ans = min(ans, cur);
    for (auto i = 0; i < N; i++) {
        if (s[i] == '?') {
            cur -= X * B[0].query(i-1) + Y * B[0].query(i+1, N-1);
            cur += Y * B[1].query(i-1) + X * B[1].query(i+1, N-1);

            B[1].update(i, -1);
            B[0].update(i, 1);
            mina(ans, cur);
        }
    }

    cout << (ans) << '\n';

    return 0;
}