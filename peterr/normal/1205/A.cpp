#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 1)
                cout << i * 2 - 1<< " ";
            else
                cout << i * 2 << " ";
        }
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 1)
                cout << i * 2 << " ";
            else
                cout << i * 2 - 1 << " ";
        }
    }
    return 0;
}