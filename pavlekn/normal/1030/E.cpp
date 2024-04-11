#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        unsigned int count = 0;
        for (; x; count++)
        {
            x &= (x - 1);
        }
        a[i] = count;
    }
    int ans = 0;
    vector<int> dp0(n + 1);
    dp0[0] = 0;
    vector<int> dp1(n + 1);
    dp1[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[n - i] % 2 == 0)
        {
            dp0[i] = dp0[i - 1] + 1;
            dp1[i] = dp1[i - 1];
        }
        else
        {
            dp0[i] = dp1[i - 1];
            dp1[i] = dp0[i - 1] + 1;
        }
        ans += dp0[i];
    }
    for (int l = n - 1; l >= 0; --l)
    {
        int mx = 0;
        int sum = 0;
        for (int r = l; r < n && r - l < 63; ++r)
        {
            mx = max(mx, a[r]);
            sum += a[r];
            if (sum % 2 == 0 && mx * 2 > sum)
            {
                --ans;
            }
        }
    }
    cout << ans << endl;
}