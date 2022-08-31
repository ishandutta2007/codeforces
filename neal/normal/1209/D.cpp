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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    union_find UF(N);

    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        UF.unite(x, y);
    }

    int total = 0;

    for (int i = 0; i < N; i++)
        if (UF.find(i) == i)
            total += UF.size[i] - 1;

    cout << K - total << '\n';
}