#include <iostream>
#include <cstdio>
#include <math.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef double ld;
 
#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fi first
#define se second


const double eps = 1e-7;

int main()
{
    //**/freopen("in.txt", "r", stdin);
    fastRead;
    ld r, d, n;
    cin >> r >> d >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ld x, y, r1;
        cin >> x >> y >> r1;
        ld t = sqrt(x * x + y * y);
        if (fabs(d - r) < eps)
        {
            if (t + r1 < d + eps)
                ans++;
            continue;
        }
        if (r1 + eps > t)
            continue;
        if (t - r1 + eps > r - d && t + r1 - eps < r)
            ans++;
    }
    cout << ans;
    return 0;
}