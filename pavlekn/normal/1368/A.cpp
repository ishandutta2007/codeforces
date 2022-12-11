#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int a, b, n;
        cin >> a >> b >> n;
        if (a > b)
        {
            swap(a, b);
        }
        int ans = 0;
        while (b <= n)
        {
            a += b;
            swap(a, b);
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}