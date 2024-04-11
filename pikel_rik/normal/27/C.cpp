#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

template <typename T, int e, typename F = function<T(const T&, const T&)>> class SegmentTree {
public:
    int n;
    vector<T> t;
    F f;
    SegmentTree() : n(), t(), f() {}

    template <typename U> void build(const U& arr, int _n, F func = plus<T>()) {
        n = _n;
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

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    a[N - 1] = inf;
    a[N - 2] = -inf;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> v(n);
    iota(all(v), 0);

    const int n1 = n + 1, n2 = n + 2;

    SegmentTree<int, N - 1> t1;
    t1.build(v, n, [&] (int x, int y) {
        if (a[x] < a[y])
            return x;
        return y;
    });

    SegmentTree<int, N - 2> t2;
    t2.build(v, n, [&] (int x, int y) {
        if (a[x] > a[y])
            return x;
        return y;
    });

    for (int i = 1; i < n - 1; i++) {
        int q1 = t1.query(0, i - 1), q2 = t1.query(i + 1, n - 1);
        if (a[q1] < a[i] and a[q2] < a[i]) {
            cout << "3\n";
            cout << q1 + 1 << " " << i + 1 << " " << q2 + 1 << "\n";
            return 0;
        }

        q1 = t2.query(0, i - 1); q2 = t2.query(i + 1, n - 1);
        if (a[q1] > a[i] and a[q2] > a[i]) {
            cout << "3\n";
            cout << q1 + 1 << " " << i + 1 << " " << q2 + 1 << "\n";
            return 0;
        }
    }

    cout << "0\n";
    return 0;
}