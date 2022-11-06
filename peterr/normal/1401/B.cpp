#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        int ans = 2 * min(z1, y2);
        int amt = min(z1, y2);
        z1 -= amt;
        y2 -= amt;
        if (z1)
        {
            amt = min(z1, z2);
            z1 -= amt;
            z2 -= amt;
        }
        if (x1)
        {
            amt = min(x1, z2);
            x1 -= amt;
            z2 -= amt;
        }
        ans -= 2 * min(z2, y1);
        cout << ans << "\n";
    }
    return 0;
}