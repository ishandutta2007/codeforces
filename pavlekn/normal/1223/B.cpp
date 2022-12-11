#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    for (int _ = 0; _ < q; ++_)
    {
        string s, t;
        cin >> s >> t;
        int n = s.size();
        string ans = "NO";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (s[i] == t[j])
                {
                    ans = "YES";
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}