#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, dx1, dy1, dx2, dy2;
    cin >> n >> dx1 >> dy1 >> dx2 >> dy2;
    long long det = abs((long long) dx1 * dy2 - (long long) dx2 * dy1);
    if (n != det)
    {
        cout << "NO\n";
        return 0;
    }
    int g = __gcd(abs(dy1), abs(dy2));
    dy1 /= g;
    dy2 /= g;
    int r = -dy2;
    int s = dy1;
    int modx = (int) abs((long long) r * dx1 + (long long) s * dx2);
    cout << "YES\n";
    for (int i = 0; i < modx; i++)
    {
        for (int j = 0; j < g; j++)
        {
            cout << i << " " << j << "\n";
        }
    }
    return 0;
}