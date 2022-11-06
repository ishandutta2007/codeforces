#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, b, d;
        cin >> r >> b >> d;
        if (r > b)
            swap(r, b);
        if ((long long) r * (d + 1) >= b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}