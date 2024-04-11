#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int MOD = 1E9 + 7;
long long a[MAXN + 1];
vector<int> adjList[MAXN + 1];

void add(int &first, int second)
{
    first += second;
    if (first >= MOD)
        first -= MOD;
}

int dfs(int v, int p, map<long long, int> &freq)
{
    map<long long, int> temp;
    temp[a[v]]++;
    int ans = (int) (a[v] % MOD);
    for (auto x : freq)
    {
        long long g = __gcd(x.first, a[v]);
        add(ans, (int) ((long long) g * x.second % MOD));
        temp[g] += x.second;
    }
    swap(freq, temp);
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        add(ans, dfs(adj, v, freq));
    }
    swap(freq, temp);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    map<long long, int> temp;
    cout << dfs(1, 1, temp) << "\n";
    return 0;
}