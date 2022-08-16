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
const int N = 1e5 + 5;

template <typename T> class SegmentTree {
public:
    int n;
    T e;
    vector<T> t;
    function<T(const T&, const T&)> f;
    SegmentTree() : n(), t(), f(), e() {}

    template <typename U> void build(const U& arr, int _n, T _e = T(), function<T(const T&, const T&)> func = plus<T>()) {
        e = _e; n = _n;
        f = move(func);
        t.resize(4 * n + 4);

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

    template <typename U> void update(int idx, U val) {
        function<void(int, int, int)> update = [&](int i, int l, int r) {
            if (l == r) {
                t[i] = T(val);
                return;
            }
            int mid = l + (r - l) / 2;
            if (idx <= mid)
                update(i << 1, l, mid);
            else update(i << 1 | 1, mid + 1, r);

            t[i] = f(t[i << 1], t[i << 1 | 1]);
        };
        update(1, 0, n - 1);
    }

    template <typename U> void update(int ql, int qr, U val) {
        function<void(int, int, int)> update = [&](int i, int l, int r) {
            if (ql > r or qr < l)
                return;
            if (l == r) {
                t[i] = T(val);
                return;
            }
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
            if (l >= ql and r <= qr)
                return t[i];
            int mid = l + (r - l) / 2;
            T x = query(i << 1, l, mid), y = query(i << 1 | 1, mid + 1, r);
            return f(x, y);
        };
        return query(1, 0, n - 1);
    }
};

int n, tin[N], tout[N], d[N], T;
vector<int> euler, g[N];
vector<pair<int, int>> edges;

void first(int x, int p = -1, int dep = 0) {
    tin[x] = T++;
    d[x] = dep;
    euler.push_back(x);

    for (int &i : g[x]) {
        if (i == p) continue;
        if (edges[i].first == x)
            first(edges[i].second, i, dep + 1);
        else first(edges[i].first, i, dep + 1);
        euler.push_back(x);
    }
    tout[x] = T++;
}

SegmentTree<int> st;
int lca(int u, int v) {
    if (tin[u] > tin[v])
        return st.query(tin[v], tin[u]);
    return st.query(tin[u], tin[v]);
}

int mark[N], ans[N], dp[N];
bool visited[N];

void dfs(int x, int p = -1) {
    visited[x] = true;
    dp[x] = mark[x];

    int v;
    for (int &i : g[x]) {
        if (i == p) continue;
        if (edges[i].first == x)
            v = edges[i].second;
        else v = edges[i].first;

        dfs(v, i);
        ans[i] = dp[v];
        dp[x] += dp[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(i - 1);
        g[v].push_back(i - 1);
        edges.emplace_back(u, v);
    }

    first(1);
    d[0] = N;

    st.build(euler, euler.size(), 0, [&] (int u, int v) {
        if (d[u] < d[v])
            return u;
        return v;
    });

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int u, v; cin >> u >> v;
        int w = lca(u, v);
        if (u == v)
            continue;
        
        if (w == u)
            mark[w]--, mark[v]++;
        else if (w == v)
            mark[w]--, mark[u]++;
        else mark[u]++, mark[v]++, mark[w] -= 2;
    }

    dfs(1);

    for (int i = 0; i < n - 1; i++)
        cout << ans[i] << " "; cout << "\n";
    return 0;
}