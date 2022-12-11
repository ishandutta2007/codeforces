#include <bits/stdc++.h>

using namespace std;

#define int long long

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
        vector<vector<int>> a(n, vector<int> (5));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        for (int i = 1; i < n; ++i)
        {
            int cnt = 0;
            for (int j = 0; j < 5; ++j)
            {
                if (a[i][j] < a[ans][j])
                {
                    ++cnt;
                }
            }
            if (cnt >= 3)
            {
                ans = i;
            }
        }
        int c = 1;
        for (int i = 0; i < n; ++i)
        {
            int cnt = 0;
            for (int j = 0; j < 5; ++j)
            {
                if (a[i][j] > a[ans][j])
                {
                    ++cnt;
                }
            }
            if (cnt >= 3)
            {
                ++c;
            }
        }
        if (c < n)
        {
            ans = -2;
        }
        cout << ans + 1 << endl;
    }
    return 0;
}