#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;
vector<bool> in_heap;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    adj.assign(N, {});
    visited.assign(N, false);
    in_heap.assign(N, false);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> permutation;
    priority_queue<int, vector<int>, greater<int>> heap;
    heap.push(0);
    in_heap[0] = true;

    while (!heap.empty()) {
        int top = heap.top();
        heap.pop();

        if (visited[top])
            continue;

        visited[top] = true;
        permutation.push_back(top);

        for (int neighbor : adj[top])
            if (!in_heap[neighbor]) {
                heap.push(neighbor);
                in_heap[neighbor] = true;
            }
    }

    for (int i = 0; i < N; i++)
        cout << permutation[i] + 1 << (i < N - 1 ? ' ' : '\n');
}