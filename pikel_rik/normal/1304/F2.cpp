#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

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
            t[i] = T(val);
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

int n, m, k;
vector<vector<int>> a, dp, pref;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;
    a.assign(n + 1, vector<int>(m));
    dp.assign(n + 1, vector<int>(m));
    pref.assign(n + 1, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    pref = a; {
        int sum = 0;
        for (int j = 0; j < k; j++) {
            sum += a[0][j];
            sum += a[1][j];
        }
        dp[1][k - 1] = sum;
        for (int j = 1; j + k <= m; j++) {
            sum -= a[0][j - 1] + a[1][j - 1];
            sum += a[0][j + k - 1] + a[1][j + k - 1];
            dp[1][j + k - 1] = sum;
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j < m; j++) {
                pref[i][j] += pref[i][j - 1];
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            pref[i][j] += pref[i][j - 1];
        }

        for (int j = k - 1; j < m; j++) {
            if (j - k < k - 1) {
                dp[i - 1][j] -= pref[i - 1][k - 1] - (j >= k ? pref[i - 1][j - k] : 0);
            }
        }

        SegmentTree<int> st(dp[i - 1], m, 0, [&] (int x, int y) {
            return x > y ? x : y;
        });

        for (int j = 0; j + k <= m; j++) {
            int sum = pref[i][j + k - 1] - (j > 0 ? pref[i][j - 1] : 0) + pref[i - 1][j + k - 1] - (j > 0 ? pref[i - 1][j - 1] : 0);
            dp[i][j + k - 1] = sum + st.query(0, m - 1);
            st.update(max(k - 1, j), j + k - 1, a[i - 1][j]);
            if (j + k < m)
                st.update(j + k, min(j + k + k - 1, m - 1), -a[i - 1][j + k]);
        }
    }

    cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
    return 0;
}