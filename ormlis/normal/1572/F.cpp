#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 3e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct fenwick {
    int n{};
    vector<ll> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, ll x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    ll get(int i) {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    ll get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

struct SmartFenwick {
    fenwick f1, f2;

    void build(int n) {
        f1.build(n);
        f2.build(n);
    }

    void upd(int l, int r, ll x) {
        // [l, r]
        f1.upd(l, x);
        f1.upd(r, -x);
        f2.upd(l, -1ll * (l - 1) * x);
        f2.upd(r, 1ll * r * x);
    }
    ll get(int r) {
        return 1ll * f1.get(r) * r + f2.get(r);
    }

    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
} SF;

struct segment_tree_beats {
    struct Node {
        int mx = 0, s_mx = -INFi;
        int cnt = 0;
        int upd = INFi;

        void combine(const Node &a, const Node &b) {
            mx = max(a.mx, b.mx);
            cnt = a.cnt + b.cnt;
            s_mx = -INFi;
            if (b.mx != mx) {
                cnt -= b.cnt;
                s_mx = b.mx;
            } else if (a.mx != mx) {
                s_mx = a.mx;
                cnt -= a.cnt;
            }
            s_mx = max(s_mx, max(a.s_mx, b.s_mx));
        }

        void check(int x, int l, int r, bool upd2 = false) {
            if (mx <= x) return;
            if (upd2) {
                SF.upd(x + 1, mx, -cnt);
            }
            mx = upd = x;
        }
    };

    void push(int v, int l, int r) {
        if (tree[v].upd == INFi) return;
        tree[v << 1].check(tree[v].upd, l, (l + r) >> 1);
        tree[(v << 1) + 1].check(tree[v].upd, (l + r) >> 1, r);
        tree[v].upd = INFi;
    }

    vector<Node> tree{};
    int n{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
        make(1, 0, n);
    }

    void make(int v, int l, int r) {
        if (l + 1 == r) {
            tree[v].mx = l;
            tree[v].cnt = 1;
            return;
        }
        make(v << 1, l, (l + r) >> 1);
        make((v << 1) + 1, (l + r) >> 1, r);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    void updmin(int v, int l, int r, int &lq, int &rq, int &val) {
        if (tree[v].mx <= val) return;
        if (lq <= l && r <= rq && tree[v].s_mx < val) {
            tree[v].check(val, lq, rq, true);
            return;
        }
        push(v, l, r);
        int mid = (l + r) >> 1;
        if (mid > lq) updmin(v << 1, l, mid, lq, rq, val);
        if (rq > mid) updmin((v << 1) + 1, mid, r, lq, rq, val);
        tree[v].combine(tree[v << 1], tree[(v << 1) + 1]);
    }

    void upd_pos(int v, int l, int r, int i, int x) {
        if (l + 1 == r) {
            SF.upd(l, tree[v].mx, -1);
            tree[v].mx = x;
            tree[v].cnt = 1;
            SF.upd(l, tree[v].mx, 1);
            return;
        }
        push(v, l, r);
        int mid = (l + r) >> 1;
        if (mid > i) upd_pos(v << 1, l, mid, i, x);
        else upd_pos((v << 1) + 1, mid, r, i, x);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    void updmin(int lq, int rq, int val) {
        if (lq >= rq) return;
        updmin(1, 0, n, lq, rq, val);
    }

    void updpos(int i, int val) {
        upd_pos(1, 0, n, i, val);
    }
} ST;

void solve() {
    int n, q; cin >> n >> q;
    SF.build(n);
    ST.build(n);
    SF.upd(0, n - 1, 1);
    range(_, q) {
        int p; cin >> p;
        int c, g; cin >> c >> g;
        if (p == 1) {
            ST.updpos(c - 1, g - 1);
            ST.updmin(0, c - 1, c - 2);
        } else {
            int l = c - 1;
            int r = g - 1;
            cout << SF.get(l, r) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}