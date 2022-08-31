#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

template <typename T> class SegmentTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> t;
    vector<int> lazy;
    T e;
    F f;
    SegmentTree() : n(), t(), lazy(), e(), f() {}

    template <typename U> void build(const U& arr, int _n, T _e, F _f) {
        n = (1 << _n);
        t.resize(2 * n);
        lazy.resize(_n + 1);
        e = _e;
        f = _f;
        build(arr, 1, 0, n - 1);
    }

    template <typename U> void build(const U& arr, int i, int l, int r) {
//        cout << i << " " << l << " " << r << "\n";
        if (l == r) {
            t[i] = T(arr[l]);
            return;
        }

        int mid = (l + r) >> 1;
        build(arr, i << 1, l, mid);
        build(arr, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    template <typename U> void update(int idx, U val) {
        update(idx, val, 1, 0, n - 1);
    }

    template <typename U> void update(int idx, U val, int i, int l, int r) {
        if (l == r) {
            int k = 32 - __builtin_clz(r - l + 1) - 1;

            int sum = 0;
            for (int j = lazy.size() - 1; j >= k + 1; j--) {
                sum += lazy[j];
                if (sum & 1)
                    i ^= (1 << (j - k - 1));
            }

            t[i] = T(val);
            while (i > 1) {
                i >>= 1;
                t[i] = f(t[i << 1], t[i << 1 | 1]);
            }
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            update(idx, val, i << 1, l, mid);
        else update(idx, val, i << 1 | 1, mid + 1, r);
    }

    void reverse(int k) {
        lazy[k] ^= 1;
    }

    T query(int ql, int qr) {
        return query(ql, qr, 1, 0, n - 1);
    }

    T query(int ql, int qr, int i, int l, int r) {
        if (ql > r or qr < l)
            return e;
        if (ql <= l and r <= qr) {
            int k = 32 - __builtin_clz(r - l + 1) - 1;

            int sum = 0;
            for (int j = lazy.size() - 1; j >= k + 1; j--) {
                sum += lazy[j];
                if (sum & 1)
                    i ^= (1 << (j - k - 1));
            }

            return t[i];
        }
        int mid = (l + r) >> 1;
        T x = query(ql, qr, i << 1, l, mid), y = query(ql, qr, i << 1 | 1, mid + 1, r);
        return f(x, y);
    }
};

const int N = (1 << 18);

int n, q, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < (1 << n); i++) cin >> a[i];

    SegmentTree<ll> st;
    st.build(a, n, 0, [&] (ll x, ll y) { return x + y; });

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int i, k;
            cin >> i >> k;
            st.update(--i, k);
        }
        else if (t == 2) {
            int k;
            cin >> k;
            st.reverse(k);
        }
        else if (t == 3) {
            int k;
            cin >> k;
            st.reverse(k + 1);
            st.reverse(k);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << st.query(--l, --r) << "\n";
        }
    }
    return 0;
}