#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    Dijkstra dijkstra(4 * N);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        for (int iter = 0; iter < 2; iter++) {
            // Neither free nor double
            for (int s = 0; s < 4; s++)
                dijkstra.add_directional_edge(4 * u + s, 4 * v + s, w);

            // Both free + double
            dijkstra.add_directional_edge(4 * u, 4 * v + 3, w);

            // Only free
            dijkstra.add_directional_edge(4 * u, 4 * v + 2, 0);
            dijkstra.add_directional_edge(4 * u + 1, 4 * v + 3, 0);

            // Only double
            dijkstra.add_directional_edge(4 * u, 4 * v + 1, 2 * w);
            dijkstra.add_directional_edge(4 * u + 2, 4 * v + 3, 2 * w);

            swap(u, v);
        }
    }

    dijkstra.dijkstra({0});
    vector<int64_t> answer;

    for (int i = 1; i < N; i++)
        answer.push_back(dijkstra.dist[4 * i + 3]);

    output_vector(answer);
}