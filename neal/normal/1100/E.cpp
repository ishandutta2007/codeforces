#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> topological_sort(const vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> in_degree(n, 0);
    vector<int> order;

    for (int i = 0; i < n; i++)
        for (int neighbor : adj[i])
            in_degree[neighbor]++;

    for (int i = 0; i < n; i++)
        if (in_degree[i] == 0)
            order.push_back(i);

    int current = 0;

    while (current < (int) order.size()) {
        int node = order[current++];

        for (int neighbor : adj[node])
            if (--in_degree[neighbor] == 0)
                order.push_back(neighbor);
    }

    return order;
}


struct edge {
    int node, cost, index;

    edge(int _node = -1, int _cost = -1, int _index = -1) : node(_node), cost(_cost), index(_index) {}
};

int N, M;
vector<vector<edge>> adj;

vector<vector<int>> setup_adj(int max_cost) {
    vector<vector<int>> topo_adj(N, vector<int>());

    for (int i = 0; i < N; i++)
        for (edge &e : adj[i])
            if (e.cost > max_cost)
                topo_adj[i].push_back(e.node);

    return topo_adj;
}

bool works(int max_cost) {
    return (int) topological_sort(setup_adj(max_cost)).size() == N;
}

int main() {
    scanf("%d %d", &N, &M);
    adj.assign(N, {});
    int max_c = 0;

    for (int i = 0; i < M; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        u--; v--;
        adj[u].emplace_back(v, c, i);
        max_c = max(max_c, c);
    }

    int low = 0, high = max_c;

    while (low < high) {
        int mid = (low + high) / 2;

        if (works(mid))
            high = mid;
        else
            low = mid + 1;
    }

    assert(low == high);
    int max_cost = low;
    vector<int> order = topological_sort(setup_adj(max_cost));
    assert((int) order.size() == N);
    vector<int> location(N, -1);

    for (int i = 0; i < N; i++)
        location[order[i]] = i;

    set<int> roads;

    for (int i = 0; i < N; i++)
        for (edge &e : adj[i])
            if (location[i] > location[e.node])
                roads.insert(e.index);

    vector<int> output(roads.begin(), roads.end());
    printf("%d %d\n", max_cost, (int) output.size());

    for (int i = 0; i < (int) output.size(); i++)
        printf("%d%c", output[i] + 1, i < (int) output.size() - 1 ? ' ' : '\n');
}