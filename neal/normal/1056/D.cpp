#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> parent;
vector<vector<int>> children;
vector<int> leaf_counts;

int dfs(int node) {
    int leaves = 0;

    for (int child : children[node])
        leaves += dfs(child);

    leaves = max(leaves, 1);
    leaf_counts.push_back(leaves);
    return leaves;
}

int main() {
    scanf("%d", &N);
    parent.assign(N, -1);
    children.assign(N, {});

    for (int i = 1; i < N; i++) {
        scanf("%d", &parent[i]);
        parent[i]--;
        children[parent[i]].push_back(i);
    }

    dfs(0);
    assert((int) leaf_counts.size() == N);
    sort(leaf_counts.begin(), leaf_counts.end());

    for (int i = 0; i < N; i++)
        printf("%d%c", leaf_counts[i], i < N - 1 ? ' ' : '\n');
}