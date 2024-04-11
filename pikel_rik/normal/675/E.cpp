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
            t[i] = T(arr[l], l);
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
            t[i] = T(val, l);
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
    int mx, idx;
    node(): mx(), idx(-1) {}
    node(int x, int i): mx(x), idx(i) {}
};

node combine(const node& a, const node& b) {
    if (a.idx < 0)
        return b;
    if (b.idx < 0)
        return a;

    if (a.mx > b.mx)
        return a;
    return b;
}

int n, a[N];
ll dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++) cin >> a[i], --a[i];

    SegmentTree<node> st(a, n, node(), combine);

    for (int i = n - 2; i >= 0; i--) {
        int idx = st.query(i + 1, a[i]).idx;
        dp[i] = idx - i + n - 1 - a[i] + dp[idx];
    }

    cout << accumulate(dp, dp + n, 0ll) << '\n';
    return 0;
}