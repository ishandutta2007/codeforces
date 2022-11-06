#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m;
    int q;
    cin >> n >> m >> q;
    long long g = __gcd(n, m);
    while (q--)
    {
        int sx, ex;
        long long sy, ey;
        cin >> sx >> sy >> ex >> ey;
        sy--;
        ey--;
        int comp1, comp2;
        if (sx == 1)
        {
            comp1 = sy / (n / g);
        }
        else
        {
            comp1 = sy / (m / g);
        }
        if (ex == 1)
        {
            comp2 = ey / (n / g);
        }
        else
        {
            comp2 = ey / (m / g);
        }
        if (comp1 == comp2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}