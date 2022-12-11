#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

#define int long long

vector<vector<pair<int, int>>> g(MAXN);

int k;

vector<int> p;

int d[MAXN];
int deg[MAXN];
int H[10][10];

int r[MAXN];

int ans = 0;
int sum = 0;

void gen(int i)
{
    if (i == k)
    {
        int cur = 0;
        for (int i = 0; i < k; ++i)
        {
            cur += H[i + 1][p[i] + 1];
        }
        if (cur == sum)
        {
            ++ans;
        }
        return;
    }
    for (int j = 0; j <= i; ++j)
    {
        p.push_back(j);
        gen(i + 1);
        p.pop_back();
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); srand(clock());
    int n, m;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].push_back({w, v});
        ++d[u];
    }
    for (int i = 0; i < n; ++i)
    {
        sort(g[i].begin(), g[i].end());
    }
    for (int i = 0; i < n; ++i)
    {
        r[i] = rand() * 32 + rand();
        sum += r[i];
    }
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            for (int u = 0; u < n; ++u)
            {
                if (d[u] == i)
                {
                    H[i][j] += r[g[u][j - 1].second];
                }
            }
        }
    }
    gen(0);
    cout << ans << endl;
    return 0;
}