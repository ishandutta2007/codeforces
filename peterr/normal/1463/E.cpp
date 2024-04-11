#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
vector<int> adjList[MAXN + 1];
vector<int> chainsOut[MAXN + 1];
vector<int> chainsIn[MAXN + 1];
int pos[MAXN + 1];
int chainId[MAXN + 1];
int chainSz[MAXN + 1];
vector<int> chains[MAXN + 1];
int sz[MAXN + 1];
bool visited[MAXN + 1];
int visible[MAXN + 1];
vector<int> lastSeen[MAXN + 1];
int depth[MAXN + 1];

void dfs1(int v, int p, int dep)
{
    depth[v] = dep;
    sz[v] = 1;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        dfs1(adj, v, dep + 1);
        if (chainId[v] == chainId[adj])
            sz[v] += sz[adj];
    }
}

bool dfs2(int v, int p, int dep)
{
    int id = chainId[v];
    if (!lastSeen[id].empty() && (depth[lastSeen[id].back()] != dep - 1 || pos[v] < pos[lastSeen[id].back()]))
        return false;
    lastSeen[id].push_back(v);
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        if (!dfs2(adj, v, dep + 1))
            return false;
    }
    lastSeen[id].pop_back();
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int root = 0;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        if (!p)
            root = i;
        else
        {
            adjList[p].push_back(i);
            adjList[i].push_back(p);
        }
        chainId[i] = i;
        chainSz[i] = 1;
        chains[i].push_back(i);
    }
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        chainsIn[y].push_back(x);
        chainsOut[x].push_back(y);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((int) chainsIn[i].size() > 0 || (int) chainsOut[i].size() == 0)
            continue;
        int id = chainId[i];
        int cur = i;
        while (!visited[cur])
        {
            chainId[cur] = id;
            visited[cur] = true;
            pos[cur] = cnt++;
            if (!chainsOut[cur].empty())
            {
                cur = chainsOut[cur].back();
                chains[id].push_back(cur);
                chainSz[id]++;
            }
        }
    }
    if (cnt < k)
    {
        cout << "0\n";
        return 0;
    }
    dfs1(root, root, 0);
    if (!dfs2(root, root, 0))
    {
        cout << "0\n";
        return 0;
    }
    fill(visited + 1, visited + n + 1, false);
    vector<int> ans;
    visible[chainId[root]] = sz[root];
    queue<int> q;
    if (sz[root] == chainSz[chainId[root]])
        q.push(chainId[root]);
    while (!q.empty())
    {
        int id = q.front();
        q.pop();
        for (int node : chains[id])
        {
            visited[node] = true;
            ans.push_back(node);
            for (int adj : adjList[node])
            {
                if (visited[adj] || chainId[adj] == id)
                    continue;
                visible[chainId[adj]] += sz[adj];
                if (visible[chainId[adj]] == chainSz[chainId[adj]])
                    q.push(chainId[adj]);
            }
        }
    }
    if ((int) ans.size() == n)
    {
        for (int node : ans)
            cout << node << " ";
        cout << "\n";
    }
    else
        cout << "0\n";
    return 0;
}