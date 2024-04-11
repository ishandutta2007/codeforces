#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct union_find {
    vector<int> parent;
    vector<int> size;
    vector<int> largest;

    union_find(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        largest.assign(n + 1, 0);

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
        largest[x] = max(largest[x], largest[y]);
        return true;
    }
};


const int INF = 1e9 + 5;

struct color {
    int index = -1, count = 0, first = INF, last = INF;

    bool operator<(const color &other) const {
        return make_pair(first, last) < make_pair(other.first, other.last);
    }
};

const int A_MAX = 2e5 + 5;

int N, Q;
vector<int> A;
vector<color> colors(A_MAX);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    A.resize(N);

    for (int a = 0; a < A_MAX; a++)
        colors[a].index = a;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        colors[A[i]].count++;
        colors[A[i]].first = min(colors[A[i]].first, i);
        colors[A[i]].last = i;
    }

    union_find UF(A_MAX);

    for (int a = 0; a < A_MAX; a++)
        UF.largest[a] = colors[a].count;

    sort(colors.begin(), colors.end());
    int max_last = -1, max_last_index = -1;

    for (int a = 0; a < A_MAX; a++) {
        if (colors[a].count == 0)
            continue;

        if (colors[a].first <= max_last)
            UF.unite(colors[a].index, max_last_index);

        if (colors[a].last > max_last) {
            max_last = colors[a].last;
            max_last_index = colors[a].index;
        }
    }

    int total = N;

    for (int a = 0; a < A_MAX; a++)
        if (UF.find(a) == a)
            total -= UF.largest[a];

    cout << total << '\n';
}