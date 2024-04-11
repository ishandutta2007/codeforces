#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        long long ans = (long long) a * abs(x - y);
        int dist = min(abs(x), abs(y));
        if ((long long) x * y <= 0)
            dist = 0;
        if (2 * a < b)
            ans += (long long) 2 * dist * a;
        else
            ans += (long long) dist * b;
        cout << ans << endl;
    }
    return 0;
}