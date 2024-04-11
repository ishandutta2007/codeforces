#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int N;
vector<int> parent;
vector<vector<int>> children;
vector<int> dp_moves, dp_depth;

void dfs(int node) {
    int sum = 0, biggest = 0;

    for (int child : children[node]) {
        dfs(child);
        sum += dp_moves[child] + dp_depth[child];
        biggest = max(biggest, dp_depth[child]);
    }

    dp_moves[node] = sum - biggest;
    dp_depth[node] = biggest + 1;
}

vector<int> order;
vector<int> operations;

void build_order(int node) {
    order.push_back(node);

    sort(children[node].begin(), children[node].end(), [&](int a, int b) {
        return dp_depth[a] < dp_depth[b];
    });

    for (int child : children[node])
        build_order(child);

    int previous = -1;

    for (int child : children[node]) {
        if (previous >= 0) {
            for (int i = 0; i < dp_depth[previous]; i++)
                operations.push_back(child);
        }

        previous = child;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    parent.assign(N, -1);
    children.assign(N, {});

    for (int i = 1; i < N; i++) {
        cin >> parent[i];
        children[parent[i]].push_back(i);
    }

    dp_moves.assign(N, INF);
    dp_depth.assign(N, INF);
    dfs(0);

    order.clear();
    build_order(0);

    for (int i = 0; i < N; i++)
        cout << order[i] << (i < N - 1 ? ' ' : '\n');

    cout << dp_moves[0] << '\n';

    for (int i = 0; i < (int) operations.size(); i++)
        cout << operations[i] << (i < (int) operations.size() - 1 ? ' ' : '\n');
}