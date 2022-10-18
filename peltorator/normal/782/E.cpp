#include <bits/stdc++.h>

using namespace std;

typedef double ld;

vector<int> go, used;
vector<int> g[200001];

void dfs(int v)
{
    go.push_back(v);
    used[v] = 1;
    for (int u : g[v])
        if (!used[u])
        {
            dfs(u);
            go.push_back(v);
        }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    if (n == 1)
    {
        for (int i = 1; i <= k; i++)
            cout << "1 1" << endl;
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        int k, l;
        cin >> k >> l;
        g[k].push_back(l);
        g[l].push_back(k);
    }
    used.assign(n + 1, 0);
    dfs(1);
    int t = (2 * n + k - 1) / k;
    int cur = 0;
    for (int i = 1; i <= k; i++)
    {
        cout << t << " ";
        for (int j = cur; j < min(cur + t, (int)(go.size())); j++)
            cout << go[j] << " ";
        for (int tt = 0, j = max((int)(go.size()), cur); j < cur + t; j++, tt++)
            if (tt % 2 == 0)
                cout << g[go.back()][0] << " ";
            else
                cout << go.back() << " ";
        cur += t;
        cout << endl;
    }
    return 0;
}