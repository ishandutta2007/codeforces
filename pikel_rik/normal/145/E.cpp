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
    int n;
    T e;
    vector<T> t;
    vector<int> lazy;
    function<T(const T&, const T&)> f;
    SegmentTree() : n(), t(), f(), lazy(), e() {}

    template <typename U> void build(const U& arr, int _n, T _e = T(), function<T(const T&, const T&)> func = plus<T>()) {
        e = _e; n = _n;
        f = move(func);
        t.resize(4 * n + 4);
        lazy.resize(4 * n + 4);

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

    void push (int x) {
        if (lazy[x]) {
            swap(t[x << 1].c1, t[x << 1].c2);
            swap(t[x << 1].besti, t[x << 1].bestd);

            swap(t[x << 1 | 1].c1, t[x << 1 | 1].c2);
            swap(t[x << 1 | 1].besti, t[x << 1 | 1].bestd);

            lazy[x << 1] ^= 1;
            lazy[x << 1 | 1] ^= 1;
            lazy[x] ^= 1;
        }
    }

    void update(int ql, int qr) {
        function<void(int, int, int)> update = [&](int i, int l, int r) {
            if (ql > r or qr < l)
                return;
            if (ql <= l and r <= qr) {
                swap(t[i].c1, t[i].c2);
                swap(t[i].besti, t[i].bestd);
                lazy[i] ^= 1;
                return;
            }
            push(i);
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
            if (ql <= l and r <= qr)
                return t[i];
            push(i);
            int mid = l + (r - l) / 2;
            T x = query(i << 1, l, mid), y = query(i << 1 | 1, mid + 1, r);
            return f(x, y);
        };
        return query(1, 0, n - 1);
    }
};

int n, m;
string s;

struct node {
    int c1, c2, besti, bestd;
    node(): c1(), c2(), besti(), bestd() {}
    node(char c): c1(c == '4'), c2(c == '7'), besti(1), bestd(1) {}
    node(int c1, int c2, int besti, int bestd) : c1(c1), c2(c2), besti(besti), bestd(bestd) {}
};

node combine (const node& a, const node& b) {
    node temp;
    temp.c1 = a.c1 + b.c1;
    temp.c2 = a.c2 + b.c2;

    temp.besti = max({a.besti + b.c2, a.c1 + b.besti, a.c1 + b.c1, a.c2 + b.c2});
    temp.bestd = max({a.bestd + b.c1, a.c2 + b.bestd, a.c1 + b.c1, a.c2 + b.c2});
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s;

    SegmentTree<node> st;
    st.build(s, n, node(), combine);

    while (m--) {
        string str;
        cin >> str;

        if (str == "count")
            cout << st.query(0, n - 1).besti << "\n";
        else {
            int l, r;
            cin >> l >> r;
            st.update(--l, --r);
        }
    }
    return 0;
}