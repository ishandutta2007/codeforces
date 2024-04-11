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

struct node {
    ll a, b;
    node(): a(0), b(INT_MIN) {}
    explicit node(ll x): a(x), b(x) {}
    node(ll _a, ll _b): a(_a), b(_b) {}
};

template <typename T, typename F = function<T(const T&, const T&)>> class SegmentTree {
public:
    int n;
    vector<T> t;
    F f;
    SegmentTree() : n(), t(), f() {}

    void build(const int arr[], int _n, F func) {
        n = _n;
        f = func;
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

    void build(const vector<int>& v, F func) {
        n = v.size();
        f = move(func);
        t.resize(4 * n + 4);

        function<void(const vector<int>&, int, int, int)> build = [&] (const vector<int>& v, int i, int l, int r) {
            if (l == r) {
                t[i] = T(v[l]);
                return;
            }

            int mid = l + (r - l) / 2;
            build(v, i << 1, l, mid);
            build(v, i << 1 | 1, mid + 1, r);

            t[i] = f(t[i << 1], t[i << 1 | 1]);
        };
        build(v, 1, 0, n - 1);
    }

    void update(int ql, int qr, int m) {
        function<void(int, int, int)> update = [&](int i, int l, int r) {
            if (ql > r or qr < l)
                return;
            if (t[i].b < m)
                return;
            if (l == r) {
                t[i].a = t[i].a % m;
                t[i].b = t[i].b % m;
                return;
            }
            int mid = l + (r - l) / 2;
            update(i << 1, l, mid);
            update(i << 1 | 1, mid + 1, r);

            t[i] = f(t[i << 1], t[i << 1 | 1]);
        };
        update(1, 0, n - 1);
    }

    void update(int idx, int val) {
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

    T query(int ql, int qr) {
        function<T(int, int, int)> query = [&](int i, int l, int r) {
            if (ql > r or qr < l)
                return T();
            if (ql <= l and r <= qr)
                return t[i];
            int mid = l + (r - l) / 2;
            T x = query(i << 1, l, mid), y = query(i << 1 | 1, mid + 1, r);
            return f(x, y);
        };
        return query(1, 0, n - 1);
    }
};

const int N = 1e5 + 5;
int n, a[N];

node combine(node x, node y) {
    return {x.a + y.a, max(x.b, y.b)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> a[i];

    SegmentTree<node> t;
    t.build(a, n, combine);

    while (m--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r; cin >> l >> r;
            cout << t.query(--l, --r).a << "\n";
        }
        else if (type == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            t.update(--l, --r, x);
        }
        else {
            int i, x;
            cin >> i >> x;
            t.update(--i, x);
        }
    }
    return 0;
}