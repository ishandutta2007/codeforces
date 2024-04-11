#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); srand(clock());
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
        int cur = 0;
        string ans = "YES";
        for (int i = 1; i < n; ++i)
        {
            cur += max(0, a[i] - a[i - 1]);
            if (a[i] < cur)
            {
                ans = "NO";
            }
        }
        cout << ans << endl;
    }
    return 0;
}