#include <bits/stdc++.h>

using namespace std;

#define int long long

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
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        string ans = "NO";
        for (int i = 1; i < n; ++i)
        {
            if (a[i].first == a[i - 1].first && a[i - 1].second + 1 < a[i].second)
            {
                ans = "YES";
            }
        }
        for (int i = 2; i < n; ++i)
        {
            if (a[i].first == a[i - 1].first && a[i - 1].first == a[i - 2].first)
            {
                ans = "YES";
            }
        }
        cout << ans << endl;
    }
    return 0;
}