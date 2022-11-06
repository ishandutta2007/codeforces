#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<pair<int, int>> adjList[MAXN + 1];
vector<pair<int, int>> revAdjList[MAXN + 1];
pair<int, int> t[MAXN + 1];
bool visited[MAXN + 1];
int curTime = 1;
int compId[MAXN + 1];
long long dist[MAXN + 1];
vector<long long> g;

void dfs(int v)
{
    visited[v] = true;
    for (pair<int, int> edge : adjList[v])
    {
        int adj = edge.first;
        if (visited[adj])
            continue;
        dfs(adj);
    }
    t[v] = {curTime++, v};
}

void dfs2(int v, int id)
{
    visited[v] = true;
    compId[v] = id;
    for (pair<int, int> edge : revAdjList[v])
    {
        int adj = edge.first;
        if (visited[adj])
            continue;
        dfs2(adj, id);
    }
}

void dfs3(int v, long long d, vector<long long> &cycleLens)
{
    dist[v] = d;
    visited[v] = true;
    for (pair<int, int> edge : adjList[v])
    {
        int adj = edge.first;
        int w = edge.second;
        if (compId[v] != compId[adj])
            continue;
        if (visited[adj])
        {
            cycleLens.push_back(abs(dist[v] - dist[adj] + w));
        }
        else
        {
            dfs3(adj, d + w, cycleLens);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, l;
        cin >> u >> v >> l;
        adjList[u].push_back({v, l});
        revAdjList[v].push_back({u, l});
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    /*
    for (int i = 1; i <= n; i++)
    {
        cout << "finish time " << i << " " << t[i].first << endl;
    }
    */
    sort(t + 1, t + n + 1);
    reverse(t + 1, t + n + 1);
    fill(visited + 1, visited + n + 1, false);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int v = t[i].second;
        if (!visited[v])
        {
            dfs2(v, cnt++);
        }
    }
    g = vector<long long>(cnt, -1);
    fill(visited + 1, visited + n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            vector<long long> vec;
            dfs3(i, 0, vec);
            if (!vec.empty())
            {
                long long theGcd = vec[0];
                for (long long num : vec)
                {
                    //cout << "num " << num << endl;
                    theGcd = __gcd(theGcd, num);
                }
                g[compId[i]] = theGcd;
            }
            //cout << "gcd of " << compId[i] << " " << g[compId[i]] << endl;
        }
    }
    /*
    for (int i = 1; i <= n; i++)
        cout << "id " << i << " " << compId[i] << endl;
    */
    int q;
    cin >> q;
    while (q--)
    {
        int v, s, mod;
        cin >> v >> s >> mod;
        if (s == 0)
        {
            cout << "YES\n";
        }
        else
        {
            int target = mod - s;
            int id = compId[v];
            if (g[id] == -1)
            {
                cout << "NO\n";
            }
            else
            {
                long long gg = __gcd(g[id], (long long) mod);
                if (target % gg == 0)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
    return 0;
}