#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int ans1 = 0;
    for (int i = 0; i < k; ++i)
    {
        ans1 += (n - i);
    }
    int pr = -1;
    int ans2 = 1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > n - k)
        {
            if (pr != -1)
            {
                ans2 *= (i - pr);
                ans2 %= mod;
            }
            pr = i;
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}