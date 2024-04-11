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
        int a, b, c;
        a = -1;
        for (int five = 0; five <= 2; five++)
        {
            for (int seven = 0; seven <= 2; seven++)
            {
                if (five * 5 + seven * 7 <= n && (n - five * 5 - seven * 7) % 3 == 0)
                {
                    a = (n - five * 5 - seven * 7) / 3;
                    b = five;
                    c = seven;
                }
            }
        }
        if (a == -1)
            cout << "-1\n";
        else
            cout << a << " " << b << " " << c << "\n";
    }
    return 0;
}