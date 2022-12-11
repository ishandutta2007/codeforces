#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

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
        string ans = "NO";
        int l, r;
        for (int i = 1; i < n; ++i)
        {
            if (abs(a[i] - a[i - 1]) > 1)
            {
                l = i;
                r = i + 1;
                ans = "YES";
                break;
            }
        }
        cout << ans << endl;
        if (ans == "YES")
        {
            cout << l << " " << r << endl;
        }
    }
    return 0;
}