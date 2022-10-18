#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
//#define string basic_string<unsigned char>
#define char unsigned char

using namespace std;
//mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

const int N = 212345;

vector<int> g[N];
int used[N];
int mn, mx;

void dfs(int v, int col)
{
    used[v] = col;
    mn = min(mn, v);
    mx = max(mx, v);
    for (int u : g[v])
        if (!used[u])
            dfs(u, col);
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int m;
    cin >> m;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++)
        cnt[i] = i, used[i] = 0, g[i].clear();
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int col = 0;
    vector<pair<int, int> > q;
    for (int i = 0; i < n; i++)
        if (!used[i])
        {
            mn = mx = i;
            dfs(i, ++col);
            q.push_back({mn, -1});
            q.push_back({mx, 1});
        }
    sort(q.begin(), q.end());
    int ans = 0;
    int bal = 0;
    for (auto it : q)
    {
        int x = it.second;
        if (x == -1 && bal)
            ans++;
        bal += x;
    }
    cout << ans << '\n';
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