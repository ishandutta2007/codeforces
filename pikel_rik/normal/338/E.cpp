#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 150000 + 5;

template <typename T>
class SegmentTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> t;
    vector<int> lazy;
    T e;
    F f;
    SegmentTree() : n(), t(), lazy(), e(), f() {}

    template <typename U>
    SegmentTree(const U& arr, int n, T e, F f): n(n), t(4 * n), lazy(4 * n), e(e), f(f) {
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

    void push (int x, int l, int r) {
        if (lazy[x]) {
            t[x << 1] += lazy[x];
            t[x << 1 | 1] += lazy[x];
            lazy[x << 1] += lazy[x];
            lazy[x << 1 | 1] += lazy[x];
            lazy[x] = 0;
        }
    }

    template <typename U>
    void update(int idx, U val) {
        updateHelper(idx, val, 1, 0, n - 1);
    }

    template <typename U>
    void updateHelper(int idx, U val, int i, int l, int r) {
        if (l == r) {
            t[i] += T(val);
            return;
        }
        push(i, l, r);
        int mid = (l + r) >> 1;
        if (idx <= mid)
            updateHelper(idx, val, i << 1, l, mid);
        else updateHelper(idx, val, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    template <typename U>
    void update(int ql, int qr, U val) {
        updateHelper(ql, qr, val, 1, 0, n - 1);
    }

    template <typename U>
    void updateHelper(int ql, int qr, U val, int i, int l, int r) {
        if (ql > r or qr < l)
            return;
        if (ql <= l and r <= qr) {
            t[i] += val;
            lazy[i] += val;
            return;
        }
        push(i, l, r);
        int mid = (l + r) >> 1;
        updateHelper(ql, qr, val, i << 1, l, mid);
        updateHelper(ql, qr, val, i << 1 | 1, mid + 1, r);

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
        push(i, l, r);
        int mid = (l + r) >> 1;
        T x = queryHelper(ql, qr, i << 1, l, mid), y = queryHelper(ql, qr, i << 1 | 1, mid + 1, r);
        return f(x, y);
    }
};

int n, len, h, b[N], a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> len >> h;
    for (int i = 0; i < len; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(b, b + len);

    int answer = 0;
    vector<int> val(len + 1);
    iota(val.begin(), val.end(), 0);

    SegmentTree<int> st(val, len + 1, INT_MAX, [&] (int x, int y) {
        return x < y ? x : y;
    });
    for (int i = 0; i < len; i++) {
        int temp = len - (lower_bound(b, b + len, h - a[i]) - b);
        st.update(temp, len, -1);
    }

    answer += st.query(0, len - 1) >= 0;

    for (int i = 1; i + len <= n; i++) {
        int temp = len - (lower_bound(b, b + len, h - a[i - 1]) - b);
        st.update(temp, len, 1);

        temp = len - (lower_bound(b, b + len, h - a[i + len - 1]) - b);
        st.update(temp, len, -1);
        answer += st.query(0, len) >= 0;
    }

    cout << answer << '\n';
    return 0;
}