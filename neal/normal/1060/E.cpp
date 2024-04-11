#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> adj;
vector<int> depth, subtree;

void dfs(int node, int parent) {
    depth[node] = parent == -1 ? 0 : depth[parent] + 1;
    subtree[node] = 1;

    for (int child : adj[node])
        if (child != parent) {
            dfs(child, node);
            subtree[node] += subtree[child];
        }
}

int main() {
    scanf("%d", &N);
    adj.assign(N, vector<int>());
    depth.resize(N);
    subtree.resize(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);
    long long total_length = 0;
    int even = 0, odd = 0;

    for (int i = 0; i < N; i++) {
        total_length += (long long) subtree[i] * (N - subtree[i]);

        if (depth[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    long long odd_paths = (long long) even * odd;
    printf("%lld\n", (total_length + odd_paths) / 2);
}