#include <bits/stdc++.h>

using namespace std;

const int INF = 1E6;
const int MAXN = 3000;
int bal[MAXN + 1];
int sz[MAXN + 1];
vector<int> adjList[MAXN + 1];
pair<int, long long> dp[MAXN + 1][MAXN + 1];

void dfs(int v, int p)
{
    sz[v] = 1;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        dfs(adj, v);
        sz[v] += sz[adj];
    }
}

void solve(int v, int p, int n)
{
    fill(dp[v] + 1, dp[v] + n + 1, make_pair(-INF, -INF));
    dp[v][1] = make_pair(0, bal[v]);
    //cout << "bal " << bal[v] << endl;
    int curSize = 1;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        solve(adj, v, n);
        for (int i = curSize + sz[adj]; i >= 1; i--)
        {
            pair<int, long long> best = make_pair(-INF, -INF);
            for (int j = max(1, i - sz[adj]); j <= min(i, curSize); j++)
            {
                int k = i - j + 1;
                best = max(best, make_pair(dp[v][j].first + dp[adj][k].first, dp[v][j].second + dp[adj][k].second));
            }
            for (int j = max(1, i - sz[adj]); j <= min(i - 1, curSize); j++)
            {
                int k = i - j;
                best = max(best, make_pair(dp[v][j].first + dp[adj][k].first + (dp[adj][k].second > 0), dp[v][j].second));
            }
            dp[v][i] = best;
        }
        curSize += sz[adj];
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
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            adjList[i].clear();
            cin >> bal[i];
            bal[i] = -bal[i];
        }
        for (int i = 1; i <= n; i++)
        {
            int w;
            cin >> w;
            bal[i] += w;
        }
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        dfs(1, 1);
        solve(1, 1, n);
        int ans = dp[1][m].first + (dp[1][m].second > 0);
        cout << ans << "\n";
    }
    return 0;
}