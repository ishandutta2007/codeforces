#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        if (2 * l >= r + 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}