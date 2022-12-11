#include <bits/stdc++.h>

using namespace std;

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        int l = a[0];
        int r = n;
        int cur = l;
        string ans = "Yes";
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != cur)
            {
                ans = "No";
            }
            ++cur;
            if (a[i] == r)
            {
                r = l - 1;
                l = a[i + 1];
                cur = l;
            }
        }
        cout << ans << endl;
    }
    return 0;
}