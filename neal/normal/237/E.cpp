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

// Warning: when choosing flow_t and cost_t, make sure they can handle the sum of flows and costs, not just individual
// flows and costs.
template<typename flow_t, typename cost_t>
struct min_cost_flow {
    const cost_t COST_INF = numeric_limits<cost_t>::max() / 2;

    struct edge {
        int node, rev;
        flow_t capacity;
        cost_t cost;

        edge() {}

        edge(int _node, int _rev, flow_t _capacity, cost_t _cost)
            : node(_node), rev(_rev), capacity(_capacity), cost(_cost) {}
    };

    int V = -1, E = 0;
    vector<vector<edge>> adj;
    vector<cost_t> dist;
    vector<int> prv;
    vector<edge*> prev_edge;
    bool too_many_bellman_ford_iterations = false;

    min_cost_flow(int vertices = -1) {
        if (vertices >= 0)
            init(vertices);
    }

    void init(int vertices) {
        V = vertices;
        E = 0;
        adj.assign(V, {});
        dist.resize(V);
        prv.resize(V);
        prev_edge.resize(V);
        too_many_bellman_ford_iterations = false;
    }

    void add_directional_edge(int u, int v, flow_t capacity, cost_t cost) {
        assert(0 <= u && u < V && 0 <= v && v < V);
        edge uv_edge(v, int(adj[v].size()) + (u == v ? 1 : 0), capacity, cost);
        edge vu_edge(u, int(adj[u].size()), 0, -cost);
        adj[u].push_back(uv_edge);
        adj[v].push_back(vu_edge);
        E++;
    }

    edge &reverse_edge(const edge &e) {
        return adj[e.node][e.rev];
    }

    bool bellman_ford(int source, int sink) {
        dist.assign(V, COST_INF);
        prv.assign(V, -1);
        prev_edge.assign(V, nullptr);

        int64_t work = 0;
        vector<int> last_seen(V, -1);
        vector<int> nodes = {source}, next_nodes;
        dist[source] = 0;

        for (int iteration = 0; iteration < V; iteration++) {
            next_nodes.clear();

            for (int node : nodes) {
                for (edge &e : adj[node])
                    if (e.capacity > 0 && dist[node] + e.cost < dist[e.node]) {
                        dist[e.node] = dist[node] + e.cost;
                        prv[e.node] = node;
                        prev_edge[e.node] = &e;

                        if (last_seen[e.node] != iteration) {
                            last_seen[e.node] = iteration;
                            next_nodes.push_back(e.node);
                        }
                    }

                work += adj[node].size();
            }

            swap(nodes, next_nodes);
        }

        if (work > 1.75L * E * (32 - __builtin_clz(V)) + 100)
            too_many_bellman_ford_iterations = true;

        return prv[sink] != -1;
    }

    struct dijkstra_state {
        cost_t dist;
        int node;

        dijkstra_state() {}

        dijkstra_state(cost_t _dist, int _node) : dist(_dist), node(_node) {}

        bool operator<(const dijkstra_state &other) const {
            return dist > other.dist;
        }
    };

    void dijkstra_check(priority_queue<dijkstra_state> &pq, int node, cost_t new_dist, int previous, edge *previous_edge) {
        if (new_dist < dist[node]) {
            dist[node] = new_dist;
            prv[node] = previous;
            prev_edge[node] = previous_edge;
            pq.emplace(dist[node], node);
        }
    }

    bool dijkstra(int source, int sink) {
        dist.assign(V, COST_INF);
        prv.assign(V, -1);
        prev_edge.assign(V, nullptr);

        priority_queue<dijkstra_state> pq;
        dijkstra_check(pq, source, 0, -1, nullptr);

        while (!pq.empty()) {
            dijkstra_state top = pq.top();
            pq.pop();

            if (top.dist > dist[top.node])
                continue;

            for (edge &e : adj[top.node])
                if (e.capacity > 0)
                    dijkstra_check(pq, e.node, top.dist + e.cost, top.node, &e);
        }

        return prv[sink] != -1;
    }

    void reduce_cost() {
        for (int i = 0; i < V; i++)
            for (edge &e : adj[i])
                if (dist[i] < COST_INF && dist[e.node] < COST_INF)
                    e.cost += dist[i] - dist[e.node];
    }

    pair<flow_t, cost_t> solve_min_cost_flow(int source, int sink, flow_t flow_goal = numeric_limits<flow_t>::max()) {
        assert(V >= 0);
        flow_t total_flow = 0;
        cost_t total_cost = 0;

        while (total_flow < flow_goal && bellman_ford(source, sink)) {
            if (too_many_bellman_ford_iterations)
                break;

            flow_t path_cap = flow_goal - total_flow;
            cost_t cost_sum = 0;

            for (int node = sink; prv[node] != -1; node = prv[node])
                path_cap = min(path_cap, prev_edge[node]->capacity);

            for (int node = sink; prv[node] != -1; node = prv[node]) {
                edge *e = prev_edge[node];
                e->capacity -= path_cap;
                reverse_edge(*e).capacity += path_cap;
                cost_sum += e->cost;
            }

            total_flow += path_cap;
            total_cost += cost_sum * path_cap;
        }

        if (too_many_bellman_ford_iterations) {
            cost_t reduce_sum = 0;

            do {
                reduce_cost();
                reduce_sum += dist[sink];
                flow_t path_cap = flow_goal - total_flow;

                for (int node = sink; prv[node] != -1; node = prv[node])
                    path_cap = min(path_cap, prev_edge[node]->capacity);

                for (int node = sink; prv[node] != -1; node = prv[node]) {
                    edge *e = prev_edge[node];
                    assert(e->cost == 0);
                    e->capacity -= path_cap;
                    reverse_edge(*e).capacity += path_cap;
                }

                total_flow += path_cap;
                total_cost += reduce_sum * path_cap;
            } while (total_flow < flow_goal && dijkstra(source, sink));
        }

        return make_pair(total_flow, total_cost);
    }
};


const int ALPHABET = 26;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    string T;
    cin >> T;
    int N;
    cin >> N;
    vector<string> S(N);
    vector<int> A(N);

    for (int i = 0; i < N; i++)
        cin >> S[i] >> A[i];

    int source = N + ALPHABET, sink = N + ALPHABET + 1;
    min_cost_flow<int, int> graph(N + ALPHABET + 2);

    for (int c = 0; c < ALPHABET; c++)
        graph.add_directional_edge(source, c, count(T.begin(), T.end(), 'a' + c), 0);

    for (int i = 0; i < N; i++)
        graph.add_directional_edge(ALPHABET + i, sink, A[i], 0);

    for (int i = 0; i < N; i++)
        for (char &ch : S[i]) {
            int c = ch - 'a';
            graph.add_directional_edge(c, ALPHABET + i, 1, i + 1);
        }

    auto answer = graph.solve_min_cost_flow(source, sink);

    if (answer.first < int(T.size())) {
        cout << -1 << '\n';
        return 0;
    }

    cout << answer.second << '\n';
}