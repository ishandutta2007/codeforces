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
        int val = 0;
        int upd = -1;
        int len = 0;

        void check(int x) {
            upd = x;
            val = x * len;
        }

        void combine(const Node &a, const Node &b) {
            val = a.val + b.val;
        }
    };

    int n{};
    vector<Node> tree{};

    void build(int k, vector<int> &a) {
        n = k;
        tree.resize(n * 4);
        make(1, 0, n, a);
    }

    void make(int v, int l, int r, vector<int> &a) {
        if (l + 1 == r) {
            tree[v].val = a[l];
            tree[v].len = 1;
            return;
        }
        make(v << 1, l, (l + r) >> 1, a);
        make(v << 1 | 1, (l + r) >> 1, r, a);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
        tree[v].len = tree[v << 1].len + tree[v << 1 | 1].len;
    }

    void push(int v) {
        if (tree[v].upd == -1) return;
        tree[v << 1].check(tree[v].upd);
        tree[v << 1 | 1].check(tree[v].upd);
        tree[v].upd = -1;
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

    int get(int v, int l, int r, int lq, int rq) {
        if (l >= rq || r <= lq) return 0;
        if (lq <= l && r <= rq) {
            return tree[v].val;
        }
        push(v);
        return get(v << 1, l, (l + r) >> 1, lq, rq) +
               get((v << 1) + 1, (l + r) >> 1, r, lq, rq);
    }

    void upd(int lq, int rq, int x) {
        upd(1, 0, n, lq, rq, x);
    }

    int get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    string f;
    cin >> f;
    vector<pair<int, int>> qs(q);
    range(i, q) cin >> qs[i].first >> qs[i].second;
    segment_tree st;
    vector<int> a(n, 0);
    range(i, n) if (f[i] == '1') a[i] = 1;
    st.build(n, a);
    for(int i = q - 1; i >= 0; --i) {
        int len = qs[i].second - qs[i].first + 1;
        int sw = st.get(0, qs[i].second) - st.get(0, qs[i].first - 1);
        if (sw * 2 == len) {
            cout << "NO\n";
            return;
        }
        if (sw * 2 > len) {
            st.upd(qs[i].first - 1, qs[i].second, 1);
        } else {
            st.upd(qs[i].first - 1, qs[i].second, 0);
        }
    }
    range(i, n) {
        int x = 0;
        if (s[i] == '1') x = 1;
        if (st.get(i, i + 1) != x) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}