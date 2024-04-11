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

ll modexp(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return ans;
}

class UnionFind {
public:
    int n;
    vector<int> p, r;
    explicit UnionFind(int n = 0): n(n), p(n + 1), r(n + 1) {
        iota(all(p), 0);
    }
    int size() const {
        return n;
    }
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    bool merge(int x, int y) {
        int l1 = find(x);
        int l2 = find(y);

        if (l1 == l2)
            return false;
        if (r[l1] > r[l2])
            p[l2] = l1;
        else if (r[l1] < r[l2])
            p[l1] = l2;
        else {
            p[l2] = l1;
            r[l1]++;
        }
        n--;
        return true;
    }
};

int n, m;
vector<int> g[N];
vector<pair<int, int>> edges;

bool visited[N], d[N];

void dfs(int x, bool dep) {
    visited[x] = true;
    d[x] = dep;

    for (int &i : g[x]) {
        if (visited[i] and d[i] == d[x]) {
            cout << "0\n";
            exit(0);
        }
        else if (!visited[i]) {
            dfs(i, !dep);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    UnionFind uf(n);

    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        if (w == 1) {
            uf.merge(u, v);
        }
        else {
            edges.emplace_back(u, v);
        }
    }

    for (auto [u, v] : edges) {
        u = uf.find(u);
        v = uf.find(v);

        if (u == v) {
            cout << "0\n";
            return 0;
        }

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int comp = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[uf.find(i)]) {
            dfs(uf.find(i), true);
            comp++;
        }
    }

    cout << modexp(2, comp - 1) << "\n";
    return 0;
}