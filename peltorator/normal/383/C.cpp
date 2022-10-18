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
#include <bitset>
#include <ctime>
#include <cassert>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 200001, B = 250, T = 2;

ll a[N];
int lvl[N];
vector<int> g[N];
int timer, tin[T][N], tout[T][N];
vector<int> tour[T];

void dfs(int v, int pr, int level)
{
    lvl[v] = level;
    tin[lvl[v] % 2][v] = tour[lvl[v] % 2].size();
    tour[lvl[v] % 2].push_back(v);
    tin[(lvl[v] + 1) % 2][v] = tour[(lvl[v] + 1) % 2].size();
    for (int u : g[v])
        if (u != pr)
            dfs(u, v, level + 1);
    for (int i = 0; i < 2; i++)
        tout[i][v] = tour[i].size();
}

bool anc(int pr, int v)
{
    return tin[pr] <= tin[v] && tout[pr] >= tout[v];
}

const int TT = 2000001;
int t[T][TT];

void upd(int num, int v, int l, int r, int ql, int qr, int val)
{
    if (r <= l || ql >= r || l >= qr)
        return;
    if (ql <= l && r <= qr)
    {
        t[num][v] += val;
        return;
    }
    int mid = (r + l) / 2;
    upd(num, 2 * v, l, mid, ql, qr, val);
    upd(num, 2 * v + 1, mid, r, ql, qr, val);
}

int tf(int num, int v, int l, int r, int q)
{
    if (r <= l || q >= r || l > q)
        return 0;
    if (l + 1 == r)
        return t[num][v];
    int mid = (r + l) / 2;
    if (q < mid)
        return t[num][v] + tf(num, 2 * v, l, mid, q);
    return t[num][v] + tf(num, 2 * v + 1, mid, r, q);
}

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
        return 1;
    int m;
    cin >> m;
    for (int i = 1; i <= n; i++)
    {   
        cin >> a[i];
        g[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    timer = 1;
    tour[0].clear();
    tour[1].clear();
    dfs(1, -1, 1);
    for (int i = 0; i < TT; i++)
        t[1][i] = t[0][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int type, v;
        cin >> type >> v;
        if (type == 1)
        {
            int val;
            cin >> val;
            upd(lvl[v] % 2, 1, 0, (int)tour[lvl[v] % 2].size(), tin[lvl[v] % 2][v], tout[lvl[v] % 2][v], val);
            upd((lvl[v] + 1) % 2, 1, 0, (int)tour[(lvl[v] + 1) % 2].size(), tin[(lvl[v] + 1) % 2][v], tout[(lvl[v] + 1) % 2][v], -val);
        }
        else
        {
            cout << a[v] + tf(lvl[v] % 2, 1, 0, (int)tour[lvl[v] % 2].size(), tin[lvl[v] % 2][v]) << "\n";
        }
    }
    return 0;
}

int32_t main()
{
    int T = 1;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    while (!solve()) {
  //  cin >> T; for (int i = 0; i < T; i++) { solve();
        #ifdef ONPC
            cerr << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
        #endif
    }
#ifndef ONLINE_JUDGE
    cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
#endif
    return 0;
}