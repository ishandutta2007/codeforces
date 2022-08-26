#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 1e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct segment_tree {
    struct Node {
        ll val;
        ll upd;

        Node() : val(0), upd(0) {}

        void check(ll x) {
            val += x;
            upd += x;
        }

        void combine(const Node &a, const Node &b) {
            val = max(a.val, b.val) + upd;
        }
    };

    int n{};
    vector<Node> tree{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
    }


    void upd(int v, int l, int r, int lq, int rq, ll x) {
        if (l >= rq || r <= lq) return;
        if (lq <= l && r <= rq) {
            tree[v].check(x);
            return;
        }
        upd(v << 1, l, (l + r) >> 1, lq, rq, x);
        upd((v << 1) + 1, (l + r) >> 1, r, lq, rq, x);
        tree[v].combine(tree[v << 1], tree[(v << 1) + 1]);
    }

    ll get(int v, int l, int r, ll add) {
        if (tree[v].val + add <= 0) return INFi;
        if (l + 1 == r) return l;
        add += tree[v].upd;
        int x = get(v << 1 | 1, (l + r) >> 1, r, add);
        if (x == INFi) x = get(v << 1, l, (l + r) >> 1, add);
        return x;
    }

    void upd(int lq, int rq, ll x) {
        upd(1, 0, n, lq, rq, x);
    }

    ll get() {
        return get(1, 0, n, 0);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    segment_tree st;
    st.build(1e6 + 5);
    st.upd(0, 1e6 + 5, -INFi);
    vector<int> a(n), b(m);
    map<int, int> cnt;
    range(i, n) {
        cin >> a[i];
        st.upd(0, a[i] + 1, 1);
        if (cnt[a[i]] == 0) st.upd(a[i], a[i] + 1, INFi);
        cnt[a[i]]++;
    }
    range(i, m) {
        cin >> b[i];
        st.upd(0, b[i] + 1, -1);
    }
    int q; cin >> q;
    range(_, q) {
        int t; cin >> t;
        int i, x; cin >> i >> x;
        i--;
        if (t == 1) {
            st.upd(0, a[i] + 1, -1);
            cnt[a[i]]--;
            if (cnt[a[i]] == 0) st.upd(a[i], a[i] + 1, -INFi);
            a[i] = x;
            cnt[a[i]]++;
            if (cnt[a[i]] == 1) st.upd(a[i], a[i] + 1, INFi);
            st.upd(0, a[i] + 1, 1);
        } else {
            st.upd(0, b[i] + 1, 1);
            b[i] = x;
            st.upd(0, b[i] + 1, -1);
        }
        ll w = st.get();
        if (w == INFi) {
            cout << "-1\n";
        } else {
            cout << w << '\n';
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