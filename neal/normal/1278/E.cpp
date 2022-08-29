#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> L, R;
vector<vector<int>> adj;
vector<int> subtree_size;

void dfs(int node, int parent) {
    subtree_size[node] = 1;

    // Erase the edge to parent.
    if (parent >= 0)
        adj[node].erase(find(adj[node].begin(), adj[node].end(), parent));

    for (int child : adj[node]) {
        dfs(child, node);
        subtree_size[node] += subtree_size[child];
    }
}

void solve(int node, int start, int end) {
    L[node] = start;
    R[node] = end - 1 - 2 * (subtree_size[node] - 1) + adj[node].size();
    int subtract = adj[node].size();

    for (int child : adj[node]) {
        solve(child, R[node] - subtract, end);
        subtract--;
        end -= 2 * subtree_size[child] - 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    adj.assign(N, {});

    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    subtree_size.assign(N, 0);
    dfs(0, -1);

    L.assign(N, -1);
    R.assign(N, -1);
    solve(0, 0, 2 * N);

    for (int i = 0; i < N; i++)
        cout << L[i] + 1 << ' ' << R[i] + 1 << '\n';
}