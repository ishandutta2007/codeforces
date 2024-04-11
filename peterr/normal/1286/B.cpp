#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
int c[MAXN + 1];
vector<int> adjList[MAXN + 1];
int ans[MAXN + 1];
bool used[MAXN + 1];
int sze[MAXN + 1];

bool dfs(int v, int p)
{
    sze[v] = 1;
    for (int adj : adjList[v])
    {
        if (adj != p)
        {
            if (!dfs(adj, v))
                return false;
            sze[v] += sze[adj];
        }
    }
    return c[v] <= sze[v] - 1;
}

void solve(int v, int a, int b, int p)
{
    int i = a;
    for (; used[i] || c[v] > 0; i++)
    {
        if (!used[i])
            c[v]--;
    }
    ans[v] = i;
    used[ans[v]] = true;
    int cur = a;
    for (int adj : adjList[v])
    {
        if (adj != p)
        {
            while (used[cur])
                cur++;
            int start = cur;
            int endd = start;
            int cnt = 1;
            while (cnt < c[adj])
            {
                endd++;
                cnt++;
                while (used[endd])
                    endd++;
            }
            solve(adj, start, endd, v);
            cur = endd;
        }
    }
}

int main()
{
    int root = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p >> c[i];
        if (p == 0)
        {
            root = i;
        }
        else
        {
            adjList[i].push_back(p);
            adjList[p].push_back(i);
        }
    }
    if (!dfs(root, 0))
    {
        cout << "NO" << endl;
    }
    else
    {
        solve(root, 1, n, 0);
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++)
        {
            if (i > 1)
                cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}