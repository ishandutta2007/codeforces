#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

// using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 1e6 + 1000;
const int md = 1e9 + 123;
const int md2 = 1e9 + 7;

struct segment_tree {
    struct Node {
        int val = INFi;
        int upd = 0;

        void check(int x) {
            upd += x;
            val += x;
        }

        void combine(const Node &a, const Node &b) {
            val = min(a.val, b.val);
        }
    };

    int n{};
    vector<Node> tree{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
    }

    void push(int v) {
        if (!tree[v].upd) return;
        tree[v << 1].check(tree[v].upd);
        tree[v << 1 | 1].check(tree[v].upd);
        tree[v].upd = 0;
    }

    void upd(int v, int l, int r, int &lq, int &rq, int &x) {
        if (l >= rq || r <= lq) return;
        if (lq <= l && r <= rq) {
            tree[v].check(x);
            return;
        }
        push(v);
        upd(v << 1, l, (l + r) >> 1, lq, rq, x);
        upd((v << 1) + 1, (l + r) >> 1, r, lq, rq, x);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    void upd_pos(int v, int l, int r, int &pos, int &x) {
        if (l > pos || r <= pos) return;
        if (l + 1 == r) {
            tree[v].val = x;
            return;
        }
        push(v);
        upd_pos(v << 1, l, (l + r) >> 1, pos, x);
        upd_pos((v << 1) + 1, (l + r) >> 1, r, pos, x);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    int get(int v, int l, int r, int lq, int rq) {
        if (l >= rq || r <= lq) return INFi;
        if (lq <= l && r <= rq) {
            return tree[v].val;
        }
        push(v);
        return min(get(v << 1, l, (l + r) >> 1, lq, rq),
                   get((v << 1) + 1, (l + r) >> 1, r, lq, rq));
    }

    void upd(int lq, int rq, int x) {
        upd(1, 0, n, lq, rq, x);
    }

    void upd_pos(int pos, int x) {
        upd_pos(1, 0, n, pos, x);
    }

    int get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};

void solve() {
    int n;
    cin >> n;
    segment_tree st;
    st.build(n + 1);
    st.upd_pos(0, 0);
    int last = 0;
    range(_, n) {
        int x;
        cin >> x;
        if (x == last) {
            int mn = min({st.get(0, n + 1) + 1, st.get(x, x + 1)});
            st.upd_pos(x, mn);
            continue;
        }
        int mn = min({st.get(0, n + 1) + 1, st.get(x, x + 1)});
        st.upd(0, n + 1, 1);
        st.upd_pos(last, mn);
        last = x;
    }
    cout << st.get(0, n + 1);
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