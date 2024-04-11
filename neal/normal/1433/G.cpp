#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int64_t INF64 = int64_t(2e18) + 5;

struct Dijkstra {
    struct edge {
        int node = -1;
        int64_t weight = 0;

        edge() {}

        edge(int _node, int64_t _weight) : node(_node), weight(_weight) {}
    };

    struct state {
        int64_t dist;
        int node;

        state() {}

        state(int64_t _dist, int _node) : dist(_dist), node(_node) {}

        bool operator<(const state &other) const {
            return dist > other.dist;
        }
    };

    int n;
    vector<vector<edge>> adj;
    vector<int64_t> dist;
    vector<int> parent;

    Dijkstra(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
    }

    void add_directional_edge(int a, int b, int64_t weight) {
        adj[a].emplace_back(b, weight);
    }

    void add_bidirectional_edge(int a, int b, int64_t weight) {
        add_directional_edge(a, b, weight);
        add_directional_edge(b, a, weight);
    }

    void dijkstra_check(priority_queue<state> &pq, int node, int from, int64_t new_dist) {
        if (new_dist < dist[node]) {
            dist[node] = new_dist;
            parent[node] = from;
            pq.emplace(new_dist, node);
        }
    }

    void dijkstra(const vector<int> &source) {
        if (n == 0) return;
        dist.assign(n, INF64);
        parent.assign(n, -1);
        priority_queue<state> pq;

        for (int src : source)
            dijkstra_check(pq, src, -1, 0);

        while (!pq.empty()) {
            state top = pq.top();
            pq.pop();

            if (top.dist > dist[top.node])
                continue;

            for (edge &e : adj[top.node])
                dijkstra_check(pq, e.node, top.node, top.dist + e.weight);
        }
    }
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M, K;
    cin >> N >> M >> K;
    vector<array<int, 2>> edges(M);
    Dijkstra dijkstra(N);

    for (int i = 0; i < M; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        edges[i] = {x, y};
        dijkstra.add_bidirectional_edge(x, y, w);
    }

    vector<vector<int64_t>> D(N);

    for (int i = 0; i < N; i++) {
        dijkstra.dijkstra({i});
        D[i] = dijkstra.dist;
    }

    vector<array<int, 2>> routes(K);

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        routes[i] = {a, b};
    }

    int64_t best = INF64;

    for (int zero = 0; zero < M; zero++) {
        int x = edges[zero][0], y = edges[zero][1];
        int64_t cost = 0;

        for (auto &route : routes) {
            int a = route[0], b = route[1];
            cost += min({D[a][b], D[x][a] + D[y][b], D[x][b] + D[y][a]});
        }

        best = min(best, cost);
    }

    cout << best << '\n';
}