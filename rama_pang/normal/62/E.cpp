/* https://codeforces.com/problemset/problem/62/E */

#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;

struct TidalFlow {

    struct FlowEdge {
        int u, v;
        lint cap, flow = 0;
        FlowEdge(int _u, int _v, lint _cap) : u(_u), v(_v), cap(_cap) {}
    };

    int N, M = 0;
    int S, T;
    vector<FlowEdge> E;
    vector<vector<int>> G;
    vector<int> L;

    TidalFlow(int n) {
        N = n;
        G.resize(N);
    }

    void addEdge(int u, int v, lint cap) {
        G[u].emplace_back(M);
        G[v].emplace_back(M + 1);
        E.emplace_back(u, v, cap);
        E.emplace_back(v, u, 0);
        M += 2;
    }

    bool bfs() {
        queue<int> q;
        vector<int> level(N, -1);

        q.emplace(S);
        level[S] = 0;
        L.clear();

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
                    L.emplace_back(i);
                }
            }
        }

        return level[T] != -1;
    }

    lint tideCycle() {
        int sz = L.size();
        vector<lint> h(N), p(sz), l(N);

        h[S] = INF;
        for (int i = 0; i < sz; i++) {
            auto e = E[L[i]];
            p[i] = min(e.cap - e.flow, h[e.u]);
            h[e.v] += p[i];
        }

        l[T] = h[T];
        for (int i = sz - 1; i >= 0; i--) {
            auto e = E[L[i]];
            p[i] = min({p[i], h[e.u] - l[e.u], l[e.v]});
            l[e.v] -= p[i];
            l[e.u] += p[i];
        }

        h.assign(N, 0);
        h[S] = l[S];
        for (int i = 0; i < sz; i++) {
            auto e = E[L[i]];
            p[i] = min(p[i], h[e.u]);
            h[e.u] -= p[i];
            h[e.v] += p[i];
            E[L[i]].flow += p[i];
            E[L[i] ^ 1].flow -= p[i];
        }
    
        return h[T];
    }

    lint maxFlow(int s, int t) {
        S = s, T = t;
        lint f = 0;
        while (bfs()) {
            while (lint new_f = tideCycle()) {
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

    vector<vector<int>> v(N, vector<int>(M));
    vector<vector<int>> h(N, vector<int>(M));


    // vector<vector<int>> name(N, vector<int>(M, 0));
    // int Source = N * M, Sink = N * M + 1;

    // TidalFlow flow(N * M + 2);

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         name[i][j] = i * M + j;
    //     }
    // }

    // for (int i = 0; i < N; i++) {
    //     flow.addEdge(Source, name[i][0], INF);
    //     flow.addEdge(name[i][M - 1], Sink, INF);
    // }

    for (int j = 0; j < M - 1; j++) {
        for (int i = 0; i < N; i++) {
            cin >> h[i][j];
            // flow.addEdge(name[i][j], name[i][j + 1], h[i][j]);
            // flow.addEdge(name[i][j + 1], name[i][j], h[i][j]);
        }
    }

    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            cin >> v[i][j];
            // flow.addEdge(name[i][j], name[(i + 1) % N][j], v[i][j]);
            // flow.addEdge(name[(i + 1) % N][j], name[i][j], v[i][j]);
        }
    }

    // cout << flow.maxFlow(Source, Sink) << "\n";

    vector<int> diff(1 << N);
    for (int mask = 0; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            int j = (i + 1) % N;
            bool b1 = (mask & (1 << i)) == 0;
            bool b2 = (mask & (1 << j)) == 0;
            if (b1 != b2) {
                diff[mask] |= (1 << i);
            }
        }
    }

    vector<vector<lint>> dp(M, vector<lint>(1 << N, 0));
    for (int mask = 0; mask < (1 << N); mask++) {
        dp[0][mask] = INF;
    }
    dp[0][(1 << N) - 1] = 0;

    vector<lint> xsum(1 << N), ysum(1 << N);

    for (int j = 1; j < M; j++) {
        for (int mask = 0; mask < (1 << N); mask++) {
            dp[j][mask] = INF;
            xsum[mask] = ysum[mask] = 0;
            for (int i = 0; i < N; i++) {
                if (diff[mask] & (1 << i)) {
                    ysum[mask] += v[i][j];
                }
                if (mask & (1 << i)) {
                    xsum[mask] += h[i][j - 1];
                }
            }
        }
        for (int mask = 0; mask < (1 << N); mask++) {
            for (int prev = 0; prev < (1 << N); prev++) {
                dp[j][mask] = min(dp[j][mask], dp[j - 1][prev] + xsum[mask ^ prev] + ysum[mask]);
            }
        }
    }

    cout << dp[M - 1][0] << "\n";
    return 0;
}