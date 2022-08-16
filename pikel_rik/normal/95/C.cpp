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
const int N = 1001;

int n, x, y, t[N], c[N];
ll dist[N][N];

vector<pair<int, int>> g[N];
bool visited[N];

void dijkstra(int s) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
    fill(visited, visited + n + 1, false);

    dist[s][s] = 0;

    q.push({0ll, s});

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        for (auto &p : g[u]) {
            if (dist[s][p.first] > p.second + dist[s][u]) {
                dist[s][p.first] = p.second + dist[s][u];
                q.push({dist[s][p.first], p.first});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 1; i <= 1000; i++) for (int j = 1; j <= 1000; j++) dist[i][j] = LLONG_MAX;

    int m;
    cin >> n >> m >> x >> y;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    for (int i = 1; i <= n; i++) cin >> t[i] >> c[i];
    for (int i = 1; i <= n; i++) dijkstra(i);

    queue<pair<ll, int>> q;
    q.push({0, x});

    ll best = LLONG_MAX;
    fill(visited, visited + n + 1, false);

    while (!q.empty()) {
        ll w = q.front().first;
        int u = q.front().second;

        if (u == y) {
            best = min(best, w);
            q.pop();
            continue;
        }

        q.pop();
        visited[u] = true;

        for (int i = 1; i <= n; i++) {
            if (!visited[i] and dist[i][u] <= t[u])
                q.push({w + c[u], i});
        }
    }

    if (best == LLONG_MAX) cout << "-1\n";
    else cout << best << "\n";

    return 0;
}