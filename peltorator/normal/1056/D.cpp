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

const int N = 112345;

int cnt[N], l[N], r[N];
vector<int> g[N];
int cur = 0;

void dfs(int v)
{
    if (g[v].size() == 0)
    {
        l[v] = r[v] = cur++;
    }
    else
    {
        l[v] = -1;
        for (int u : g[v])
        {
            dfs(u);
            if (l[v] == -1)
                l[v] = l[u];
            r[v] = r[u];
        }
    }
    cnt[r[v] - l[v]]++;
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    for (int i = 0; i < N; i++)
    {
        g[i].clear();
        l[i] = r[i] = cnt[i] = 0;
    }
    cur = 0;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    dfs(1);
    for (int i = 1; i < N; i++)
        cnt[i] += cnt[i - 1];
    int kek = 0;
    for (int i = 1; i <= n; i++)
    {
        while (cnt[kek] < i)
            kek++;
        cout << kek + 1 << ' ';
    }
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