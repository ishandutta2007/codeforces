#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct union_find {
    vector<int> parent;
    vector<int> size;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
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

template<typename T_edge>
struct kruskal {
    struct edge {
        int a, b;
        T_edge weight;
        int index = -1;
        bool in_tree = false;

        edge() {}

        edge(int _a, int _b, T_edge _weight, int _index = -1) : a(_a), b(_b), weight(_weight), index(_index) {}

        bool operator<(const edge &other) const {
            return weight < other.weight;
        }
    };

    union_find UF;
    vector<edge> edges;
    vector<bool> original_in_tree;

    kruskal(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        UF.init(n);
        edges = {};
    }

    void add_edge(int a, int b, T_edge weight) {
        edges.emplace_back(a, b, weight, edges.size());
        original_in_tree.push_back(false);
    }

    template<typename T_sum>
    T_sum solve() {
        sort(edges.begin(), edges.end());
        T_sum total = 0;

        for (edge &e : edges)
            if (UF.unite(e.a, e.b)) {
                total += e.weight;
                e.in_tree = true;
                original_in_tree[e.index] = true;
            }

        return total;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> X(N), Y(N);

    for (int i = 0; i < N; i++)
        cin >> X[i] >> Y[i];

    vector<int> C(N), K(N);

    for (int i = 0; i < N; i++)
        cin >> C[i];

    for (int i = 0; i < N; i++)
        cin >> K[i];

    kruskal<long long> mst(N + 1);

    for (int i = 0; i < N; i++)
        mst.add_edge(i, N, C[i]);

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            mst.add_edge(i, j, (long long) (K[i] + K[j]) * (abs(X[i] - X[j]) + abs(Y[i] - Y[j])));

    long long total = mst.solve<long long>();
    cout << total << '\n';
    vector<int> power_stations;
    vector<pair<int, int>> connections;

    for (kruskal<long long>::edge &e : mst.edges)
        if (e.in_tree) {
            if (e.a == N || e.b == N)
                power_stations.push_back(e.a + e.b - N);
            else
                connections.emplace_back(e.a, e.b);
        }

    sort(power_stations.begin(), power_stations.end());
    cout << power_stations.size() << '\n';

    for (int i = 0; i < (int) power_stations.size(); i++)
        cout << power_stations[i] + 1 << (i < (int) power_stations.size() - 1 ? ' ' : '\n');

    cout << connections.size() << '\n';

    for (pair<int, int> &connection : connections)
        cout << connection.first + 1 << ' ' << connection.second + 1 << '\n';
}