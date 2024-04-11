#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int p, c;
        p = c = 0;
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (x - p < 0 || y - c < 0)
                ans = false;
            if (y - c > x - p)
                ans = false;
            p = x;
            c = y;
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}