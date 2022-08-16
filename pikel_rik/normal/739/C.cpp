#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 3e5 + 5;

template <typename T> class SegmentTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> t;
    vector<ll> lazy;
    T e;
    F f;
    SegmentTree() : n(), t(), lazy(), e(), f() {}

    template <typename U> void build(const U& arr, int _n, T _e, F _f) {
        n = _n;
        t.resize(4 * n + 4);
        lazy.resize(4 * n + 4);
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

    void push (int x, int l, int r) {
        if (lazy[x]) {
            t[x << 1].add(lazy[x]);
            t[x << 1 | 1].add(lazy[x]);
            lazy[x << 1] += lazy[x];
            lazy[x << 1 | 1] += lazy[x];
            lazy[x] = 0;
        }
    }

    template <typename U> void update(int ql, int qr, U val) {
        update(ql, qr, val, 1, 0, n - 1);
    }

    template <typename U> void update(int ql, int qr, U val, int i, int l, int r) {
        if (ql > r or qr < l)
            return;
        if (ql <= l and r <= qr) {
            t[i].add(val);
            lazy[i] += val;
            return;
        }
        push(i, l, r);
        int mid = (l + r) >> 1;
        update(ql, qr, val, i << 1, l, mid);
        update(ql, qr, val, i << 1 | 1, mid + 1, r);

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
        push(i, l, r);
        int mid = (l + r) >> 1;
        T x = query(ql, qr, i << 1, l, mid), y = query(ql, qr, i << 1 | 1, mid + 1, r);
        return f(x, y);
    }
};

struct node {
    int best, bestp, bests, len;
    ll first, last;
    int prefi, prefd, sufi, sufd;

    node(): best(), bestp(), bests(), len(), first(), last(), prefi(), prefd(), sufi(), sufd() {}
    node(int x): best(1), bestp(1), bests(1), len(1), first(x), last(x), prefi(1), prefd(1), sufi(1), sufd(1) {}

    void add(ll d) {
        first += d;
        last += d;
    }
};

node combine(const node& a, const node& b) {
    node res;
    res.len = a.len + b.len;
    res.best = max(a.best, b.best);
    if (a.last != b.first)
        res.best = max(res.best, a.sufi + b.prefd);

    res.first = a.first;
    res.last = b.last;

    res.bestp = a.bestp;
    res.bests = b.bests;

    res.prefi = a.prefi;
    res.prefd = a.prefd;
    res.sufi = b.sufi;
    res.sufd = b.sufd;

    if (a.last > b.first) {
        res.best = max(res.best, a.bests + b.prefd);

        if (a.bests == a.len)
            res.bestp = max(res.bestp, a.len + b.prefd);
        if (b.prefd == b.len)
            res.bests = max(res.bests, a.bests + b.len);

        if (a.prefd == a.len)
            res.prefd = a.len + b.prefd;
        if (b.prefd == b.len)
            res.sufd = a.sufd + b.len;
    }

    if (a.last < b.first) {
        res.best = max(res.best, a.sufi + b.bestp);

        if (b.bestp == b.len)
            res.bests = max(res.bests, a.sufi + b.len);
        if (a.sufi == a.len)
            res.bestp = max(res.bestp, a.len + b.bestp);

        if (a.prefi == a.len)
            res.prefi = a.len + b.prefi;
        if (b.prefi == b.len)
            res.sufi = a.sufi + b.len;
    }
    return res;
}

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    SegmentTree<node> st;
    st.build(a, n, node(), combine);

    int m;
    cin >> m;

    while (m--) {
        int l, r, d;
        cin >> l >> r >> d; --l; --r;
        st.update(l, r, d);
        cout << st.query(0, n - 1).best << "\n";
    }
    return 0;
}