#include<bits/stdc++.h>

using namespace std;

#define int long long

#pragma GCC optimize("-O3")
#pragma GCC target("avx2")

vector<pair<int, int>> dd[(1 << 15)];

int dp[(1 << 15)];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int k;
    cin >> k;
    vector<vector<int>> a(k);
    vector<int> sum(k);
    int sm = 0;
    for (int32_t i = 0; i < (1 << 15); ++i)
    {
        dd[i].resize(k, {-1, -1});
    }
    map<int, int> g;
    for (int32_t i = 0; i < k; ++i)
    {
        int n;
        cin >> n;
        for (int32_t j = 0; j < n; ++j)
        {
            int x;
            cin >> x;
            g[x] = i + 1;
            a[i].push_back(x);
            sum[i] += x;
            sm += x;
        }
    }
    for (int i = 0; i < k; ++i)
    {
        sum[i] = sm / k - sum[i];
    }
    if (sm % k != 0)
    {
        cout << "No" << endl;
        return 0;
    }
    for (int32_t i = 0; i < k; ++i)
    {
        for (auto el : a[i])
        {
            vector<int> used(k);
            int val = el;
            int ind = i;
            used[ind] = true;
            int mask = (1 << i);
            vector<pair<int, int>> cur(k);
            int ii = 0;
            while (g[sum[ind] + val] && !used[g[sum[ind] + val] - 1])
            {
                ++ii;
                int val2 = val + sum[ind];
                cur[g[sum[ind] + val] - 1] = {val2, ind + 1};
                ind = g[sum[ind] + val] - 1;
                val = val2;
                used[ind] = true;
                mask += (1 << ind);
            }
            if (g[val + sum[ind]] - 1 == i && el == val + sum[ind] && (ii || sum[i] == 0))
            {
                cur[g[sum[ind] + val] - 1] = {val + sum[ind], ind + 1};
                dp[mask] = true;
                dd[mask] = cur;
            }
        }
    }
    dp[0] = true;
    for (int m = 0; m < (1 << k); ++m)
    {
        if (!dp[m])
        {
            for (int s = m; s > 0; s = (s - 1) & m)
            {
                if (dp[s] && dp[m - s])
                {
                    dp[m] = true;
                    for (int32_t i = 0; i < k; ++i)
                    {
                        if (s & (1 << i))
                        {
                            dd[m][i] = dd[s][i];
                        }
                        else
                        {
                            dd[m][i] = dd[m - s][i];
                        }
                    }
                }
            }
        }
    }
    if (dp[(1 << k) - 1])
    {
        cout << "Yes" << endl;
        for (int i = 0; i < k; ++i)
        {
            cout << dd[(1 << k) - 1][i].first << " " << dd[(1 << k) - 1][i].second << endl;
        }
    }
    else
    {
        cout << "No" << endl;
        return 0;
    }
    return 0;
}