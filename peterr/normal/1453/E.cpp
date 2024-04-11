#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<int> adjList[MAXN + 1];
int dp[MAXN + 1];

bool check(int v, int p, int k)
{
    if ((int) adjList[v].size() == 1 && v != p)
    {
        dp[v] = 0;
        return true;
    }
    int mn = MAXN;
    int bigger = -1;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        if (!check(adj, v, k))
            return false;
        if (dp[adj] + 2 > k)
        {
            if (bigger == -1)
                bigger = dp[adj] + 1;
            else
                return false;
        }
        mn = min(mn, dp[adj] + 1);
    }
    if (bigger == -1)
        dp[v] = mn;
    else
        dp[v] = bigger;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            adjList[i].clear();
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        int ans = 0;
        for (int jump = n; jump; jump >>= 1)
        {
            while (ans + jump <= n)
            {
                if (check(1, 1, ans + jump))
                {
                    if (dp[1] <= ans + jump)
                        break;
                }
                ans += jump;
            }
        }
        cout << ans + 1 << "\n";
    }
    return 0;
}