#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
//using namespace __gnu_pbds;


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
const int maxN = 2e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct segment_tree {
    struct Node {
        ll ans;
        int lc, rc;
        int sz;

        void combine(const Node &a, const Node &b) {
            ans = a.ans + b.ans;
            lc = a.lc + (a.lc == a.sz ? b.lc : 0);
            rc = b.rc + (b.rc == b.sz ? a.rc : 0);
            ans += 1ll * a.rc * b.lc;
            sz = a.sz + b.sz;
        }

        void check(int x) {
            ans = x;
            lc = x;
            rc = x;
            sz = 1;
        }

        Node() : ans(0), lc(0), rc(0), sz(0) {}
    };

    vector<Node> tree{};
    int n{};

    void build(int k, vector<int> &a) {
        n = k;
        tree.resize(n * 4);
        make(1, 0, n, a);
    }

    void make(int v, int l, int r, vector<int> &a) {
        if (l + 1 == r) {
            tree[v].check(a[l]);
            return;
        }
        make(v << 1, l, (l + r) >> 1, a);
        make(v << 1 | 1, (l + r) >> 1, r, a);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    void upd(int v, int l, int r, int &pos, int &val) {
        if (l > pos || r <= pos) return;
        if (l + 1 == r) {
            tree[v].check(val);
            return;
        }
        upd(v << 1, l, (l + r) >> 1, pos, val);
        upd(v << 1 | 1, (l + r) >> 1, r, pos, val);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    Node get(int v, int l, int r, int lq, int rq) {
        if (l >= rq || r <= lq) return Node();
        if (lq <= l && r <= rq) return tree[v];
        auto a = get(v << 1, l, (l + r) >> 1, lq, rq);
        auto b = get(v << 1 | 1, (l + r) >> 1, r, lq, rq);
        Node c;
        c.combine(a, b);
        return c;
    }

    ll get(int lq, int rq) {
        return get(1, 0, n, lq, rq).ans;
    }

    void upd(int pos, int val) {
        upd(1, 0, n, pos, val);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> b(n);
    range(i, n) {
        cin >> a[i];
    }
    range(i, n - 1) {
        b[i] = (a[i + 1] >= a[i]);
    }
    segment_tree st;
    st.build(n, b);
    range(_, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            x--;
            a[x] = y;
            if (x > 0) {
                b[x - 1] = (a[x] >= a[x - 1]);
                st.upd(x - 1, b[x - 1]);
            }
            if (x + 1 < n) {
                b[x] = (a[x + 1] >= a[x]);
                st.upd(x, b[x]);
            }
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << r - l + st.get(l, r - 1) << '\n';
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