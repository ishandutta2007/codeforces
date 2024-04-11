#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9;

int N, d1, d2;
bool bgood = true;
int ans = 0;

void apply (ld dd)
{
    if (dd <= d1 * (ld) d1 + EPS && bgood)
        ans++, bgood = false;
    else if (dd > d2 * d2 + EPS)
        bgood = true;
}

ld gv (int x1, int x2, int x3, int x4, ld d)
{
    return (x2 - x1) * d + (x4 - x3) * (1 - d);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> d1 >> d2;

    int px, py, px2, py2;
    for (int i = 0; i < N; i++)
    {
        int x, y, x2, y2;
        cin >> x >> y >> x2 >> y2;
        if (i)
        {
            ld lo = 0, hi = 1;
            while (hi - lo > EPS / 1000)
            {
                ld m1 = (lo * 2 + hi) / 3, m2 = (lo + 2 * hi) / 3;
                ld xv = gv (px, px2, x, x2, m1), yv = gv (py, py2, y, y2, m1);
                ld xv2 = gv (px, px2, x, x2, m2), yv2 = gv (py, py2, y, y2, m2);
                if (xv * xv + yv * yv > xv2 * xv2 + yv2 * yv2)
                    lo = m1;
                else
                    hi = m2;
            }
            ld xv = gv (px, px2, x, x2, lo), yv = gv (py, py2, y, y2, lo);
            apply (xv * xv + yv * yv);
        }
        int dd = (x - x2) * (x - x2) + (y - y2) * (y - y2);
        apply (dd);
        px = x;
        py = y;
        px2 = x2;
        py2 = y2;
    }
    cout << ans << "\n";
}