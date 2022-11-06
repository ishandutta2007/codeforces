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
        int g = 1;
        while ((int) to_string(g).length() < c)
        {
            g *= 2;
        }
        int x = g;
        int y = g;
        while ((int) to_string(x).length() < a)
            x *= 3;
        while ((int) to_string(y).length() < b)
            y *= 5;
        cout << x << " " << y << "\n";
        //cout << __gcd(x, y) << endl;
    }
    return 0;
}