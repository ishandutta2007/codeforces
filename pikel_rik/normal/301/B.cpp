#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 100 + 5;

int n, c, a[N];
pair<int, int> p[N];
vector<pair<int, int>> g[N];

ll d[N];
bool visited[N];

void Dijkstra(int s = 1) {
    fill(visited, visited + n + 1, false);
    fill(d, d + n + 1, LLONG_MAX);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
    q.push({0, s});

    d[s] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (auto &[v, w] : g[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;
    for (int i = 2; i <= n - 1; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            g[i].emplace_back(j, c * (abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second)) - a[i]);
        }
    }

    Dijkstra(1);
    cout << d[n] << "\n";
    return 0;
}