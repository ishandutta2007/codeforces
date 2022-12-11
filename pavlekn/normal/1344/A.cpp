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
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        vector<int> cnt(n);
        string ans = "YES";
        for (int i = 0; i < n; ++i)
        {
            ++cnt[i];
            ++cnt[((i + a[i]) % n + n) % n];
        }
        for (int i = 0; i < n; ++i)
        {
            if (cnt[i] != 2)
            {
                ans = "NO";
            }
        }
        cout << ans << endl;
    }
    return 0;
}