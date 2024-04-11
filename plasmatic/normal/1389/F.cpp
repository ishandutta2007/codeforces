// f-bicolored-segments.yml
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

struct Seg {
    int l, r, c;
    bool operator<(const Seg &o) const {
        return r == o.r ? l < o.l : r < o.r;
    }
};
istream& operator>>(istream &in, Seg &o) {
    in >> o.l >> o.r >> o.c;
    return in;
}

const int MN = 2e5 + 1;
int N,
    dp[MN];
Seg segs[MN];

const int MS = MN * 2 + 10;
#define MID int mid = (l + r) / 2, lhs = i + 1, rhs = i + (mid - l + 1) * 2;
struct SegTree {
    int seg[MS * 2], lazy[MS * 2];
    void push(int i, int l, int r) {
        if (lazy[i]) {
            MID;
            seg[i] += lazy[i];
            if (l != r) {
                lazy[lhs] += lazy[i];
                lazy[rhs] += lazy[i];
            }
            lazy[i] = 0;
        }
    }
    int upd(int ql, int qr, int v, int i = 1, int l = 1, int r = 2 * N + 2) {
        push(i, l, r);
        if (ql > r || qr < l) return seg[i];
        if (l >= ql && r <= qr) {
            lazy[i] = v;
            push(i, l, r);
            return seg[i];
        }
        MID;
        return seg[i] = max(upd(ql, qr, v, lhs, l, mid), upd(ql, qr, v, rhs, mid + 1, r));
    }
    int upd1(int q, int v, int i = 1, int l = 1, int r = 2 * N + 2) {
        push(i, l, r);
        if (q > r || q < l) return seg[i];
        if (l == q && r == q) return seg[i] = v;
        MID;
        return seg[i] = max(upd1(q, v, lhs, l, mid), upd1(q, v, rhs, mid + 1, r));
    }
    int query(int ql, int qr, int i = 1, int l = 1, int r = 2 * N + 2) {
        if (ql > r || qr < l) return -INF;
        push(i, l, r);
        if (l >= ql && r <= qr) return seg[i];
        MID;
        return max(query(ql, qr, lhs, l, mid), query(ql, qr, rhs, mid + 1, r));
    }
} qtree[2];

vector<int> ranks;
int get(int x) {
    return lower_bound(all(ranks), x) - ranks.begin() + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    for (auto i = 1; i <= N; i++) {
        cin >> (segs[i]); 
        segs[i].c--;
        ranks.pb(segs[i].l);
        ranks.pb(segs[i].r);
    }
    sort(segs + 1, segs + N + 1);
    ranks.pb(-INF);
    sort(all(ranks));
    ranks.resize(unique(all(ranks)) - ranks.begin());

    for (auto i = 1; i <= N; i++) {
        auto &s = segs[i];
        qtree[s.c ^ 1].upd(1, get(s.l) - 1, 1);
        dp[i] = qtree[s.c ^ 1].query(1, get(s.l) - 1);
        qtree[s.c].upd1(get(s.r), dp[i]);
    }

    int ans = 0;
    for (auto i = 0; i < 2; i++) {
        maxa(ans, qtree[i].query(1, 2 * N)); }
    cout << (ans) << '\n';

    return 0;
}