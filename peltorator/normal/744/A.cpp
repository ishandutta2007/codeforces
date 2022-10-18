#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;

vector<int> g[200001], c, used;
vector<int> x;
int col = 0, ans;
bool ok;

int dfs(int v)
{
    ans++;
    if (c[v])
        ok = true;
    used[v] = col;
    for (int u : g[v])
        if (!used[u])
            dfs(u);
    return 0;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    c.resize(n + 1, 0);
    for (int i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        c[t] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int k, l;
        cin >> k >> l;
        g[k].push_back(l);
        g[l].push_back(k);
    }
    used.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        if (!used[i])
        {
            col++;
            ans = 0;
            ok = false;
            dfs(i);
            if (ok)
                x.push_back(ans);
        }
    sort(x.begin(), x.end());
    ll ans = 0, sum = 0;
    for (int i = 0; i + 1 < x.size(); i++)
    {
        ans += x[i] * (x[i] - 1) / 2;
        sum += x[i];
    }
    ans += (n - sum) * (n - sum - 1) / 2;
    cout << ans - m;
    return 0;
}