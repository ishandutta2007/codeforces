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
const int N = 5e5 + 5;

template <typename T> class SegmentTree {
public:
    #define F function<T(const T&, const T&)>

    int n;
    vector<T> t;
    vector<int> lazy;
    F f;
    SegmentTree() : n(), t(), f(), lazy() {}

    template <typename U> void build(const U& arr, int _n, F func = plus<T>()) {
        n = _n;
        f = move(func);
        t.resize(4 * n + 4);
        lazy.resize(4 * n + 4);
        build(arr, 1, 0, n - 1);
    }

    template <typename U> void build(const U& arr, int i, int l, int r) {
        if (l == r) {
            t[i] = T(arr[l]);
            return;
        }

        int mid = l + (r - l) / 2;
        build(arr, i << 1, l, mid);
        build(arr, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    void push (int x) {
        if (lazy[x]) {
            lazy[x] = 0;
            t[x << 1].flip();
            t[x << 1 | 1].flip();
            lazy[x << 1] ^= 1;
            lazy[x << 1 | 1] ^= 1;
        }
    }

    void update(int ql, int qr) {
        update(ql, qr, 1, 0, n - 1);
    }

    void update(int ql, int qr, int i, int l, int r) {
        if (ql > r or qr < l)
            return;
        if (ql <= l and r <= qr) {
            t[i].flip();
            lazy[i] ^= 1;
            return;
        }
        push(i);
        int mid = l + (r - l) / 2;
        update(ql, qr, i << 1, l, mid);
        update(ql, qr, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    T query(int ql, int qr) {
        return query(ql, qr, 1, 0, n - 1);
    }

    T query(int ql, int qr, int i, int l, int r) {
        if (ql > r or qr < l)
            return T();
        if (l >= ql and r <= qr)
            return t[i];
        push(i);
        int mid = l + (r - l) / 2;
        T x = query(ql, qr, i << 1, l, mid), y = query(ql, qr, i << 1 | 1, mid + 1, r);
        return f(x, y);
    }
};

int n, q;

struct node {
    int len, first, last, prefi, prefd, sufi, sufd, besti, bestd;
    node(): len(), first(), last(), prefi(), prefd(), sufi(), sufd(), besti(), bestd() {}
    node(char c): len(1), first(c == '<'), last(c == '<'), prefi(1), prefd(1), sufi(1), sufd(1), besti(1), bestd(1) {}

    void flip() {
        first = 1 - first;
        last = 1 - last;
        swap(prefi, prefd);
        swap(sufi, sufd);
        swap(besti, bestd);
    }
};

node combine(const node& x, const node& y) {
    if (!x.len)
        return y;
    if (!y.len)
        return x;

    node ans;
    ans.len = x.len + y.len;
    ans.first = x.first;
    ans.last = y.last;

    ans.besti = max(x.besti, y.besti);
    ans.bestd = max(x.bestd, y.bestd);

    ans.prefi = x.prefi; ans.prefd = x.prefd;
    ans.sufi = y.sufi; ans.sufd = y.sufd;

    if (x.last <= y.first) {
        ans.besti = max(ans.besti, x.sufi + y.prefi);
        if (x.prefi == x.len)
            ans.prefi = max(ans.prefi, x.len + y.prefi);
        if (y.prefi == y.len)
            ans.sufi = max(ans.sufd, x.sufi + y.len);
    }
    if (x.last >= y.first) {
        ans.bestd = max(ans.bestd, x.sufd + y.prefd);
        if (x.prefd == x.len)
            ans.prefd = max(ans.prefd, x.len + y.prefd);
        if (y.prefd == y.len)
            ans.sufd = max(ans.sufd, x.sufd + y.len);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    string s; cin >> s;

    SegmentTree<node> st;
    st.build(s, n, combine);

    while (q--) {
        int l, r;
        cin >> l >> r; --l; --r;
        st.update(l, r);
        cout << st.query(l, r).besti << "\n";
    }
    return 0;
}