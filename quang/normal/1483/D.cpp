#include <bits/stdc++.h>

using namespace std;

const int N = 610;
const long long INF = 1e18;

struct Edge {
    int v, w, id;
};

int n, m;
vector<Edge> adj[N];
long long dist[N][N];

// v, l
vector<pair<int, int>> triples[N];

long long minLen[N];
bool good[N * N];
int res = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fill(dist[i] + 1, dist[i] + n + 1, INF);
        dist[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w, i});
        adj[v].push_back({u, w, i});
        dist[u][v] = min(dist[u][v], 1ll * w);
        dist[v][u] = min(dist[v][u], 1ll * w);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int u, v, l;
        cin >> u >> v >> l;
        triples[u].push_back({v, l});
    }
    for (int u = 1; u <= n; u++) {
        if (triples[u].empty()) continue;
        for (int i = 1; i <= n; i++) {
            minLen[i] = INF;
            for (auto [v, l] : triples[u]) {
                minLen[i] = min(minLen[i], dist[i][v] - l);
            }
        }
        for (int x = 1; x <= n; x++) {
            for (auto edge : adj[x]) {
                if (!good[edge.id] && dist[u][x] + edge.w + minLen[edge.v] <= 0) {
                    good[edge.id] = 1;
                    res++;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}