#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef double ld;
const int N = 200001;
int used[N];
vector<int> ans, gr[N];
set<int> g[N];

int dfs(int v)
{
    used[v] = 1;
    int t = 1;
    for (int i = 0; i < gr[v].size(); i++)
        if (!used[gr[v][i]])
            t += dfs(gr[v][i]);
    return t;
}

int main()
{
 //   freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].insert(y);
        g[y].insert(x);
    }
    for (int i = 0; i < n; i++)
        g[i].insert(i);// sort(g[i].begin(), g[i].end());
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (g[i].count(j))
            j++;
        if (j < n)
            gr[i].push_back(j), gr[j].push_back(i);
        j = n - 1;
        while (g[i].count(j))
            j--;
        if (j >= 0)
            gr[i].push_back(j), gr[j].push_back(i);
        for (int ii = 0; ii < 1e7 / n; ii++)
        {
            int t = rand() % n;
            if (!g[i].count(t))
                gr[i].push_back(t), gr[t].push_back(i);
        }
       /* if (j == g[i].size() && g[i].size() < n)
            gr[i].push_back(g[i].size());
        id (j < g[i].size())*/
    }
    for (int i = 0; i < n; i++)
        if (!used[i])
            ans.push_back(dfs(i));
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i : ans)
        cout << i << " ";
    return 0;
}