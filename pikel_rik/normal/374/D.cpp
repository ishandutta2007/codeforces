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
const int N = 1e6 + 5;

template <typename T> class SegmentTree {
public:
    #define F function<T(const T&, const T&)>

    int n;
    vector<T> t;
    T e;
    F f;
    SegmentTree() : n(), t(), e(), f() {}

    template <typename U> void build(const U& arr, int _n, T _e = T(), F func = plus<>()) {
        n = _n;
        t.resize(4 * n + 4);
        e = _e;
        f = func;
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

    template <typename U> void update(int idx, U val) {
        update(idx, val, 1, 0, n - 1);
    }

    template <typename U> void update(int idx, U val, int i, int l, int r) {
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

    T query(int k) {
        return query(k, 1, 0, n - 1);
    }

    T query(int k, int i, int l, int r) {
        if (l == r)
            return l;

        int mid = (l + r) >> 1;
        if (t[i << 1] >= k)
            return query(k, i << 1, l, mid);
        return query(k - t[i << 1], i << 1 | 1, mid + 1, r);
    }
};

int n, m, a[N], p[N], ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i];

    fill(p, p + (int)1e6, 1);
    SegmentTree<int> st;
    st.build(p, (int)1e6);

    int l = 0, ptr = 0;
    while (n--) {
        int x;
        cin >> x;

        if (x == -1) {
            vector<int> v;

            for (int i = 0; i < m and a[i] <= l; i++) {
                int pos = st.query(a[i]);
                p[pos] = 0;
                v.push_back(pos);
            }
            for (int i : v)
                st.update(i, 0);
            l -= v.size();
        }
        else {
            ans[ptr++] = x;
            l++;
        }
    }

    if (l == 0) {
        cout << "Poor stack!\n";
        return 0;
    }

    for (int i = 0; i < ptr; i++) {
        if (p[i]) cout << ans[i];
    }
    return 0;
}