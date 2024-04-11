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
        bool ans = true;
        int x;
        cin >> x;
        x %= 2;
        for (int i = 1; i < n; i++)
        {
            int y;
            cin >> y;
            if (y % 2 != x)
                ans = false;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}