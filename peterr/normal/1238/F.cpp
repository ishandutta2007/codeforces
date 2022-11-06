#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
vector<int> adjList[MAXN + 1];
int dp[MAXN + 1];

void compute(int v, int p)
{
    int maxx = 0;
    for (int adj : adjList[v])
    {
        if (adj != p)
        {
            dp[v]++;
            compute(adj, v);
            maxx = max(maxx, dp[adj]);
        }
    }
    dp[v] += maxx;
    dp[v] = max(dp[v], 1);
    //cout << v << " " << dp[v] << endl;
}

int solve(int v, int p)
{
    int ans = 0;
    int m1, m2;
    m1 = m2 = 0;
    int numChildren = 0;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        numChildren++;
        ans = max(ans, solve(adj, v));
        int x = dp[adj];
        if (x > m2)
            m2 = x;
        if (m2 > m1)
            swap(m1, m2);
    }
    int temp = m1 + m2 + (int) adjList[v].size() - 1;
    if (m2 == 0)
        temp++;
    if (m1 == 0)
        temp++;
    ans = max(ans, temp);
    return ans;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        fill(dp + 1, dp + n + 1, 0);
        for (int i = 1; i <= n; i++)
            adjList[i].clear();
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        compute(1, 1);
        cout << solve(1, 1) << "\n";
    }
    return 0;
}