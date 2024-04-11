#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
vector<int> adjList[MAXN + 1];
bool visited[MAXN + 1];
int c[MAXN + 1];
vector<pair<int, int>> weights;
bool canTake[MAXN + 1][MAXN + 1];
vector<vector<int>> reds;
vector<vector<int>> blues;
int ans[MAXN + 1];

bool dfs(int v, bool color, int &red, int &total)
{
    visited[v] = true;
    total++;
    if (color)
    {
        reds.back().push_back(v);
        red++;
    }
    else
        blues.back().push_back(v);
    c[v] = color;
    for (int adj : adjList[v])
    {
        if (visited[adj])
        {
            if (c[v] == c[adj])
                return false;
        }
        else
        {
            if (!dfs(adj, !color, red, total))
                return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, n1, n2, n3;
    cin >> n >> m >> n1 >> n2 >> n3;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    bool valid = true;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            reds.push_back(vector<int>());
            blues.push_back(vector<int>());
            int red, total;
            red = total = 0;
            if (!dfs(i, 0, red, total))
                valid = false;
            weights.push_back(make_pair(red, total - red));
        }
    }
    if (!valid)
    {
        cout << "NO\n";
        return 0;
    }
    canTake[0][0] = true;
    for (int i = 1; i <= (int) weights.size(); i++)
    {
        pair<int, int> pr = weights[i - 1];
        for (int j = 0; j <= n2; j++)
        {
            if (!canTake[i - 1][j])
                continue;
            if (j + pr.first <= n2)
                canTake[i][j + pr.first] = true;
            if (j + pr.second <= n2)
                canTake[i][j + pr.second] = true;
        }
    }
    if (!canTake[(int) weights.size()][n2])
    {
        cout << "NO\n";
        return 0;
    }
    for (int i = (int) weights.size(); i >= 1; i--)
    {
        if (weights.back().first <= n2 && canTake[i - 1][n2 - weights.back().first])
        {
            n2 -= weights.back().first;
            for (int v : reds.back())
                ans[v] = 2;
            for (int v : blues.back())
            {
                if (n1)
                {
                    ans[v] = 1;
                    n1--;
                }
                else
                    ans[v] = 3;
            }
        }
        else
        {
            n2 -= weights.back().second;
            for (int v : blues.back())
                ans[v] = 2;
            for (int v : reds.back())
            {
                if (n1)
                {
                    ans[v] = 1;
                    n1--;
                }
                else
                    ans[v] = 3;
            }
        }
        weights.pop_back();
        reds.pop_back();
        blues.pop_back();
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << ans[i];
    cout << "\n";
    return 0;
}