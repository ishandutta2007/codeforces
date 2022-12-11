#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n + 10);
    int m = 0;
    vector<int> two;
    two.push_back(1);
    for (int i = 0; i < 30; ++i)
    {
        two.push_back(two[i] * 2);
    }
    for (int i = 1; i <= n; ++i)
    {
        int k = -1;
        for (int j = 1; (i % j) == 0; j *= 2)
        {
            ++k;
        }
        a[k].push_back(i);
        m = max(m, k + 1);
    }
    for (int i = 0; i < m; ++i)
    {
        if (i + 1 == m - 1)
        {
            int maxi = 0;
            int c = 0;
            for (auto el : a[i])
            {
                ++c;
                maxi = max(maxi, el);
            }
            for (auto el : a[i + 1])
            {
                maxi = max(maxi, el);
            }
            for (int j = 0; j < c; ++j)
            {
                cout << two[i] << " ";
            }
            cout << maxi;
            return 0;
        }
        else
        {
            for (int j = 0; j < a[i].size(); ++j)
            {
                cout << two[i] << " ";
            }
        }
    }
}