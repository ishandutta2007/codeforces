#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> adj;
vector<int> parent;
vector<int> depth;
vector<int> sequence;

void dfs(int node) {
    depth[node] = parent[node] == -1 ? 0 : depth[parent[node]] + 1;

    for (int neighbor : adj[node])
        if (neighbor != parent[node]) {
            parent[neighbor] = node;
            dfs(neighbor);
        }
}

bool verify() {
    assert((int) sequence.size() == N);

    if (sequence[0] != 1)
        return false;

    for (int i = 0; i + 1 < N; i++)
        if (depth[sequence[i]] > depth[sequence[i + 1]])
            return false;

    vector<int> level;
    level.push_back(1);
    int seq_index = 1;

    while (!level.empty()) {
        vector<int> next_level;

        for (int node : level) {
            int children = adj[node].size() - (parent[node] == -1 ? 0 : 1);

            for (int i = 0; i < children; i++) {
                if (seq_index >= N || parent[sequence[seq_index]] != node)
                    return false;

                next_level.push_back(sequence[seq_index]);
                seq_index++;
            }
        }

        level = next_level;
    }

    return seq_index == N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    adj.resize(N + 1);
    depth.resize(N + 1);
    parent.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    parent[1] = -1;
    dfs(1);
    sequence.resize(N);

    for (int i = 0; i < N; i++)
        cin >> sequence[i];

    cout << (verify() ? "Yes" : "No") << '\n';
}