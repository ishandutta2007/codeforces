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


int N, M;
vector<bool> A;
vector<bool> visited;
union_find UF;

void connect(int node, int source) {
    if (A[node])
        UF.unite(node, source);

    if (visited[node])
        return;

    visited[node] = true;

    for (int i = 0; i < N; i++)
        if (node >> i & 1)
            connect(node ^ 1 << i, source);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    A.assign(1 << N, false);

    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        A[a] = true;
    }

    UF.init(1 << N);
    visited.assign(1 << N, false);

    for (int mask = 0; mask < 1 << N; mask++)
        if (A[mask])
            connect(mask ^ ((1 << N) - 1), mask);

    int components = 0;

    for (int mask = 0; mask < 1 << N; mask++)
        if (A[mask] && UF.find(mask) == mask)
            components++;

    cout << components << '\n';
}