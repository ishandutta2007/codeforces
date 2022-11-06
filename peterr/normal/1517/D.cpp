#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
const int MAXK = 20;
const int NODES = MAXN * MAXN;
const int INF = 1E9;
vector<pair<int, int>> adjList[NODES];
int dp[NODES][MAXK / 2 + 1];

int encode(int i, int j, int m)
{
    return i * m + j;
}

void addEdge(int u, int v, int w)
{
    adjList[u].push_back({v, w});
    adjList[v].push_back({u, w});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            int x;
            cin >> x;
            addEdge(encode(i, j, m), encode(i, j + 1, m), x);
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            addEdge(encode(i, j, m), encode(i + 1, j, m), x);
        }
    }
    if (k & 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << "-1" << " \n"[j == m - 1];
            }
        }
        return 0;
    }
    for (int i = 0; i < k / 2; i++)
    {
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                int ind = encode(r, c, m);
                dp[ind][i + 1] = INF;
                for (pair<int, int> edge : adjList[ind])
                {
                    int adj = edge.first;
                    int w = edge.second;
                    dp[ind][i + 1] = min(dp[ind][i + 1], dp[adj][i] + w);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int ind = encode(i, j, m);
            cout << dp[ind][k / 2] * 2 << " \n"[j == m - 1];
        }
    }
    return 0;
}