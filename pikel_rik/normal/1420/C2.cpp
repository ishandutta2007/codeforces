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
            t[i] = T(val);
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
    ll minodd, maxodd, mineven, maxeven;
    node(): minodd(LLONG_MAX), maxodd(LLONG_MIN), mineven(LLONG_MAX), maxeven(LLONG_MIN) {}
    node(int x): minodd(x), maxodd(x), mineven(0), maxeven(0) {}
};

node combine(const node& a, const node& b) {
    node res;
    res.minodd = min({a.minodd, b.minodd, a.minodd - b.maxeven, a.mineven + b.minodd});
    res.maxodd = max({a.maxodd, b.maxodd, a.maxodd - b.mineven, a.maxeven + b.maxodd});
    res.mineven = min({a.mineven, b.mineven, a.mineven + b.mineven, a.minodd - b.maxodd});
    res.maxeven = max({a.maxeven, b.maxeven, a.maxeven + b.maxeven, a.maxodd - b.minodd});
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int& i : a) cin >> i;

        SegmentTree<node> st(a, n, node(), combine);
        cout << max(st.t[1].maxeven, st.t[1].maxodd) << '\n';
        while (q--) {
            int l, r;
            cin >> l >> r; --l; --r;
            swap(a[l], a[r]);
            st.update(l, a[l]);
            st.update(r, a[r]);
            cout << max(st.t[1].maxeven, st.t[1].maxodd) << '\n';
        }
    }
    return 0;
}