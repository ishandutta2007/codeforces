#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 4e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct segment_tree {
    struct Node {
        ll sum = 0;
        int mn = 0, s_mn = INFi;
        int cnt = 0;
        int upd = 0;

        void combine(const Node &a, const Node &b) {
            mn = min(a.mn, b.mn);
            cnt = a.cnt + b.cnt;
            s_mn = INFi;
            if (b.mn != mn) {
                cnt -= b.cnt;
                s_mn = b.mn;
            } else if (a.mn != mn) {
                s_mn = a.mn;
                cnt -= a.cnt;
            }
            s_mn = min(s_mn, min(a.s_mn, b.s_mn));
            sum = a.sum + b.sum;
        }

        void check(int &val) {
            if (mn >= val) return;
            sum += 1ll * cnt * (val - mn);
            mn = val;
            upd = val;
        }
    };

    void push(int v) {
        tree[v << 1].check(tree[v].upd);
        tree[(v << 1) + 1].check(tree[v].upd);
    }

    vector<Node> tree{};
    int n{};

    void build(int k, vector<int> &a) {
        n = k;
        tree.resize(n * 4);
        make(1, 0, n, a);
    }

    void make(int v, int l, int r, vector<int> &a) {
        if (l + 1 == r) {
            tree[v].cnt = 1;
            tree[v].sum = a[l];
            tree[v].mn = a[l];
            return;
        }
        make(v << 1, l, (l + r) >> 1, a);
        make((v << 1) + 1, (l + r) >> 1, r, a);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    void updmax(int v, int l, int r, int &lq, int &rq, int &val) {
        if (tree[v].mn >= val) return;
        if (lq <= l && r <= rq && tree[v].s_mn > val) {
            tree[v].check(val);
            return;
        }
        push(v);
        int mid = (l + r) >> 1;
        if (mid > lq) updmax(v << 1, l, mid, lq, rq, val);
        if (rq > mid) updmax((v << 1) + 1, mid, r, lq, rq, val);
        tree[v].combine(tree[v << 1], tree[(v << 1) + 1]);
    }

    ll get(int v, int l, int r, int &lq, int &rq) {
        if (lq <= l && r <= rq) {
            return tree[v].sum;
        }
        int mid = (l + r) >> 1;
        ll res = 0;
        push(v);
        if (mid > lq) res += get(v << 1, l, mid, lq, rq);
        if (rq > mid) res += get((v << 1) + 1, mid, r, lq, rq);
        return res;
    }

    int find_sum(int v, int l, int r, ll x) {
        if (tree[v].sum <= x) return r;
        if (x == 0 || l + 1 == r) return l;
        push(v);
        ll k = tree[v << 1].sum;
        if (k >= x) return find_sum(v << 1, l, (l + r) >> 1, x);
        else return find_sum(v << 1 | 1, (l + r) >> 1, r, x - k);
    }

    int find_pos(int v, int l, int r, ll x) {
        if (tree[v].mn > x) return r;
        if (l + 1 == r) return l;
        push(v);
        ll k = tree[v << 1].mn;
        if (k <= x) return find_pos(v << 1, l, (l + r) >> 1, x);
        else return find_pos(v << 1 | 1, (l + r) >> 1, r, x);
    }

    ll get(int lq, int rq) {
        auto res = get(1, 0, n, lq, rq);
        return res;
    }

    void updmax(int lq, int rq, int val) {
        updmax(1, 0, n, lq, rq, val);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    segment_tree st;
    st.build(n, a);
    range(_, q) {
        int t, x;
        ll y;
        cin >> t >> x >> y;
        x--;
        if (t == 1) {
            st.updmax(0, x + 1, y);
        } else {
            int res = 0;
            while (x != n) {
                ll s = 0;
                if (x != 0) s = st.get(0, x);
                s += y;
                int j = st.find_sum(1, 0, n, s);
                res += j - x;
                if (j != 0) s -= st.get(0, j);
                y = s;
                x = max(j, st.find_pos(1, 0, n, y));
            }
            cout << res << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}