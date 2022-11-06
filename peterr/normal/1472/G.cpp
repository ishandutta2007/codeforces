#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<int> adjList[MAXN + 1];
int d[MAXN + 1];
vector<int> where[MAXN];
int ans[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            adjList[i].clear();
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
        }
        for (int i = 0; i < n; i++)
            where[i].clear();
        fill(d + 1, d + n + 1, -1);
        fill(ans + 1, ans + n + 1, n + 1);
        queue<int> q;
        q.push(1);
        d[1] = 0;
        where[0].push_back(1);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int adj : adjList[v])
            {
                if (d[adj] != -1)
                    continue;
                d[adj] = d[v] + 1;
                q.push(adj);
                where[d[adj]].push_back(adj);
            }
        }
        /*
        for (int i = 1; i <= n; i++)
            cout << "dist " << i << " " << d[i] << endl;
        */
        for (int i = n - 1; i >= 0; i--)
        {
            for (int v : where[i])
            {
                ans[v] = d[v];
                for (int adj : adjList[v])
                {
                    if (d[adj] > d[v])
                        ans[v] = min(ans[v], ans[adj]);
                    else
                        ans[v] = min(ans[v], d[adj]);
                }
            }
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " \n"[i == n];
    }
    return 0;
}