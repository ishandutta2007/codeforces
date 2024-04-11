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
        bool dec = true;
        int prev;
        cin >> prev;
        for (int i = 1; i < n; i++)
        {
            int x;
            cin >> x;
            if (x >= prev)
                dec = false;
            prev = x;
        }
        if (dec)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}