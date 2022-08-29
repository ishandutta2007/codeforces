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

int N, L;
vector<pair<long long, int>> C;
vector<vector<int>> adj;
vector<int> leaf_start, leaf_end;

void dfs(int node, int parent) {
    leaf_start[node] = L;

    if (node != 0 && adj[node].size() == 1)
        L++;

    for (int neighbor : adj[node])
        if (neighbor != parent)
            dfs(neighbor, node);

    leaf_end[node] = L;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    C.resize(N);
    adj.assign(N, {});

    for (int i = 0; i < N; i++) {
        cin >> C[i].first;
        C[i].second = i;
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    leaf_start.assign(N, -1);
    leaf_end.assign(N, -1);
    L = 0;
    dfs(0, -1);

    union_find UF(L + 1);
    sort(C.begin(), C.end());
    vector<int> optimal;
    long long S = 0;

    for (int i = 0, j = 0; i < N; i = j) {
        while (j < N && C[i].first == C[j].first)
            j++;

        for (int k = i; k < j; k++) {
            int index = C[k].second;
            int start = leaf_start[index], end = leaf_end[index];

            if (UF.find(start) != UF.find(end))
                optimal.push_back(index);
        }

        for (int k = i; k < j; k++) {
            int index = C[k].second;
            int start = leaf_start[index], end = leaf_end[index];

            if (UF.unite(start, end))
                S += C[k].first;
        }
    }

    int K = optimal.size();
    sort(optimal.begin(), optimal.end());
    cout << S << ' ' << K << '\n';

    for (int i = 0; i < K; i++)
        cout << optimal[i] + 1 << (i < K - 1 ? ' ' : '\n');
}