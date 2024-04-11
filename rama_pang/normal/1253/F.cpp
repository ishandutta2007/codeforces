#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M, K, Q;
    cin >> N >> M >> K >> Q;

    vector<tuple<int, int, lint>> E, Et;
    vector<vector<pair<int, lint>>> G(N), Gt(N);

    for (int i = 0; i < M; i++) {
        int u, v; lint w; cin >> u >> v >> w;
        u--; v--;
        E.push_back(tuple<int, int, lint>{u, v, w});
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    function<vector<lint>()> dijkstra = [&] {
        vector<lint> dist(N, -1);
        priority_queue<pair<lint, int>, vector<pair<lint, int>>, greater<pair<lint, int>>> pq;

        for (int i = 0; i < K; i++) {
            pq.push({0, i});
            dist[i] = 0;
        }

        while (!pq.empty()) {
            int u; lint w;
            u = pq.top().second;
            w = pq.top().first;
            pq.pop();
            if (w != dist[u]) continue;

            for (auto i : G[u]) {
                if (dist[i.first] == -1 || dist[i.first] > dist[u] + i.second) {
                    dist[i.first] = dist[u] + i.second;
                    pq.push({dist[i.first], i.first});
                }
            }
        }

        return dist;
    };

    vector<lint> dist = dijkstra();

    for (auto i : E) {
        int u = get<0>(i);
        int v = get<1>(i);
        lint w = get<2>(i);
        Et.push_back(tuple<int, int, lint>{u, v, w + dist[u] + dist[v]});
    }

    sort(Et.begin(), Et.end(), [&](tuple<int, int, lint> a, tuple<int, int, lint> b) {
        return get<2>(a) < get<2>(b);
    });

    vector<int> root(N);
    iota(root.begin(), root.end(), 0);
    function<int(int)> find_root = [&](int n) {
        return (root[n] == n)? n : root[n] = find_root(root[n]);
    };

    for (auto i : Et) {
        int u, v; u = get<0>(i); v = get<1>(i);
        lint w = get<2>(i);

        if (find_root(u) == find_root(v)) continue;
        root[find_root(u)] = find_root(v);
        
        Gt[u].push_back({v, w});
        Gt[v].push_back({u, w});
    }

    vector<vector<pair<int, lint>>> lift(N + 1, vector<pair<int, lint>>(20, make_pair(N, -1)));
    vector<int> depth(N + 1, -1);
    function<void(int, int, int)> dfs = [&](int n, int p, int d) {
        depth[n] = d;
        for (auto i : Gt[n]) if (i.first != p) {
            dfs(i.first, n, d + 1);

            lift[i.first][0].first = n;
            lift[i.first][0].second = i.second;
        }
        return;
    };

    dfs(0, N, 0);

    for (int j = 1; j < 20; j++) {
        for (int i = 0; i < N; i++) {
            lift[i][j].first = lift[lift[i][j - 1].first][j - 1].first;
            lift[i][j].second = max(lift[i][j - 1].second, lift[lift[i][j - 1].first][j - 1].second);
        }
    }

    function<lint(int, int)> solve = [&](int a, int b) {
        lint res = 0;
        if (depth[a] > depth[b]) swap(a, b);

        for (int j = 19; j >= 0; j--) {
            if (depth[lift[b][j].first] > depth[a]) {
                res = max(res, lift[b][j].second);
                b = lift[b][j].first;
            }
        }
        
        if (depth[b] > depth[a]) {
            res = max(res, lift[b][0].second);
            b = lift[b][0].first;
        }
        
        assert(depth[a] == depth[b]);
        
        for (int j = 19; j >= 0; j--) {
            if (lift[a][j].first != lift[b][j].first) {
                res = max(res, lift[a][j].second);
                res = max(res, lift[b][j].second);
                a = lift[a][j].first;
                b = lift[b][j].first;
            }
        }

        if (a == b) return res;

        res = max(res, lift[a][0].second);
        res = max(res, lift[b][0].second);
        a = lift[a][0].first;
        b = lift[b][0].first;

        assert(a == b);

        return res;
    };

    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        cout << solve(a, b) << "\n";
    }

    return 0;

}