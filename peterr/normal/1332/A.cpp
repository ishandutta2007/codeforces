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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        bool ans = true;
        if (a + b > 0 && x1 == x2)
            ans = false;
        if (c + d > 0 && y1 == y2)
            ans = false;
        int otherX = x + (b - a);
        int otherY = y + (d - c);
        if (otherX < x1 || otherX > x2)
            ans = false;
        if (otherY < y1 || otherY > y2)
            ans = false;
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}