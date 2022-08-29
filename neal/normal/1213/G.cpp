#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct union_find {
    vector<int> parent;
    vector<int> size;
    int components = 0;

    union_find(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        components = n;

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
        components--;
        return true;
    }
};


const int W_MAX = 2e5 + 5;

struct edge {
    int u, v, weight;

    bool operator<(const edge &other) const {
        return weight < other.weight;
    }
};

int N, M;
vector<edge> edges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N - 1; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
    }

    sort(edges.begin(), edges.end());
    union_find UF(N);
    vector<long long> answers(W_MAX, 0);
    long long pairs = 0;
    size_t index = 0;

    for (long long w = 0; w < W_MAX; w++) {
        while (index < edges.size() && edges[index].weight <= w) {
            if (UF.find(edges[index].u) != UF.find(edges[index].v)) {
                int u_root = UF.find(edges[index].u);
                int v_root = UF.find(edges[index].v);
                pairs += (long long) UF.size[u_root] * UF.size[v_root];
                UF.unite(u_root, v_root);
            }

            index++;
        }

        answers[w] = pairs;
    }

    for (int i = 0; i < M; i++) {
        int q;
        cin >> q;
        cout << answers[q] << (i < M - 1 ? ' ' : '\n');
    }
}