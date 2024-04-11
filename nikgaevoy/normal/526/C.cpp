#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <cstdio>
#include <ctime>

using namespace std;
const int inf = int (1e9 + 7);

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int c, hr, hb, wr, wb;
    cin >> c >> hr >> hb >> wr >> wb;

    time_t end = clock () + time_t (0.95 * CLOCKS_PER_SEC);
    double r = (double) hr / wr, b = (double) hb / wb;

    if (max (wr, wb) > 1000)
    {
        if (wr < wb)
        {
            swap (hr, hb);
            swap (wr, wb);
            swap (r, b);
        }
    }
    else if (r < b)
    {
        swap (hr, hb);
        swap (wr, wb);
        swap (r, b);
    }

    int f = c / wr, s = (c % wr) / wb, free = c - f * wr - s * wb;
    long long res = (long long) hr * f + (long long) hb * s;
    long long now = res;

    int add = wr / wb;
    long long dn = add * (long long) hb - hr, df = wr - add * (long long) wb;

    while (clock () < end && f > 0)
    {
        f--;
        free += df;
        now += dn;

        while (free >= wb)
        {
            free -= wb;
            now += hb;
        }

        if (res < now)
            res = now;
    }

    cout << res << endl;

    return 0;
}