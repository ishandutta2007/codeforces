#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<vector<int>> adj;
int answer = 0;

int dfs(int node, int parent = -1) {
    vector<int> dists;

    for (int neighbor : adj[node])
        if (neighbor != parent)
            dists.push_back(dfs(neighbor, node) + 1);

    sort(dists.begin(), dists.end());

    while (dists.size() >= 2 && dists.back() + dists[dists.size() - 2] > K) {
        dists.pop_back();
        answer++;
    }

    return dists.empty() ? 0 : dists.back();
}

int main() {
    scanf("%d %d", &N, &K);
    adj.resize(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root = 0;

    while (adj[root].size() == 1)
        root++;

    assert(dfs(root) > 0);
    answer++;
    printf("%d\n", answer);
}