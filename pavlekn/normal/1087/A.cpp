#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); srand(clock());
    string s;
    cin >> s;
    int n = s.size();
    int x = n - 1;
    int y = 0;
    string ans;
    if (n % 2)
    {
        --n;
        ans += s[0];
        ++y;
    }
    for (int i = 0; i < n; ++i)
    {
        if (i % 2)
        {
            ans += s[y];
            ++y;
        }
        else
        {
            ans += s[x];
            --x;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}