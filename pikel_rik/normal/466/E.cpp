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
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }
    void union_find(int x, int y) {
        int l1 = find(x);
        int l2 = find(y);

        if (l1 != l2) {
            if (r[l1] > r[l2])
                p[l2] = l1;
            else if (r[l1] < r[l2])
                p[l1] = l2;
            else {
                p[l2] = l1;
                r[l1]++;
            }
            n--;
        }
    }
};

int n, m, l[N], p[N], tin[N], tout[N], T;
vector<int> g[N];

void dfs(int x) {
    tin[x] = T++;

    for (int &i : g[x]) {
        if (i == p[x]) continue;
        dfs(i);
    }

    tout[x] = T++;
}

bool f(int u, int v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    UnionFind uf(n);

    vector<pair<int, int>> q1, q2;
    iota(l, l + n + 1, 0);

    while (m--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);

            l[uf.find(x)] = l[uf.find(y)];
            uf.union_find(x, y);
            p[x] = y;
        }
        else if (t == 2) {
            int x;
            cin >> x;
            q1.emplace_back(l[uf.find(x)], x);
        }
        else {
            int x, i;
            cin >> x >> i; --i;

            q2.emplace_back(x, i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!p[i]) {
            dfs(i);
        }
    }

    for (auto &[x, i]: q2) {
        if (f(q1[i].first, x) and f(x, q1[i].second))
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}