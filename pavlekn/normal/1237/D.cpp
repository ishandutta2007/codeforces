#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize("-O3")
#pragma GCC target("avx")

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(3 * n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i + n] = a[i];
        a[i + 2 * n] = a[i];
    }
    int j = 3 * n;
    vector<int> dp(3 * n + 1);
    set<pair<int, int>> mn;
    set<pair<int, int>> mx;
    mn.insert({0, 3 * n});
    mx.insert({0, 3 * n});
    a.push_back(0);
    int i = 3 * n - 1;
    int its = 0;
    dp[3 * n] = 1;
    while (i >= 0)
    {
        mn.insert({a[i], i});
        while ((mn.begin()->first) * 2 < a[i])
        {
            mn.erase(mn.find({a[j], j}));
            --j;
        }
        dp[i] = j - i + 1;
        --i;
    }
    for (int i = 0; i < n; ++i)
    {
        if (dp[i] < 2 * n)
        {
            cout << dp[i] << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }
    cout << endl;
    return 0;
}