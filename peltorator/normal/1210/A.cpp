#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>

using namespace std;
//mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

const int N = 10;

int mx = 0;
vector<int> g[N];
int n;
int col[N];

int cnt[N][N];

void gen(int v)
{
    if (v == n)
    {
        for (int i = 0; i < n; i++)
            for (int u : g[i])
            {
                int t = col[i];
                int z = col[u];
                cnt[min(t, z)][max(t, z)] = 1;
            }
        int cur = 0;
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
            {
                cur += cnt[i][j];
                cnt[i][j] = 0;
            }
        mx = max(mx, cur);
        return;
    }
    for (int i = 0; i < 6; i++)
    {
        col[v] = i;
        gen(v + 1);
    }
}

int solve()
{
    if (!(cin >> n))
        return 1;
    int m;
    cin >> m;
    for (int i = 0; i < n; i++)
        g[i].clear();
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    mx = 0;
    gen(0);
    cout << mx << endl;
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    // cin >> TET;
    for (int i = 1; i <= TET; i++)
    {
        if (solve())
            break;
        cout << '\n';
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}