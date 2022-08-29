#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct edge {
    int node, length;

    edge(int _node = -1, int _length = -1) : node(_node), length(_length) {}
};

int N;
vector<int> gas;
vector<vector<edge>> adj;
long long best;

long long dfs(int node, int parent) {
    long long down = gas[node];

    for (edge &e : adj[node])
        if (e.node != parent) {
            long long child = dfs(e.node, node) - e.length;
            best = max(best, down + child);
            down = max(down, child + gas[node]);
        }

    return down;
}

int main() {
    scanf("%d", &N);
    gas.resize(N);
    adj.assign(N, {});

    for (int &w : gas)
        scanf("%d", &w);

    for (int i = 0; i < N - 1; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        u--; v--;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    best = *max_element(gas.begin(), gas.end());
    dfs(0, -1);
    printf("%lld\n", best);
}