#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <assert.h>
#include <queue>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L
#define PI 3.141592653589793238462643383279502884L

#define long long long int

using std::vector;
using std::map;
using std::set;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::cerr;

// @author: pashka

struct edge {
    int src, dst, cap, cost, flw;
};

vector<edge> edges;
vector<vector<int>> graph;

void dijkstra(int s, vector<long> &phi, vector<long> &d, vector<int> &prev) {
    std::fill(d.begin(), d.end(), MAX_LONG);
    d[s] = 0;
    std::priority_queue<pair<long, int>> pq;
    pq.push({-d[s], s});
    while (!pq.empty()) {
        int v = pq.top().second;
        long cur_d = -pq.top().first;
        pq.pop();
        if (cur_d > d[v]) continue;
        for (int j = 0; j < graph[v].size(); ++j) {
            edge &e = edges[graph[v][j]];
            if (e.flw == e.cap) continue;
            long dd = d[v] + e.cost + phi[e.src] - phi[e.dst];
            if (dd < d[e.dst]) {
                d[e.dst] = dd;
                prev[e.dst] = graph[v][j];
                pq.push({-d[e.dst], e.dst});
            }
        }
    }
}

// Returns pair (flow, cost).
pair<int, long> minCostMaxFlow(int s, int t) {
    int n = graph.size();
    int m = edges.size();
    vector<long> phi(n);
    for (int i = 0; i < n; i++) {
        phi[i] = MAX_LONG;
    }
    phi[s] = 0;
    bool ok = false;
    while (!ok) {
        ok = true;
        for (int v = 0; v < n; v++) {
            for (int e : graph[v]) {

            }
        }
        for (edge &e : edges) {
            if (e.flw < e.cap) {
                int x = e.src;
                int y = e.dst;
                if (phi[x] < MAX_LONG) {
                    if (phi[y] > phi[x] + e.cost) {
                        phi[y] = phi[x] + e.cost;
                        ok = false;
                    }
                }
            }
        }
    }
    int flow = 0;
    long cost = 0;
    vector<long> dist(n);
    vector<int> prev(n);
    while (true) {
        dijkstra(s, phi, dist, prev);
        if (dist[t] == MAX_LONG) break;
        {
            int i = t;
            int delta = MAX_INT;
            while (i != s) {
                edge &e = edges[prev[i]];
                delta = std::min(delta, e.cap - e.flw);
                i = e.src;
            }
            assert(delta >= 0);
            flow += delta;
            i = t;
            while (i != s) {
                edge &e = edges[prev[i]];
                edge &er = edges[prev[i] ^ 1];
                e.flw += delta;
                er.flw -= delta;
                assert(e.flw <= e.cap);
                cost += (long) e.cost * delta;
                i = e.src;
            }
        }
        for (int i = 0; i < n; i++) {
            phi[i] += dist[i];
        }
    }
    return {flow, cost};
}

void addEdge(int u, int v, int cap, int cost) {
//    cout << u << " " << v << " " << cost << "\n";
    edges.push_back({u, v, cap, cost, 0});
    edges.push_back({v, u, 0, -cost, 0});
    graph[u].push_back(edges.size() - 2);
    graph[v].push_back(edges.size() - 1);
}

int main() {
    std::ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    graph.resize(n * m + 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == 0) {
                addEdge(n * m, i * m + j, 1, 0);
                if (i > 0) {
                    addEdge(i * m + j, (i - 1) * m + j, 1, a[i][j] == a[i - 1][j] ? 0 : 1);
                }
                if (i < n - 1) {
                    addEdge(i * m + j, (i + 1) * m + j, 1, a[i][j] == a[i + 1][j] ? 0 : 1);
                }
                if (j > 0) {
                    addEdge(i * m + j, i * m + j - 1, 1, a[i][j] == a[i][j - 1] ? 0 : 1);
                }
                if (j < m - 1) {
                    addEdge(i * m + j, i * m + j + 1, 1, a[i][j] == a[i][j + 1] ? 0 : 1);
                }
            } else {
                addEdge(i * m + j, n * m + 1, 1, 0);
            }
        }
    }

    auto p = minCostMaxFlow(n * m, n * m + 1);
    assert(p.first == n * m / 2);
    cout << p.second << "\n";

    return 0;
}