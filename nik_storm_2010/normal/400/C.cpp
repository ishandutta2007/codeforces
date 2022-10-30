#include<cstdio>
#include<algorithm>

using namespace std;
const int N = 200000;

int xx[N], yy[N];

int main()
{
    int n, m, x, y, z, p, nx, ny;
    scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &z, &p);
    for (int i = 0; i < p; i++) scanf("%d %d", &xx[i], &yy[i]);
    x %= 4, y %= 2, z %= 4;
    for (int t = 1; t <= x; t++)
    {
        for (int i = 0; i < p; i++)
        {
            nx = yy[i], ny = n - xx[i] + 1;
            xx[i] = nx;
            yy[i] = ny;
        }
        swap(n, m);
    }
    if (y == 1) for (int i = 0; i < p; i++) yy[i] = m - yy[i] + 1;
    for (int t = 1; t <= z; t++)
    {
        for (int i = 0; i < p; i++)
        {
            nx = m - yy[i] + 1, ny = xx[i];
            xx[i] = nx;
            yy[i] = ny;
        }
        swap(n, m);
    }
    for (int i = 0; i < p; i++) printf("%d %d\n", xx[i], yy[i]);
    return 0;
}