#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    if (2 * n <= m)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << '1';
        }
        cout << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << '1';
        }
    }
    else
    {
        for (int i = 0; i < n - 1; ++i)
        {
            cout << '4';
        }
        cout << '5' << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << '5';
        }
    }
}