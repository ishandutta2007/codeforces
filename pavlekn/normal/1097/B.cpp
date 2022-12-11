#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int res = 0;
    for (int k = 0; k < (1 << n); ++k)
    {
        int e = k;
        vector<int> m(n);
        for (int i = 0; i < n; ++i)
        {
            m[i] = e % 2;
            e /= 2;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (m[i])
            {
                ans += a[i];
            }
            else
            {
                ans -= a[i];
            }
        }
        if ((ans + 36000) % 360 == 0)
        {
            res = 1;
        }
    }
    if (res)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}