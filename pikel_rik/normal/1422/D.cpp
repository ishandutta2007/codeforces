#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);

class Graph {
public:
    struct edge {
        int u, v, w;
        edge(int u, int v, int w): u(u), v(v), w(w) {}
    };

    int n, m;
    vector<edge> edges;
    vector<vector<pair<int, int>>> adj;

    Graph(): n(), m(), adj(), edges() {}
    Graph(int n): n(n), m(), adj(n), edges() {}

    const vector<pair<int, int>>& operator[](const int &x) const { return adj[x]; }
    vector<pair<int, int>>& operator[](const int &x) { return adj[x]; }

    void addEdge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        edges.emplace_back(u, v, w);
        m++;
    }
};

vector<ll> Dijkstra(const Graph& g, int s) {
    vector<bool> visited(g.n);
    vector<ll> dist(g.n, INT_MAX);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
    q.emplace(0, s);

    dist[s] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (auto &[v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

const int N = 1e5 + 5;

int n, m, sx, sy, fx, fy;
pair<int, int> a[N];

int dist(int i, int j) {
    return min(abs(a[i].first - a[j].first), abs(a[i].second - a[j].second));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> a[0].first >> a[0].second >> fx >> fy;
    for (int i = 1; i <= m; i++) cin >> a[i].first >> a[i].second;

    Graph g(m + 1);
    vector<int> indices(m + 1);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&] (int i, int j) {
        return a[i] < a[j];
    });

    for (int len = 1; len <= min(4, m); len++) {
        for (int i = 0; i + len <= m; i++) {
            g.addEdge(indices[i], indices[i + len], dist(indices[i], indices[i + len]));
        }
    }

    sort(indices.begin(), indices.end(), [&] (int i, int j) {
        return a[i].second < a[j].second or (a[i].second == a[j].second and a[i].first < a[j].first);
    });

    for (int len = 1; len <= min(4, m); len++) {
        for (int i = 0; i + len <= m; i++) {
            g.addEdge(indices[i], indices[i + len], dist(indices[i], indices[i + len]));
        }
    }

    vector<ll> dist = Dijkstra(g, 0);
    ll ans = LLONG_MAX;

    for (int i = 0; i <= m; i++) {
        ans = min(ans, dist[i] + abs(a[i].first - fx) + abs(a[i].second - fy));
    }
    cout << ans << '\n';
    return 0;
}