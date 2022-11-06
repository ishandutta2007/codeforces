#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<int> f[MAXN + 1];
vector<int> r[MAXN + 1];
bool rec[MAXN + 1];
char q[MAXN + 1];
int minn1[MAXN + 1];
int minn2[MAXN + 1];

bool dfs(int v, vector<int> adjList[MAXN + 1], int minn[MAXN + 1])
{
    minn[v] = v;
    rec[v] = true;
    for (int adj : adjList[v])
    {
        if (rec[adj])
            return false;
        if (minn[adj] == -1)
            if (!dfs(adj, adjList, minn))
                return false;
        minn[v] = min(minn[v], minn[adj]);
    }
    rec[v] = false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        f[a].push_back(b);
        r[b].push_back(a);
    }
    int ans = 0;
    fill(minn1 + 1, minn1 + n + 1, -1);
    fill(minn2 + 1, minn2 + n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (minn1[i] == -1)
        {
            if (!dfs(i, f, minn1))
            {
                ans = -1;
                break;
            }
        }
        if (minn2[i] == -1)
        {
            if (!dfs(i, r, minn2))
            {
                ans = -1;
                break;
            }
        }
        if (min(minn1[i], minn2[i]) == i)
        {
            q[i] = 'A';
            ans++;
        }
        else
            q[i] = 'E';
    }
    cout << ans << "\n";
    if (ans != -1)
    {
        for (int i = 1; i <= n; i++)
            cout << q[i];
        cout << "\n";
    }
    return 0;
}