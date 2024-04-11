#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "? ";
    for (int i = 1; i <= 100; i++)
    {
        cout << i;
        if (i < 100)
            cout << " ";
    }
    cout << endl;
    fflush(stdout);
    int ans;
    cin >> ans;
    for (int i = 0; i < 7; i++)
    {
        if (ans & (1 << i))
        {
            ans ^= (1 << i);
        }
    }
    cout << "? ";
    for (int i = 0; i < 100; i++)
    {
        cout << (i << 7);
        if (i < 99)
            cout << " ";
    }
    cout << endl;
    fflush(stdout);
    int temp;
    cin >> temp;
    for (int i = 7; i < 14; i++)
    {
        if (temp & (1 << i))
        {
            temp ^= (1 << i);
        }
    }
    ans |= temp;
    cout << "! " << ans << endl;
    fflush(stdout);
    return 0;
}