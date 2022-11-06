#include <bits/stdc++.h>

using namespace std;

const int MAXK = 500;
const int MAXN = 5E4;
vector<int> adjList[MAXN + 1];
bool activated[MAXN + 1];
int sz[MAXN + 1];
int freq[MAXK + 1];

void dfs(int v, int p)
{
    assert(!activated[v]);
    sz[v] = 1;
    for (int adj : adjList[v])
    {
        if (!activated[adj] && adj != p)
        {
            dfs(adj, v);
            sz[v] += sz[adj];
        }
    }
}

int getCentroid(int v)
{
    assert(!activated[v]);
    dfs(v, v);
    int totalSz = sz[v];
    int prev = v;
    while (true)
    {
        bool flag = false;
        for (int adj : adjList[v])
        {
            if (adj != prev && !activated[adj] && sz[adj] > totalSz / 2)
            {
                prev = v;
                v = adj;
                flag = true;
                break;
            }
        }
        if (!flag)
            break;
    }
    return v;
}

long long dfs2(int v, int p, int level, int k)
{
    assert(!activated[v]);
    long long ans = k - level >= 0 ? freq[k - level] : 0;
    for (int adj : adjList[v])
    {
        if (!activated[adj] && adj != p)
        {
            ans += dfs2(adj, v, level + 1, k);
        }
    }
    return ans;
}

void dfs3(int v, int p, int level)
{
    if (level <= MAXK)
        freq[level]++;
    for (int adj : adjList[v])
    {
        if (!activated[adj] && adj != p)
            dfs3(adj, v, level + 1);
    }
}

long long solve(int v, int k)
{
    assert(!activated[v]);
    v = getCentroid(v);
    fill(freq, freq + MAXK + 1, 0);
    freq[0] = 1;
    long long ans = 0;
    for (int adj : adjList[v])
    {
        if (!activated[adj])
        {
            ans += dfs2(adj, v, 1, k);
            dfs3(adj, v, 1);
        }
    }
    activated[v] = true;
    for (int adj : adjList[v])
    {
        if (!activated[adj])
        {
            ans += solve(adj, k);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    long long ans = solve(1, k);
    cout << ans << endl;
    return 0;
}