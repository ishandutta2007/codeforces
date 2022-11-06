#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y;
        cin >> x >> y;
        if (x - 1 == y)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}