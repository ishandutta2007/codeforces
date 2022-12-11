#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b)
        {
            swap(a, b);
        }
        if (b > c)
        {
            swap(b, c);
        }
        if (a > b)
        {
            swap(a, b);
        }
        int ans = 0;
        ans = a;
        if (c - a >= b)
        {
            ans += b;
            cout << ans << endl;
        }
        else
        {
            ans += (b + c - a) / 2;
            cout << ans << endl;
        }
    }
    return 0;
}