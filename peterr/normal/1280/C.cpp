#include <bits/stdc++.h>

using namespace std;

const int LOGN = 17;
const int MAXN = 2E5;
vector<pair<int, int>> adjList[MAXN + 1];
int s[MAXN + 1];
int deg[MAXN + 1];

long long dfs(int v, int p, long long &ans2, int n)
{
    long long ans = 0;
    s[v] = 1;
    for (pair<int, int> edge: adjList[v])
    {
        int adj = edge.first;
        if (adj == p)
            continue;
        ans += dfs(adj, v, ans2, n);
        if (s[adj] % 2 != 0)
            ans += edge.second;
        s[v] += s[adj];
        ans2 += (long long) edge.second * min(s[adj], n - s[adj]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        for (int i = 1; i <= 2 * k; i++)
        {
            adjList[i].clear();
        }
        for (int i = 0; i < 2 * k - 1; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            adjList[a].push_back(make_pair(b, w));
            adjList[b].push_back(make_pair(a, w));
            deg[a]++;
            deg[b]++;
        }
        vector<int> vec;
        for (int i = 1; i <= 2 * k; i++)
        {
            if (deg[i] == 1)
                vec.push_back(i);
        }
        long long ans2 = 0;
        long long ans1 = dfs(1, 1, ans2, 2 * k);
        cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}