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
        int n = s.size();
        vector<int> used(n);
        int ans = 0;
        for (int i = 1; i < n; ++i)
        {
            if ((s[i] == s[i - 1] && !used[i - 1]) || (i > 1 && s[i] == s[i - 2] && !used[i - 2]))
            {
                used[i] = true;
                ++ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}