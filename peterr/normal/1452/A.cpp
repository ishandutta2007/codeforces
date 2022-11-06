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
        if (x < y)
            swap(x, y);
        int ans = 2 * y;
        if (x > y)
        {
            ans++;
            x--;
        }
        ans += (x - y) * 2;
        cout << ans << "\n";
    }
    return 0;
}