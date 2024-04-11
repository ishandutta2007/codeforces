#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int MAXM = 3E5;
pair<int, int> edges[MAXM];
vector<int> adjList[MAXN + 1];
vector<pair<int, int>> queries;
int a[MAXN + 1];
int par[MAXN + 1];
int sz[MAXN + 1];
int ptr[MAXN + 1];
vector<set<int>> nums;
bool del[MAXM];
vector<int> isBridge[MAXM];
vector<int> comp[MAXN + 1];

int getRoot(int x)
{
    if (par[x] != x)
        par[x] = getRoot(par[x]);
    return par[x];
}

bool mge(int x, int y, vector<int> &vec)
{
    x = getRoot(x);
    y = getRoot(y);
    if (x == y)
        return false;
    if (sz[x] > sz[y])
        swap(x, y);
    for (int z : comp[x])
    {
        vec.push_back(z);
        comp[y].push_back(z);
    }
    par[x] = y;
    sz[y] += sz[x];
    return true;
}

void dfs(int v, int id, set<int> &s)
{
    s.insert(a[v]);
    ptr[v] = id;
    for (int edgeId : adjList[v])
    {
        int adj = edges[edgeId].first;
        if (adj == v)
            adj = edges[edgeId].second;
        if (ptr[adj] == -1)
            dfs(adj, id, s);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
        cin >> a[i];
        comp[i].push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        adjList[u].push_back(i);
        adjList[v].push_back(i);
    }
    fill(ptr + 1, ptr + n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (ptr[i] == -1)
        {
            nums.push_back(set<int>());
            dfs(i, (int) nums.size() - 1, nums.back());
        }
    }
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        queries.push_back({u, v});
        if (u == 2)
            del[v - 1] = true;
    }
    for (int i = 0; i < m; i++)
    {
        if (del[i])
            continue;
        int id = i;
        int u = edges[id].first;
        int v = edges[id].second;
        mge(u, v, isBridge[id]);
    }
    reverse(queries.begin(), queries.end());
    for (pair<int, int> pr : queries)
    {
        if (pr.first == 2)
        {
            int id = pr.second - 1;
            int u = edges[id].first;
            int v = edges[id].second;
            mge(u, v, isBridge[id]);
        }
    }
    reverse(queries.begin(), queries.end());
    for (pair<int, int> pr : queries)
    {
        if (pr.first == 1)
        {
            if (nums[ptr[pr.second]].empty())
                cout << "0\n";
            else
            {
                cout << *(nums[ptr[pr.second]].rbegin()) << "\n";
                nums[ptr[pr.second]].erase(--nums[ptr[pr.second]].end());
            }
        }
        else
        {
            int id = pr.second - 1;
            if (isBridge[id].size())
            {
                nums.push_back(set<int>());
                int oldPtr = ptr[isBridge[id].back()];
                for (int v : isBridge[id])
                {
                    if (nums[oldPtr].count(a[v]))
                    {
                        nums[oldPtr].erase(a[v]);
                        nums.back().insert(a[v]);
                    }
                    ptr[v] = (int) nums.size() - 1;
                }
            }
        }
    }
    return 0;
}