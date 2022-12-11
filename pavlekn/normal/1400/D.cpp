#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e3 + 225;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        int ans = 0;
        vector<int> pr(n + 1);
        vector<int> sf(n + 1);
        for (int i = 0; i < n; ++i)
        {
            for (int k = 0; k <= n; ++k)
            {
                sf[k] = 0;
            }
            for (int j = n - 1; j >= i + 1; --j)
            {
                ans += pr[a[j]] * sf[a[i]];
                ++sf[a[j]];
            }
            pr[a[i]]++;
        }
        cout << ans << endl;
    }
    return 0;
}