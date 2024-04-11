#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

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

    template <typename U> void add(const int& idx, const U& val) {
        add(idx, val, 1, 0, n - 1);
    }

    template <typename U> void add(const int& idx, const U& val, int i, int l, int r) {
        if (l == r) {
            t[i].sum += val;
            t[i].count++;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            add(idx, val, i << 1, l, mid);
        else add(idx, val, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    T query(int ql, int qr) {
        return query(ql, qr, 1, 0, n - 1);
    }

    T query(int ql, int qr, int i, int l, int r) {
        if (ql > r or qr < l)
            return e;
        if (ql <= l and r <= qr)
            return t[i];
        int mid = (l + r) >> 1;
        T x = query(ql, qr, i << 1, l, mid), y = query(ql, qr, i << 1 | 1, mid + 1, r);
        return f(x, y);
    }
};

struct node {
    int count;
    ll sum;
    node(): count(), sum() {}
    node(ll x): count(x > 1), sum(x) {}
};

node combine(const node& a, const node& b) {
    node res;
    res.count = a.count + b.count;
    res.sum = a.sum + b.sum;
    return res;
}

int n;
pair<int, int> a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int i = 0; i < n; i++) cin >> a[i].second;

    vector<int> temp;
    for (int i = 0; i < n; i++) {
        temp.push_back(a[i].second);
    }

    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for (int i = 0; i < n; i++) {
        a[i].second = lower_bound(temp.begin(), temp.end(), a[i].second) - temp.begin();
    }

    sort(a, a + n);
    ll ans = 0;

    SegmentTree<node> st;
    st.build(vector<int>(temp.size()), temp.size(), node(), combine);

    for (int i = 0; i < n; i++) {
        node res = st.query(0, a[i].second);
//        cout << res.count << " " << res.sum << "\n";
        ans += res.count * (ll)a[i].first - res.sum;
        st.add(a[i].second, a[i].first);
    }

    cout << ans << "\n";
    return 0;
}