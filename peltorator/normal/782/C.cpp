#include <bits/stdc++.h>

using namespace std;

typedef double ld;

vector<int> g[200001], col;

int numcol = 1;


void dfs(int v, int col1)
{
    int cur = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if (!col[u])
        {
            while (cur == col1 || cur == col[v])
                cur++;
            numcol = max(numcol, cur);
            col[u] = cur++;
            dfs(u, col[v]);
        }
    }
}

int main()
{
    cout.precision(100);
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int k, l;
        cin >> k >> l;
        g[k].push_back(l);
        g[l].push_back(k);
    }
    col.assign(n + 1, 0);
    col[1] = 1;
    dfs(1, 0);
    cout << numcol << endl;
    for (int i = 1; i <= n; i++)
        cout << col[i] << " ";
    return 0;
}