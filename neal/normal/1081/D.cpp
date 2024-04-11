#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


struct union_find {
    vector<int> parent;
    vector<int> size;

    union_find(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        return true;
    }
};


const int INF = 1e9 + 5;

struct edge {
    int node, weight;

    edge(int _node = -1, int _weight = -1) : node(_node), weight(_weight) {}
};

int N, M, K;
vector<int> special;
vector<vector<edge>> adj;

bool connected(int max_weight) {
    union_find uf(N);

    for (int i = 0; i < N; i++)
        for (edge &e : adj[i])
            if (e.weight <= max_weight)
                uf.unite(i, e.node);

    int root = -1;

    for (int i = 0; i < K; i++)
        if (root == -1)
            root = uf.find(special[i]);
        else if (root != uf.find(special[i]))
            return false;

    return true;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    special.resize(K);
    adj.assign(N, {});

    for (int &x : special) {
        scanf("%d", &x);
        x--;
    }

    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int low = 0, high = INF;

    while (low < high) {
        int mid = (low + high) / 2;

        if (connected(mid))
            high = mid;
        else
            low = mid + 1;
    }

    for (int i = 0; i < K; i++)
        printf("%d%c", low, i < K - 1 ? ' ' : '\n');
}