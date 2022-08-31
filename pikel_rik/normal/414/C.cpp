#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 9;
const int inf = INT_MAX;
const int N = 1 << 20;

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
    SegmentTree(const U& arr, int n, T e, F f): n(n), t(2 * n), e(e), f(f) {
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
};

struct node {
    ll inv;
    vector<int> vec;
    node(): inv(), vec() {}
    node(int x): inv(), vec({x}) {}
};

node combine(const node& a, const node& b) {
    node res;
    res.vec.resize(a.vec.size() + b.vec.size());

    for (int i = 0, j = 0, k = 0; i < a.vec.size() or j < b.vec.size();) {
        if (i < a.vec.size() and j < b.vec.size()) {
            if (a.vec[i] <= b.vec[j]) {
                res.vec[k++] = a.vec[i++];
            } else {
                res.vec[k++] = b.vec[j++];
                res.inv += a.vec.size() - i;
            }
        } else if (i < a.vec.size()) {
            res.vec[k++] = a.vec[i++];
        } else {
            res.vec[k++] = b.vec[j++];
        }
    }
    return res;
}

int n, m, a[N], flip[21];
ll inv[21][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < (1 << n); i++) cin >> a[i];
    {
        SegmentTree<node> st(a, (1 << n), node(), combine);
        for (int j = 0; j < n; j++) {
            for (int i = (1 << j); i < (1 << (j + 1)); i++) {
                inv[n - j][0] += st.t[i].inv;
            }
        }
    }
    {
        reverse(a, a + (1 << n));
        SegmentTree<node> st(a, (1 << n), node(), combine);
        for (int j = 0; j < n; j++) {
            for (int i = (1 << j); i < (1 << (j + 1)); i++) {
                inv[n - j][1] += st.t[i].inv;
            }
        }
    }

    cin >> m;
    while (m--) {
        int q;
        cin >> q;

        for (int i = 0; i <= q; i++)
            flip[i] ^= 1;

        ll ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += inv[i][flip[i]];
        }
        cout << ans << '\n';
    }
    return 0;
}