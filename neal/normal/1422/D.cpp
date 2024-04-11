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
        dbg(a, b, weight);
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

    auto get_dist = [](int64_t dx, int64_t dy) {
        return min(abs(dx), abs(dy));
    };

    int64_t _;
    int M;
    cin >> _ >> M;
    int64_t SX, SY, FX, FY;
    cin >> SX >> SY >> FX >> FY;
    vector<pair<array<int64_t, 2>, int>> locations(M);

    for (int i = 0; i < M; i++) {
        cin >> locations[i].first[0] >> locations[i].first[1];
        locations[i].second = i;
    }

    Dijkstra dijkstra(M + 2);
    int start = M, finish = M + 1;

    dijkstra.add_directional_edge(start, finish, abs(SX - FX) + abs(SY - FY));

    for (int i = 0; i < M; i++) {
        dijkstra.add_directional_edge(start, i, get_dist(SX - locations[i].first[0], SY - locations[i].first[1]));
        dijkstra.add_directional_edge(i, finish, abs(FX - locations[i].first[0]) + abs(FY - locations[i].first[1]));
    }

    sort(locations.begin(), locations.end());

    for (int i = 0; i < M - 1; i++)
        dijkstra.add_bidirectional_edge(locations[i].second, locations[i + 1].second, abs(locations[i].first[0] - locations[i + 1].first[0]));

    for (int i = 0; i < M; i++)
        swap(locations[i].first[0], locations[i].first[1]);

    sort(locations.begin(), locations.end());

    for (int i = 0; i < M - 1; i++)
        dijkstra.add_bidirectional_edge(locations[i].second, locations[i + 1].second, abs(locations[i].first[0] - locations[i + 1].first[0]));

    dijkstra.dijkstra({start});
    cout << dijkstra.dist[finish] << '\n';
}