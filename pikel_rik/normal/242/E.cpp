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

template <typename T, typename F = function<T(const T&, const T&)>> class SegmentTree {
public:
    int n;
    vector<T> t;
    vector<T> lazy;
    F f;
    SegmentTree() : n(), t(), f(), lazy() {}
    SegmentTree(const T arr[], int _n, F func = plus<T>()) { build(arr, _n, func); }
    SegmentTree(const vector<T> &v, F func = plus<T>()) { build(v, func); }

    void build(const T arr[], int _n, F func = plus<T>()) {
        n = _n;
        f = move(func);
        t.resize(4 * n + 4);
        lazy.resize(4 * n + 4);

        function<void(const T[], int, int, int)> build = [&] (const T arr[], int i, int l, int r) {
            if (l == r) {
                t[i] = arr[l];
                return;
            }

            int mid = l + (r - l) / 2;
            build(arr, i << 1, l, mid);
            build(arr, i << 1 | 1, mid + 1, r);

            t[i] = f(t[i << 1], t[i << 1 | 1]);
        };
        build(arr, 1, 0, n - 1);
    }

    void build(const vector<T>& v, F func = plus<T>()) {
        n = v.size();
        f = move(func);
        t.resize(4 * n + 4);
        lazy.resize(4 * n + 4);

        function<void(const vector<T>&, int, int, int)> build = [&] (const vector<T>& v, int i, int l, int r) {
            if (l == r) {
                t[i] = v[l];
                return;
            }

            int mid = l + (r - l) / 2;
            build(v, i << 1, l, mid);
            build(v, i << 1 | 1, mid + 1, r);

            t[i] = f(t[i << 1], t[i << 1 | 1]);
        };
        build(v, 1, 0, n - 1);
    }

    void push (int x, int l, int r) {
        t[x] = (r - l + 1) - t[x];
        lazy[x] = 0;
        if (l != r) {
            lazy[x << 1] ^= 1;
            lazy[x << 1 | 1] ^= 1;
        }
    }

    void update(int l, int r) {
        function<void(int, int, int, int, int)> update = [&](int ql, int qr, int i, int l, int r) {
            if (lazy[i])
                push(i, l, r);
            if (ql > r or qr < l)
                return;
            if (ql <= l and r <= qr) {
                push(i, l, r);
                return;
            }
            int mid = l + (r - l) / 2;
            update(ql, qr, i << 1, l, mid);
            update(ql, qr, i << 1 | 1, mid + 1, r);

            t[i] = f(t[i << 1], t[i << 1 | 1]);
        };
        update(l, r, 1, 0, n - 1);
    }

    T query(int l, int r) {
        function<T(int, int, int, int, int)> query = [&](int ql, int qr, int i, int l, int r) {
            if (lazy[i])
                push(i, l, r);
            if (ql > r or qr < l)
                return T();
            if (ql <= l and r <= qr)
                return t[i];
            int mid = l + (r - l) / 2;
            T x = query(ql, qr, i << 1, l, mid), y = query(ql, qr, i << 1 | 1, mid + 1, r);
            return f(x, y);
        };
        return query(l, r, 1, 0, n - 1);
    }
};

int n;
vector<int> bits[20];
SegmentTree<int> t[20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        for (int j = 0; j < 20; j++) {
            if (a & (1 << j))
                bits[j].push_back(1);
            else bits[j].push_back(0);
        }
    }

    for (int j = 0; j < 20; j++) {
        t[j].build(bits[j]);
    }

    int m;
    cin >> m;

    while (m--) {
        int type;
        cin >> type;

        int l, r;
        cin >> l >> r; --l; --r;

        if (type == 1) {
            ll ans = 0;
            for (int j = 0; j < 20; j++) {
                ans += t[j].query(l, r) * (1ll << j);
            }
            cout << ans << "\n";
        }
        else {
            int x; cin >> x;
            for (int j = 0; j < 20; j++) {
                if (x & (1 << j))
                    t[j].update(l, r);
            }
        }
    }
    return 0;
}