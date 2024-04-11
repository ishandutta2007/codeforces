#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 2000;

int c[N], ymin, ymax, n;
char a[2 * N][2 * N];

void build(int x, int y, int num)
{
    if (num > n) return;
    if (num % 2)
    {
        for (int i = 0; i < c[num]; i++)
        {
            ymin = min(ymin, x);
            ymax = max(ymax, x);
            a[x][y] = 47;
            y++;
            if (i != c[num] - 1) x--;
        }
        build(x, y, num + 1);
    }
    else
    {
        for (int i = 0; i < c[num]; i++)
        {
            ymin = min(ymin, x);
            ymax = max(ymax, x);
            a[x][y] = 92;
            y++;
            if (i != c[num] - 1) x++;
        }
        build(x, y, num + 1);
    }
}

int main()
{
    for (int i = 0; i < 2 * N; i++) for (int j = 0; j < 2 * N; j++) a[i][j] = ' ';
    scanf("%d", &n);
    ymin = +2e9, ymax = -2e9;
    int cur = N, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
        sum += c[i];
    }
    build(N, 0, 1);
    for (int i = ymin; i <= ymax; i++) for (int j = 0; j < sum; j++)
    {
        printf("%c", a[i][j]);
        if (j == sum - 1) printf("\n");
    }
    return 0;
}