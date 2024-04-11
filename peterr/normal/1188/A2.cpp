#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
vector<pair<int, int>> adjList[MAXN + 1];
int val[MAXN];
int leaf[MAXN + 1];
int where[MAXN + 1];
int lz[MAXN + 1];
vector<tuple<int, int, int>> ans;

void dfs(int v, int p)
{
    if ((int) adjList[v].size() == 1)
    {
        leaf[v] = v;
    }
    else
    {
        for (pair<int, int> edge : adjList[v])
        {
            int adj = edge.first;
            if (adj == p)
                continue;
            dfs(adj, v);
            where[v] = adj;
            leaf[v] = leaf[adj];
        }
    }
}

void solve(int v, int p, int parentLeaf = 0)
{
    if ((int) adjList[v].size() == 1)
        return;
    for (pair<int, int> edge : adjList[v])
    {
        int adj = edge.first;
        int ind = edge.second;
        if (adj == p)
            continue;
        if (adj == where[v])
        {
            val[ind] -= lz[v];
            lz[adj] += lz[v];
        }
        int otherLeaf = 0;
        for (pair<int, int> edge : adjList[v])
        {
            if (edge.first != p && edge.first != adj)
            {
                otherLeaf = leaf[edge.first];
                break;
            }
        }
        assert(parentLeaf != 0);
        assert(otherLeaf != 0);
        ans.push_back(make_tuple(leaf[adj], parentLeaf, val[ind] / 2));
        ans.push_back(make_tuple(leaf[adj], otherLeaf, val[ind] / 2));
        ans.push_back(make_tuple(otherLeaf, parentLeaf, -val[ind] / 2));
        lz[adj] += val[ind];
        solve(adj, v, parentLeaf);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v >> val[i];
        adjList[u].push_back(make_pair(v, i));
        adjList[v].push_back(make_pair(u, i));
    }
    if (n == 2)
    {
        cout << "YES\n";
        cout << "1\n";
        cout << "1 2 " << val[0] << "\n";
        return 0;
    }
    bool valid = true;
    for (int i = 1; i <= n; i++)
    {
        if ((int) adjList[i].size() == 2)
        {
            valid = false;
            break;
        }
    }
    if (!valid)
    {
        cout << "NO\n";
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        assert((int) adjList[i].size() != 2);
        if ((int) adjList[i].size() >= 3)
        {
            dfs(i, i);
            for (pair<int, int> edge : adjList[i])
            {
                int adj = edge.first;
                int ind = edge.second;
                int parentLeaf1 = 0;
                for (pair<int, int> edge : adjList[i])
                {
                    if (edge.first != adj)
                    {
                        parentLeaf1 = leaf[edge.first];
                        break;
                    }
                }
                int parentLeaf2 = 0;
                for (pair<int, int> edge : adjList[i])
                {
                    if (edge.first != adj && leaf[edge.first] != parentLeaf1)
                    {
                        parentLeaf2 = leaf[edge.first];
                        break;
                    }
                }
                assert(parentLeaf1 != 0);
                assert(parentLeaf2 != 0);
                ans.push_back(make_tuple(leaf[adj], parentLeaf1, val[ind] / 2));
                ans.push_back(make_tuple(leaf[adj], parentLeaf2, val[ind] / 2));
                ans.push_back(make_tuple(parentLeaf1, parentLeaf2, -val[ind] / 2));
                lz[adj] = val[ind];
                solve(adj, i, parentLeaf1);
            }
            break;
        }
    }
    cout << "YES\n" << ans.size() << "\n";
    for (tuple<int, int, int> tup : ans)
    {
        cout << get<0>(tup) << " " << get<1>(tup) << " " << get<2>(tup) << "\n";
    }
    return 0;
}