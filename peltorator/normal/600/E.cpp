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
typedef long double ld;

const int N = 100001;

int c[N];
ll ans[N];
map<int, int> q[N];
vector<int> g[N];
int num[N];
int sz[N];
int used[N];

void dfs(int v)
{
    used[v] = 1;
    num[v] = -1;
    sz[v] = 0;
    ans[v] = 0;
    for (int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if (used[u])
            continue;
        dfs(u);
        if (num[v] == -1)
        {
            num[v] = num[u];
            sz[v] = sz[u];
            ans[v] = ans[u];
        }
        else
        {
            if (q[num[v]].size() > q[num[u]].size())
            {
                for (map<int, int>::iterator it = q[num[u]].begin(); it != q[num[u]].end(); it++)
                {
                    if (it->second == 0)
                        continue;
                    q[num[v]][it->first] += it->second;
                    if (q[num[v]][it->first] == sz[v])
                        ans[v] += it->first;
                    else if (q[num[v]][it->first] > sz[v])
                    {
                        ans[v] = it->first;
                        sz[v] = q[num[v]][it->first];
                    }
                }
            }
            else
            {
                ll T = ans[u];
                for (map<int, int>::iterator it = q[num[v]].begin(); it != q[num[v]].end(); it++)
                {
                    if (it->second == 0)
                        continue;
                    q[num[u]][it->first] += it->second;
                    if (q[num[u]][it->first] == sz[u])
                        ans[u] += it->first;
                    else if (q[num[u]][it->first] > sz[u])
                    {
                        ans[u] = it->first;
                        sz[u] = q[num[u]][it->first];
                    }
                }
                ans[v] = ans[u];
                sz[v] = sz[u];
                num[v] = num[u];
                ans[u] = T;
            }
        }
    }
    if (num[v] == -1)
        num[v] = v;
    q[num[v]][c[v]]++;
    if (q[num[v]][c[v]] == sz[v])
        ans[v] += c[v];
    else if (q[num[v]][c[v]] > sz[v])
    {
        ans[v] = c[v];
        sz[v] = q[num[v]][c[v]];
    }
}

int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.precision(30);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}