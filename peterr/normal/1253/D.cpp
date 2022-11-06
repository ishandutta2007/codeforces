#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
vector<int> adjList[MAXN + 1];
bool visited[MAXN + 1];

void dfs(int v, int &small, int &big)
{
    visited[v] = true;
    small = min(v, small);
    big = max(v, big);
    for (int adj : adjList[v])
    {
        if (!visited[adj])
        {
            dfs(adj, small, big);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<pair<int, int>> comps;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            int small, big;
            small = big = i;
            dfs(i, small, big);
            comps.push_back({small, big});
        }
    }
    sort(comps.begin(), comps.end());
    int ans = 0;
    int rb = comps[0].second;
    for (int i = 1; i < (int) comps.size(); i++)
    {
        if (comps[i].first <= rb)
        {
            ans++;
        }
        rb = max(rb, comps[i].second);
    }
    cout << ans << endl;

    return 0;
}