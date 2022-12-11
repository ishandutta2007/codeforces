#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t = s;
        sort(t.begin(), t.end());
        int ans = n;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == t[i])
            {
                --ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}