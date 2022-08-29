#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

// Warning: when choosing flow_t and cost_t, make sure they can handle the sum of flows and costs, not just individual
// flows and costs.
template<typename flow_t, typename cost_t>
struct min_cost_flow {
    static const flow_t FLOW_INF = numeric_limits<flow_t>::max() / 2;
    static const cost_t COST_INF = numeric_limits<cost_t>::max() / 2;

    struct edge {
        int node, rev;
        flow_t capacity;
        cost_t cost;

        edge() {}

        edge(int _node, int _rev, flow_t _capacity, cost_t _cost)
            : node(_node), rev(_rev), capacity(_capacity), cost(_cost) {}
    };

    int V = -1;
    vector<vector<edge>> adj;
    vector<cost_t> dist;
    vector<int> prev;
    vector<edge*> prev_edge;

    min_cost_flow(int vertices = -1) {
        if (vertices >= 0)
            init(vertices);
    }

    void init(int vertices) {
        V = vertices;
        adj.assign(V, {});
        dist.resize(V);
        prev.resize(V);
        prev_edge.resize(V);
    }

    void add_directional_edge(int u, int v, flow_t capacity, cost_t cost) {
        edge uv_edge(v, adj[v].size() + (u == v ? 1 : 0), capacity, cost);
        edge vu_edge(u, adj[u].size(), 0, -cost);
        adj[u].push_back(uv_edge);
        adj[v].push_back(vu_edge);
    }

    edge &reverse_edge(const edge &e) {
        return adj[e.node][e.rev];
    }

    bool bellman_ford(int source, int sink) {
        for (int i = 0; i < V; i++) {
            dist[i] = COST_INF;
            prev[i] = -1;
            prev_edge[i] = nullptr;
        }

        vector<int> last_seen(V, -1);
        vector<int> nodes = {source}, next_nodes;
        dist[source] = 0;

        for (int iteration = 0; iteration < V; iteration++) {
            next_nodes.clear();

            for (int node : nodes)
                for (edge &e : adj[node])
                    if (e.capacity > 0 && dist[node] + e.cost < dist[e.node]) {
                        dist[e.node] = dist[node] + e.cost;
                        prev[e.node] = node;
                        prev_edge[e.node] = &e;

                        if (last_seen[e.node] != iteration) {
                            last_seen[e.node] = iteration;
                            next_nodes.push_back(e.node);
                        }
                    }

            swap(nodes, next_nodes);
        }

        return prev[sink] != -1;
    }

    pair<flow_t, cost_t> solve_min_cost_flow(int source, int sink, flow_t flow_goal = FLOW_INF) {
        assert(V >= 0);
        flow_t total_flow = 0;
        cost_t total_cost = 0;

        while (total_flow < flow_goal && bellman_ford(source, sink)) {
            flow_t path_cap = flow_goal - total_flow;
            cost_t cost_sum = 0;

            for (int node = sink; prev[node] != -1; node = prev[node])
                path_cap = min(path_cap, prev_edge[node]->capacity);

            for (int node = sink; prev[node] != -1; node = prev[node]) {
                edge *e = prev_edge[node];
                e->capacity -= path_cap;
                reverse_edge(*e).capacity += path_cap;
                cost_sum += e->cost;
            }

            total_flow += path_cap;
            total_cost += cost_sum * path_cap;
        }

        return make_pair(total_flow, total_cost);
    }
};


const int AB_MAX = 1e9 + 5;

struct stock {
    int A, B, index;

    bool operator<(const stock &other) const {
        return B < other.B;
    }
};

int N;
vector<stock> owned, wanted;

bool possible(long long time) {
    vector<long long> have, need;
    long long largest = 0;

    for (int i = 0, left = 0, right = 0; i < N; i++) {
        while (left < N && owned[left].B <= owned[i].B) {
            largest = max(largest, owned[left].A * time + owned[left].B);
            left++;
        }

        while (right < N && wanted[right].B <= owned[i].B) {
            largest = max(largest, wanted[right].A * time + wanted[right].B);
            right++;
        }

        have.push_back(largest);
    }

    for (stock &s : wanted)
        need.push_back(s.A * time + s.B);

    sort(have.begin(), have.end());
    sort(need.begin(), need.end());

    for (int i = 0; i < N; i++)
        if (have[i] < need[i])
            return false;

    return true;
}

int fewest_exchanges(long long time) {
    vector<stock> sorted_by_end;

    for (stock &s : wanted)
        sorted_by_end.push_back(s);

    sort(sorted_by_end.begin(), sorted_by_end.end(), [&](const stock &x, const stock &y) {
        return x.A * time + x.B < y.A * time + y.B;
    });

    vector<long long> ends(N);

    for (int i = 0; i < N; i++)
        ends[i] = sorted_by_end[i].A * time + sorted_by_end[i].B;

    int V = 4 * N + 2;
    int source = V - 2, sink = V - 1;
    min_cost_flow<int16_t, int16_t> graph(V);

    for (int i = 0; i < N; i++) {
        graph.add_directional_edge(source, i, 1, 0);
        graph.add_directional_edge(N + i, sink, 1, 0);
    }

    // Set up helper nodes. Nodes in [2 * N, 3 * N) connect to prefixes of the right side sorted by B. Nodes in
    // [3 * N, 4 * N) connect to prefixes of the right side sorted by A * time + B. The connections are given N capacity
    // to be effectively infinite.
    for (int i = 0; i < N; i++) {
        graph.add_directional_edge(2 * N + i, N + wanted[i].index, N, 0);

        if (i > 0)
            graph.add_directional_edge(2 * N + i, 2 * N + i - 1, N, 0);
    }

    for (int i = 0; i < N; i++) {
        graph.add_directional_edge(3 * N + i, N + sorted_by_end[i].index, N, 0);

        if (i > 0)
            graph.add_directional_edge(3 * N + i, 3 * N + i - 1, N, 0);
    }

    // Connect the left side to the appropriate helper nodes. Compare to H-hungarian.cc to see which edges we are
    // building here.
    for (int i = 0; i < N; i++) {
        int count = upper_bound(wanted.begin(), wanted.end(), owned[i]) - wanted.begin();

        if (count > 0)
            graph.add_directional_edge(i, 2 * N + count - 1, 1, 1);
    }

    for (int i = 0; i < N; i++) {
        long long end = owned[i].A * time + owned[i].B;
        int count = upper_bound(ends.begin(), ends.end(), end) - ends.begin();

        if (count > 0)
            graph.add_directional_edge(i, 3 * N + count - 1, 1, 1);
    }

    long long largest = 0;

    for (int i = 0, left = 0, right = 0; i < N; i++) {
        while (left < N && owned[left].B <= owned[i].B) {
            largest = max(largest, owned[left].A * time + owned[left].B);
            left++;
        }

        while (right < N && wanted[right].B <= owned[i].B) {
            largest = max(largest, wanted[right].A * time + wanted[right].B);
            right++;
        }

        int count = upper_bound(ends.begin(), ends.end(), largest) - ends.begin();

        if (count > 0)
            graph.add_directional_edge(i, 3 * N + count - 1, 1, 2);
    }

    auto result = graph.solve_min_cost_flow(source, sink);
    assert(result.first == N);
    return result.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    owned.resize(N);
    wanted.resize(N);

    for (stock &s : owned)
        cin >> s.A >> s.B;

    for (stock &s : wanted)
        cin >> s.A >> s.B;

    sort(owned.begin(), owned.end());
    sort(wanted.begin(), wanted.end());

    for (int i = 0; i < N; i++)
        owned[i].index = wanted[i].index = i;

    int low = 0, high = AB_MAX;

    while (low < high) {
        int mid = (low + high) / 2;

        if (possible(mid))
            high = mid;
        else
            low = mid + 1;
    }

    if (low == AB_MAX) {
        cout << -1 << '\n';
        return 0;
    }

    cout << low << ' ' << fewest_exchanges(low) << '\n';
}