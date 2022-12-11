#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

const int INF = 2e9 + 29;

vector<vector<int>> g(MAXN);
int c[MAXN];
int used[MAXN];
int ans[MAXN];

string an = "YES";

bool cmp(int u, int v)
{
    return ans[u] < ans[v];
}

vector<int> t[MAXN];

void dfs(int u)
{
    used[u] = true;
    if (g[u].size() == 0)
    {
        ans[u] = 1;
    }
    for (auto v : g[u])
    {
        dfs(v);
        for (auto el : t[v])
        {
            t[u].push_back(el);
        }
    }
    sort(t[u].begin(), t[u].end(), cmp);
    for (int i = 1; i < t[u].size(); ++i)
    {
        if (ans[t[u][i]] <= ans[t[u][i - 1]])
        {
            ans[t[u][i]] = ans[t[u][i - 1]] + 1;
        }
    }
    if (c[u] > t[u].size())
    {
        an = "NO";
    }
    else
    {
        if (c[u] == 0)
        {
            ans[u] = 1;
            for (auto el : t[u])
            {
                ans[el]++;
            }
        }
        else
        {
            ans[u] = ans[t[u][c[u] - 1]] + 1;
            for (int i = c[u]; i < t[u].size(); ++i)
            {
                ans[t[u][i]]++;
            }
        }
    }
    t[u].push_back(u);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "YES" << endl;
        cout << 1 << endl;
        return 0;
    }
    int root = 0;
    for (int i = 0; i < n; ++i)
    {
        int u;
        cin >> u >> c[i];
        --u;
        if (u >= 0)
        {
            g[u].push_back(i);
        }
        else
        {
            root = i;
        }
    }
    dfs(root);
    cout << an << endl;
    if (an == "YES")
    {
        for (int i = 0; i < n; ++i)
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}