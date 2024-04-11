#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
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
#include <random>

#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

const int N = 1005;

vector<int> g[N];

vector<int> used;

int dfs(int v, int p)
{
    if (used[v])
        return v;
    for (int u : g[v])
        if (u != p)
        {
            int t = dfs(u, v);
            if (t != -1)
                return t;
        }
    return -1;
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int k1;
    cin >> k1;
    vector<int> x(k1);
    for (int i = 0; i < k1; i++)
        cin >> x[i];
    int k2;
    cin >> k2;
    vector<int> y(k2);
    for (int i = 0; i < k2; i++)
        cin >> y[i];
    cout << "B " << y[0] << endl;
    int v;
    cin >> v;
    used.assign(n + 1, 0);
    for (int i : x)
        used[i] = 1;
    int need = dfs(v, -1);
    cout << "A " << need << endl;
    int u;
    cin >> u;
    bool ok = 0;
    for (int i : y)
        if (i == u)
            ok = 1;
    cout << "C ";
    if (ok)
        cout << need;
    else
        cout << -1;
    cout << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int T = 100;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cout << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cout << "__________________________\n";
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}