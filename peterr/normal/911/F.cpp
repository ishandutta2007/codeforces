#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<int> adjList[MAXN + 1];
int d1[MAXN + 1];
int d2[MAXN + 1];
bool mark[MAXN + 1];
tuple<int, int, int> q[MAXN];
int ind = 0;
int v1 = 0;
int v2 = 0;
vector<int> path;

pair<int, int> far(int v, int p, int l)
{
    pair<int, int> ans = make_pair(v, l);
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        pair<int, int> pr = far(adj, v, l + 1);
        if (pr.second > ans.second)
            ans = pr;
    }
    return ans;
}

void dfs(int v, int p, int d[MAXN + 1], int l)
{
    d[v] = l;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        dfs(adj, v, d, l + 1);
    }
}

bool domark(int v, int p, int tar)
{
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        if (domark(adj, v, tar))
        {
            path.push_back(v);
            mark[v] = true;
            return true;
        }
    }
    if (v == tar)
    {
        path.push_back(v);
        mark[v] = true;
        return true;
    }
    return false;
}

long long solve(int v, int p)
{
    long long ans = 0;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        ans += solve(adj, v);
    }
    if (!mark[v])
    {
        ans += max(d1[v], d2[v]);
        if (d1[v] > d2[v])
            q[ind++] = make_tuple(v, v1, v);
        else
            q[ind++] = make_tuple(v, v2, v);
        mark[v] = true;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    v1 = far(1, 1, 0).first;
    v2 = far(v1, v1, 0).first;
    dfs(v1, v1, d1, 0);
    dfs(v2, v2, d2, 0);
    domark(v1, v1, v2);
    long long ans = (long long) d1[v2] * (d1[v2] + 1) / 2;
    ans += solve(v1, v1);
    for (int x : path)
    {
        if (x != v1)
            q[ind++] = make_tuple(x, v1, x);
    }
    cout << ans << "\n";
    for (int i = 0; i < ind; i++)
        cout << get<0>(q[i]) << " " << get<1>(q[i]) << " " << get<2>(q[i]) << "\n";
    return 0;
}