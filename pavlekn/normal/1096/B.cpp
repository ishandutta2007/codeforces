#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod = 998244353;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1;
    for (int k = 0; k < 26; ++k)
    {
        char c = 'a' + k;
        int l, r;
        l = -1;
        r = -1;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != c)
            {
                l = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] != c)
            {
                r = i;
                break;
            }
        }
        if (l != -1)
            ans += (l + 1) * (n - r) - 1;
    }
    cout << ans % mod << endl;
    return 0;
}