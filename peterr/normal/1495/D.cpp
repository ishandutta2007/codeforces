#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400;
const int INF = 1000;
const int MOD = 998244353;
vector<int> adjList[MAXN + 1];
int dist[MAXN + 1][MAXN + 1];
int from[MAXN + 1][MAXN + 1];
int ans[MAXN + 1][MAXN + 1];
bool visited[MAXN + 1];
bool inPath[MAXN + 1];

int solve(int v, int u, int n)
{
    fill(visited + 1, visited + n + 1, false);
    fill(inPath + 1, inPath + n + 1, false);
    int cur = u;
    vector<int> path;
    while (cur != v)
    {
        path.push_back(cur);
        inPath[cur] = true;
        cur = from[v][cur];
    }
    path.push_back(v);
    inPath[v] = true;
    visited[u] = true;
    queue<int> q;
    q.push(u);
    int ans = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int adj : adjList[cur])
        {
            if (visited[adj])
                continue;
            visited[adj] = true;
            q.push(adj);
            int diff = dist[adj][u] - dist[adj][v] + dist[u][v];
            if (diff < 0 || (diff & 1))
            {
                return 0;
            }
            if (!inPath[adj])
            {
                int level = dist[adj][u] + dist[adj][v] - dist[u][v];
                if (level <= 0 || (level & 1))
                {
                    return 0;
                }
                level /= 2;
                diff /= 2;
                int cnt = 0;
                for (int adj2 : adjList[adj])
                {
                    if (!visited[adj2])
                        continue;
                    int diff2 = (dist[adj2][u] - dist[adj2][v] + dist[u][v]) / 2;
                    int level2 = (dist[adj2][u] + dist[adj2][v] - dist[u][v]) / 2;
                    if (diff2 == diff && level2 == level - 1)
                        cnt++;
                }
                ans = (int) ((long long) ans * cnt % MOD);
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fill(dist[i] + 1, dist[i] + n + 1, INF);
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        dist[u][v] = dist[v][u] = 1;
        from[u][v] = u;
        from[v][u] = v;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (dist[j][i] + dist[i][k] < dist[j][k])
                {
                    dist[j][k] = dist[j][i] + dist[i][k];
                    from[j][k] = from[i][k];
                }
            }
        }
    }
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dist[i][j] << "/" << from[i][j] << " ";
        }
        cout << endl;
    }
    */
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            ans[i][j] = ans[j][i] = solve(i, j, n);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ans[i][j] << " \n"[j == n];
        }
    }
    return 0;
}