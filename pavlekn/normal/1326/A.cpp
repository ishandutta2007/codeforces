#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << -1 << endl;
            continue;
        }
        if (n % 3 == 1)
        {
            for (int i = 0; i < n - 4; ++i)
            {
                cout << 2;
            }
            cout << 2243 << endl;
        }
        else
        {
            for (int i = 0; i < n - 1; ++i)
            {
                cout << 2;
            }
            cout << 3 << endl;
        }
    }
    return 0;
}