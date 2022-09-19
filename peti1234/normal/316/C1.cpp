#include <bits/stdc++.h>

using namespace std;
int n, m, t[82][82], kezd, veg;
struct Edge
{
    int from, to, capacity, cost;
};
vector<Edge> sz;
void add(int a, int b, int c) {
    sz.push_back({a, b, 1, c});
}
int cs(int a, int b) {
    return (a-1)*m+b;
}

vector<vector<int>> adj, cost, capacity;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    if (flow < K)
        return -1;
    else
        return cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m, kezd=n*m+1, veg=n*m+2;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> t[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int x=cs(i, j), y=t[i][j];
            if ((i+j)%2) {
                add(kezd, x, 0);
                if (i>1) {
                    add(x, cs(i-1, j), 1-(y==t[i-1][j]));
                }
                if (j>1) {
                    add(x, cs(i, j-1), 1-(y==t[i][j-1]));
                }

                if (i<n) {
                    add(x, cs(i+1, j), 1-(y==t[i+1][j]));
                }

                if (j<m) {
                    add(x, cs(i, j+1), 1-(y==t[i][j+1]));
                }

            } else {
                add(x, veg, 0);
            }
        }
    }
    int ans=min_cost_flow(veg+1, sz, n*m/2, kezd, veg);
    cout << ans << endl;
    return 0;
}
/*
3 4
1 1 6 6
2 2 4 4
3 3 5 5
*/