#include <bits/stdc++.h>

using namespace std;

const long long INF = 1E18;
const int MAXN = 1E5;
const int MAXW = 51;
const int NODES = MAXN + MAXN * MAXW;
vector<pair<int, int>> adjList[NODES];
long long ans[NODES];

int encode(int v, bool par, int w=0)
{
    return par * MAXN + v * (par ? MAXW : 1) + w;
}

void addEdge(int v, int u, int w)
{
    adjList[encode(v, 0)].push_back({encode(u, 1, w), 0});
    for (int i = 1; i <= MAXW; i++)
    {
        adjList[encode(v, 1, i)].push_back({encode(u, 0), (w + i) * (w + i)});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fill(ans, ans + NODES, INF);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        addEdge(v, u, w);
        addEdge(u, v, w);
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, encode(0, 0)});
    ans[0] = 0;
    while (!pq.empty())
    {
        pair<long long, int> pr = pq.top();
        pq.pop();
        int v = pr.second;
        long long d = pr.first;
        if (d > ans[v])
            continue;
        for (pair<int, int> edge : adjList[v])
        {
            int u = edge.first;
            int w = edge.second;
            //if (u == encode(0, 1, 3))
            //    cout << "TEST " << w << " " << d << " " << v << endl;
            if (w + d < ans[u])
            {
                ans[u] = w + d;
                pq.push({ans[u], u});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == INF)
            ans[i] = -1;
        cout << ans[i] << " \n"[i == n - 1];
    }
    //cout << ans[encode(0, 1, 3)] << endl;
    //cout << ans[encode(3, 1, 5)] << endl;
    //cout << ans[encode(1, 0)] << endl;
    return 0;
}