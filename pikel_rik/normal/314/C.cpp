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
const int N = 1e5 + 5;

template <typename T> class SegmentTree {
public:

    int n;
    T e;
    vector<T> t;
    function<T(const T&, const T&)> f;
    SegmentTree() : n(), t(), f(), e() {}

    template <typename U> void build(const U& arr, int _n, T _e = T(), function<T(const T&, const T&)> func = plus<T>()) {
        e = _e; n = _n;
        f = move(func);
        t.resize(4 * n + 4);

        function<void(int, int, int)> build = [&] (int i, int l, int r) {
            if (l == r) {
                t[i] = T(arr[l]);
                return;
            }

            int mid = l + (r - l) / 2;
            build(i << 1, l, mid);
            build(i << 1 | 1, mid + 1, r);

            t[i] = f(t[i << 1], t[i << 1 | 1]);
        };
        build(1, 0, n - 1);
    }

    template <typename U> void update(int idx, U val) {
        function<void(int, int, int)> update = [&](int i, int l, int r) {
            if (l == r) {
                t[i] = T(val);
                return;
            }
            int mid = l + (r - l) / 2;
            if (idx <= mid)
                update(i << 1, l, mid);
            else update(i << 1 | 1, mid + 1, r);

            t[i] = f(t[i << 1], t[i << 1 | 1]);
        };
        update(1, 0, n - 1);
    }

    template <typename U> void update(int ql, int qr, U val) {
        function<void(int, int, int)> update = [&](int i, int l, int r) {
            if (ql > r or qr < l)
                return;
            if (l == r) {
                t[i] = T(val);
                return;
            }
            int mid = l + (r - l) / 2;
            update(i << 1, l, mid);
            update(i << 1 | 1, mid + 1, r);

            t[i] = f(t[i << 1], t[i << 1 | 1]);
        };
        update(1, 0, n - 1);
    }

    T query(int ql, int qr) {
        function<T(int, int, int)> query = [&](int i, int l, int r) {
            if (ql > r or qr < l)
                return e;
            if (l >= ql and r <= qr)
                return t[i];
            int mid = l + (r - l) / 2;
            T x = query(i << 1, l, mid), y = query(i << 1 | 1, mid + 1, r);
            return f(x, y);
        };
        return query(1, 0, n - 1);
    }
};

int n, a[N], dp[10*N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    SegmentTree<int> st;
    st.build(dp, 10*N, 0, [&] (int x, int y) {
        return (x + y) % mod;
    });

    for (int i = 0; i < n; i++) {
        int q = st.query(0, a[i]);
        dp[a[i]] = (a[i] * (ll)q % mod + a[i]) % mod;
        st.update(a[i], dp[a[i]]);
    }

    cout << st.query(0, 10*N - 1) << "\n";
    return 0;
}