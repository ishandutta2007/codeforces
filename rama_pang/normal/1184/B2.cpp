#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;

struct TidalFlow {
    struct FlowEdge {
        int u, v;
        lint cap, flow = 0;
        FlowEdge(int u, int v, lint cap) : u(u), v(v), cap(cap) {}
    };

    int N, M = 0;
    vector<FlowEdge> E;
    vector<vector<int>> G;

    TidalFlow(int n) {
        N = n;
        G.resize(N);
    }

    void addEdge(int u, int v, lint cap) {
        E.emplace_back(u, v, cap);
        E.emplace_back(v, u, 0);
        G[u].emplace_back(M);
        G[v].emplace_back(M + 1);
        M += 2;
    }

    bool bfs(int s, int t, vector<int>& edge) {
        vector<int> level(N, -1);
        queue<int> q;

        q.emplace(s);
        level[s] = 0;
        edge.clear();

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto i : G[u]) {
                auto e = E[i];
                if (e.cap - e.flow == 0) {
                    continue;
                }
                if (level[e.v] == -1) {
                    level[e.v] = level[u] + 1; 
                    q.emplace(e.v);
                }
                if (level[e.v] == level[u] + 1) {
                    edge.emplace_back(i);
                }
            }
        }

        return level[t] != -1;
    }

    lint tide(int s, int t, vector<int>& edge) {
        vector<lint> h(N), p(edge.size()), l(N);
        int sz = (int)edge.size();

        h[s] = INF;
        for (int i = 0; i < sz; i++) {
            auto e = E[edge[i]];
            p[i] = min(e.cap - e.flow, h[e.u]);
            h[e.v] += p[i];
        }

        l[t] = h[t];
        for (int i = sz - 1; i >= 0; i--) {
            auto e = E[edge[i]];
            p[i] = min({p[i], h[e.u] - l[e.u], l[e.v]});
            l[e.v] -= p[i];
            l[e.u] += p[i];
        }

        h.assign(N, 0);
        h[s] = l[s];
        for (int i = 0; i < sz; i++) {
            auto e = E[edge[i]];
            p[i] = min(p[i], h[e.u]);
            h[e.u] -= p[i];
            h[e.v] += p[i];
            E[edge[i]].flow += p[i];
            E[edge[i] ^ 1].flow -= p[i];
        }

        return h[t];
    }

    lint maxFlow(int s, int t) {
        lint f = 0;
        vector<int> edge;
        while (bfs(s, t, edge)) {
            while (lint new_f = tide(s, t, edge)) {
                f += new_f;
            }
        }
        return f;
    }

};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<lint>> dist(N, vector<lint>(N, INF));
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        dist[u][v] = min(dist[u][v], 1ll);
        dist[v][u] = min(dist[v][u], 1ll);
    }
    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int S, B, K, H;
    cin >> S >> B >> K >> H;
    vector<pair<int, pair<int, int>>> Ship(S), Base(B);
    for (int i = 0; i < S; i++) {
        cin >> Ship[i].first >> Ship[i].second.first >> Ship[i].second.second;
        Ship[i].first--;
    }
    for (int i = 0; i < B; i++) {
        cin >> Base[i].first >> Base[i].second.first;
        Base[i].first--;
    }

    TidalFlow flow(S + B + 2); // source = S + B, sink = S + B + 1

    for (int i = 0; i < S; i++) {
        for (int j = 0; j < B; j++) {
            if (Ship[i].second.first >= Base[j].second.first && 
                dist[Ship[i].first][Base[j].first] <= Ship[i].second.second) {
                
                flow.addEdge(i, j + S, 1);
            }
        }
    }

    for (int i = 0; i < S; i++) {
        flow.addEdge(S + B, i, 1);
    }
    for (int i = 0; i < B; i++) {
        flow.addEdge(S + i, S + B + 1, 1);
    }

    cout << min(1ll * K * flow.maxFlow(S + B, S + B + 1), 1ll * S * H) << "\n";
    return 0;
}