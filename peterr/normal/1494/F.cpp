#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3000;
pair<int, int> edges[MAXN];
bool ac[MAXN];
set<int> adjList[MAXN + 1];
set<int> adjListSave[MAXN + 1];
bool deg[MAXN + 1];
bool visited[MAXN + 1];
int hasEdge[MAXN + 1];

int other(pair<int, int> pr, int x)
{
    if (pr.first == x)
        return pr.second;
    return pr.first;
}

void dfs(int v, vector<int> &nodes)
{
    nodes.push_back(v);
    visited[v] = true;
    for (int edgeId : adjList[v])
    {
        int adj = other(edges[edgeId], v);
        if (!ac[edgeId] || visited[adj])
            continue;
        dfs(adj, nodes);
    }
}

void euler(int v, vector<int> &path)
{
    while (!adjList[v].empty())
    {
        int edgeId = *adjList[v].begin();
        int adj = other(edges[edgeId], v);
        adjList[v].erase(adjList[v].begin());
        adjList[adj].erase(adjList[adj].find(edgeId));
        if (!ac[edgeId])
            continue;
        euler(adj, path);
    }
    path.push_back(v);
}

bool solve(int n, int m, int root)
{
    fill(hasEdge + 1, hasEdge + n + 1, -1);
    fill(deg + 1, deg + n + 1, 0);
    fill(ac, ac + m, false);
    //vector<pair<int, int>> newEdges;
    for (int i = 0; i < m; i++)
    {
        if (edges[i].first == root || edges[i].second == root)
        {
            hasEdge[other(edges[i], root)] = i;
            continue;
        }
        deg[edges[i].first] ^= 1;
        deg[edges[i].second] ^= 1;
        //newEdges.push_back(edges[i]);
        ac[i] = true;
    }
    vector<vector<int>> comps;
    fill(visited + 1, visited + n + 1, false);
    for (int i = 1; i <= n; i++)
        adjList[i] = adjListSave[i];
    for (int i = 1; i <= n; i++)
    {
        if (i == root || visited[i])
            continue;
        comps.push_back(vector<int>());
        dfs(i, comps.back());
    }
    for (vector<int> comp : comps)
    {
        if (comp.size() == 1)
            continue;
        bool foundOdd = false;
        for (int v : comp)
        {
            if (deg[v] && hasEdge[v] != -1)
            {
                deg[root] ^= 1;
                deg[v] ^= 1;
                ac[hasEdge[v]] = true;
                foundOdd = true;
            }
        }
        if (!foundOdd)
        {
            for (int v : comp)
            {
                if (hasEdge[v] != -1)
                {
                    deg[root] ^= 1;
                    deg[v] ^= 1;
                    ac[hasEdge[v]] = true;
                    break;
                }
            }
        }
    }
    int numOdd = 0;
    for (int i = 1; i <= n; i++)
    {
        numOdd += deg[i];
    }
    if (numOdd > 2)
        return false;
    if (numOdd == 2 && !deg[root])
        return false;
    for (int i = 1; i <= n; i++)
    {
        adjList[i] = adjListSave[i];
    }
    vector<int> path;
    euler(root, path);
    path.push_back(-1);
    for (int i = 0; i < m; i++)
    {
        if (ac[i])
            continue;
        path.push_back(other(edges[i], root));
        path.push_back(root);
    }
    cout << path.size() << "\n";
    for (int v : path)
        cout << v << " ";
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
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        adjListSave[u].insert(i);
        adjListSave[v].insert(i);
    }
    bool found = false;
    for (int i = 1; i <= n; i++)
    {
        //cout << "testing " << i << endl;
        if (solve(n, m, i))
        {
            found = true;
            break;
        }
    }
    if (!found)
        cout << "0\n";
    return 0;
}