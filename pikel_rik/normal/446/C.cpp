#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 9;
const int inf = INT_MAX;
const int N = 3e5 + 5;

ll fib[N];
ll sum(ll a, ll b, int n) {
    if (n == 1)
        return a;
    return ((fib[n] + mod - fib[2] + 1) * a % mod + (fib[n + 1] + mod - fib[2]) * b % mod) % mod;
}

ll fibo(ll a, ll b, int n) {
    if (n == 1)
        return a;
    return (fib[n - 2] * a + fib[n - 1] * b) % mod;
}

template <typename T>
class SegmentTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> t;
    vector<pair<int, int>> lazy;
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
        int mid = (l + r) >> 1;
        t[x << 1] = (t[x << 1] + sum(lazy[x].first, lazy[x].second, mid - l + 1)) % mod;
        t[x << 1 | 1] = (t[x << 1 | 1] + sum(lazy[x].first, lazy[x].second, r - l + 1) + mod - sum(lazy[x].first, lazy[x].second, mid - l + 1)) % mod;
        lazy[x << 1].first = (lazy[x << 1].first + lazy[x].first) % mod;
        lazy[x << 1].second = (lazy[x << 1].second + lazy[x].second) % mod;
        lazy[x << 1 | 1].first = (lazy[x << 1 | 1].first + fibo(lazy[x].first, lazy[x].second, mid - l + 2)) % mod;
        lazy[x << 1 | 1].second = (lazy[x << 1 | 1].second + fibo(lazy[x].first, lazy[x].second, mid - l + 3)) % mod;
        lazy[x].first = lazy[x].second = 0;
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
            t[i] = (t[i] + sum(fib[l - ql + 1], fib[l - ql + 2], r - l + 1)) % mod;
            lazy[i].first = (lazy[i].first + fib[l - ql + 1]) % mod;
            lazy[i].second = (lazy[i].second + fib[l - ql + 2]) % mod;
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

int n, m, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i < N; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    SegmentTree<int> st(a, n, 0, [&] (int x, int y) { return (x + y) % mod; });

    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1) {
            st.update(--l, --r, 0);
        } else {
            cout << st.query(--l, --r) << '\n';
        }
    }
    return 0;
}