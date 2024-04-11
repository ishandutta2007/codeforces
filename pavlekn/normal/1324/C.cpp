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
        string s;
        cin >> s;
        s += 'R';
        int n = s.size();
        int pr = -1;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'R')
            {
                ans = max(ans, i - pr);
                pr = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}