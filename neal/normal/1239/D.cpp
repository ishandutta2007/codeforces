#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct SCC {
    int V = 0;
    vector<vector<int>> adj;
    vector<int> tour_index, low_link;
    int tour;

    vector<int> stack;
    vector<bool> in_stack;
    int S = 0;

    vector<vector<int>> components;
    vector<int> which_component;

    SCC(int v = 0) {
        init(v);
    }

    SCC(const vector<vector<int>> &_adj) {
        init(_adj);
    }

    void init(int v) {
        V = v;
        adj.assign(V, {});
    }

    void init(const vector<vector<int>> &_adj) {
        adj = _adj;
        V = adj.size();
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
    }

    // Tarjan's algorithm.
    void dfs(int node) {
        tour_index[node] = tour++;
        low_link[node] = tour_index[node];
        stack[S++] = node;
        in_stack[node] = true;

        for (int neighbor : adj[node])
            if (tour_index[neighbor] < 0) {
                // neighbor is part of our subtree.
                dfs(neighbor);
                low_link[node] = min(low_link[node], low_link[neighbor]);
            } else if (in_stack[neighbor]) {
                // neighbor is our tree ancestor, so it's a candidate for low_link.
                low_link[node] = min(low_link[node], tour_index[neighbor]);
            }

        if (low_link[node] == tour_index[node]) {
            // node is the highest node in an SCC, which includes everything on the stack up to it.
            components.emplace_back();
            vector<int> &component = components.back();
            int x;

            do {
                assert(S > 0);
                x = stack[--S];
                in_stack[x] = false;
                which_component[x] = (int) components.size() - 1;
                component.push_back(x);
            } while (x != node);
        }
    }

    void build() {
        tour_index.assign(V, -1);
        low_link.assign(V, -1);
        which_component.assign(V, -1);

        S = 0;
        stack.resize(V);
        in_stack.assign(V, false);
        tour = 0;

        // Note that Tarjan's algorithm provides the SCCs in reverse topological order.
        components = {};

        for (int i = 0; i < V; i++)
            if (tour_index[i] < 0)
                dfs(i);
    }
};


void solve_case() {
    int N, M;
    cin >> N >> M;
    SCC scc(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        scc.add_edge(a, b);
    }

    scc.build();

    if ((int) scc.components[0].size() == N) {
        cout << "No" << '\n';
        return;
    }

    cout << "Yes" << '\n';
    vector<int> jury = scc.components[0];
    vector<int> cats;
    vector<bool> in_jury(N, false);

    for (int x : jury)
        in_jury[x] = true;

    for (int i = 0; i < N; i++)
        if (!in_jury[i])
            cats.push_back(i);

    cout << jury.size() << ' ' << cats.size() << '\n';

    for (int i = 0; i < (int) jury.size(); i++)
        cout << jury[i] + 1 << (i < (int) jury.size() - 1 ? ' ' : '\n');

    for (int i = 0; i < (int) cats.size(); i++)
        cout << cats[i] + 1 << (i < (int) cats.size() - 1 ? ' ' : '\n');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}