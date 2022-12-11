#include<bits/stdc++.h>

using namespace std;

const int MAXN = 107;

int dp[MAXN][MAXN][MAXN];
int ind[MAXN][MAXN][MAXN];
int a[MAXN][MAXN];

const long long INF = 1e18 + 118;

int n;

long long ans = INF;

bool used[MAXN];

void gen(int a, vector<int> & v)
{
    if (a == 0)
    {
        long long cur = 0;
        for (auto el : v)
        {
            used[el] = true;
        }
        for (int i = 0; i < v.size(); ++i)
        {
            int fl = false;
            for (int k = 0; k < min(n, 6); ++k)
            {
                if (!used[ind[v[i]][v[(i + 1) % v.size()]][k]])
                {
                    fl = true;
                    cur += (long long)dp[v[i]][v[(i + 1) % v.size()]][k];
                    break;
                }
            }
            if (!fl)
            {
                cur = INF;
            }
        }
        for (auto el : v)
        {
            used[el] = false;
        }
        ans = min(ans, cur);
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        v.push_back(i);
        gen(a - 1, v);
        v.pop_back();
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            vector<pair<int, int>> cc;
            for (int k = 0; k < n; ++k)
            {
                cc.push_back({a[i][k] + a[k][j], k});
            }
            sort(cc.begin(), cc.end());
            for (int k = 0; k < n; ++k)
            {
                dp[i][j][k] = cc[k].first;
                ind[i][j][k] = cc[k].second;
            }
        }
    }
    vector<int> v = {0};
    gen(k / 2 - 1, v);
    cout << ans << endl;
    return 0;
}