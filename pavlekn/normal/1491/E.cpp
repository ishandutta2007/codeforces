#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

vector<vector<int>> g(MAXN);

int used[MAXN];
int deg[MAXN];
int dist[MAXN];
int mn[MAXN];

int f[30];

int n;

int sz[MAXN];

void check(int u)
{
    sz[u] = 1;
    used[u] = true;
    vector<int> cur;
    for (auto v : g[u])
    {
        if (!used[v])
        {
            check(v);
            sz[u] += sz[v];
            cur.push_back(sz[v]);
        }
    }
    if (n != sz[u])
    {
        cur.push_back(n - sz[u]);
    }
    vector<int> us(30);
    sort(cur.begin(), cur.end());
    int i = 0;
    for (auto el : cur)
    {
        int mm = el;
        for (int i = 29; i >= 0; --i)
        {
            if (mm >= f[i] && !us[i])
            {
                us[i] = true;
                mm -= f[i];
            }
        }
        if (mm > 0)
        {
            cout << "NO" << endl;
            exit(0);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < 30; ++i)
    {
        f[i] = f[i - 1] + f[i - 2];
        mn[i] = (mn[i - 1] + 1) / 2 + 1 + (mn[i - 2] + 1) / 2;
    }
    int num = -1;
    for (int i = 0; i < 30; ++i)
    {
        if (f[i] == n)
        {
            num = i;
        }
    }
    if (num == -1)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++deg[u]; ++deg[v];
    }
    for (int i = 0; i < n; ++i)
    {
        int cnt = 0;
        for (auto v : g[i])
        {
            if (deg[v] == 1)
            {
                ++cnt;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        used[i] = false;
    }
    check(0);
    cout << "YES" << endl;
    return 0;
}