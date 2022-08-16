#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

template <typename T> class FenwickTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> bit;
    F f;

    FenwickTree(): n(), bit(), f() {}
    explicit FenwickTree(int n, F f = plus<T>()): n(n), bit(n + 1, 0), f(f) {}

    void add(int i, int val) {
        while (i <= n) {
            bit[i] = f(bit[i], val);
            i += i & -i;
        }
    }
    T query(int i) {
        T ans = T();
        while (i > 0) {
            ans = f(ans, bit[i]);
            i -= i & -i;
        }
        return ans;
    }
};

int n, m, d[N], id[N], cur;
vector<int> g[N], branch[N];
vector<pair<int, int>> edges;

void dfs(int x, int par, int dep) {
    d[x] = dep;
    id[x] = cur;
    branch[cur].push_back(x);

    for (int &i : g[x]) {
        if (i == par) continue;
        dfs(i, x, dep + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.emplace_back(u, v);
    }

    int root = 1;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() > 2) {
            root = i;
            break;
        }
    }

    vector<FenwickTree<int>> ft(g[root].size());

    for (int &i : g[root]) {
        dfs(i, root, 1);
        ft[cur] = FenwickTree<int>(branch[cur].size());
        cur++;
    }

    cin >> m;
    while (m--) {
        int t;
        cin >> t;

        if (t == 1) {
            int i;
            cin >> i; --i;

            auto [u, v] = edges[i];
            if (d[u] > d[v])
                swap(u, v);
            ft[id[v]].add(d[v], -1);
        }
        else if (t == 2) {
            int i;
            cin >> i; --i;

            auto [u, v] = edges[i];
            if (d[u] > d[v])
                swap(u, v);
            ft[id[v]].add(d[v], 1);
        }
        else {
            int a, b;
            cin >> a >> b;

            if (id[a] == id[b]) {
                if (d[a] > d[b])
                    swap(a, b);
                if (ft[id[a]].query(d[b]) - ft[id[b]].query(d[a])) {
                    cout << "-1\n";
                } else cout << d[b] - d[a] << "\n";
            } else {
                if (ft[id[a]].query(d[a]) + ft[id[b]].query(d[b]))
                    cout << "-1\n";
                else cout << d[a] + d[b] << "\n";
            }
        }
    }
    return 0;
}