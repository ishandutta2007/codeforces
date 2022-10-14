/**
 * A triple is non-beautiful if 1 team wins over the others.
 * Thus if this team won i matches, then there are i(i + 1) / 2
 * non-beautiful triples.
 * 
 * Let (w1, w2, w3, ..., wn) be thu number of wins of each
 * team. The number of non-beautiful triples would be
 * (w1(w1 - 1) + w2(w2 - 1) + ... + wn(wn - 1)) / 2.
 * 
 * Since w1 + w2 + w3 + ... + wn = n(n - 1) / 2, we only
 * need to minimize w1 ^ 2 + w2 ^ 2 + ... + wn ^ 2.
 * 
 * Use min-cost max-flow to compute answer in O(n ^ 4).
 * (There are O(n ^ 2) nodes and edges, however the graph
 * is directed from left to right. Thus in O(n ^ 2) iterations
 * of SPFA, there will no longer be a valid path. Since there
 * is no negative cycle, and all edges have cost 0 except the
 * last layer, the SPFA only needes O(n ^ 2) to find the shortest
 * path (shortest path in DAG). Thus the time complexity is O(n ^ 4)).
 * 
**/

#include <bits/stdc++.h>
using namespace std;

struct MinCostMaxFlow {
    const int INF = 1e9;

    struct Edge {
        int u; // from
        int v; // to
        int cap, flow = 0;
        int cost;
        Edge(int _u, int _v, int _cap, int _cost) : u(_u), v(_v), cap(_cap), cost(_cost) {}
    };

    int N, M = 0;
    int S, T;
    vector<Edge> E;
    vector<vector<int>> G;

    queue<int> q;
    vector<bool> in_queue;
    vector<int> dist, pre;

    MinCostMaxFlow(int n) {
        N = n;
        G.resize(N);
        in_queue.resize(N);
        dist.resize(N);
        pre.resize(N);
    }

    void addEdge(int u, int v, int cap, int cost) {
        G[u].emplace_back(M);
        G[v].emplace_back(M + 1);
        E.emplace_back(u, v, cap, cost);
        E.emplace_back(v, u, 0, -cost);
        M += 2;
    }

    int spfa() { // Shortest Path Faster Algorithm
        fill(begin(dist), end(dist), INF);
        fill(begin(in_queue), end(in_queue), false);
        fill(begin(pre), end(pre), 0);

        q.emplace(S);
        dist[S] = 0;
        in_queue[S] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue[u] = false;
            for (auto i : G[u]) {
                auto e = E[i];
                if (e.cap - e.flow > 0 && dist[e.v] > dist[e.u] + e.cost) {
                    dist[e.v] = dist[e.u] + e.cost;
                    pre[e.v] = i;
                    if (!in_queue[e.v]) {
                        q.emplace(e.v);
                        in_queue[e.v] = true;
                    }
                }
            }
        }

        if (dist[T] == INF) {
            return 0;
        }

        int push = INF;
        int cur = T;
        while (cur != S) {
            push = min(push, E[pre[cur]].cap - E[pre[cur]].flow);
            cur = E[pre[cur]].u;
        }
        cur = T;
        while (cur != S) {
            E[pre[cur]].flow += push;
            E[pre[cur] ^ 1].flow -= push;
            cur = E[pre[cur]].u;
        }

        return push;
    }

    pair<int, int> MCMF(int s, int t) { // (flow, cost)
        S = s, T = t;
        int flow = 0, cost = 0;
        while (int new_flow = spfa()) {
            flow += new_flow;
            cost += dist[T] * new_flow;
        }
        return {flow, cost};
    }

    vector<pair<int, int>> backtrack(int N) {
        vector<pair<int, int>> res;
        for (auto e : E) {
            if (e.cap > 0 && e.cap - e.flow == 0) {
                for (int i = 0; i < N; i++) {
                    for (int j = i + 1; j < N; j++) {
                        int h = N + i * N + j;
                        if (e.u == h && e.v == i) {
                            res.emplace_back(i, j);
                        } else if (e.u == h && e.v == j) {
                            res.emplace_back(j, i);
                        }
                    }
                }
                
            }
        }
        return res;
    }

};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    MinCostMaxFlow MCMF(N * N + 2);
    vector<string> ans(N, string(N, '0'));
    int Source = N * N, Sink = N * N + 1;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        ans[u][v] = '1';
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (ans[i][j] == '0' && ans[j][i] == '0') {
                int h = N + i * N + j;
                MCMF.addEdge(Source, h, 1, 0);
                MCMF.addEdge(h, i, 1, 0);
                MCMF.addEdge(h, j, 1, 0);
            }
        }
        int win = 0;
        for (int j = 0; j < N; j++) {
            if (ans[i][j] == '1') {
                win++;
            }
        }
        for (int cur = 2 * win + 1; cur <= 2 * N - 1; cur += 2) {
            MCMF.addEdge(i, Sink, 1, cur);
        }
    }

    MCMF.MCMF(Source, Sink);
    vector<pair<int, int>> win = MCMF.backtrack(N);
    for (int i = 0; i < win.size(); i++) {
        ans[win[i].first][win[i].second] = '1';
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}