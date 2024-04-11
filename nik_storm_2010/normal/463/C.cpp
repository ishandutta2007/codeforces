#include <cstdio>

using namespace std;
typedef long long ll;
const int N = 3000;

int a[N][N];
ll d1[2 * N], d2[2 * N];

int main()
{
    int n, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
    {
        scanf("%d", &a[i][j]);
        d1[i + j] += a[i][j];
        d2[i - j + N] += a[i][j];
    }
    long long ans1 = -1, ans2 = -1;
    int x1, y1, x2, y2;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
    {
        long long cur = d1[i + j] + d2[i - j + N] - a[i][j];
        if ((i + j) % 2)
        {
            if (ans1 < cur) ans1 = cur, x1 = i, y1 = j;
        }
        else
        {
            if (ans2 < cur) ans2 = cur, x2 = i, y2 = j;
        }
    }
    printf("%I64d\n%d %d %d %d\n", ans1 + ans2, x1, y1, x2, y2);
    return 0;
}