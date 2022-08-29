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


struct edge {
    int a, b, weight;

    bool operator<(const edge &other) const {
        return weight < other.weight;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<edge> edges(M);

    for (edge &e : edges) {
        cin >> e.a >> e.b >> e.weight;
        e.a--; e.b--;
    }

    int A = edges[0].a, B = edges[0].b;
    edges.erase(edges.begin());
    sort(edges.begin(), edges.end());
    union_find UF(N);

    for (edge &e : edges) {
        UF.unite(e.a, e.b);

        if (UF.find(A) == UF.find(B)) {
            cout << e.weight << '\n';
            return 0;
        }
    }

    cout << (int) 1e9 << '\n';
}