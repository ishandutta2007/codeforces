// ./f-reverse-and-swap.yml
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

const int MN = 262144 + 10, LG = 18 + 1;
int N, Q, lg,
    val[MN];

int gSwapc[LG];
#define MID int mid = (l + r) / 2, lhs = i + 1, rhs = i + (mid - l + 1) * 2;

struct node {
    int l, r;
    ll sum = 0;
    int lazy = 0;
} seg[MN*2];
int ptr = 0;

ll build(int &rt, int l = 1, int r = N) {
    if (!rt) rt = ++ptr;
    auto &n = seg[rt];
    if (l == r) return n.sum = val[l];
    int mid = (l + r) / 2;
    return n.sum = build(n.l, l, mid) + build(n.r, mid+1, r);
}
void push(int &rt, int lev) {
    auto &n = seg[rt];
    if (n.lazy != gSwapc[lev]) {
        if ((gSwapc[lev] - n.lazy) & 1)
            swap(n.l, n.r);
        n.lazy = gSwapc[lev];
    }
}
ll upd(int &rt, int q, int v, int l = 1, int r = N, int lev = lg) {
    push(rt, lev);
    auto &n = seg[rt];
    if (q > r || q < l) return n.sum;
    if (q == l && q == r) return n.sum = v;
    int mid = (l + r) / 2;
    return n.sum = upd(n.l, q, v, l, mid, lev-1) + upd(n.r, q, v, mid+1, r, lev-1);
}
ll query(int &rt, int ql, int qr, int l = 1, int r = N, int lev = lg) {
    push(rt, lev);
    if (ql > r || qr < l) return 0;
    auto &n = seg[rt];
    if (ql <= l && qr >= r) return n.sum;
    int mid = (l + r) / 2;
    return query(n.l, ql, qr, l, mid, lev-1) + query(n.r, ql, qr, mid+1, r, lev-1);
}

int rt = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (lg) >> (Q);
    N = 1 << lg;
    for (auto i = 1; i <= N; i++)
        cin >> (val[i]);
    build(rt);
    
    while (Q--) {
        int T;
        cin >> T;
        if (T == 1) {
            int q, v;
            cin >> q >> v;
            upd(rt, q, v);
        }
        else if (T == 2) {
            int k;
            cin >> k;
            for (auto i = 1; i <= k; i++)
                gSwapc[i]++;
        }
        else if (T == 3) {
            int k;
            cin >> k;
            gSwapc[k+1]++;
        }
        else if (T == 4) {
            int l, r;
            cin >> l >> r;
            ll ans = query(rt, l, r);
            cout << (ans) << '\n';
        }
    }

    return 0;
}