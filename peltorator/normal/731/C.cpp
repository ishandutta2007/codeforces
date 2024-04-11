#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>

using namespace std;

vector<int> c, g[200000], used;
vector< set< pair<int, int> > > q, Q;
int num, num1;

int dfs(int v, int j)
{
    used[v] = 1;
    auto p = Q[j].lower_bound(make_pair(c[v], -1e9));
    int h = 0;
    if (p != Q[j].end() && p->first == c[v])
    {
        h = p->second;
        Q[j].erase(*p);
    }
    q[j].insert(make_pair(h - 1, c[v]));
    Q[j].insert(make_pair(c[v], h - 1));
    num1++;
    for (int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if (used[u] == 0)
            dfs(u, j);
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    c.resize(n);
    used.resize(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        g[l - 1].push_back(r - 1);
        g[r - 1].push_back(l - 1);
    }
    int answ = 0;
    for (int i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            num1 = 0;
            set< pair<int, int> > p;
            q.push_back(p);
            Q.push_back(p);
            dfs(i, q.size() - 1);
            answ += num1 + q[q.size() - 1].begin()->first;
        }
    }
    cout << answ;
    return 0;
}