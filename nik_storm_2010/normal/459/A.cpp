#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (x1 > x2 || (x1 == x2 && y1 > y2)) swap(x1, x2), swap(y1, y2);
    int dx = abs(x1 - x2), dy = abs(y1 - y2);
    if (dx != 0 && dy != 0)
    {
        if (dx != dy) puts("-1"); else printf("%d %d %d %d\n", x2, y1, x1, y2);
        return 0;
    }
    if (dx != 0) printf("%d %d %d %d\n", x1, y1 + dx, x2, y2 + dx); else printf("%d %d %d %d\n", x1 + dy, y1, x2 + dy, y2);
    return 0;
}