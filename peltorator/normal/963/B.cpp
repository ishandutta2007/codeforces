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

using namespace std;

mt19937 rnd(239);

typedef long long ll;
typedef long double ld;

const int N = 200001;
vector<int> vec, g[N], cuted;

void dfs2(int v, int pr)
{
    vec.push_back(v);
    cuted[v] = 1;
    for (int u : g[v])
        if (u != pr && !cuted[u])
            dfs2(u, v);
}

int dfs(int v, int pr, bool kek)
{
    int cur = 0;
    if (kek)
        cur = 1;
    for (int u : g[v])
        if (u != pr && !cuted[u])
        {
            if (dfs(u, v, 1))
                cur++;
        }
    if (cur % 2 == 0)
    {
        vec.push_back(v);
        cuted[v] = 1;
        for (int u : g[v])
            if (u != pr && !cuted[u])
                dfs2(u, v);
        return 0;
    }
    return 1;
}

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    cuted.assign(n + 1, 0);
    vec.clear();
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        if (p)
        {
            g[i].push_back(p);
            g[p].push_back(i);
        }
    }
    dfs(1, -1, 0);
    if (n % 2 == 0 || vec.size() != n)
    {
        cout << "NO\n";
        return 0;
    }
   // cout << vec.size() << endl;
    cout << "YES\n";
    for (int i : vec)
        cout << i << '\n';
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cerr << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cerr << "_______________________________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}