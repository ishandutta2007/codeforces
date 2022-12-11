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
        cin >> s; s.push_back('$');
        cin >> t;  t.push_back('$');
        int n = s.size();
        int m = t.size();
        if (n < m)
        {
            cout << "NO" << endl;
            continue;
        }
        string ans = "NO";
        int cnt = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == cur && s[i] == t[cnt])
            {
                ++cnt;
                if (cnt == m)
                {
                    break;
                }
                cur = 1 - cur;
            }
        }
        if (cnt == m)
        {
            ans = "YES";
        }
        cnt = 0;
        cur = 1;
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == cur && s[i] == t[cnt])
            {
                ++cnt;
                if (cnt == m)
                {
                    break;
                }
                cur = 1 - cur;
            }
        }
        if (cnt == m)
        {
            ans = "YES";
        }
        cout << ans << endl;
    }
    return 0;
}