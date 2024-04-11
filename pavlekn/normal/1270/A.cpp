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
        int n, m, k;
        cin >> n >> m >> k;
        string ans = "NO";
        for (int i = 0; i < m; ++i)
        {
            int x;
            cin >> x;
            if (x == n)
            {
                ans = "YES";
            }
        }
        for (int i = 0; i < k; ++i)
        {
            int x;
            cin >> x;
        }
        cout << ans << endl;
    }
    return 0;
}