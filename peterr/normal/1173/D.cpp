#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 2 * 1e5;
vector<int> adjList[MAXN + 1];
bool visited[MAXN + 1];
int numWays[MAXN + 1];

int factorial(int i)
{
    if (i == 1 || i == 0)
        return 1;
    return ((long long) i * factorial(i - 1)) % MOD;
}

void solve(int i)
{
    int children = 0;
    int ways = 1;
    visited[i] = true;
    for (int adj : adjList[i])
    {
        if (!visited[adj])
        {
            children++;
            solve(adj);
            ways = ((long long) ways * numWays[adj]) % MOD;
        }
    }
    numWays[i] = factorial(children + 1);
    numWays[i] = ((long long) numWays[i] * ways) % MOD;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    int res = 1;
    visited[1] = true;
    for (int adj : adjList[1])
    {
        solve(adj);
        res = ((long long) res * numWays[adj]) % MOD;
    }
    numWays[1] = ((long long) factorial(adjList[1].size()) * res) % MOD;
    numWays[1] = ((long long) numWays[1] * n) % MOD;
    cout << numWays[1] << endl;
    return 0;
}