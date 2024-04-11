#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1000000005;

int N, X, Y;
int maxx, minx, maxy, miny, maxs, mins, maxd, mind;

int main ()
{
    minx = miny = mins = mind = INF;
    maxx = maxy = maxs = maxd = -INF;
    scanf ("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf ("%d %d", &X, &Y);
        minx = min (minx, X - 1);
        maxx = max (maxx, X + 1);
        miny = min (miny, Y - 1);
        maxy = max (maxy, Y + 1);
        mins = min (mins, X + Y - 1);
        maxs = max (maxs, X + Y + 1);
        mind = min (mind, X - Y - 1);
        maxd = max (maxd, X - Y + 1);
    }

    printf ("%d\n", 2 * (maxx - minx) + 2 * (maxy - miny) - abs (mins - (minx + miny)) - abs (maxs - (maxx + maxy)) - abs (mind - (minx - maxy)) - abs (maxd - (maxx - miny)));
    return 0;
}