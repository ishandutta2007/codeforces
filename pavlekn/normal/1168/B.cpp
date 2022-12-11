#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e9;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += max(0ll, n - i - 10 + 1);
        for (int j = i + 3; j <= n; ++j)
        {
            if (j - i >= 10)
            {
                break;
            }
            int fl = false;
            for (int p = i; p < j; ++p)
            {
                for (int k = 1; p + 2 * k < j; ++k)
                {
                    if (s[p] == s[p + k] && s[p] == s[p + 2 * k])
                    {
                        fl = true;
                    }
                }
            }
            if (fl)
            {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}