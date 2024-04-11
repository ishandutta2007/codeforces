#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<vector<pair<int, int>>> adj;
vector<int> parent;
vector<long long> dist;
vector<int> farthest;

int dfs(int node, int prev = -1, long long d = 0) {
    parent[node] = prev;
    dist[node] = d;
    farthest[node] = node;

    for (pair<int, int> p : adj[node]) {
        if (p.first == prev)
            continue;

        int child_farthest = dfs(p.first, node, d + p.second);

        if (dist[child_farthest] > dist[farthest[node]])
            farthest[node] = child_farthest;
    }

    return farthest[node];
}

bool solvable(long long max_dist) {
    int deepest = dfs(0);
    int path_start = deepest;

    // Find the highest ancestor who is at most max_dist away from deepest.
    while (parent[path_start] != -1 && dist[parent[path_start]] >= dist[deepest] - max_dist)
        path_start = parent[path_start];

    dfs(path_start);
    int node = path_start, depth = 0;

    while (node != -1 && depth <= K) {
        int child = -1;

        for (pair<int, int> p : adj[node]) {
            if (p.first == parent[node])
                continue;

            if (dist[farthest[p.first]] - dist[node] > max_dist) {
                // Can't have two children who both have nodes farther than max_dist.
                if (child != -1)
                    return false;

                child = p.first;
            }
        }

        node = child;
        depth++;
    }

    return depth <= K;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    adj.resize(N);
    parent.resize(N);
    dist.resize(N);
    farthest.resize(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        adj[u].emplace_back(v, d);
        adj[v].emplace_back(u, d);
    }

    long long low = 0, high = dist[dfs(0)];

    while (low < high) {
        long long mid = (low + high) / 2;

        if (solvable(mid))
            high = mid;
        else
            low = mid + 1;
    }

    cout << low << '\n';
    return 0;
}