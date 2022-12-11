#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int q;
    cin >> q;
    for (int _ = 0; _ < q; ++_)
    {
        string s;
        string t;
        cin >> s;
        cin >> t;
        int n = s.size();
        int m = t.size();
        string ans = "NO";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j + i <= n; ++j)
            {
                int fl = true;
                for (int k = i; k < i + j; ++k)
                {
                    if (s[k] != t[k - i])
                    {
                        fl = false;
                        break;
                    }
                }
                if (!fl)
                {
                    continue;
                }
                int num = j;
                for (int k = i + j - 2; num < m; --k)
                {
                    if (k < 0)
                    {
                        fl = false;
                        break;
                    }
                    if (s[k] != t[num])
                    {
                        fl = false;
                        break;
                    }
                    ++num;
                }
                if (!fl)
                {
                    continue;
                }
                if (fl)
                {
                    ans = "YES";
                    break;
                }
            }
            if (ans == "YES")
            {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}