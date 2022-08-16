#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

template <typename T>
class SegmentTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> t;
    vector<int> lazy;
    T e;
    F f;
    SegmentTree() : n(), t(), lazy(), e(), f() {}

    template <typename U>
    SegmentTree(const U& arr, int n, T e, F f): n(n), t(4 * n), lazy(4 * n, -1), e(e), f(f) {
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
        if (lazy[x] != -1) {
            int mid = (l + r) >> 1;
            t[x << 1] = (mid - l + 1) * lazy[x];
            t[x << 1 | 1] = (r - mid) * lazy[x];
            lazy[x << 1] = lazy[x];
            lazy[x << 1 | 1] = lazy[x];
            lazy[x] = -1;
        }
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
        push(i, l, r);
        int mid = (l + r) >> 1;
        if (idx <= mid)
            updateHelper(idx, val, i << 1, l, mid);
        else updateHelper(idx, val, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
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
            t[i] = (r - l + 1) * val;
            lazy[i] = val;
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

int n, q;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    cin >> s;

    SegmentTree<int> st[26];
    for (int i = 0; i < 26; i++) {
        st[i] = SegmentTree<int>(vector<int>(n), n, 0, [&] (int x, int y) {
            return x + y;
        });
    }

    for (int i = 0; i < n; i++) {
        st[s[i] - 'a'].update(i, 1);
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k; --l; --r;

        int sum = 0;
        if (k == 1) {
            for (int i = 0; i < 26; i++) {
                int temp = st[i].query(l, r);
                if (temp) {
                    st[i].update(l, r, 0);
                    st[i].update(l + sum, l + sum + temp - 1, 1);
                    sum += temp;
                }
            }
        }
        else {
            for (int i = 25; i >= 0; i--) {
                int temp = st[i].query(l, r);
                if (temp) {
                    st[i].update(l, r, 0);
                    st[i].update(l + sum, l + sum + temp - 1, 1);
                    sum += temp;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (st[j].query(i, i)) {
                cout << char('a' + j);
                break;
            }
        }
    }
    return 0;
}