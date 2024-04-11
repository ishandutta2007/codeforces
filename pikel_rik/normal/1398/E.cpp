#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

template <typename T> class SegmentTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> t;
    T e;
    F f;
    SegmentTree() : n(), t(), e(), f() {}

    template <typename U> void build(const U& arr, int _n, T _e, F _f) {
        n = _n;
        t.resize(4 * n + 4);
        e = _e;
        f = _f;
        build(arr, 1, 0, n - 1);
    }

    template <typename U> void build(const U& arr, int i, int l, int r) {
        if (l == r) {
            t[i] = T(arr[l]);
            return;
        }

        int mid = (l + r) >> 1;
        build(arr, i << 1, l, mid);
        build(arr, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    template <typename U> void update(const int& idx, const U& val) {
        update(idx, val, 1, 0, n - 1);
    }

    template <typename U> void update(const int& idx, const U& val, int i, int l, int r) {
        if (l == r) {
            t[i] = T(val);
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            update(idx, val, i << 1, l, mid);
        else update(idx, val, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    T query(int ql, int qr) {
        return query(ql, qr, 1, 0, n - 1);
    }

    T query(int ql, int qr, int i, int l, int r) {
        if (ql > r or qr < l)
            return e;
        if (ql <= l and r <= qr)
            return t[i];
        int mid = (l + r) >> 1;
        T x = query(ql, qr, i << 1, l, mid), y = query(ql, qr, i << 1 | 1, mid + 1, r);
        return f(x, y);
    }

    int query(int k) {
        return query(k, 1, 0, n - 1);
    }

    int query(int k, int i, int l, int r) {
        if (l == r)
            return l;

        int mid = (l + r) >> 1;
        if (t[i << 1].cnt >= k)
            return query(k, i << 1, l, mid);
        return query(k - t[i << 1].cnt, i << 1 | 1, mid + 1, r);
    }
};

pair<int, int> q[N];

struct node {
    int cnt;
    ll sum;
    node(): cnt(), sum() {}
    node(int x): cnt(x > 0), sum(x) {}
};

node combine(const node& x, const node& y) {
    node res;
    res.cnt = x.cnt + y.cnt;
    res.sum = x.sum + y.sum;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> q[i].first >> q[i].second;
        if (q[i].second > 0)
            v.push_back(q[i].second);
    }

    sort(all(v));
    v.resize(unique(all(v)) - v.begin());

    SegmentTree<node> st;
    st.build(vector<int>(v.size()), v.size(), node(), combine);

    set<int> s;
    for (int i = 0; i < n; i++) {
        int t = q[i].first, d = q[i].second;
        int idx = lower_bound(all(v), abs(d)) - v.begin();

        if (t == 0) {
            if (d > 0)
                st.update(idx, d);
            else st.update(idx, 0);
        }
        else {
            if (d > 0) {
                s.insert(d);
                st.update(idx, d);
            }
            else {
                s.erase(-d);
                st.update(idx, 0);
            }
        }

        node ans = st.query(0, v.size() - 1);

        if (ans.cnt == 0)
            cout << ans.sum << "\n";
        else if (ans.cnt == s.size())
            cout << 2 * ans.sum - *s.begin() << "\n";
        else if (s.size() == 0)
            cout << ans.sum << "\n";
        else {
            int k = st.query(ans.cnt - s.size() + 1);

            if (st.query(k, k).sum <= *s.begin()) {
                k = st.query(ans.cnt - s.size());
                ans.sum -= *s.begin();
            }
            cout << ans.sum + st.query(k, v.size() - 1).sum << "\n";
        }
    }
    return 0;
}