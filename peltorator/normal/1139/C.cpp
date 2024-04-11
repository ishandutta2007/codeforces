#ifdef ONPC
    # define _GLIBCXX_DEBUG
#endif
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
#include <iomanip>

#ifdef ONPC
    #define deb(a) cerr << "      " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

#define sz(a) (a).size()

using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

const int N = 2e5;

int used[N];

vector<int> g[N];

ll binpow(ll a, ll b)
{
    if (!b)
        return 1;
    if (b % 2)
        return (a * binpow(a, b - 1)) % MOD;
    return binpow(a * a % MOD, b / 2);
}

int dfs(int v)
{
    used[v] = 1;
    int cnt = 1;
    for (int u : g[v])
        if (!used[u])
            cnt += dfs(u);
    return cnt;
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
        g[i].clear();
    for (int i = 1; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        if (!z)
        {
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }
    ll ans = binpow(n, k);
    for (int i = 0; i < n; i++)
        used[i] = 0;
    for (int i = 0; i < n; i++)
        if (!used[i])
        {
            int x = dfs(i);
            ans = (ans + MOD - binpow(x, k)) % MOD;
        }
    cout << ans << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1e9;
    //cin >> T;
    while (T--)
    {
        if (solve())
            break;
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}