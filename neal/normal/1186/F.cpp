#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct edge {
    int node, rev, index;
    bool done = false;

    edge() {}

    edge(int _node, int _rev, int _index) : node(_node), rev(_rev), index(_index) {}
};

int N, M;
vector<vector<edge>> adj;

void add_edge(int u, int v) {
    edge uv_edge(v, adj[v].size() + (u == v ? 1 : 0), -1);
    edge vu_edge(u, adj[u].size(), -1);
    adj[u].push_back(uv_edge);
    adj[v].push_back(vu_edge);
}

edge &reverse_edge(const edge &e) {
    return adj[e.node][e.rev];
}

vector<size_t> edge_index;

void eulerian_dfs(int node, edge *from_edge, vector<pair<int, edge*>> &tour) {
    while (edge_index[node] < adj[node].size()) {
        edge &e = adj[node][edge_index[node]];

        if (!e.done) {
            e.done = true;
            reverse_edge(e).done = true;
            eulerian_dfs(e.node, &e, tour);
        }

        edge_index[node]++;
    }

    // Generate the actual tour in reverse.
    tour.emplace_back(node, from_edge);
}

vector<pair<int, edge*>> solve_all_eulerian_circuits() {
    if (M == 0)
        return {};

    edge_index.assign(N, 0);
    vector<pair<int, edge*>> tour;

    for (int i = 0; i < N; i++)
        if (edge_index[i] < adj[i].size())
            eulerian_dfs(i, nullptr, tour);

    reverse(tour.begin(), tour.end());
    int T = tour.size();

    // Shift the edges down one index.
    for (int i = 0; i + 1 < T; i++)
        tour[i].second = tour[i + 1].second;

    tour.back().second = nullptr;
    return tour;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    adj.assign(N + 1, {});

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    for (int i = 1; i <= N; i++)
        if (adj[i].size() % 2 != 0) {
            add_edge(0, i);
            M++;
        }

    N++;
    vector<pair<int, edge*>> tour = solve_all_eulerian_circuits();
    int T = tour.size();
    vector<bool> keep(T, true);

    for (int i = 0; i < T; i++)
        if (tour[i].second == nullptr || tour[i].first == 0 || tour[i + 1].first == 0)
            keep[i] = false;

    for (int i = 1; i + 1 < T; i++)
        if (keep[i - 1] && keep[i + 1])
            keep[i] = false;

    int K = 0;

    for (int i = 0; i < T; i++)
        K += keep[i];

    cout << K << '\n';

    for (int i = 0; i < T; i++)
        if (keep[i])
            cout << tour[i].first << ' ' << tour[i + 1].first << '\n';
}