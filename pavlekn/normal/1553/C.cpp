#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n = 10;
        string s;
        cin >> s;
        vector<int> a(n);
        int cnt1 = 0;
        int cnt2 = 0;
        int ans = 10;
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
            {
                if (s[i] == '?' || s[i] == '1')
                {
                    ++cnt1;
                }
            }
            else
            {
                if (s[i] == '1')
                {
                    ++cnt2;
                }
            }
            int s1 = 0;
            int s2 = 0;
            for (int j = i + 1; j < n; ++j)
            {
                if (j % 2 == 0)
                {

                }
                else
                {
                    ++s2;
                }
            }
            if (s1 + cnt1 > s2 + cnt2)
            {
                ans = min(ans, i + 1);
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
            {
                if (s[i] == '1')
                {
                    ++cnt1;
                }
            }
            else
            {
                if (s[i] == '1' || s[i] == '?')
                {
                    ++cnt2;
                }
            }
            int s1 = 0;
            int s2 = 0;
            for (int j = i + 1; j < n; ++j)
            {
                if (j % 2 == 0)
                {
                    ++s1;
                }
                else
                {

                }
            }
            if (s1 + cnt1 < s2 + cnt2)
            {
                ans = min(ans, i + 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}