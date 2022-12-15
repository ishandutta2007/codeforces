#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n <= 3)
        {
            cout << -1 << "\n";
            continue;
        }
        int d = n / 4;
        if (n % 4) d--;
        for (int i = 1; i <= d; i++)
        {
            int a,b,c,d;
            a = 4 * i - 2;
            b = 4 * i;
            c = 4 * i - 3;
            d = 4 * i - 1;
            cout << a << " ";
            cout << b << " ";
            cout << c << " ";
            cout << d << " ";
        }
        int res = n - 4 * d;
        if (res <= 6)
        {
            for (int i = 1; i <= res; i += 2)
            {
                cout << 4 * d + i << " ";
            }
            for (int i = 2; i <= res; i += 2)
            {
                cout << 4 * d + i << " ";
            }
        } else {
            for (int i = 1; i <= 7; i += 2)
            {
                cout << 4 * d + i << " ";
            }
            cout << 4 * d + 4 << " " << 4 * d + 6 << " " << 4 * d + 2 << " ";
        }
        cout << "\n";
    }
    return 0;
}