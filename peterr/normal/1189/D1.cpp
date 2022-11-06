#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
vector<int> adjList[MAXN + 1];
int deg[MAXN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    int leaves = 0;
    bool deg2 = false;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 1)
            leaves++;
        else if (deg[i] == 2)
            deg2 = true;
    }
    if (deg2)
    {
        cout << "NO";
    }
    else if ((long long) (leaves) * (leaves - 1) / 2 < n - 1)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
    return 0;
}