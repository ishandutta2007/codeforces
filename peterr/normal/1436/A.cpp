#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            m -= x;
        }
        if (m == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}