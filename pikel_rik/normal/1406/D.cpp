#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

template <typename T>
class SegmentTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> t;
    T e;
    F f;
    SegmentTree() : n(), t(), e(), f() {}

    template <typename U>
    SegmentTree(const U& arr, int n, T e, F f): n(n), t(4 * n), e(e), f(f) {
        build(arr, 1, 0, n - 1);
    }

    template <typename U>
    void build(const U& arr, int i, int l, int r) {
        if (l == r) {
            t[i] = T(arr[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(arr, i << 1, l, mid);
        build(arr, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    template <typename U>
    void update(int idx, U val) {
        updateHelper(idx, val, 1, 0, n - 1);
    }

    template <typename U>
    void updateHelper(int idx, U val, int i, int l, int r) {
        if (l == r) {
            t[i] = T(t[i].pos + t[i].neg + val);
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            updateHelper(idx, val, i << 1, l, mid);
        else updateHelper(idx, val, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    T query(int ql, int qr) {
        return queryHelper(ql, qr, 1, 0, n - 1);
    }

    T queryHelper(int ql, int qr, int i, int l, int r) {
        if (ql > r or qr < l)
            return e;
        if (ql <= l and r <= qr)
            return t[i];
        int mid = (l + r) >> 1;
        T x = queryHelper(ql, qr, i << 1, l, mid), y = queryHelper(ql, qr, i << 1 | 1, mid + 1, r);
        return f(x, y);
    }
};

struct node {
    ll pos, neg;
    node(): pos(), neg() {}
    node(ll x): pos(), neg() {
        if (x >= 0)
            pos = x;
        else neg = x;
    }
};

node combine(const node& a, const node& b) {
    node res;
    res.pos = a.pos + b.pos;
    res.neg = a.neg + b.neg;
    return res;
}

int n, a[N], diff[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        cout << (a[0] + (a[0] > 0)) / 2 << '\n';

        int q;
        cin >> q;

        while (q--) {
            int l, r, x;
            cin >> l >> r >> x;
            a[0] += x;
            cout << (a[0] + (a[0] > 0)) / 2 << '\n';
        }
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        diff[i] = a[i + 1] - a[i];
    }

    SegmentTree<node> st(diff, n - 1, node(), combine);
    ll start = a[0];
    {
        ll ans = start + st.t[1].pos;
        cout << (ans + (ans > 0)) / 2 << '\n';
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x; --l; --r;

        if (l > 0)
            st.update(l - 1, x);
        else start += x;

        if (r < n - 1)
            st.update(r, -x);

        ll ans = start + st.t[1].pos;
        cout << (ans + (ans > 0)) / 2 << '\n';
    }
    return 0;
}