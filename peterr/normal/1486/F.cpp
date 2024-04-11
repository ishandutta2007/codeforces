#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
const int LOGN = 19;
vector<int> adjList[MAXN + 1];
pair<int, int> paths[MAXN];
int root[MAXN];
int under[MAXN][2];
vector<int> pathsHere[MAXN + 1];
int anc[LOGN][MAXN + 1];
int dep[MAXN + 1];
int par[MAXN + 1];
int pref[MAXN + 1];
int neg[MAXN + 1];

void dfs(int v, int p, int d)
{
    par[v] = p;
    dep[v] = d;
    anc[0][v] = p;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        dfs(adj, v, d + 1);
    }
}

void dfs2(int v, int p)
{
    if (v != 1)
    {
        pref[v] += pref[p];
    }
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        dfs2(adj, v);
    }
}

bool isAnc(int v, int q)
{
    int diff = dep[v] - dep[q];
    if (diff < 0)
        return false;
    for (int i = 0; i < LOGN; i++)
    {
        if (diff & (1 << i))
            v = anc[i][v];
    }
    return v == q;
}

int lca(int u, int v, int &under1, int &under2)
{
    under1 = under2 = -1;
    if (u == v)
        return u;
    if (dep[u] > dep[v])
        swap(u, v);
    int diff = dep[v] - dep[u];
    if (diff != 0)
    {
        for (int i = 0; i < LOGN; i++)
        {
            if ((diff - 1) & (1 << i))
                v = anc[i][v];
        }
        if (u == anc[0][v])
        {
            under1 = v;
            return u;
        }
        v = anc[0][v];
    }
    for (int i = LOGN - 1; i >= 0; i--)
    {
        if (anc[i][u] != anc[i][v])
        {
            u = anc[i][u];
            v = anc[i][v];
        }
    }
    under1 = u;
    under2 = v;
    if (under1 > under2)
        swap(under1, under2);
    return anc[0][u];
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
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    dfs(1, 1, 0);
    for (int i = 1; i < LOGN; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            anc[i][j] = anc[i - 1][anc[i - 1][j]];
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        paths[i] = {u, v};
        root[i] = lca(u, v, under[i][0], under[i][1]);
        //cout << "under of " << i << " " << x << " " << y << endl;
        pathsHere[root[i]].push_back(i);
        pref[root[i]]++;
        for (int j = 0; j < 2; j++)
        {
            if (under[i][j] == -1)
                continue;
            pref[under[i][j]]--;
            neg[under[i][j]]++;
        }
    }
    dfs2(1, 1);
    map<int, int> mp1;
    map<pair<int, int>, int> mp2;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        long long s = (long long) pathsHere[i].size();
        ans += s * (s - 1) / 2;
        mp1.clear();
        mp2.clear();
        for (int pathId : pathsHere[i])
        {
            for (int j = 0; j < 2; j++)
            {
                if (under[pathId][j] == -1)
                    continue;
                ans -= mp1[under[pathId][j]];
                mp1[under[pathId][j]]++;
            }
            if (under[pathId][0] != -1 && under[pathId][1] != -1)
            {
                ans += mp2[{under[pathId][0], under[pathId][1]}];
                mp2[{under[pathId][0], under[pathId][1]}]++;
            }
        }
    }
    //cout << ans << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (under[i][j] == -1)
                continue;
            if (isAnc(paths[i].first, under[i][j]))
                ans += pref[paths[i].first] - pref[root[i]] + neg[under[i][j]];
            if (isAnc(paths[i].second, under[i][j]))
                ans += pref[paths[i].second] - pref[root[i]] + neg[under[i][j]];
        }
    }
    cout << ans << "\n";
    return 0;
}