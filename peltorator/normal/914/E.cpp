#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;
typedef double ld;

#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int MAXN = 200007;
const int N = MAXN;
const int F = (1 << 21);
 
vector<int> g[MAXN], d;
int used[MAXN];
ll ans[N];
int a[N];
int cnt, n;
 
int dfs(int v, int p)
{
    //cout << v << " ";
    cnt++;
    d[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if (!used[u] && u != p)
            d[v] += dfs(u, v);
    }
    return d[v];
}
 
int centroid(int v)
{
    cnt = 0;
    dfs(v, -1);
    int p = -1;
    while (true)
    {
        int z = -1;
        for (int i = 0; i < g[v].size(); i++)
        {
            int u = g[v][i];
            if (!used[u] && u != p && d[u] * 2 >= cnt)
                z = u;
        }
        if (z == -1)
            break;
        p = v;
        v = z;
    }
    return v;
}

ll kek[F];
ll timer;
ll q[F];
ll mem[F];
ll root;
vector<int> tau, w;
vector<int> was, ff;

ll dfs1(int v, int lvl, int p)
{
    ff.push_back(v);
    ll cur = mem[(a[root] ^ lvl)] - q[(a[root] ^ lvl)];
    for (int i = 0; i <= 20; i++)
    {
        int R = (a[root] ^ lvl ^ (1 << i));
        cur += mem[R] - q[R];
        if (lvl == (1 << i))
            cur++;
    }
    if (lvl == 0)
        cur++;
    for (int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if (!used[u] && u != p)
            cur += dfs1(u, (lvl ^ a[u]), v);
    }
    ans[v] += cur;
    return cur;
}

void dfs2(int v, int lvl, int p)
{
    if (!q[lvl])
        tau.push_back(lvl);
    w.push_back(lvl);
    q[lvl]++;
    for (int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if (!used[u] && u != p)
            dfs2(u, (lvl ^ a[u]), v);
    }
}

void go(int v)
{
    //cout << "--------\n";
    //cout << "find centr from " << v << " " << endl;
    v = centroid(v);
    //cout << "\ncentroid: " << v << endl << "----------\n";
    root = v;
    used[v] = 1;
    w.clear();
    for (int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if (used[u])
            continue;
        timer++;
        tau.clear();
        dfs2(u, (a[v] ^ a[u]), v);
        for (int j = 0; j < tau.size(); j++)
        {
            int ms = tau[j];
            ans[v] += q[ms] * mem[(ms ^ a[v])];
            for (int j = 0; j <= 20; j++)
                ans[v] += q[ms] * mem[(a[v] ^ ms ^ (1 << j))];
        }
        for (int j = 0; j < tau.size(); j++)
        {
            int ms = tau[j];
            mem[ms] += q[ms];
            q[ms] = 0;
        }
    }
    for (int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if (used[u])
            continue;
        timer++;
        tau.clear();
        ff.clear();
        dfs2(u, (a[v] ^ a[u]), v);
        dfs1(u, (a[v] ^ a[u]), v);
        for (int j = 0; j < tau.size(); j++)
            q[tau[j]] = 0;
    }
    ans[v] += mem[0];
    ans[v]++;
    for (int i = 0; i <= 20; i++)
        ans[v] += mem[(1 << i)];
    for (int i = 0; i < w.size(); i++)
            mem[w[i]] = 0;
    for (int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if (!used[u])
            go(u);
    }
}
 
int main()
{
   // freopen("in.txt", "r", stdin);
   // fastRead;
    //cin >> n;
    scanf("%d", &n);
    d.assign(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
       // cin >> u >> v;
        scanf("%d %d", &u, &v);
        g[v].push_back(u);
        g[u].push_back(v);
    }
    string s;
    //cin >> s;
    getline(cin, s);
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
        a[i + 1] = (1 << (int)(s[i] - 'a'));
    go(1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}