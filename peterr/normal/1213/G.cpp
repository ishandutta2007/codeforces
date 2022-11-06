#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 2E5;

vector<pair<int, int>> edges[MAXN + 1];
long long ans[MAXN + 1];
int parent[MAXN + 1];
int sze[MAXN + 1];

int getRoot(int x)
{
    if (parent[x] != x)
        parent[x] = getRoot(parent[x]);
    return parent[x];
}

void mge(int a, int b)
{
    int r1 = getRoot(a);
    int r2 = getRoot(b);
    if (r1 == r2)
        return;
    if (sze[r1] > sze[r2])
        swap(r1, r2);
    parent[r1] = r2;
    sze[r2] += sze[r1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[w].push_back({u, v});
    }
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sze[i] = 1;
    }
    long long curAns = 0;
    for (int weight = 1; weight <= MAXN; weight++)
    {
        for (pair<int, int> pr : edges[weight])
        {
            int r1 = getRoot(pr.first);
            int r2 = getRoot(pr.second);
            if (r1 != r2)
            {
                curAns += (long long) sze[r1] * sze[r2];
                mge(r1, r2);
            }
        }
        ans[weight] = curAns;
    }
    for (int i = 0; i < m; i++)
    {
        if (i != 0)
            cout << " ";
        int q;
        cin >> q;
        cout << ans[q];
    }
    cout << endl;
    return 0;
}