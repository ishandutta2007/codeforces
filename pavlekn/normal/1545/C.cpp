#include <bits/stdc++.h>

using namespace std;

#pragma GCC target("avx2")

const int mod = 998244353;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        long long cnt = 1;
        vector<vector<int>> a(2 * n, vector<int> (n));
        vector<vector<int>> c(n, vector<int> (n));
        vector<vector<int>> ind(n, vector<int> (n));
        vector<vector<int>> g(2 * n);
        for (int i = 0; i < 2 * n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> a[i][j];
                --a[i][j];
            }
        }
        for (int i = 0; i < 2 * n; ++i)
        {
            for (int j = i + 1; j < 2 * n; ++j)
            {
                int fl = false;
                for (int k = 0; k < n; ++k)
                {
                    if (a[i][k] == a[j][k])
                    {
                        fl = true;
                        break;
                    }
                }
                if (fl)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector<int> ans;
        vector<int> used(2 * n);
        for (int its = 0; its < n; ++its)
        {
            int ii = -1;
            for (int i = 0; i < 2 * n; ++i)
            {
                if (used[i])
                {
                    continue;
                }
                if (ii == -1)
                {
                    ii = i;
                }
                for (int j = 0; j < n; ++j)
                {
                    c[j][a[i][j]]++;
                    ind[j][a[i][j]] = i;
                }
            }
            int cur = -1;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (c[i][j] == 1)
                    {
                        cur = ind[i][j];
                    }
                    c[i][j] = 0;
                }
            }
            if (cur == -1)
            {
                cnt *= 2;
                cnt %= mod;
                ans.push_back(ii);
                used[ii] = true;
                for (auto el : g[ii])
                {
                    used[el] = true;
                }
            }
            else
            {
                ans.push_back(cur);
                used[cur] = true;
                for (auto el : g[cur])
                {
                    used[el] = true;
                }
            }
        }
        cout << cnt << "\n";
        for (auto el : ans)
        {
            cout << el + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}