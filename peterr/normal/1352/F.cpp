#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (b == 0)
        {
            if (a)
            {
                for (int i = 0; i < a + 1; i++)
                    cout << 0;
            }
            else
            {
                for (int i = 0; i < c + 1; i++)
                    cout << 1;
            }
            cout << endl;
        }
        else
        {
            for (int i = 0; i < a + 1; i++)
                cout << 0;
            for (int i = 0; i < c + 1; i++)
                cout << 1;
            for (int i = 0; i < b - 1; i++)
                cout << (i & 1);
            cout << endl;
        }
    }
    return 0;
}