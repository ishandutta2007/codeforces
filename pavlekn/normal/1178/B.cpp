#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin >> a;
    int n = a.size();
    int cnt = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == 'v' && a[i - 1] == 'v')
        {
            ++cnt;
        }
    }
    int cur = 0;
    int ans = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == 'v' && a[i - 1] == 'v')
        {
            ++cur;
        }
        if (a[i] == 'o')
        {
            ans += cur * (cnt - cur);
        }
    }
    cout << ans << endl;
    return 0;
}