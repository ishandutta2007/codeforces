#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
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
        sort(a.begin(), a.end());
        int ans = max(0ll, min(n - 2, a[n - 2] - 1));
        cout << ans << endl;
    }
    return 0;
}