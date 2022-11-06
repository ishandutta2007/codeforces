#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
vector<int> adjList[MAXN + 1];
int dp[MAXN + 1][2];
vector<int> from[MAXN + 1][2];
vector<pair<int, int>> addition;
vector<pair<int, int>> removal;
vector<vector<int>> comps;

void dfs(int v, int p)
{
    dp[v][0] = dp[v][1] = 0;
    from[v][0].clear();
    from[v][1].clear();
    int children = 0;
    vector<int> goodChildren;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        children++;
        dfs(adj, v);
        if (dp[adj][0] == dp[adj][1])
            goodChildren.push_back(adj);
        dp[v][0] += min(dp[adj][0], dp[adj][1]);
    }
    dp[v][0] += children;
    dp[v][1] = dp[v][0];
    for (int i = 0; i < min(2, (int) goodChildren.size()); i++)
    {
        from[v][0].push_back(goodChildren[i]);
        dp[v][0]--;
    }
    for (int i = 0; i < min(1, (int) goodChildren.size()); i++)
    {
        from[v][1].push_back(goodChildren[i]);
        dp[v][1]--;
    }
}

void solve(int v, int p, bool isEnd, int id, bool isNew)
{
    while (id >= (int) comps.size())
    {
        comps.push_back(vector<int>());
    }
    int cnt = 0;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        bool isConnected = false;
        for (int x : from[v][isEnd])
        {
            if (x == adj)
                isConnected = true;
        }
        if (!isConnected)
            removal.push_back({v, adj});
        if (isConnected)
            solve(adj, v, isConnected, id, false);
        else
            solve(adj, v, false, (int) comps.size(), true);
        cnt += isConnected;
    }
    if (isNew && cnt == 0)
    {
        comps[id].push_back(v);
        comps[id].push_back(v);
    }
    else if (isNew && cnt == 1)
    {
        comps[id].push_back(v);
    }
    else if (cnt == 0)
        comps[id].push_back(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        removal.clear();
        addition.clear();
        comps.clear();
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            adjList[i].clear();
        }
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        dfs(1, 1);
        solve(1, 1, false, 0, true);
        /*
        for (vector<int> vec : comps)
        {
            cout << "COMP" << endl;
            for (int x : vec)
                cout << x << " ";
            cout << endl;
        }
        */
        for (int i = 0; i < (int) comps.size() - 1; i++)
        {
            addition.push_back({comps[i][1], comps[i + 1][0]});
        }
        cout << dp[1][0] << "\n";
        assert(removal.size() == addition.size());
        for (int i = 0; i < (int) removal.size(); i++)
        {
            cout << removal[i].first << " " << removal[i].second << " " << addition[i].first << " " << addition[i].second << "\n";
        }
    }
    return 0;
}