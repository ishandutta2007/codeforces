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
const int N = 5e5 + 5;

int n, p[N], st[N], fi[N], T = 0;
vector<int> g[N];

void dfs(int x = 1, int par = 0) {
    p[x] = par;
    st[x] = T++;

    for (int &i : g[x]) {
        if (i == par) continue;
        dfs(i, x);
    }

    fi[x] = T++;
}

template <typename T, typename F = function<T(const T&, const T&)>> class SegmentTree {
public:
    int n;
    vector<T> t, lazy;
    vector<bool> marked;
    F f;
    SegmentTree() : n(), t(), f() {}
    SegmentTree(const T arr[], int _n, F func = plus<T>()) { build(arr, _n, func); }
    SegmentTree(const vector<T> &v, F func = plus<T>()) { build(v, func); }

    void build(const T arr[], int _n, F func) {
        n = _n;
        f = move(func);
        t.resize(4 * n + 4);
        lazy.resize(4 * n + 4);
        marked.resize(4 * n + 4);

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

    void build(const vector<T>& v, F func) {
        n = v.size();
        f = move(func);
        t.resize(4 * n + 4);
        lazy.resize(4 * n + 4);
        marked.resize(4 * n + 4);

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
        if (marked[x]) {
            int mid = l + (r - l) / 2;
            lazy[x << 1] = lazy[x << 1 | 1] = lazy[x];
            marked[x << 1] = marked[x << 1 | 1] = true;

            t[x << 1] = (mid - l + 1) * lazy[x];
            t[x << 1 | 1] = (r - mid) * lazy[x];
            marked[x] = false;
            lazy[x] = 0;
        }
    }

    void update(int l, int r, int val) {
        function<void(int, int, int, int, int, int)> update = [&](int ql, int qr, int val, int i, int l, int r) {
            if (ql > r or qr < l)
                return;
            if (ql <= l and r <= qr) {
                t[i] = (r - l + 1) * val;
                marked[i] = true;
                lazy[i] = val;
                return;
            }
            push(i, l, r);
            int mid = l + (r - l) / 2;
            update(ql, qr, val, i << 1, l, mid);
            update(ql, qr, val, i << 1 | 1, mid + 1, r);

            t[i] = f(t[i << 1], t[i << 1 | 1]);
        };
        update(l, r, val, 1, 0, n - 1);
    }

    T query(int l, int r) {
        function<T(int, int, int, int, int)> query = [&](int ql, int qr, int i, int l, int r) {
            if (ql > r or qr < l)
                return T();
            if (ql <= l and r <= qr)
                return t[i];
            push(i, l, r);
            int mid = l + (r - l) / 2;
            T x = query(ql, qr, i << 1, l, mid), y = query(ql, qr, i << 1 | 1, mid + 1, r);
            return f(x, y);
        };
        return query(l, r, 1, 0, n - 1);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs();
    vector<int> a(T, 1);
    SegmentTree<int> tree(a);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            if (x != 1 and tree.query(st[x], fi[x]) > 0) {
                tree.update(st[p[x]], st[p[x]], 1);
            }
            tree.update(st[x], fi[x], 0);
        }
        else if (t == 2) {
            tree.update(st[x], st[x], 1);
        }
        else {
            if (tree.query(st[x], fi[x]) == 0)
                cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}