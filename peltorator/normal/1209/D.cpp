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

const int N = 312345;

vector<int> g[N];
int used[N];

void dfs(int v)
{
    used[v] = 1;
    for (int u : g[v])
        if (!used[u])
            dfs(u);
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int k;
    cin >> k;
    vector<int> x(k), y(k);
    for (int i = 0; i < k; i++)
    {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
        g[x[i]].push_back(y[i]);
        g[y[i]].push_back(x[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (!used[i] && sz(g[i]))
            cnt++, dfs(i);
    for (int j = 0; j < n; j++)
        if (sz(g[j]))
            cnt--;
    cout << k + cnt << endl;
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