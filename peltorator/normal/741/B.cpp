#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> g[100001], w, b, used, sum, sumb;
vector< pair<ll, ll> > group[100001];

ll d[1001][1001];

ll dfs(ll v, ll col)
{
    used[v] = col;
    sum[col] += w[v];
    sumb[col] += b[v];
    group[col].push_back({w[v], b[v]});
    for (ll i = 0; i < g[v].size(); i++)
    {
        ll u = g[v][i];
        if (!used[u])
            dfs(u, col);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, W;
    cin >> n >> m >> W;
    w.resize(n + 1);
    b.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (ll i = 0; i < m; i++)
    {
        ll k, l;
        cin >> k >> l;
        g[k].push_back(l);
        g[l].push_back(k);
    }
    used.resize(n + 1);
    ll Col = 0;
    sum.push_back(0);
    sumb.push_back(0);
    for (int i = 1; i <= n; i++)
        if (!used[i])
        {
            sum.push_back(0);
            sumb.push_back(0);
            Col++;
            dfs(i, Col);
            sort(group[Col].begin(), group[Col].end());
            vector< pair<ll, ll> > x;
            for (int j = 0; j < group[Col].size(); j++)
                if (j == 0 || group[Col][j].second > x[x.size() - 1].second)
                    x.push_back(group[Col][j]);
            group[Col] = x;
        }
    ll ans = 0;
    for (ll col = 1; col <= Col; col++)
    {
        for (ll weight = 0; weight <= W; weight++)
        {
            if (sum[col] <= weight)
                d[col][weight] = d[col - 1][weight - sum[col]] + sumb[col];
            if (weight > 0)
                d[col][weight] = max(d[col][weight], d[col][weight - 1]);
            d[col][weight] = max(d[col][weight], d[col - 1][weight]);
            for (ll i = 0; i < group[col].size(); i++)
            {
                ll we = group[col][i].first, be = group[col][i].second;
                if (we <= weight)
                    d[col][weight] = max(d[col][weight], d[col - 1][weight - we] + be);
            }
        }
    }
    cout << d[Col][W];
    return 0;
}