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

#define sz(a) (int)((a).size())
#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

vector<int> a[4][4];
ll d[4][4];

int used[4];

ll dfs(int v)
{
    used[v] = 1;
    ll ans = d[v][v];
    for (int i = 0; i < 4; i++)
        if (a[v][i].size() && !used[i])
            ans += d[v][i] + dfs(i);
    return ans;
}

int go[4][4];

ll gen(int v)
{
  //  cout << "in " << v << endl;
    ll ans = 0;
    bool ok = 0;
    if (!used[v])
    {
        ok = 1;
        used[v] = 1;
    }
    for (int i = 0; i < 4; i++)
        if (i != v && !go[v][i] && a[v][i].size())
        {
            if (a[v][i].size() == 1 && go[i][v])
                continue;
            go[v][i] = 1;
            ll k = d[v][i];
            if (!go[i][v] && a[v][i].size() % 2 == 0)
                k -= a[v][i][0];
            if (go[i][v] && a[v][i].size() % 2 == 1)
                k = -a[v][i][0];
            else if (go[i][v])
                k = a[v][i][0];
            ans = max(ans, gen(i) + k);
            go[v][i] = 0;
        }
    if (ok)
        used[v] = 0;
  //  cout << "out " << v << ' ' << ans + (ok ? d[v][v] : 0) << endl;
    return ans + (ok ? d[v][v] : 0);
}

ll gen()
{
    ll ans = 0;
    for (int i = 0; i < 4; i++)
        ans = max(ans, gen(i));
    return ans;
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            a[i][j].clear(), used[i] = 0, d[i][j] = 0, go[i][j] = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        z--;
        a[x][z].push_back(y);
        if (x != z)
            a[z][x].push_back(y);
    }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k : a[i][j])
                d[i][j] += k;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            sort(a[i][j].begin(), a[i][j].end());
    ll ans = 0;
  /*  for (int i = 1; i < 15; i++)
    {
        for (int i = 0; i < 4; i++)
            used[i] = 0;
        for (int j = 0; j < 4; j++)
            if ((i & (1 << j)))
                used[j] = 1;
        int k = 0;
        while ((i & (1 << k)))
            k++;
        ans = max(ans, dfs(k));
    }*/
    for (int i = 0; i < 4; i++)
        used[i] = 0;
    cout << max(ans, gen()) << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int T = 100;
    //cin >> T;
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