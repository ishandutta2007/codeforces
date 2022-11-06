#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<int> adjList[MAXN + 1];
int numGood[MAXN + 1];
int numBad[MAXN + 1];
bool isGood[MAXN + 1];
int moves[MAXN + 1];

void detGoodness(int v, int k)
{
    isGood[v] = numBad[v] == 0 && numGood[v] % k == 0;
}

void dfs(int v, int p, int k)
{
    numGood[v] = numBad[v] = moves[v] = 0;
    isGood[v] = false;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        dfs(adj, v, k);
        if (isGood[adj])
            numGood[v]++;
        else
            numBad[v]++;
        moves[v] += moves[adj];
    }
    detGoodness(v, k);
    moves[v] += numGood[v] / k;
}

void reroot(int x, int y, int k)
{
    moves[x] -= moves[y];
    moves[x] -= numGood[x] / k;
    if (isGood[y])
        numGood[x]--;
    else
        numBad[x]--;
    moves[x] += numGood[x] / k;
    detGoodness(x, k);
    moves[y] -= numGood[y] / k;
    moves[y] += moves[x];
    if (isGood[x])
        numGood[y]++;
    else
        numBad[y]++;
    moves[y] += numGood[y] / k;
    detGoodness(y, k);
}

int solve(int v, int p, int k)
{
    int ans = moves[v];
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        reroot(v, adj, k);
        ans = max(ans, solve(adj, v, k));
        reroot(adj, v, k);
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
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
            adjList[i].clear();
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        dfs(1, 1, k);
        cout << solve(1, 1, k) << "\n";
    }
    return 0;
}