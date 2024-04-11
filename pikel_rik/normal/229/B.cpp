#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 1;

int n, d[N];
vector<int> t[N];
vector<pair<int, int>> g[N];

bool visited[N];

int time(int i, int dist) {
    if (t[i].empty())
        return 0;

    auto it = lower_bound(all(t[i]), dist);

    if (it == t[i].end() or *it != dist)
        return 0;

    int start = it - t[i].begin();
    int lo = start, hi = (int)t[i].size() - 1;

    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;

        if (t[i][mid] != t[i][start] + mid - start)
            hi = mid - 1;
        else lo = mid;
    }
    return lo - start + 1;
}

void dijkstra(int s = 1) {
    fill(visited, visited + n + 1, false);
    fill(d, d + n + 1, inf);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, s});

    d[s] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (pair<int, int> &i : g[u]) {
            int ti = time(u, d[u]);
            if (d[i.first] > d[u] + i.second + ti) {
                d[i.first] = d[u] + i.second + ti;
                q.push({d[i.first], i.first});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        t[i].resize(k);
        for (int j = 0; j < k; j++) cin >> t[i][j];
    }

    dijkstra();

    d[n] == inf ? cout << "-1\n" : cout << d[n] << "\n";
    return 0;
}