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
        vector<int> a(n);
        string ans = "NO";
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            a[i] = abs(a[i]);
        }
        vector<int> sum;
        for (int msk = 0; msk < (1 << n); ++msk)
        {
            int cur = 0;
            for (int i = 0; i < n; ++i)
            {
                if (msk & (1 << i))
                {
                    cur += a[i];
                }
            }
            sum.push_back(cur);
        }
        sort(sum.begin(), sum.end());
        for (int i = 1; i < sum.size(); ++i)
        {
            if (sum[i] == sum[i - 1])
            {
                ans = "YES";
            }
        }
        cout << ans << endl;
    }
    return 0;
}