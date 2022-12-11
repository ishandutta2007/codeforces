#include<bits/stdc++.h>

using namespace std;

#define int long long

#pragma GCC optimize("-O3")
#pragma GCC target("avx")

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; ++j)
            {
                ans[j].push_back(i * n + j + 1);
            }
        }
        else
        {
            for (int j = 0; j < n; ++j)
            {
                ans[n - j - 1].push_back(i * n + j + 1);
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (auto el : ans[i])
        {
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}