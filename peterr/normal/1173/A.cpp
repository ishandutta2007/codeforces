#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    if (z == 0)
    {
        if (x > y)
            cout << "+";
        else if (x < y)
            cout << "-";
        else
            cout << "0";
    }
    else
    {
        if (x > y)
        {
            if (z >= x - y)
                cout << "?";
            else
                cout << "+";
        }
        else if (x < y)
        {
            if (z >= y - x)
                cout << "?";
            else
                cout << "-";
        }
        else
            cout << "?";
    }

    return 0;
}