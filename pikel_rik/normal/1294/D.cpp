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

    T query() {
        return query(1, 0, n - 1);
    }

    T query(int i, int l, int r) {
//        cout << l << " " << r << "\n";
        if (l == r)
            return l;
        int mid = (l + r) >> 1;
        if (t[i << 1] < mid - l + 1)
            return query(i << 1, l, mid);
        return query(i << 1 | 1, mid + 1, r);
    }
};

const int N = 4e5 + 5;

int pos[N], a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    SegmentTree<int> st;
    st.build(vector<int>(n + 1), n + 1, 0, [&] (int x, int y) { return x + y; });

    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;

        y %= x;

        if (pos[y] + y < n) {
            a[pos[y] + y] = 1;
            st.update(pos[y] + y, 1);
            pos[y] += x;
        }

        if (a[0] == 0)
            cout << "0\n";
        else cout << st.query() << "\n";
    }
    return 0;
}