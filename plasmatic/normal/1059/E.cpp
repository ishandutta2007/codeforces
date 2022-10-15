// e-split-the-tree.yml
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
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

// Thanks wesley thanks wesley thanks wesley
// RMQ + Increment query
struct Comp {
    using Data = int;
    using Lazy = int;
    const Data vdef = INF;
    const Lazy ldef = 0;
    Data merge(Data l, Data r) { return min(l, r); }
    Lazy mergeLazy(Lazy l, Lazy r) { return l + r; }
    void applyLazy(Data &to, Lazy v, int l, int r) { to += v; }
};
#define MID int mid = (l + r) / 2, lhs = i + 1, rhs = i + (mid - l + 1) * 2;
template <class Comp> struct LazySegmentTree {
    using Data = typename Comp::Data; using Lazy = typename Comp::Lazy; Comp C;
    int N;
    vector<Data> seg; vector<Lazy> lazy;
    void init(int n0) {
        N = n0;
        seg.assign(2 * N + 2, C.vdef);
        lazy.assign(2 * N + 2, C.ldef);
    }
    void push(int i, int l, int r) {
        if (lazy[i] != C.ldef) {
            MID;
            C.applyLazy(seg[i], lazy[i], l, r);
            if (l != r) {
                lazy[lhs] = C.mergeLazy(lazy[lhs], lazy[i]);
                lazy[rhs] = C.mergeLazy(lazy[rhs], lazy[i]);
            }
            lazy[i] = C.ldef;
        }
    }
    Data _query(int ql, int qr, int i, int l, int r) {
        if (ql > r || qr < l) return C.vdef;
        push(i, l, r);
        if (l >= ql && r <= qr) return seg[i];
        MID;
        return C.merge(_query(ql, qr, lhs, l, mid), _query(ql, qr, rhs, mid + 1, r));
    }
    Data _update(int ql, int qr, Lazy v, int i, int l, int r) {
        push(i, l, r);
        if (ql > r || qr < l) return seg[i];
        if (l >= ql && r <= qr) {
            lazy[i] = v;
            push(i, l, r);
            return seg[i];
        }
        MID;
        return seg[i] = C.merge(_update(ql, qr, v, lhs, l, mid), _update(ql, qr, v, rhs, mid + 1, r));
    }
    Data _updatePoint(int q, Data v, int i, int l, int r) {
        push(i, l, r);
        if (q > r || q < l) return seg[i];
        if (l == q && r == q) return seg[i] = v;
        MID;
        return seg[i] = C.merge(_updatePoint(q, v, lhs, l, mid), _updatePoint(q, v, rhs, mid + 1, r));
    }
    Data query(int ql, int qr) { return _query(ql, qr, 1, 1, N); }
    void update(int ql, int qr, Lazy v) { _update(ql, qr, v, 1, 1, N); }
    void updatePoint(int q, Data v) { _updatePoint(q, v, 1, 1, N); }
};

const int MN = 2e5 + 1;
int N, L;
ll S,
   val[MN];
vector<int> g[MN];

// blift
const int LG = 19;
int cord = 0,
    dep[MN], tb[LG][MN], ord[MN], ordR[MN];
ll sum[LG][MN];

int leafc = 0;
void dfsInit(int c, int p, int cdep) {
    dep[c] = cdep;
    tb[0][c] = p;
    sum[0][c] = val[c];
    ord[c] = ++cord;
    for (int to : g[c])
        dfsInit(to, c, cdep + 1);
    if (g[c].empty()) {
        g[c].pb(++leafc);
        dep[leafc] = cdep + 1;
        tb[0][leafc] = c;
        sum[0][leafc] = 0;
        ord[leafc] = ordR[leafc] = ++cord;
    }
    ordR[c] = cord;
}

int dp[MN];
LazySegmentTree<Comp> seg;
vector<int> rem[MN];
void dfs(int c) {
    int rbound = min(dep[c], L), cur = tb[0][c], upv = 1;
    ll csum = val[tb[0][c]];
    for (auto i = LG-1; i >= 0; i--) {
        int bit = 1 << i;
        // if (i<=5&&c==7){
        //     cout<<"rbound="<<(rbound)<<", "; cout<<"cur="<<(cur)<<", "; cout<<"upv="<<(upv)<<", "; cout<<"csum="<<(csum)<<", "; cout<<"bit="<<(bit)<<", "; cout << endl; // db rbound,cur,upv,csum,bit
        //     cout<<"csum+sum[i][cur]="<<(csum+sum[i][cur])<<", "; cout<<"upv+bit="<<(upv+bit)<<", "; cout << endl; // db csum+sum[i][cur],upv+bit
        // }
        if (csum + sum[i][tb[0][cur]] <= S && upv + bit <= rbound) {
            csum += sum[i][tb[0][cur]];
            upv += bit;
            cur = tb[i][cur];
        }
    }
    if (cur != -1) rem[cur].pb(c);
    int dpsum = 0;
    for (auto to : g[c]) {
        dfs(to);
        dpsum += dp[to];
    }
    seg.update(ord[c], ordR[c], dpsum);
    if (g[c].empty()) // leaf node
        dp[c] = 0;
    else // not leaf node
        dp[c] = 1 + seg.query(ord[c], ordR[c]);
    seg.updatePoint(ord[c], dp[c]);
    seg.update(ord[c], ordR[c], -dp[c]);
    // cout<<"c="<<(c)<<", "; cout<<"dp[c]="<<(dp[c])<<", "; cout<<"cur="<<(cur)<<", "; cout << endl; // db c,dp[c],cur
    for (auto x : rem[c])
        seg.updatePoint(ord[x], INF);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (L) >> (S);
    for (auto i = 1; i <= N; i++) {
        cin >> (val[i]);
        if (val[i] > S) {
            cout << (-1) << '\n';
            return 0;
        }
    }
    for (auto i = 2; i <= N; i++) {
        int p;
        cin >> p;
        g[p].pb(i);
    }

    leafc = N;
    dfsInit(1, -1, 0);
    for (auto i = 1; i < LG; i++) {
        for (auto j = 1; j <= leafc; j++) {
            int pp = tb[i - 1][j];
            tb[i][j] = pp == -1 ? pp : tb[i - 1][pp];
            sum[i][j] = pp == -1 ? LLINF : (sum[i - 1][j] + sum[i - 1][pp]);
            // if (i<5) {
            //     cout<<"i="<<(i)<<", "; cout<<"j="<<(j)<<", "; cout<<"tb[i][j]="<<(tb[i][j])<<", "; cout<<"sum[i][j]="<<(sum[i][j])<<", "; cout << endl; // db i,j,tb[i][j],sum[i][j]
            // }
        }
    }

    seg.init(leafc);
    for (auto i = 1; i <= leafc; i++)
        seg.updatePoint(i, 0);
    dfs(1);
    cout << (dp[1]) << '\n';

    return 0;
}