#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 3e5 + 5;

template <typename T>
class SegmentTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> t;
    vector<int> ans, lazy;
    T e;
    F f;
    SegmentTree() : n(), t(), lazy(), e(), f() {}

    template <typename U>
    SegmentTree(const U& arr, int n, T e, F f): n(n), t(4 * n), ans(4 * n), lazy(4 * n), e(e), f(f) {
        build(arr, 1, 0, n - 1);
    }

    template <typename U>
    void build(const U& arr, int i, int l, int r) {
        if (l == r) {
            t[i] = arr[l];
            ans[i] = 1;
            return;
        }

        int mid = (l + r) >> 1;
        build(arr, i << 1, l, mid);
        build(arr, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
        ans[i] = ans[i << 1] + ans[i << 1 | 1];
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

    void update(int idx) {
        updateHelper(idx, 1, 0, n - 1);
    }

    void updateHelper(int idx, int i, int l, int r) {
        if (l == r) {
            t[i] = INT_MIN;
            ans[i] = 0;
            return;
        }
        push(i, l, r);
        int mid = (l + r) >> 1;
        if (idx <= mid)
            updateHelper(idx, i << 1, l, mid);
        else updateHelper(idx, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
        ans[i] = ans[i << 1] + ans[i << 1 | 1];
    }

    void update(int ql, int qr) {
        updateHelper(ql, qr, 1, 0, n - 1);
    }

    void updateHelper(int ql, int qr, int i, int l, int r) {
        if (ql > r or qr < l)
            return;
        if (ql <= l and r <= qr) {
            lazy[i]++;
            t[i]++;
            return;
        }
        push(i, l, r);
        int mid = (l + r) >> 1;
        updateHelper(ql, qr, i << 1, l, mid);
        updateHelper(ql, qr, i << 1 | 1, mid + 1, r);
        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    int query(int ql, int qr) {
        return queryHelper(ql, qr, 1, 0, n - 1);
    }

    int queryHelper(int ql, int qr, int i, int l, int r) {
        if (ql > r or qr < l)
            return 0;
        if (ql <= l and r <= qr)
            return ans[i];
        push(i, l, r);
        int mid = (l + r) >> 1;
        int x = queryHelper(ql, qr, i << 1, l, mid), y = queryHelper(ql, qr, i << 1 | 1, mid + 1, r);
        return x + y;
    }

    int maxIndex() {
        return maxIndex(1, 0, n - 1);
    }

    int maxIndex(int i, int l, int r) {
        if (l == r)
            return l;
        push(i, l, r);
        int mid = (l + r) >> 1;
        if (t[i << 1] >= t[i << 1 | 1])
            return maxIndex(i << 1, l, mid);
        return maxIndex(i << 1 | 1, mid + 1, r);
    }
};

int n, q, a[N], req[N], ans[N];
vector<pair<int, int>> queries[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == i + 1) {
            sum++;
            req[i] = INT_MIN;
        } else if (a[i] < i + 1) {
            req[i] = i + 1 - a[i] - sum;
            if (req[i] <= 0)
                sum++;
        } else {
            req[i] = 1;
        }
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        int l = x, r = n - 1 - y;
        queries[l].emplace_back(r, i);
    }

    SegmentTree<int> st(req, n, INT_MIN, [&] (int x, int y) {
        return x > y ? x : y;
    });

    for (int i = 0; i < n; i++) {
        if (req[i] > 0) {
            st.update(i);
        }
    }

    for (int l = 0; l < n; l++) {
        for (auto& [r, i] : queries[l]) {
            ans[i] = st.query(l, r);
        }
        if (a[l] == l + 1) {
            st.update(l + 1, n - 1);
            while (st.t[1] > 0) {
                int idx = st.maxIndex();
                st.update(idx + 1, n - 1);
                st.update(idx);
            }
        }
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
    return 0;
}