#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> color;
vector<vector<int>> adj;

// down[node] = max diff for node's subtree. must include node.
// up[node] = max diff for the subtree of node that its parent is responsible for, empty subset included.
vector<int> down, up;

void solve_down(int node, int parent) {
    down[node] = 2 * color[node] - 1;

    for (int child : adj[node])
        if (child != parent) {
            solve_down(child, node);
            down[node] += max(down[child], 0);
        }
}

void solve_up(int node, int parent) {
    for (int child : adj[node])
        if (child != parent) {
            up[child] = max(up[node] + down[node] - max(down[child], 0), 0);
            solve_up(child, node);
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    color.resize(N);
    adj.assign(N, {});

    for (int &c : color)
        cin >> c;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    down.resize(N);
    solve_down(0, -1);
    up.resize(N);
    up[0] = 0;
    solve_up(0, -1);

    for (int i = 0; i < N; i++)
        cout << down[i] + up[i] << (i < N - 1 ? ' ' : '\n');
}