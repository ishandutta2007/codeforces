#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<int> adjList[MAXN + 1];
int dist[3][MAXN + 1];
int p[MAXN];
long long pre[MAXN];

void bfs(int dist[MAXN + 1], int v)
{
    queue<pair<int, int>> q;
    q.push(make_pair(v, 0));
    dist[v] = 0;
    while (!q.empty())
    {
        pair<int, int> pr = q.front();
        q.pop();
        for (int adj : adjList[pr.first])
        {
            if (dist[adj] == -1)
            {
                dist[adj] = pr.second + 1;
                q.push(make_pair(adj, dist[adj]));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;
        for (int i = 0; i < m; i++)
            cin >> p[i];
        sort(p, p + m);
        pre[0] = p[0];
        for (int i = 1; i < m; i++)
            pre[i] = pre[i - 1] + p[i];
        for (int i = 1; i <= n; i++)
            adjList[i].clear();
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        fill(dist[0] + 1, dist[0] + n + 1, -1);
        fill(dist[1] + 1, dist[1] + n + 1, -1);
        fill(dist[2] + 1, dist[2] + n + 1, -1);
        bfs(dist[0], a);
        bfs(dist[1], b);
        bfs(dist[2], c);
        long long ans = 1E18;
        for (int i = 1; i <= n; i++)
        {
            int ones = dist[0][i] + dist[2][i];
            int twos = dist[1][i];
            if (ones + twos - 1 >= m)
                continue;
            ans = min(ans, pre[ones + twos - 1] + (twos > 0 ? pre[twos - 1] : 0));
        }
        cout << ans << "\n";
    }
    return 0;
}