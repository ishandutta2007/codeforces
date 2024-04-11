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

    int N, M;
    cin >> N >> M;
    union_find UF(N);

    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        int current = -1;

        while (k-- > 0) {
            int x;
            cin >> x;
            x--;

            if (current >= 0)
                UF.unite(current, x);

            current = x;
        }
    }

    for (int i = 0; i < N; i++)
        cout << UF.size[UF.find(i)] << (i < N - 1 ? ' ' : '\n');
}