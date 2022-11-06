#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        int c1, c2, c3, c4, c5, c6;
        cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
        long long ans = 0;
        if (x >= 0 && y >= 0)
            ans = (long long) c6 * x + (long long) c2 * y;
        else if (x <= 0 && y >= 0)
            ans = (long long) -c3 * x + (long long) c2 * y;
        else if (x <= 0 && y <= 0)
            ans = (long long) -c3 * x + (long long) -c5 * y;
        else
            ans = (long long) c6 * x + (long long) -c5 * y;
        if (x > 0)
        {
            if (y >= x)
                ans = min(ans, (long long) c1 * x + (long long) c2 * (y - x));
            else
                ans = min(ans, (long long) c1 * x + (long long) c5 * (x - y));
        }
        if (y > 0)
        {
            if (x >= y)
                ans = min(ans, (long long) c1 * y + (long long) c6 * (x - y));
            else
                ans = min(ans, (long long) c1 * y + (long long) c3 * (y - x));
        }
        if (x < 0)
        {
            if (y >= x)
                ans = min(ans, (long long) -c4 * x + (long long) c2 * (y - x));
            else
                ans = min(ans, (long long) -c4 * x + (long long) c5 * (x - y));
        }
        if (y < 0)
        {
            if (x >= y)
                ans = min(ans, (long long) -c4 * y + (long long) c6 * (x - y));
            else
                ans = min(ans, (long long) -c4 * y + (long long) c3 * (y - x));
        }
        cout << ans << "\n";
    }
    return 0;
}