#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int w, h, n;
        cin >> w >> h >> n;
        int a = 1;
        int b = 1;
        while (!(w & 1))
        {
            w >>= 1;
            a *= 2;
        }
        while (!(h & 1))
        {
            h >>= 1;
            b *= 2;
        }
        if (a * b >= n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}