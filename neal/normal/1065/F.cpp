#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<vector<int>> children;

// Returns {commit count, non-commit count, distance to nearest leaf}
vector<int> dfs(int node) {
    if (children[node].empty())
        return {1, 1, 0};

    int commit = 0, non_commit = 0, nearest = N, max_diff = 0;

    for (int child : children[node]) {
        vector<int> result = dfs(child);
        commit += result[1];
        non_commit += result[1];
        max_diff = max(max_diff, result[0] - result[1]);
        nearest = min(nearest, result[2] + 1);
    }

    // When nearest >= K, none of our leaves can return to our parent anymore.
    if (nearest >= K)
        non_commit = 0;

    return {commit + max_diff, non_commit, nearest};
}

int main() {
    scanf("%d %d", &N, &K);
    children.resize(N);

    for (int i = 1; i < N; i++) {
        int p;
        scanf("%d", &p);
        p--;
        children[p].push_back(i);
    }

    printf("%d\n", dfs(0)[0]);
}