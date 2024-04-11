#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int mx = 0;
        int ans = 1E9;
        for (int i = 0; i < n; i++)
        {
            int y;
            cin >> y;
            if (y == x)
                ans = 1;
            mx = max(mx, y);
        }
        if (mx > x)
            ans = min(ans, 2);
        else
            ans = min(ans, (x + mx - 1) / mx);
        cout << ans << endl;
    }
    return 0;
}