#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, l, d[N], ans;
vector<pair<int, int>> g[N];

bool visited[N];

void dijkstra(int s) {
    fill(d, d + n + 1, inf);
    d[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.emplace(0, s);

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (auto &[v, w] : g[u]) {
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                q.emplace(d[v], v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m, s;
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    cin >> l;

    dijkstra(s);
    fill(visited, visited + n + 1, false);

    for (int u = 1; u <= n; u++) {
        if (d[u] == l)
            ans++;
        for (auto &[v, w] : g[u]) {
            if (visited[v]) continue;
            int d1 = l - d[u], d2 = l - d[v];
            if (d1 > 0 and d1 < w and d1 + d[u] <= w - d1 + d[v])
                ans++;
            if (d2 > 0 and d2 < w and d2 + d[v] < w - d2 + d[u])
                ans++;
        }
        visited[u] = true;
    }

    cout << ans << "\n";
    return 0;
}