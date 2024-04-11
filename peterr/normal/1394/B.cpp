#include <bits/stdc++.h>

using namespace std;

const int BASE = 10;
const int MOD[3] = {1000000007, 1000000009, 1000000021};
const int MAXN = 2E5;
int target[3];
vector<pair<int, int>> adjList[MAXN + 1];
int res[10][10][3];
bool visited[MAXN + 1];
int conf[10];

int solve(int ind, int k)
{
    if (ind > k)
    {
        for (int i = 0; i < 3; i++)
        {
            int temp = 0;
            for (int j = 1; j <= k; j++)
            {
                temp += res[j][conf[j]][i];
                if (temp >= MOD[i])
                    temp -= MOD[i];
            }
            if (temp != target[i])
                return 0;
        }
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < ind; i++)
    {
        if (res[ind][i][0] == -1)
            continue;
        conf[ind] = i;
        ans += solve(ind + 1, k);
    }
    return ans;
}

int getVal(int n, int mod)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (int) ((long long) ans * BASE % mod);
        ans += visited[i];
        if (ans >= mod)
            ans -= mod;
    }
    return ans;
}

int calc(int ind, int val, int n, int mod)
{
    fill(visited + 1, visited + n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if ((int) adjList[i].size() != ind)
            continue;
        int v = adjList[i][val].second;
        if (visited[v])
            return -1;
        visited[v] = true;
    }
    return getVal(n, mod);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(make_pair(w, v));
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adjList[i].begin(), adjList[i].end());
    }
    fill(visited + 1, visited + n + 1, true);
    for (int i = 0; i < 3; i++)
    {
        target[i] = getVal(n, MOD[i]);
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int modInd = 0; modInd < 3; modInd++)
            {
                res[i][j][modInd] = calc(i, j, n, MOD[modInd]);
            }
        }
    }
    int ans = solve(1, k);
    cout << ans << "\n";
    return 0;
}