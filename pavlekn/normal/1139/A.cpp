#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((s[i]-'0') % 2 == 0)
        {
            ans += i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}