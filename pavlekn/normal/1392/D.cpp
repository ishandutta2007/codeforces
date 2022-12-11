#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18 + 11;

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
        string s;
        cin >> s;
        int fl = true;
        int l = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != s[0])
            {
                fl = false;
                l = i;
                break;
            }
        }
        if (fl)
        {
            cout << ((n + 2) / 3) << endl;
        }
        else
        {
            int cur = 1;
            int ans = 0;
            for (int i = l + 1; i < l + n; ++i)
            {
                if (s[i % n] == s[(i - 1) % n])
                {
                    ++cur;
                }
                else
                {
                    ans += cur / 3;
                    cur = 1;
                }
            }
            ans += cur / 3;
            cout << ans << endl;
        }
    }
    return 0;
}