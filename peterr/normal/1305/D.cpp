#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int deg[MAXN + 1];
vector<int> adjList[MAXN + 1];
bool visited[MAXN + 1];

int main()
{
    int n;
    cin >> n;
    int m = n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    while (n >= 2)
    {
        int u = 1;
        while (visited[u] || deg[u] > 1)
            u++;
        int v = u + 1;
        while (visited[v] || deg[v] > 1)
            v++;
        cout << "? " << u << " " << v << endl;
        int q;
        cin >> q;
        if (q == u || q == v)
        {
            cout << "! " << q << endl;
            return 0;
        }
        visited[u] = true;
        visited[v] = true;
        for (int adj : adjList[u])
            deg[adj]--;
        for (int adj : adjList[v])
            deg[adj]--;
        n -= 2;
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (!visited[i])
        {
            ans = i;
            break;
        }
    }
    cout << "! " << ans << endl;
    return 0;
}