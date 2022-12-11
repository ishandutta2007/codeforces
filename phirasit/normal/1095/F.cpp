#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v;
    long long w;

    bool operator < (const Edge &e) const {
        return w < e.w;
    }
};

vector<long long> A;
vector<int> group;
vector<Edge> edge;
int n, m;

int find(int x) {
    if (x == group[x]) return x;
    return group[x] = find(group[x]);
}
int main() {

    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    A.resize(n+1);
    int mn = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        if (A[i] < A[mn]) {
            mn = i;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (i != mn) {
            edge.push_back({i, mn, A[i] + A[mn]});
        }
    }

    for (int i = 0; i < m; ++i) {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        edge.push_back(e);
    }

    sort(edge.begin(), edge.end());

    group.resize(n+1);
    for (int i = 1; i <= n; ++i) group[i] = i;

    long long ans = 0;
    for (Edge &e : edge) {
        if (find(e.u) != find(e.v)) {
            ans += e.w;
            group[find(e.v)] = find(e.u);
        }
    }

    cout << ans << endl;

    return 0;
}