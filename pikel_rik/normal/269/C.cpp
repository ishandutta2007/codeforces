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
const int N = 2e5 + 5;

struct edge {
    int u, v, c;
    explicit edge(int u = 0, int v = 0, int c = 0): u(u), v(v), c(c) {}
};

int n, m, sum[N], ans[N];
vector<int> g[N];
edge edges[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        edges[i] = edge(u, v, c);
        g[u].push_back(i);
        g[v].push_back(i);
        sum[u] += c;
        sum[v] += c;
    }

    set<pair<int, int>> s;
    for (int i = 0; i < m; i++)
        ans[i] = -1;

    for (int &i : g[1]) {
        if (edges[i].u != 1)
            sum[edges[i].u] -= 2 * edges[i].c, ans[i] = 1;
        else if (edges[i].v != 1)
            sum[edges[i].v] -= 2 * edges[i].c, ans[i] = 0;
    }

    for (int i = 2; i <= n; i++)
        s.emplace(sum[i], i);

    while (!s.empty()) {
        int x = (*s.begin()).second;
        s.erase(s.begin());

        if (x == n) continue;

        for (int &i : g[x]) {
            if (ans[i] != -1) continue;

            if (edges[i].u != x) {
                ans[i] = 1;
                s.erase({sum[edges[i].u], edges[i].u});
                sum[edges[i].u] -= 2 * edges[i].c;
                s.emplace(sum[edges[i].u], edges[i].u);
            }
            else {
                ans[i] = 0;
                s.erase({sum[edges[i].v], edges[i].v});
                sum[edges[i].v] -= 2 * edges[i].c;
                s.emplace(sum[edges[i].v], edges[i].v);
            }
        }
    }

    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";
    return 0;
}