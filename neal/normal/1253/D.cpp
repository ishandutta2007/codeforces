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

        if (x > y)
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        components--;
        return true;
    }
};


int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    union_find UF(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        UF.unite(u, v);
    }

    vector<vector<int>> comps(N);

    for (int i = 0; i < N; i++)
        comps[UF.find(i)].push_back(i);

    int edges_needed = UF.components;
    int maximum = -1, count = 0;

    for (int root = 0; root < N; root++)
        if (!comps[root].empty()) {
            for (int x : comps[root]) {
                maximum = max(maximum, x);
                count++;
            }

            if (maximum == count - 1)
                edges_needed--;
        }

    cout << edges_needed << '\n';
}