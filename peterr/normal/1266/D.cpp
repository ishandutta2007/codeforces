#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
//vector<pair<int, long long>> adjList[MAXN + 1];
//vector<pair<int, long long>> tr[MAXN + 1];
unordered_map<int, long long> adjList[MAXN + 1];
unordered_map<int, long long> tr[MAXN + 1];
//bool visited[MAXN + 1];
/*
long long dfs(int v, long long weight)
{
    visited[v] = true;
    for (int i = 0; i < (int) adjList[v].size(); i++)
    {
        pair<int, long long> pr = adjList[v][i];
        long long d = dfs(pr.first, min(pr.second, weight));
    }
}
*/

void update(int u, int v, long long amt)
{
    adjList[u][v] += amt;
    tr[v][u] += amt;
    if (adjList[u][v] == 0)
        adjList[u].erase(v);
    if (tr[v][u] == 0)
        tr[v].erase(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, long long> due;
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        pair<int, int> pr = {u, v};
        if (due.find({v, u}) != due.end())
        {
            if (d >= due[{v, u}])
            {
                d -= due[{v, u}];
                due.erase({v, u});
            }
            else
            {
                due[{v, u}] -= d;
                d = 0;
            }
        }
        if (d == 0)
            continue;
        if (due.find(pr) != due.end())
            due[pr] = due[pr] + d;
        else
            due[pr] = d;
    }
    for (auto it = due.begin(); it != due.end(); it++)
    {
        pair<int, int> pr = it->first;
        long long d = it->second;
        int u = pr.first;
        int v = pr.second;
        adjList[u][v] = d;
        tr[v][u] = d;
        //adjList[u].push_back({v, d});
        //tr[v].push_back({u, d});
    }
    //cout << "TEST" << endl << adjList[2][3] << endl;
    for (int i = 1; i <= n; i++)
    {
        while (!adjList[i].empty() && !tr[i].empty())
        {
            int x = tr[i].begin()->first;
            int y = adjList[i].begin()->first;
            long long d = min(tr[i].begin()->second, adjList[i].begin()->second);
            //pair<int, long long> outEdge = adjList[i][(int) adjList[i].size() - 1];
            //pair<int, long long> inEdge = tr[i][(int) tr[i].size() - 1];
            //long long d = min(outEdge.second, inEdge.second);
            //adjList[x][i] -= d;
            //tr[i][x] -= d;
            //adjList[i][y] -= d;
            //tr[y][i] -= d;
            update(x, i, -d);
            update(i, y, -d);
            if (adjList[y].find(x) != adjList[y].end())
            {
                if (d >= adjList[y][x])
                {
                    d -= adjList[y][x];
                    adjList[y].erase(x);
                    tr[x].erase(y);
                }
                else
                {
                    adjList[y][x] -= d;
                    tr[x][y] -= d;
                    d = 0;
                }
            }
            if (d == 0)
                continue;
            if (adjList[x].find(y) == adjList[x].end())
            {
                adjList[x][y] = d;
                tr[y][x] = d;
            }
            else
            {
                adjList[x][y] += d;
                tr[y][x] += d;
            }

        }
    }
    stringstream ss;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto it = adjList[i].begin(); it != adjList[i].end(); it++)
        {
            int v = it->first;
            long long d = it->second;
            if (d == 0)
                continue;
            ss << i << " " << v << " " << d << endl;
            cnt++;
        }
    }
    cout << cnt << endl << ss.str();
    return 0;
}