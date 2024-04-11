#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef double ld;

#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int N = 500001;

vector<int> g[N];
int used[N];
vector<int> a;

void dfs(int v, int lvl)
{
    used[v] = 1;
    bool ok = false;
    for (int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if (!used[u])
        {
            ok = true;
            dfs(u, lvl + 1);
        }
    }
    if (!ok)
        a.push_back(lvl);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    fastRead;
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    used[1] = 1;
    for (int i = 0; i < g[1].size(); i++)
    {
        a.clear();
        dfs(g[1][i], 0);
        sort(a.begin(), a.end());
        int t = -1;
        for (int i = 0; i < a.size(); i++)
            t = max(a[i], t + 1);
        ans = max(ans, t);
    }
    cout << ans + 1 << endl;
    return 0;
}