#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef double ld;

const int N = 500001;


vector<int> g[N];
int t[N];

pair<int, int> dfs(int v, int pr)
{
    int best = v, depth = 0;
    for (int u : g[v])
        if (u != pr)
        {
            auto a = dfs(u, v);
            if (a.second + 1 > depth)
            {
                depth = a.second + 1;
                best = a.first;
            }
        }
    return {best, depth};
}

int d1[N], d2[N];

void dfs1(int v, int pr, int lvl)
{
    d1[v] = lvl;
    for (int u : g[v])
        if (u != pr)
            dfs1(u, v, lvl + 1);
}

ll f(int v, int u, int n)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (i != v && i != u && g[i].size() == 1)
            q.push(i);
    bool ok = false;
    if (!q.size())
    {
        q.push(u);
        ok = true;
    }
    ll ans = 0;
    bool ok2 = 0;
    while (q.size())
    {
        int leaf = q.front();
        q.pop();
        if (leaf == v)
            continue;
        if (leaf == u)
            ok2 = 1;
        //cout << leaf << " ";
        //cout << (d1[leaf] > d2[leaf] || ok2 ? v : u); 
       //cout << " " << leaf << "\n";
        if (d1[leaf] > d2[leaf] || ok2)
            ans += d1[leaf];
        else
            ans += d2[leaf];
        for (int to : g[leaf])
        {
            t[to]++;
            if (t[to] == g[to].size() - 1)
                q.push(to);
        }
        if (!q.size() && !ok)
        {
            q.push(u);
            ok = true;
        }
    }
    return ans;
}

int main()
{
  //  freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int v = dfs(1, -1).first;
    int u = dfs(v, -1).first;
    dfs1(u, -1, 0);
    for (int i = 1; i <= n; i++)
        d2[i] = d1[i], d1[i] = 0;
    dfs1(v, -1, 0);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += max(d1[i], d2[i]);
    cout << f(v, u, n) << endl;// ans - d1[u] << endl;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (i != v && i != u && g[i].size() == 1)
            q.push(i);
    for (int i = 1; i <= n; i++)
        t[i] = 0;
    bool ok = false;
    if (!q.size())
    {
        q.push(u);
        ok = true;
    }
    bool ok2 = 0;
    while (q.size())
    {
        int leaf = q.front();
        q.pop();
        if (leaf == v)
            continue;
        if (leaf == u)
            ok2 = 1;
        cout << leaf << " ";
        cout << (d1[leaf] > d2[leaf] || ok2 ? v : u); 
        cout << " " << leaf << "\n";
        for (int to : g[leaf])
        {
            t[to]++;
            if (t[to] == g[to].size() - 1)
                q.push(to);
        }
        if (!q.size() && !ok)
        {
            q.push(u);
            ok = true;
        }
    }
    return 0;
}