#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 998244353;
const int inf = INT_MAX;
const int N = 5e5 + 5;

template <typename T> class SegmentTree {
public:
    #define F function<T(const T&, const T&)>

    int n;
    vector<T> t;
    F f;
    SegmentTree() : n(), t(), f() {}

    template <typename U> void build(const U& arr, int _n, F func = plus<T>()) {
        n = _n;
        f = move(func);
        t.resize(4 * n + 4);
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

    template <typename U> void update(int idx, U val) {
        update(idx, val, 1, 0, n - 1);
    }

    template <typename U> void update(int idx, U val, int i, int l, int r) {
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
            return T();
        if (l >= ql and r <= qr)
            return t[i];
        int mid = l + (r - l) / 2;
        T x = query(ql, qr, i << 1, l, mid), y = query(ql, qr, i << 1 | 1, mid + 1, r);
        return f(x, y);
    }
};

int n, m;
string s;

int ways(char ch1 = '0', char ch2 = '0') {
    int x = 10 * (ch1 - '0') + ch2 - '0';
    int c = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            c += (i + j == x);
        }
    }
    return c;
}

struct node {
    int len;
    char first, last;
    ll pref, suf, total, mid;
    node(): len(), first(), last(), pref(), suf(), total(), mid() {}
    node(char c): first(c), last(c), pref(1), suf(1), total(ways('0', c)), mid() {}
};

node combine(const node& a, const node& b) {
//    if (!a.len)
//        return b;
//    if (!b.len)
//        return a;

    node temp;
    int val = ways(a.last, b.first);
    if (a.last == '0')
        val = 0;

    temp.len = a.len + b.len;
    temp.first = a.first;
    temp.last = b.last;

    temp.total = (a.total * b.total % mod + a.pref * b.suf % mod * val) % mod;
    temp.pref = (a.total * b.pref % mod + a.pref * b.mid % mod * val) % mod;
    temp.suf = (a.suf * b.total % mod + a.mid * b.suf % mod * val) % mod;
    temp.mid = (a.suf * b.pref % mod + a.mid * b.mid % mod * val) % mod;
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s;

    SegmentTree<node> st;
    st.build(s, n, combine);

    while (m--) {
        int x, d;
        cin >> x >> d; --x;
        st.update(x, (char)(d + '0'));

        cout << st.query(0, n - 1).total << "\n";
    }
    return 0;
}