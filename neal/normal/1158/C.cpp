#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// Note: if there is a cycle, the size of the return will be < n
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


int N;
vector<int> next_index;
vector<vector<int>> adj;

void solve_case() {
    cin >> N;
    next_index.resize(N);

    for (auto &x : next_index) {
        cin >> x;

        if (x >= 0)
            x--;
    }

    adj.assign(N, {});

    for (int i = N - 1; i >= 0; i--) {
        if (next_index[i] >= 0 && next_index[i] < N)
            adj[i].push_back(next_index[i]);

        for (int j = i + 1; j < next_index[i]; j = max(next_index[j], j + 1))
            adj[j].push_back(i);
    }

    vector<int> order = topological_sort(adj);

    if ((int) order.size() < N) {
        cout << -1 << '\n';
        return;
    }

    vector<int> perm(N, -1);

    for (int i = 0; i < N; i++)
        perm[order[i]] = i;

    for (int i = 0; i < N; i++)
        cout << perm[i] + 1 << (i < N - 1 ? ' ' : '\n');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}