/*  Link (Codeforces): https://codeforces.com/contest/196/problem/E

    Solution:
    Use multisource Dijstra from all portals. Then consider original edges - if they have different
    portal source, then add an edge between portals with cost (d[i] + d[j] + cost(i, j)) for edge (i, j).
    It can be proved that one of these edges represent a shortest path between two portals. Then we
    run an MST algorithm to connect all portals.
*/

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, int>> E;
    vector<vector<pair<int, lint>>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
        E.emplace_back(u, v, w);
    }

    vector<int> source(N, -1);
    vector<lint> distance(N, -1);
    priority_queue<pair<lint, int>, vector<pair<lint, int>>, greater<pair<lint, int>>> pq;

    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int v;
        cin >> v;
        v--;
        source[v] = i;
        distance[v] = 0;
        pq.emplace(0, v);
    }

    while (!pq.empty()) {
        int u = pq.top().second;
        lint w = pq.top().first;
        pq.pop();
        if (distance[u] != w) {
            continue;
        }
        for (auto i : G[u]) {
            int v = i.first;
            lint c = i.second;
            if (distance[v] == -1 || distance[v] > distance[u] + c) {
                distance[v] = distance[u] + c;
                source[v] = source[u];
                pq.emplace(distance[v], v);
            }
        }
    }

    vector<pair<lint, pair<int, int>>> Edge;
    for (auto i : E) {
        int u = get<0>(i);
        int v = get<1>(i);
        int w = get<2>(i);

        if (source[u] != source[v]) {
            Edge.push_back({distance[u] + distance[v] + w, {source[u], source[v]}});
        }
    }
    vector<int> p(N);
    iota(begin(p), end(p), 0);
    function<int(int)> par = [&](int n) {
        if (p[n] == n) {
            return n;
        }
        return p[n] = par(p[n]);
    };
    
    lint ans = distance[0];
    sort(begin(Edge), end(Edge));
    for (auto i : Edge) {
        int u = i.second.first;
        int v = i.second.second;
        lint w = i.first;
        if (par(u) != par(v)) {
            p[par(u)] = par(v);
            ans += w;
        }
    }

    cout << ans << "\n";
    return 0;
}