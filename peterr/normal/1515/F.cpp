#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
int par[MAXN + 1];
int sz[MAXN + 1];
vector<int> comps[MAXN + 1];
long long a[MAXN + 1];
vector<pair<int, int>> adjList[MAXN + 1];

int getRoot(int x)
{
    if (par[x] != x)
        par[x] = getRoot(par[x]);
    return par[x];
}

bool mge(int x, int y)
{
    x = getRoot(x);
    y = getRoot(y);
    if (x == y)
        return false;
    if (sz[x] > sz[y])
        swap(x, y);
    par[x] = y;
    sz[y] += sz[x];
    a[y] += a[x];
    for (int z : comps[x])
        comps[y].push_back(z);
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x;
    cin >> n >> m >> x;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        sz[i] = 1;
        par[i] = i;
        comps[i].push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back({v, i + 1});
        adjList[v].push_back({u, i + 1});
    }
    if (sum < (long long) (n - 1) * x)
    {
        cout << "NO\n";
        return 0;
    }
    priority_queue<pair<long long, int>> pq;
    for (int i = 1; i <= n; i++)
    {
        pq.push({a[i], i});
    }
    vector<int> ans;
    for (int i = 0; i < n - 1; i++)
    {
        while (1)
        {
            pair<long long, int> pr = pq.top();
            pq.pop();
            long long money = pr.first;
            int ind = getRoot(pr.second);
            if (a[ind] != money)
                continue;
            bool found = false;
            for (int k = 0; k < (int) comps[ind].size(); k++)
            {
                int v = comps[ind][k];
                if (adjList[v].empty())
                {
                    swap(comps[ind][k], comps[ind].back());
                    comps[ind].pop_back();
                    k--;
                    continue;
                }
                for (int j = 0; j < (int) adjList[v].size(); j++)
                {
                    pair<int, int> edge = adjList[v][j];
                    int adj = adjList[v][j].first;
                    if (getRoot(v) == getRoot(adj))
                    {
                        swap(adjList[v][j], adjList[v].back());
                        adjList[v].pop_back();
                        j--;
                    }
                    else
                    {
                        found = true;
                        ans.push_back(edge.second);
                        mge(v, adj);
                        break;
                    }
                }
                if (found)
                    break;
            }
            ind = getRoot(ind);
            a[ind] -= x;
            pq.push({a[ind], ind});
            break;
        }
    }
    cout << "YES\n";
    for (int x : ans)
        cout << x << "\n";
    return 0;
}