#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

//using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 1e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

struct segment_tree {
    struct Node {
        ll val = 0;
        ll upd = 0;
        int sz = 0;

        void combine(const Node &a, const Node &b) {
            val = a.val + b.val;
            sz = a.sz + b.sz;
        }

        void check(int x) {
            upd += x;
            val += 1ll * sz * x;
        }
    };

    vector<Node> tree{};
    int n{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
        make(1, 0, n);
    }

    void make(int v, int l, int r) {
        if (l + 1 == r) {
            tree[v].sz = 1;
            return;
        }
        make(v << 1, l, (l + r) >> 1);
        make(v << 1 | 1, (l + r) >> 1, r);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    void push(int v) {
        if (!tree[v].upd) return;
        tree[v << 1].check(tree[v].upd);
        tree[v << 1 | 1].check(tree[v].upd);
        tree[v].upd = 0;
    }

    void upd(int v, int l, int r, int &lq, int &rq, int &val) {
        if (lq >= r || l >= rq) return;
        if (lq <= l && r <= rq) {
            tree[v].check(val);
            return;
        }
        push(v);
        int mid = (l + r) >> 1;
        upd(v << 1, l, mid, lq, rq, val);
        upd((v << 1) + 1, mid, r, lq, rq, val);
        tree[v].combine(tree[v << 1], tree[(v << 1) + 1]);
    }

    int get(int v, int l, int r, int k) {
        if (tree[v].val < k) return INFi;
        if (l + 1 == r) {
            return l;
        }
        push(v);
        if (tree[v << 1].val >= k) {
            return get(v << 1, l, (l + r) >> 1, k);
        } else {
            return get(v << 1 | 1, (l + r) >> 1, r, k - tree[v << 1].val);
        }
    }

    int get(int k) {
        auto res = get(1, 0, n, k);
        return res;
    }

    void upd(int lq, int rq, int val) {
        upd(1, 0, n, lq, rq, val);
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    sort(rall(a));
    segment_tree st;
    st.build(5e5);
    st.upd(0, 1, 1);
    int ans = INFi;
    for (auto &l : a) {
        ans = min(ans, st.get(k));
        int d = st.get(1);
        st.upd(d, d + 1, -1);
        int e = (l - 1) / 2;
        int w = (l - 1) - e;
        if (e) st.upd(d + 2, d + 2 + e, 1);
        if (w) st.upd(d + 2, d + 2 + w, 1);
    }
    ans = min(ans, st.get(k));
    if (ans == INFi) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}