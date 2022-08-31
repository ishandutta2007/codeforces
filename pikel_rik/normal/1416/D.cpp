#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int N = 1e6 + 5;
const int M = 3e5 + 5;

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
    SegmentTree(const U& arr, int n, T e, F f): n(n), t(4 * n), e(e), f(f) {
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
        int mid = (l + r) >> 1;
        if (idx <= mid)
            updateHelper(idx, val, i << 1, l, mid);
        else updateHelper(idx, val, i << 1 | 1, mid + 1, r);

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
        int mid = (l + r) >> 1;
        T x = queryHelper(ql, qr, i << 1, l, mid), y = queryHelper(ql, qr, i << 1 | 1, mid + 1, r);
        return f(x, y);
    }
};

int n, m, q, p[N];
vector<int> g[N];
vector<pair<int, int>> edges(1), queries(1);
bool processed[M];

int par[N];
int find(int x) {
    return x == par[x] ? par[x] : par[x] = find(par[x]);
}

void merge(int u, int v) {
    int l1 = find(u);
    int l2 = find(v);
    if (l1 != l2) {
        ++n;
        g[n].push_back(l1);
        g[l1].push_back(n);
        g[n].push_back(l2);
        g[l2].push_back(n);
        par[l1] = par[l2] = par[n] = n;
    }
}

vector<int> euler;
int tin[N], tout[N], T;

void dfs(int x, int p) {
    tin[x] = T++;
    euler.push_back(x);
    for (int& i : g[x]) {
        if (i != p) {
            dfs(i, x);
            euler.push_back(x);
        }
    }
    tout[x] = T++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        par[i] = i;
    }

    edges.reserve(m + 1);
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        edges.emplace_back(u, v);
    }

    queries.reserve(q + m);
    for (int i = 0, t, x; i < q; i++) {
        cin >> t >> x; --t;
        if (t == 1) {
            processed[x] = true;
        }
        queries.emplace_back(t, x);
    }

    for (int i = 1; i <= m; i++) {
        if (!processed[i]) {
            queries.emplace_back(1, i);
        }
    }

    q = queries.size() - 1;
    for (int i = q; i >= 1; i--) {
        if (queries[i].first == 0) {
            queries[i].second = find(queries[i].second);
        } else {
            int idx = queries[i].second;
            merge(edges[idx].first, edges[idx].second);
        }
    }

    vector<int> temp;
    for (int i = 1; i <= n; i++) {
        if (i == find(i)) {
            temp.push_back(i);
        }
    }

    for (int i = 1; i < temp.size(); i++) {
        merge(temp[i - 1], temp[i]);
    }

    euler.reserve(2 * n);
    dfs(n, 0);

    for (int i = 0; i < euler.size(); i++) {
        if (i != tin[euler[i]]) {
            euler[i] = 0;
        }
    }

    SegmentTree<int> st(euler, euler.size(), 0, [&] (int x, int y) {
        return p[x] > p[y] ? x : y;
    });

    for (int i = 1; i <= q; i++) {
        if (queries[i].first == 0) {
            int v = queries[i].second;
            v = st.query(tin[v], tout[v]);
            cout << p[v] << '\n';
            if (p[v]) {
                st.update(tin[v], 0);
            }
        }
    }
    return 0;
}