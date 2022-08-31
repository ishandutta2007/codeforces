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

    void update(int idx, int val) {
        update(idx, val, 1, 0, n - 1);
    }

    void update(int idx, int val, int i, int l, int r) {
        if (l == r) {
            t[i] = T(val);
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid)
            update(idx, val, i << 1, l, mid);
        else update(idx, val, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    T query(int ql, int qr) {
        return query(ql, qr, 1, 0, n - 1);
    }

    T query(int ql, int qr, int i, int l, int r) {
        if (ql > r or qr < l)
            return e;
        if (l >= ql and r <= qr)
            return t[i];
        int mid = l + (r - l) / 2;
        T x = query(ql, qr, i << 1, l, mid), y = query(ql, qr, i << 1 | 1, mid + 1, r);
        return f(x, y);
    }
};

int n, a, b, x[N], dp[10*N], d[10*N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    cin >> a >> b;

    sort(x, x + n);
    n = unique(x, x + n) - x;

    for (int i = 0; i < n; i++) {
        for (int j = b + (x[i] - b % x[i]) % x[i]; j <= a; j += x[i]) {
            d[j - b] = x[i];
        }
    }

    dp[a - b] = 0;
    SegmentTree<int> st;

    st.build(dp, a - b + 1, (int)1e7, [&] (int x, int y) {
        return x < y ? x : y;
    });

    for (int i = a - 1 - b; i >= 0; i--) {
        dp[i] = 1 + dp[i + 1];

        if (d[i]) {
            int r = min(a - b, i + d[i] - 1);
            dp[i] = min(dp[i], 1 + st.query(i + 1, r));
        }
        st.update(i, dp[i]);
    }

    cout << dp[0] << "\n";
    return 0;
}