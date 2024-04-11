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
#include <complex>
#include <unordered_map>
#include <ctime>
#include <cassert>
   
using namespace std;
   
typedef long long ll;
typedef long double ld;


const int INF = 1e9;
const int N = 200001, LG = 20;

int pr[N];
int sz[N];

int find_set(int v)
{
    return (v == pr[v] ? v : pr[v] = find_set(pr[v]));
}

bool union_sets(int v, int u)
{
    v = find_set(v);
    u = find_set(u);
    if (u == v)
        return 0;
    if (sz[u] > sz[v])
        swap(u, v);
    sz[v] += sz[u];
    pr[u] = v;
    return 1;
}

ll ans[N];
vector<int> g[N], w[N], num[N];
int binup[LG][N], maxx[LG][N];
int lvl[N];
int timer;
int tin[N], tout[N];

void dfs(int v, int pr, int l, int level)
{
    tin[v] = timer++;
    binup[0][v] = pr;
    maxx[0][v] = l;
    lvl[v] = level;
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i] != pr)
            dfs(g[v][i], v, w[v][i], level + 1);
    tout[v] = timer++;
}

bool anc(int pr, int v)
{
    return tin[pr] <= tin[v] && tout[pr] >= tout[v];
}

int lca(int v, int u)
{
    if (anc(v, u))
        return v;
    if (anc(u, v))
        return u;
    for (int i = LG - 1; i >= 0; i--)
        if (!anc(binup[i][v], u))
            v = binup[i][v];
    return binup[0][v];
}

ll find1(int v, int l)
{
    ll ans = 0;
    for (int i = LG - 1; i >= 0; i--)
        if (anc(l, binup[i][v]))
            ans = max(ans, (ll)maxx[i][v]), v = binup[i][v];
    return ans;
}

ll find(int v, int u)
{
    ll ans = 0;
    int l = lca(v, u);
    if (l != v)
        ans = max(ans, find1(v, l));
    if (l != u)
        ans = max(ans, find1(u, l));
    return ans;
}

vector<pair<pair<int, int>, pair<int, int> > > e;

int solve()
{
    ios::sync_with_stdio(0);
    int n, m;
    if (!(cin >> n))
        return 1;
    cin >> m;
    e.clear();
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        e.push_back({{z, i}, {x, y}});
    }
    sort(e.begin(), e.end());
    for (int i = 1; i <= n; i++)
        pr[i] = i, sz[i] = 1;
    for (int i = 0; i < m; i++)
        ans[i] = -1;
    ll curans = 0;
    for (auto it : e)
        if (union_sets(it.second.first, it.second.second))
        {
            curans += it.first.first;
            g[it.second.first].push_back(it.second.second);
            w[it.second.first].push_back(it.first.first);
            num[it.second.first].push_back(it.first.second);
            g[it.second.second].push_back(it.second.first);
            w[it.second.second].push_back(it.first.first);
            num[it.second.second].push_back(it.first.second);
            ans[it.first.second] = 0;
        }
    for (int i = 0; i < m; i++)
        if (ans[i] == 0)
            ans[i] = curans;
    timer = 1;
    dfs(1, 1, 0, 0);
    for (int i = 1; i < LG; i++)
        for (int v = 1; v <= n; v++)
        {
            binup[i][v] = binup[i - 1][binup[i - 1][v]];
            maxx[i][v] = max(maxx[i - 1][v], maxx[i - 1][binup[i - 1][v]]);
        }
    for (auto it : e)
    {
        int v = it.second.first;
        int u = it.second.second;
        int num = it.first.second;
        int l = it.first.first;
        if (ans[num] == -1)
            ans[num] = curans - find(v, u) + l;
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";
    return 0;
}
 

int main()
{
    int T = 1;
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif
    while (!solve()) {
  //  cin >> T; for (int i = 0; i < T; i++) { solve();
        #ifdef ONPC
            cerr << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
        #endif
    }
#ifdef ONPC
    cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
#endif
    return 0;
}